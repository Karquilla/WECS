#pragma once

#include <string>
#include <ctime>

/**
 * @class DateTime
 * @brief Singleton class for handling date and time functionalities.
 */
class DateTime {
public:
    /**
     * @brief Gets the singleton instance of DateTime.
     * 
     * @return The singleton instance.
     */
    static DateTime& getInstance();

    /**
     * @brief Returns the current time as a formatted string.
     * 
     * @return Current time as a string.
     */
    std::string getTimeCurr();

    /**
     * @brief Returns the current date as a formatted string.
     * 
     * @return Current date as a string.
     */
    std::string getDateCurr();

private:
    DateTime(const DateTime&) = delete; /**< Deleted copy constructor */
    DateTime& operator=(const DateTime&) = delete; /**< Deleted assignment operator */
    DateTime() = default; /**< Private constructor */
    ~DateTime() = default; /**< Private destructor */
};
