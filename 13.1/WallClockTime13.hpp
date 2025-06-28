#ifndef WALL_CLOCK_TIME_H
#define WALL_CLOCK_TIME_H

#include <string>

// Enumeration for comparison result
enum comp { GREATER = 1, LESS = -1, EQUAL = 0 };

// Class representing a wall clock time
class WallClockTime {
private:
    int hours;
    int minutes;
    int seconds;

    // Private member function to normalize time
    void normalizeTime();

public:
    // Constructors
    WallClockTime(int hr, int min, int sec);
    WallClockTime(int min, int sec);
    WallClockTime(int sec);
    WallClockTime();

    // Getter functions
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    // Setter functions
    void setHours(int hr);
    void setMinutes(int min);
    void setSeconds(int sec);

    // Function to display time in 24-hour format
    std::string displayFormat24() const;

    // Function to display time in 12-hour format
    std::string displayFormat12() const;

    // Friend function for comparing two WallClockTime objects
    friend comp compare(const WallClockTime& t1, const WallClockTime& t2);
};

#endif

