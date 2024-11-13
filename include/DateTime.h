#pragma once

#include <string>
#include <ctime>

// Singleton class for handling date and time functionalities
class DateTime {
public:
    // Gets the singleton instance of DateTime
    static DateTime& getInstance();

    // Returns the current time as a formatted string
    std::string getTimeCurr();

    // Returns the current date as a formatted string
    std::string getDateCurr();

private:
    DateTime(const DateTime&) = delete; // Deleted copy constructor
    DateTime& operator=(const DateTime&) = delete; // Deleted assignment operator
    DateTime() = default; // Private constructor
    ~DateTime() = default; // Private destructor
};
