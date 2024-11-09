#pragma once

#include "Activity.h"
#include "DateTime.h"
#include "Event.h"
#include <map>
#include <string>



class StaffMember {
public:
    bool isConflict();

private:
    std::string authorizationLevel_;
    // map of activity as key and pair of date time , length to check for conflicts
    // ended up making two seperate schedule maps here instead of trying to
    // template the class when used we can just use if not empty to short check
    std::map<Activity, std::pair<DateTime, int>> activity_schedule;
    std::map<Event, std::pair<DateTime, int>> event_schedule;
};