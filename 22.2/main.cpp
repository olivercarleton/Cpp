#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

class TimeFormatMistake : public std::exception {
public:
    const char* what() const noexcept override {
        return "Wrong time format";
    }
};

class TimeConverter {
public:
    static std::string to24Hour(const std::string& time) {
        std::istringstream iss(time);
        int hour, minute, second;
        char colon1, colon2, period;
        std::string ampm;

        if (!(iss >> hour >> colon1 >> minute >> colon2 >> second >> std::ws && std::getline(iss, ampm)) ||
            (colon1 != ':' || colon2 != ':')) {
            throw TimeFormatMistake();
        }

        if (hour < 1 || hour > 12 || minute < 0 || minute >= 60 || second < 0 || second >= 60 ||
            (ampm != "am" && ampm != "pm")) {
            throw TimeFormatMistake();
        }

        if (hour == 12) {
            hour = (ampm == "am") ? 0 : 12;
        } else if (ampm == "pm") {
            hour += 12;
        }

        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << minute << ":" << std::setw(2) << second;
        return oss.str();
    }

    static std::string to12Hour(const std::string& time) {
        std::istringstream iss(time);
        int hour, minute, second;
        char colon1, colon2;

        if (!(iss >> hour >> colon1 >> minute >> colon2 >> second) ||
            (colon1 != ':' || colon2 != ':')) {
            throw TimeFormatMistake();
        }

        if (hour < 0 || hour > 23 || minute < 0 || minute >= 60 || second < 0 || second >= 60) {
            throw TimeFormatMistake();
        }

        std::ostringstream oss;
        std::string ampm = (hour >= 12) ? "pm" : "am";
        if (hour == 0) hour = 12;
        else if (hour > 12) hour -= 12;

        oss << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << minute << ":" << std::setw(2) << second << ampm;
        return oss.str();
    }
};

int main() {
    std::string input;
    char choice;

    do {
        std::cout << "Enter time: ";
        std::cin >> input;
        try {
            if (input.find("pm") != std::string::npos || input.find("am") != std::string::npos) {
                std::cout << "The time is: " << TimeConverter::to24Hour(input) << std::endl;
            } else {
                std::cout << "The time is: "<< TimeConverter::to12Hour(input) << std::endl;
            }
        } catch (const TimeFormatMistake& e) {
            std::cerr << "Wrong time format: " << input << std::endl;
            std::cout << "Try Again:" << std::endl;
            continue;
        }
        std::cout << "Convert Again? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
        if (choice == 'y' || choice == 'Y') std::cout << std::endl;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "End of program." << std::endl;

    return 0;
}
