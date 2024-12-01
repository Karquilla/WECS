#include "Room.h"
#include "Activity.h" // Required for the full definition of Activity

/**
 * @brief Reserves the room for the given activity.
 * 
 * This method is used to reserve the room for a specific activity.
 * It modifies the room's state to reflect the reservation details.
 * 
 * @param activity The activity for which the room needs to be reserved.
 */
void Room::reserveRoom(const Activity& activity) {
    // Implement the logic for reserving the room with this activity
}

/**
 * @brief Checks if the room is available at the specified date and time.
 * 
 * This method determines whether the room is free at the provided date and time.
 * It can be used to prevent double-booking of the room.
 * 
 * @param dateTime The date and time to check in string format.
 * @return true if the room is available, false otherwise.
 */
bool Room::checkAvailability(const std::string& dateTime) const {
    // Implement your logic here
    return true; // Placeholder return value
}

/**
 * @brief Sets the type of the room.
 * 
 * This method assigns a type to the room, such as "rome", "paris", or "lasvegas".
 * The room type influences other properties like cost.
 * 
 * @param type The type of the room as a string.
 */
void Room::setType(std::string type) {
    roomType_ = type;
}

/**
 * @brief Sets the reservation length for the room.
 * 
 * This method updates the duration (in some unit of time, e.g., days) 
 * for which the room is reserved.
 * 
 * @param count The length of the reservation.
 */
void Room::setLength(int count) {
    resLength_ = count;
}

/**
 * @brief Calculates and sets the cost of the room reservation.
 * 
 * This method computes the cost of the reservation based on the room type 
 * and reservation length. Room types have predefined rates:
 * - "rome": $300 per unit length.
 * - "paris": $400 per unit length.
 * - "lasvegas": $500 per unit length.
 * 
 * The calculated cost is stored in the `cost_` member variable.
 */
void Room::setCost() {
    int result;
    if (roomType_ == "rome") {
        result = 300 * resLength_;
    } else if (roomType_ == "paris") {
        result = 400 * resLength_;
    } else if (roomType_ == "lasvegas") {
        result = 500 * resLength_;
    }

    cost_ = result;
}