#pragma once

#include "Activity.h"
#include "Event.h"
#include <string>
#include <list>

// Class to represent a guest participating in an event and its activities
class Guest {
public:
    // Registers the guest for an activity
    void registerForActivity(Activity);

    // Checks if there are conflicts with the activity
    bool checkConflicts(Activity);

private:
    std::string uniqueID_; // Unique ID for the guest
    std::list<Activity> registeredActivities_; // Activities the guest has registered for
    Event associatedEvent_; // Event the guest is associated with
};