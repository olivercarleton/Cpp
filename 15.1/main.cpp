// main.cpp
#include "WallClockTime.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace OliverCarleton;

int main(int argc, const char* argv[]) {
    WallClockTime noon(12,0,0);
    WallClockTime tenMin(10,0);
    
    WallClockTime time1 = noon + tenMin;
    time1.setDisplayTime12();
    std::cout << "10 minutes past noon is " << time1 << std::endl;
    
    WallClockTime time2 = noon - tenMin;
    time2.setDisplayTime12();
    std::cout << "10 minutes before noon is " << time2 << std::endl;
    
    WallClockTime oneHour(1, 0, 0);
    std::cout << "1 Hour x 3 = " << oneHour * 3 << std::endl;
    std::cout << "1 Hour / 3 = " << oneHour / 3 << std::endl;

    std::cout << "What time is it now?\n";
    std::cout << "(hour) (minute) (second) separated by space :";
    std::cin >> time1;

    std::cout << "Current time is " << time1 << ", so lunch is " << noon - time1 << " ahead.\n";
    if (time1 == noon) {
        std::cout << "It's lunch time.\n";
    }
    if (time1 < noon) {
        std::cout << noon - time1 << " to lunch time.\n";
    }
    if (time1 > noon) {
        std::cout << time1 - noon << " past lunch time.\n";
    }
    
    time1 -= time2;
    time1 += time2;
    time1.setDisplayTime24();
    std::cout << "Current time is " << time1 << std::endl;
    
    time1 = oneHour;
    time1 *= 3;
    std::cout << "1 Hour x 3 = " << time1 << std::endl;
    time1 = oneHour;
    time1 /= 3;
    std::cout << "1 Hour / 3 = " << time1 << std::endl;

    return 0;
}


