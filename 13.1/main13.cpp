//HW13 April 1, 2024 Oliver Carleton
#include "WallClockTime.hpp"
#include <iostream>
#include <vector>
#include <algorithm>


int main(int argc, const char* argv[]) {
    // time1
    WallClockTime wctime1(12, 00, 00);
    std::cout << "Time1 is " << wctime1.getHours() << 'h'
                << wctime1.getMinutes() << 'm'
                << wctime1.getSeconds() << 's' << std::endl;
    std::cout << wctime1.displayFormat24() << std::endl;
    std::cout << wctime1.displayFormat12() << std::endl;
    
    // test setters
    wctime1.setHours(24);
    std::cout << "Time1\n";
    std::cout << wctime1.displayFormat24() << std::endl;
    std::cout << wctime1.displayFormat12() << std::endl;
    wctime1.setMinutes(120);
    wctime1.setSeconds(61);
    std::cout << "Time1\n";
    std::cout << wctime1.displayFormat24() << std::endl;
    std::cout << wctime1.displayFormat12() << std::endl;
    
    // time2
    std::cout << "Time2\n";
    WallClockTime wctime2(86401);
    std::cout << wctime2.displayFormat24() << std::endl;
    std::cout << wctime2.displayFormat12() << std::endl;

    
    // time3
    WallClockTime wctime3(-86401);
    std::cout << "Time3\n";
    std::cout << wctime3.displayFormat24() << std::endl;
    std::cout << wctime3.displayFormat12() << std::endl;
    
    // time4
    WallClockTime wctime4;
    std::cout << "Time4\n";
    std::cout << wctime4.displayFormat24() << std::endl;
    std::cout << wctime4.displayFormat12() << std::endl;

    // time5
    WallClockTime wctime5(59, 59);
    std::cout << "Time5\n";
    std::cout << wctime5.displayFormat24() << std::endl;
    std::cout << wctime5.displayFormat12() << std::endl;

    std::vector<WallClockTime> times;
    times.push_back(wctime1);
    times.push_back(wctime2);
    times.push_back(wctime3);
    times.push_back(wctime4);
    times.push_back(wctime5);
    
    // sort using STL lib
    std::cout << "Sort: ascending\n";
    std::sort(times.begin(), times.end(), [](auto t1, auto t2) {
        return compare(t1, t2) == LESS;
    });
    for (auto ti : times) {
        std::cout << ti.displayFormat12() << std::endl;
    }
    std::cout << "Sort: descending\n";
    std::sort(times.begin(), times.end(), [](auto t1, auto t2) {
        return compare(t1, t2) == GREATER;
    });
    for (auto ti : times) {
        std::cout << ti.displayFormat12() << std::endl;
    }
    return 0;
}
