#pragma once

#include "Activity.h"
#include "Event.h"
#include <string>
#include <list>

class Guest {
public:
    void registerForActivity(Activity);

    bool checkConflicts(Activity);
    
private:
    std::string uniqueID_; 
    // this could be a map<Event,list<Activity>
    std::list<Activity> registeredActivities_; 
    Event associatedEvent_; 
};