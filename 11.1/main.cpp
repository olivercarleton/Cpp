#include <cmath>
#include <iomanip>
#include <iostream>
//forward declarations for our functions
double ***makeDoubleArray3D(double *&v, int s1, int s2, int s3);
void destroyDoubleArray3D(double *v, double ***m, int s1, int s2, int s3);
//implementations of our functions
double ***makeDoubleArray3D(double *&v, int s1, int s2, int s3) {
    //allocate memory for the 3D array
    double *block = new double[s1 * s2 * s3];
    double ***grid = new double**[s1];

    for (int i = 0; i < s1; ++i) {
        grid[i] = new double*[s2];
        for (int j = 0; j < s2; ++j) {
            grid[i][j] = block + (i * s2 * s3) + (j * s3);
        }
    }
    //set the reference of v to the block
    v = block;
    //return the 3D array pointer
    return grid;
}
void destroyDoubleArray3D(double *v, double ***m, int s1, int s2, int s3) {
    //delete the allocated 3D array
    delete [] v; //delete the block allocated for data
    for (int i = 0; i < s1; ++i) {
        delete [] m[i]; //delete the pointers to double pointers (2D arrays)
    }
    delete [] m; //delete the pointers to double pointers (3D array)
}
int main(int argc, const char *argv[]) {
    const int size1 = 3;
    const int size2 = 4;
    const int size3 = 5;
    const double epsilon = 1.e-10;
    double *vect;
    double ***grid3d = makeDoubleArray3D(vect, size1, size2, size3);
    
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            for (int k = 0; k < size3; k++) {
                double r2 = std::pow(i - (size1 - 1) * 0.5, 2.) +
                            std::pow(j - (size2 - 1) * 0.5, 2.) +
                            std::pow(k - (size3 - 1) * 0.5, 2.);
                grid3d[i][j][k] = 1.0 / std::sqrt(std::max(r2, epsilon));
            }
        }
    }
    std::cout << "grid\n";
    std::cout.setf(std::ios::scientific);
    std::cout.precision(2);
    for (int i = 0; i < size1; i++) {
        std::cout << "i=" << i << std::endl;
        for (int j = 0; j < size2; j++) {
            for (int k = 0; k < size3; k++) {
                std::cout << std::setw(9) << grid3d[i][j][k];
            }
            std::cout << std::endl;
        }
    }
    std::cout << "vector\n";
    for (int i = 0; i < size1 * size2 * size3; i++) {
        std::cout << vect[i] << std::endl;
    }
    destroyDoubleArray3D(vect, grid3d, size1, size2, size3);
    return 0;
}

