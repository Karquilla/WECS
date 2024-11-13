#include "DateTime.h"
#include <iostream>

#include "DateTime.h"
#include <iostream>

/**
 * @brief Returns the singleton instance of DateTime.
 * 
 * @return The singleton instance.
 */
DateTime& DateTime::getInstance() {
    static DateTime instance;
    return instance;
}

/**
 * @brief Returns the current time as a formatted string.
 * 
 * @return Current time as a string.
 */
std::string DateTime::getTimeCurr() {
    // Logic to get the current time
    return "current time"; // Placeholder return
}

/**
 * @brief Returns the current date as a formatted string.
 * 
 * @return Current date as a string.
 */
std::string DateTime::getDateCurr() {
    // Logic to get the current date
    return "current date"; // Placeholder return
}