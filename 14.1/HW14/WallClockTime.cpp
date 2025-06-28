// WallClockTime.cpp
#include "WallClockTime.hpp"
#include <sstream>
#include <iomanip>

namespace OliverCarleton {

// Function to normalize the time to ensure valid representation
void WallClockTime::normalizeTime() {
    int totalSeconds = hours * 3600 + minutes * 60 + seconds;
    
    // Adjust for negative seconds
    if (totalSeconds < 0) {
        totalSeconds = (86400 + totalSeconds % 86400) % 86400;
    }

    // Normalize hours, minutes, and seconds
    hours = (totalSeconds / 3600) % 24;
    minutes = (totalSeconds % 3600) / 60;
    seconds = totalSeconds % 60;
}

// Constructors
WallClockTime::WallClockTime(int hr, int min, int sec) : hours(hr), minutes(min), seconds(sec) {
    normalizeTime();
}

WallClockTime::WallClockTime(int min, int sec) : WallClockTime(0, min, sec) {}

WallClockTime::WallClockTime(int sec) : WallClockTime(0, 0, sec) {}

WallClockTime::WallClockTime() : WallClockTime(0, 0, 0) {}

// Getters
int WallClockTime::getHours() const { return hours; }
int WallClockTime::getMinutes() const { return minutes; }
int WallClockTime::getSeconds() const { return seconds; }

// Setters
void WallClockTime::setHours(int hr) {
    hours = hr;
    normalizeTime();
}

void WallClockTime::setMinutes(int min) {
    minutes = min;
    normalizeTime();
}

void WallClockTime::setSeconds(int sec) {
    seconds = sec;
    normalizeTime();
}

// Function to display time in 24-hour format
std::string WallClockTime::displayFormat24() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hours << ":"
        << std::setw(2) << minutes << ":" << std::setw(2) << seconds;
    return oss.str();
}

// Function to display time in 12-hour format with AM/PM
std::string WallClockTime::displayFormat12() const {
    std::ostringstream oss;
    int hr = hours % 12 == 0 ? 12 : hours % 12;
    std::string am_pm = hours < 12 ? "am" : "pm";
    oss << std::setfill('0') << std::setw(2) << hr << ":"
        << std::setw(2) << minutes << ":" << std::setw(2) << seconds
        << " " << am_pm;
    return oss.str();
}

// Function to compare two WallClockTime objects
comp compare(const WallClockTime& t1, const WallClockTime& t2) {
    int t1_totalSeconds = t1.getHours() * 3600 + t1.getMinutes() * 60 + t1.getSeconds();
    int t2_totalSeconds = t2.getHours() * 3600 + t2.getMinutes() * 60 + t2.getSeconds();
    if (t1_totalSeconds < t2_totalSeconds) return LESS;
    else if (t1_totalSeconds > t2_totalSeconds) return GREATER;
    else return EQUAL;
}
} // namespace OliverCarleton


