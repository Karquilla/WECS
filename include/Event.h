#pragma once

#include "DateTime.h"
#include "Schedule.h"
#include <list>
#include <string>

class Activity;
class Manager;
class Room;

/**
 * @class Event
 * @brief Represents an event with activities, rooms, and managers.
 */
class Event {
public:

    Event();

    Event(std::string name);
    /**
     * @brief Schedules the event at a specified date and time.
     * 
     * @param dateTime The date and time for the event.
     */
    void scheduleEvent(DateTime dateTime);

    /**
     * @brief Assigns a room to the event.
     * 
     * @param room Reference to the room to assign.
     */
    void assignRoom(Room& room);

    /**
     * @brief Assigns a manager as qualified personnel to the event.
     * 
     * @param manager Reference to the manager to assign.
     */
    void assignQualifiedPersonnel(Manager& manager);

    /**
     * @brief Adds an activity to the event's list of activities.
     * 
     * @param activity Reference to the activity to add.
     */
    void addActivity(Activity& activity);

    /**
     * @brief sets an name to the event.
     * 
     * @param name the name for the event
     */
    void setName(std::string name);

    std::string getfName() { return fname_; };

    std::string getName() { return name_; };

    void loadFromFile(const std::string& filePath);

private:
    std::list<Room> rooms_; /**< List of assigned rooms */
    std::list<Manager> managers_; /**< List of managers for the event */
    std::list<Activity> activities_; /**< List of activities in the event */
    std::string eventDate_; /**< Date and time of the event */
    std::string name_;
    std::string fname_;
};
