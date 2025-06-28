//HW03 Oliver Carleton Jan 30,2024
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
int main() {
    const int numCount = 10;
    int numbers[numCount];
    int sumPositive = 0;
    int sumNegative = 0;
    int maxN = numeric_limits<int>::min();
    int minN = numeric_limits<int>::max();

    cout << "Enter 10 whole numbers:";
    for (int n = 0; n < numCount; ++n) {
        cin >> numbers[n];
    }
    for (int n = 0; n < numCount; ++n) {
        if (numbers[n] > 0) {
            sumPositive += numbers[n];
        } 
        else if (numbers[n] < 0) {
            sumNegative += numbers[n];
        }
        if (numbers[n] > maxN) {
            maxN = numbers[n];
        }
        if (numbers[n] < minN) {
            minN = numbers[n];
        }
    }
    cout << "Sum of positive numbers:" << sumPositive << endl;
    cout << "Sum of negative numbers:" << sumNegative << endl;
    cout << "Maximum number:" << maxN << endl;
    cout << "Minimum number:" << minN << endl;
    return 0;
}


