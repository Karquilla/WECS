#pragma once

#include "Activity.h"
#include "DateTime.h"
#include "Event.h"
#include <map>
#include <string>



// Class representing a staff member with scheduling and authorization level
class StaffMember {
public:
    // Checks if there are any scheduling conflicts
    bool isConflict();

private:
    std::string authorizationLevel_; // Authorization level of the staff member
    std::map<Activity, std::pair<DateTime, int>> activity_schedule; // Schedule of activities
    std::map<Event, std::pair<DateTime, int>> event_schedule; // Schedule of events
};
