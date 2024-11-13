#pragma once

#include "DateTime.h"
#include <list>

class Activity;

// Class representing a room that can be reserved for activities
class Room {
public:
    // Reserves the room for a specified activity
    void reserveRoom(Activity);

    // Checks if the room is available at the specified date and time
    bool checkAvailability(DateTime);

private:
    int capacity_; // Capacity of the room
    std::list<Resource> availableResources_; // Resources available in the room
    std::list<Activity> activities_; // Activities scheduled in the room
};