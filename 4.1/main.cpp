// HW04 Oliver Carleton FEB 2,2024
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    //constants declared
    const int inchesFoot = 12;
    const int centimetersMeter = 100;
    const double metersFoot = 0.3048;
   //varrible delcarations
    int feet, inches;
    double totalMeters, totalCentimeters;
    int meters, centimeters;
//infinite loop (conversion)
    while(1) {
        cout << "Enter length in feet (0 to terminate): ";
        cin >> feet;
        if (feet == 0) {
            cout << "Program terminated by user." << endl;
            break;
        }
        //enter length
        cout << "Enter length in inches: ";
        cin >> inches;
        totalMeters = (feet * metersFoot) + (inches * metersFoot / inchesFoot);
        //extract to meters
        meters = static_cast<int>(totalMeters);
        //converting fraction to centimeters
        totalCentimeters = (totalMeters - meters) * centimetersMeter;
        centimeters = static_cast<int>(round(totalCentimeters));
       //if for rounding up
        if (centimeters == 100) {
        centimeters = 0;
        meters += 1;
        }
        //result 
        cout << feet << " feet " << inches << " inches equals "
             << meters << " meters " << centimeters << " centimeters." << endl;
    }
return 0;
}

