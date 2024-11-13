#pragma once

#include "Activity.h"
#include "Room.h"
#include <list>

// Class to represent a resource that can be allocated to activities
class Resource {
public:
    // Allocates the resource to an activity
    void allocateToActivity(Activity);

    // Tracks the usage of the resource for an activity
    void trackUsage(Activity);

private:
    bool availabilityStatus; // Availability status of the resource
    std::list<Room> associatedRooms; // Rooms associated with the resource
    std::list<Activity> associatedActivities; // Activities associated with the resource
};