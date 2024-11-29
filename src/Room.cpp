#include "Room.h"
#include "Activity.h" // Required for the full definition of Activity


/**
 * @brief Reserves the room for the given activity.
 * 
 * @param activity The activity to reserve the room for.
 */
void Room::reserveRoom(const Activity& activity) {
    // Implement the logic for reserving the room with this activity
}

/**
 * @brief Checks if the room is available at the specified date and time.
 * 
 * @param dateTime The date and time to check for availability.
 * @return true if the room is available, false otherwise.
 */
bool Room::checkAvailability(const std::string& dateTime) const{
    // Implement your logic here
    return true; // Placeholder return value
}

void Room::setType(std::string type) {
    roomType_ = type;
}

void Room::setLength(int count) {
    resLength_ = count;
}

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