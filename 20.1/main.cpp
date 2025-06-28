//HW20 Oliver Carleton April 27, 2024
//“I affirm that I do not give or receive any unauthorized help on this homework and that all work is my own”
#include <iostream>
#include <Eigen/Dense>

int main() {
    //define the matrix A using Eigen's MatrixXd
    Eigen::MatrixXd A(3, 3);
    A << 1, 2, 3,4, 5, 6,7, 9, 10;

    //define the vector b using Eigen's VectorXd
    Eigen::VectorXd b(3);
    b << 3,3,4;

    //solve for x using Eigen's linear solver
    Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);

    //compute the residual r = b - Ax
    Eigen::VectorXd r = b - A * x;

    //compute the norm of the residual
    double r_norm = r.norm();

    //print x, r, and ||r||
    std::cout << "x =\n" << x << std::endl;
    std::cout << "r =\n" << r << std::endl;
    std::cout << "||r|| = " << r_norm << std::endl;

    return 0;
}

