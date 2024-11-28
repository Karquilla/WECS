#include <fstream>
#include <iostream>
#include "Event.h"
#include "Room.h"
#include "Manager.h"
#include "Activity.h"
#include "json.hpp"


Event::Event(){

}

/**
 * @brief Schedules the event at a specified date and time.
 * 
 * @param dateTime The date and time for the event.
 */
void Event::scheduleEvent(std::string& dateTime) {

}

/**
 * @brief Assigns a room to the event.
 * 
 * @param room Reference to the room to assign.
 */
void Event::assignRoom(Room& room) {
    // Logic to assign the room
}

/**
 * @brief Assigns a manager as qualified personnel to the event.
 * 
 * @param manager Reference to the manager to assign.
 */
void Event::assignQualifiedPersonnel(Manager& manager) {
    // Logic to assign the manager
}

/**
 * @brief Adds an activity to the event's list of activities.
 * 
 * @param activity Reference to the activity to add.
 */
void Event::addActivity(Activity& activity) {
    // Logic to add the activity to the event
}

void Event::setName(std::string& name) {
    name_ = name;
}


void Event::loadFromFile(const std::string& filePath) {
        //std::ifstream file(filePath);
        //if (!file.is_open()) {
        //    std::cerr << "Unable to open file: " << filePath << std::endl;
        //    return;
        //}
        //
        //std::string line;
        //while (std::getline(file, line)) {
        //    if (line.rfind("Name: ", 0) == 0) {
        //        name_ = line.substr(6); // Extract the value after "name: "
        //    } else if (line.rfind("Date: ", 0) == 0) {
        //        eventDate_ = line.substr(6); // Extract the value after "date: "
        //    } //else if (line.rfind("Description: ", 0) == 0) {
        //    //    start_ = line.substr(13); // Extract the value after "start: "
        //    //}
        //}
        //file.close();
    }