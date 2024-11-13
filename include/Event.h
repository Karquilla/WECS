#pragma once

#include "DateTime.h"
#include "Schedule.h"
#include <list>

class Activity;
class Manager;
class Room;

// Class to represent an event with activities, rooms, and managers
class Event {
public:
    // depricated
    // Schedules the event at a specified date and time
    // void scheduleEvent(DateTime);

    // Assigns a room to the event
    void assignRoom(Room&);

    // Assigns a manager as qualified personnel to the event
    void assignQualifiedPersonnel(Manager&);

    // Adds an activity to the event
    void addActivity(Activity&);

private:
    std::list<Room> rooms_; // List of assigned rooms
    std::list<Manager> managers_; // List of managers for the event
    std::list<Activity> activities_; // List of activities in the event
    DateTime eventDateTime_; // Date and time of the event
};
