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

    Room() = default;
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
    std::string getType() { return roomType_; };
    int getCost() { return cost_; };
    int getLength() { return resLength_; };

    void setType(std::string type);
    void setCost();
    void setLength(int);


private:
    //int capacity_; /**< Capacity of the room */
    std::string roomType_;
    int cost_;
    int resLength_;
    std::list<Resource> availableResources_; /**< Resources available in the room */
    std::list<Activity> activities_; /**< Activities scheduled in the room */
};