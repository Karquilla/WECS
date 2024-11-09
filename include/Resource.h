#pragma once

#include "Activity.h"
#include "Room.h"
#include <list>

class Resource {
public:
    void allocateToActivity(Activity);

    void trackUsage(Activity);

private:
    bool availabilityStatus; 
    std::list<Room> associatedRooms; 
    std::list<Activity> associatedActivities; 
    //list<UsageRecord> usageHistory; 
};