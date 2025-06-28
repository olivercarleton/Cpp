#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//declaration (prototype)
void showValue(char a);
void showValue(bool b);
void showValue(int i);
void showValue(double d);
void showValue(float f);
void showValue(long l);
double distance(double x1,double x2);
double distance(double x1,double y1,double x2,double y2);
double distance(double x1,double y1,double z1,double x2,double y2,double z2);

//MAIN
int main(int argc, char* argv[]) {
    // Distance Function Test
       double x1 = 1.2;
       double x2 = -1.8;
       double y1 = 1.2;
       double y2 = -1.8;
       double z1 = 0.2;
       double z2 = 1.6;
       cout << "1d distance=" << distance(x1, x2) << endl;
       cout << "2d distance=" << distance(x1, y1, x2, y2) << endl;
       cout << "3d distance=" << distance(x1, y1, z1, x2, y2, z2) << endl;
       
       // Test showValue
       char val1 = 'Y';
       bool val2 = true;
       int val3 = 123;
       double val4 = 1.23;
       float val5 = 3.21;
       long val6 = 321;
       
       showValue(val1);
       showValue(val2);
       showValue(!val2);
       showValue(val3);
       showValue(val4);
       showValue(val5);
       showValue(val6);
        return 0;
}

//definition (implementation)
//1D
double distance(double x1,double x2) {
    return abs(x1- x2);
}
//2D
double distance(double x1,double y1,double x2,double y2) {
    return sqrt(pow(x2- x1, 2) + pow(y2- y1, 2));
}
//3D
double distance(double x1,double y1,double z1,double x2,double y2,double z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}
void showValue(char a) {
    cout << "Value of type char is " << a << endl;
}

void showValue(bool b) {
    cout << "Value of type bool is " << (b ? "true" : "false") << endl;
}

void showValue(int i) {
    cout << "Value of type int is " << i << endl;
}

void showValue(double d) {
   cout << fixed << setprecision(2) << "Value of type double is " << d << endl;
   cout.unsetf(ios_base::fixed);
}

void showValue(float f) {
   cout << fixed << setprecision(2) << "Value of type float is " << f << endl;
   cout.unsetf(ios_base::fixed);
}

void showValue(long l) {
   cout << "Value of type long is " << l << endl;
}


