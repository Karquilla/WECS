#pragma once

#include <list>
#include "Activity.h"    // Include Activity because it's used
#include "Resource.h"    // Include Resource because it's used

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
    void reserveRoom(const Activity& activity);  // Use const reference to avoid copying

    /**
     * @brief Checks if the room is available at the specified date and time.
     * 
     * @param dateTime The date and time to check for availability as a string.
     * @return true if the room is available, false otherwise.
     */
    bool checkAvailability(const std::string& dateTime) const; // Use const reference and mark function as const

private:
    int capacity_; /**< Capacity of the room */
    std::list<Resource> availableResources_; /**< Resources available in the room */
    std::list<Activity> activities_; /**< Activities scheduled in the room */
};