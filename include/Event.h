#pragma once

#include "DateTime.h"
#include <list>

class Activity;
class Manager;
class Room;

class Event {
public:
    void scheduleEvent(DateTime);

    void assignRoom(Room&);

    void assignQualifiedPersonnel(Manager&);
    
    void addActivity(Activity&);
private:
    std::list<Room> rooms_;
    std::list<Manager> managers_;
    std::list<Activity> activities_;
    DateTime eventDateTime_;
};
