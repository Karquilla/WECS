#pragma once

#include "Room.h"
#include "Manager.h"
#include "Activity.h"
#include <list>
#include <string>

/**
 * @class Event
 * @brief Represents an event with activities, rooms, and managers.
 */
class Event {
public:
    /**
     * @brief Default constructor for Event.
     */
    Event();

    /**
     * @brief Constructor with name initialization.
     * 
     * @param name The name of the event.
     */
    Event(const std::string& name);

    /**
     * @brief Schedules the event at a specified date and time.
     * 
     * @param dateTime The date and time for the event.
     */
    void scheduleEvent(std::string& dateTime);

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
     * @brief Sets a name to the event.
     * 
     * @param name The name for the event.
     */
    void setName(std::string& name);

    /**
     * @brief Sets the ID for the event.
     */
    void setId();

    /**
     * @brief Gets the file name of the event.
     * 
     * @return The file name as a string.
     */
    std::string getfName() const { return fname_; }

    /**
     * @brief Gets the name of the event.
     * 
     * @return The name of the event.
     */
    std::string getName() const { return name_; }

    void loadFromFile(const std::string& filePath);


private:
    std::list<Room> rooms_; /**< List of assigned rooms */
    std::list<Manager> managers_; /**< List of managers for the event */
    std::list<Activity> activities_; /**< List of activities in the event */
    std::string eventDate_; /**< Date and time of the event */
    std::string name_; /**< The name of the event */
    std::string fname_; /**< File name associated with the event */
    std::string id_; /**< Identifier for the event */
};
