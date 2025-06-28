//HW21 Oliver Carleton April 30,2024
// “I affirm that I do not give or receive any unauthorized help on this homework and that all work is my own”
#include "MovingObject.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/odeint.hpp>
#include <fstream>
#include <iostream>
#include <cmath>
#include <functional>

namespace OliverCarleton {

const double g = 9.81;

class Cannonball : public MovingObject {
public:
    Cannonball(double m, double dc, double initial_speed, double angle, double height)
        : mass(m), drag_coefficient(dc), MovingObject(create_initial_state(initial_speed, angle, height)) {
    }

    void computeRHS(const state_type &y, state_type &dydt, const double) override {
        double speed = std::hypot(y[2], y[3]); // speed is the magnitude of the velocity vector.
        double air_resistance_x = drag_coefficient * speed * y[2]; // air resistance in the x direction.
        double air_resistance_y = drag_coefficient * speed * y[3]; // air resistance in the y direction.
        dydt[0] = y[2]; // change in x position is the x component of velocity.
        dydt[1] = y[3]; // change in y position is the y component of velocity.
        dydt[2] = -air_resistance_x / mass; // change in x velocity considering air resistance.
        dydt[3] = -air_resistance_y / mass - g; // change in y velocity considering air resistance and gravity.
    }

private:
    double mass;
    double drag_coefficient;

    static state_type create_initial_state(double initial_speed, double angle, double height) {
        double theta = (angle * M_PI) / 180.0; // Convert angle to radians.
        state_type y0(4);
        y0[0] = 0.0; // initial x position.
        y0[1] = height; // initial y position (height of the tower).
        y0[2] = initial_speed * std::cos(theta); // initial x component of velocity
        y0[3] = initial_speed * std::sin(theta); // initial y component of velocity
        return y0;
    }
};

} // namespace OliverCarleton

int main() {
    using namespace OliverCarleton;
    using namespace boost::numeric::odeint;

    std::ofstream file("/Users/olivercarleton/Documents/cpp/HW21/HW21/trajectory.txt");
    
    double mass, drag_coefficient, initial_speed, angle, height;
    std::cout << "Enter mass (kg): ";
    std::cin >> mass;
    std::cout << "Enter drag coefficient: ";
    std::cin >> drag_coefficient;
    std::cout << "Enter initial speed (m/s): ";
    std::cin >> initial_speed;
    std::cout << "Enter launch angle (degrees): ";
    std::cin >> angle;
    std::cout << "Enter height of the tower (m): ";
    std::cin >> height;

    Cannonball cannonball(mass, drag_coefficient, initial_speed, angle, height);

    if (!file.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    state_type y = cannonball.stateVector();
    const double dt = 0.1; // time step for the integration.

    // lambda function is called at each integration step.
    auto write_to_file = [&file](const state_type &y, double t) {
        if (y[1] < 0) return; // projectile has hit the ground.
        file << y[0] << ", " << y[1] << std::endl; // write x and y positions.
    };

    try {
        integrate_adaptive(make_controlled(1e-12, 1e-12, runge_kutta_dopri5<state_type>()),
                           cannonball, y, 0.0, 10000.0, dt, write_to_file);
    } catch (const std::runtime_error& e) {
        std::cout << "Simulation complete: " << e.what() << std::endl;
    }

    file.close();
    return 0;
}

