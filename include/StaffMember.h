#pragma once

#include <map>
#include <string>

// Forward declaration for Activity and Event if they are not directly needed in the class members
class Activity;
class Event;

/**
 * @class StaffMember
 * @brief Represents a staff member with scheduling and authorization level.
 */
class StaffMember {
public:
    /**
     * @brief Checks if there are any scheduling conflicts.
     * 
     * @return true if there is a conflict, false otherwise.
     */
    bool isConflict();

private:
    std::map<int, std::pair<std::string, int>> activity_schedule; /**< Schedule of activities, date and time as string */
    std::map<int, std::pair<std::string, int>> event_schedule; /**< Schedule of events, date and time as string */
};