#include "WallClockTime.hpp"
#include <sstream>
#include <iomanip>

namespace OliverCarleton {

    //private helper function to normalize the time
    void WallClockTime::normalizeTime() {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds;

        //adjust for negative seconds
        if (totalSeconds < 0) {
            totalSeconds = (86400 + totalSeconds % 86400) % 86400;
        }

        //normalize hours, minutes, and seconds
        hours = (totalSeconds / 3600) % 24;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;
    }

    //constructors
    WallClockTime::WallClockTime(int hr, int min, int sec) : hours(hr), minutes(min), seconds(sec), isDisplayFormat24(true) {
        normalizeTime();
    }

    WallClockTime::WallClockTime(int min, int sec) : WallClockTime(0, min, sec) {}

    WallClockTime::WallClockTime(int sec) : WallClockTime(0, 0, sec) {}

    WallClockTime::WallClockTime() : WallClockTime(0, 0, 0) {}

    //getters
    int WallClockTime::getHours() const { return hours; }
    int WallClockTime::getMinutes() const { return minutes; }
    int WallClockTime::getSeconds() const { return seconds; }

    //setters
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

    //function to display time in 24-hour format
    std::string WallClockTime::displayFormat24() const {
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << hours << ":"
            << std::setw(2) << minutes << ":" << std::setw(2) << seconds;
        return oss.str();
    }

    //function to display time in 12-hour format with AM/PM
    std::string WallClockTime::displayFormat12() const {
        std::ostringstream oss;
        int hr = hours % 12 == 0 ? 12 : hours % 12;
        std::string am_pm = hours < 12 ? "am" : "pm";
        oss << std::setfill('0') << std::setw(2) << hr << ":"
            << std::setw(2) << minutes << ":" << std::setw(2) << seconds
            << " " << am_pm;
        return oss.str();
    }

    //friend function to compare two WallClockTime objects
    comp compare(const WallClockTime& t1, const WallClockTime& t2) {
        int t1_totalSeconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
        int t2_totalSeconds = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
        if (t1_totalSeconds < t2_totalSeconds) return LESS;
        else if (t1_totalSeconds > t2_totalSeconds) return GREATER;
        else return EQUAL;
    }

    // Overloaded operators
    WallClockTime WallClockTime::operator+(const WallClockTime& other) const {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds +
            other.hours * 3600 + other.minutes * 60 + other.seconds;
        return WallClockTime(totalSeconds);
    }

    WallClockTime& WallClockTime::operator+=(const WallClockTime& other) {
        *this = *this + other;
        return *this;
    }

    WallClockTime WallClockTime::operator-(const WallClockTime& other) const {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds -
            other.hours * 3600 - other.minutes * 60 - other.seconds;
        return WallClockTime(totalSeconds);
    }

    WallClockTime& WallClockTime::operator-=(const WallClockTime& other) {
        *this = *this - other;
        return *this;
    }

    WallClockTime WallClockTime::operator*(int multiplier) const {
        int totalSeconds = (hours * 3600 + minutes * 60 + seconds) * multiplier;
        return WallClockTime(totalSeconds);
    }

    WallClockTime operator*(int multiplier, const WallClockTime& time) {
        return time * multiplier;
    }

    WallClockTime WallClockTime::operator/(int divisor) const {
        int totalSeconds = (hours * 3600 + minutes * 60 + seconds) / divisor;
        return WallClockTime(totalSeconds);
    }

    WallClockTime& WallClockTime::operator*=(int multiplier) {
        *this = *this * multiplier;
        return *this;
    }

    WallClockTime& WallClockTime::operator/=(int divisor) {
        *this = *this / divisor;
        return *this;
    }

    bool WallClockTime::operator<(const WallClockTime& other) const {
        return compare(*this, other) == LESS;
    }

    bool WallClockTime::operator<=(const WallClockTime& other) const {
        comp result = compare(*this, other);
        return result == LESS || result == EQUAL;
    }

    bool WallClockTime::operator>(const WallClockTime& other) const {
        return compare(*this, other) == GREATER;
    }

    bool WallClockTime::operator>=(const WallClockTime& other) const {
        comp result = compare(*this, other);
        return result == GREATER || result == EQUAL;
    }

    bool WallClockTime::operator==(const WallClockTime& other) const {
        return compare(*this, other) == EQUAL;
    }

    //overloaded stream insertion operator
    std::ostream& operator<<(std::ostream& os, const WallClockTime& time) {
        if (time.isDisplayFormat24) {
            os << time.displayFormat24();
        } else {
            os << time.displayFormat12();
        }
        return os;
    }

    //overloaded stream extraction operator
    std::istream& operator>>(std::istream& is, WallClockTime& time) {
        int hr, min, sec;
        is >> hr >> min >> sec;
        time.setHours(hr);
        time.setMinutes(min);
        time.setSeconds(sec);
        return is;
    }

    //member functions for setting display format
    void WallClockTime::setDisplayTime12() {
        isDisplayFormat24 = false;
    }

    void WallClockTime::setDisplayTime24() {
        isDisplayFormat24 = true;
    }

} // namespace OliverCarleton




