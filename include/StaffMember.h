#pragma once

#include "Activity.h"
#include "DateTime.h"
#include "Event.h"
#include <map>
#include <string>



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
    std::string authorizationLevel_; /**< Authorization level of the staff member */
    std::map<Activity, std::pair<DateTime, int>> activity_schedule; /**< Schedule of activities */
    std::map<Event, std::pair<DateTime, int>> event_schedule; /**< Schedule of events */
};
