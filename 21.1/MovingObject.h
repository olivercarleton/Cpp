#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/odeint.hpp>

namespace OliverCarleton {

typedef boost::numeric::ublas::vector<double> state_type;

class MovingObject {
public:
    // default constructor
    MovingObject() {}

    // constructor with parameter, y0 is the initial state vector.
    MovingObject(const state_type &y0) : Y(y0) {}

    // overloading operator(), callback function for odeint.
    virtual void operator()(const state_type &y, state_type &dydt, const double time) {
        computeRHS(y, dydt, time);
    }

    // virtual function that computes RHS of dY/dt=f(Y,t).
    virtual void computeRHS(const state_type &y, state_type &dydt, const double time) {
    }

    // get/Set State Vector
    state_type& stateVector() {
        return Y;
    }

private:
    state_type Y; // State Vector
};

} // namespace OliverCarleton

#endif // MOVINGOBJECT_H

