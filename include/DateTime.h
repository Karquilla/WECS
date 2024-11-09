#pragma once

#include <string>
#include <ctime>

// Meyer singlton for DateTime class
// Used to get formatted string of current date or time
class DateTime {
public:
    // Singleton instance
    static DateTime& getInstance();

    // Method to get the current date and time as a string (example functionality)
    std::string getTimeCurr();
    std::string getDateCurr();

private:
    // Delete the copy constructor and copy assignment operator
    DateTime(const DateTime&) = delete;
    DateTime& operator=(const DateTime&) = delete;

    // Private constructor to prevent direct instantiation
    DateTime() = default;

    // Private destructor
    ~DateTime() = default;
};