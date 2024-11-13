#pragma once

#include "DateTime.h"
#include <list>

class Activity;

/**
 * @class Room
 * @brief Represents a room that can be reserved for activities and checks availability.
 */
class Room {
public:
    /**
     * @brief Reserves the room for a specified activity.
     * 
     * @param activity The activity to reserve the room for.
     */
    void reserveRoom(Activity activity);

    /**
     * @brief Checks if the room is available at the specified date and time.
     * 
     * @param dateTime The date and time to check for availability.
     * @return true if the room is available, false otherwise.
     */
    bool checkAvailability(DateTime dateTime);

private:
    int capacity_; /**< Capacity of the room */
    std::list<Resource> availableResources_; /**< Resources available in the room */
    std::list<Activity> activities_; /**< Activities scheduled in the room */
};