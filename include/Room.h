#pragma once

#include "DateTime.h"
#include <list>

class Activity;
class Resource;

class Room {
public:
    void reserveRoom(Activity);

    bool checkAvailability(DateTime);

private:
    int capacity_; 
    std::list<Resource> availableResources_; 
    std::list<Activity> activities_; 
};