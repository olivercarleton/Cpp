#ifndef WALL_CLOCK_TIME_H
#define WALL_CLOCK_TIME_H

#include <string>
#include <iostream>

namespace OliverCarleton {

    //enumeration for comparison result
    enum comp { GREATER = 1, LESS = -1, EQUAL = 0 };

    //class representing a wall clock time
    class WallClockTime {
    private:
        int hours;
        int minutes;
        int seconds;
        bool isDisplayFormat24;

        //private member function to normalize time
        void normalizeTime();

    public:
        //constructors
        WallClockTime(int hr, int min, int sec);
        WallClockTime(int min, int sec);
        WallClockTime(int sec);
        WallClockTime();

        //getter functions
        int getHours() const;
        int getMinutes() const;
        int getSeconds() const;

        //setter functions
        void setHours(int hr);
        void setMinutes(int min);
        void setSeconds(int sec);

        //function to display time in 24-hour format
        std::string displayFormat24() const;

        //function to display time in 12-hour format
        std::string displayFormat12() const;

        //friend function for comparing two WallClockTime objects
        friend comp compare(const WallClockTime& t1, const WallClockTime& t2);

        //overloaded operators
        WallClockTime operator+(const WallClockTime& other) const;
        WallClockTime& operator+=(const WallClockTime& other);
        WallClockTime operator-(const WallClockTime& other) const;
        WallClockTime& operator-=(const WallClockTime& other);
        WallClockTime operator*(int multiplier) const;
        friend WallClockTime operator*(int multiplier, const WallClockTime& time);
        WallClockTime operator/(int divisor) const;
        WallClockTime& operator*=(int multiplier);
        WallClockTime& operator/=(int divisor);
        bool operator<(const WallClockTime& other) const;
        bool operator<=(const WallClockTime& other) const;
        bool operator>(const WallClockTime& other) const;
        bool operator>=(const WallClockTime& other) const;
        bool operator==(const WallClockTime& other) const;
        friend std::ostream& operator<<(std::ostream& os, const WallClockTime& time);
        friend std::istream& operator>>(std::istream& is, WallClockTime& time);

        //member functions for setting display format
        void setDisplayTime12();
        void setDisplayTime24();
    };

} // namespace OliverCarleton

#endif








