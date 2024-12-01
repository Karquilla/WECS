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
     * @brief Default constructor for Room.
     */
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

    /**
     * @brief Gets the type of the room.
     *
     * @return The type of the room as a string.
     */
    std::string getType() { return roomType_; };

    /**
     * @brief Gets the cost of reserving the room.
     *
     * @return The cost of the room as an integer.
     */
    int getCost() { return cost_; };

    /**
     * @brief Gets the length of the reservation.
     *
     * @return The length of the reservation as an integer.
     */
    int getLength() { return resLength_; };

    /**
     * @brief Sets the type of the room.
     *
     * @param type The type of the room as a string.
     */
    void setType(std::string type);

    /**
     * @brief Sets the cost of reserving the room.
     */
    void setCost();

    /**
     * @brief Sets the length of the reservation.
     *
     * @param length The length of the reservation as an integer.
     */
    void setLength(int length);

private:
    std::string roomType_; /**< Type of the room */
    int cost_; /**< Cost of reserving the room */
    int resLength_; /**< Length of the reservation */
    std::list<Resource> availableResources_; /**< Resources available in the room */
    std::list<Activity> activities_; /**< Activities scheduled in the room */
};
