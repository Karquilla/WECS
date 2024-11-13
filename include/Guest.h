#pragma once

#include "Activity.h"
#include "Event.h"
#include <string>
#include <list>

/**
 * @class Guest
 * @brief Represents a guest participating in an event and its activities.
 */
class Guest {
public:
    /**
     * @brief Registers the guest for a specific activity.
     * 
     * @param activity The activity to register for.
     */
    void registerForActivity(Activity activity);

    /**
     * @brief Checks if there are scheduling conflicts with the specified activity.
     * 
     * @param activity The activity to check against.
     * @return true if there is a conflict, false otherwise.
     */
    bool checkConflicts(Activity activity);

private:
    std::string uniqueID_; /**< Unique ID for the guest */
    std::list<Activity> registeredActivities_; /**< Activities the guest has registered for */
    Event associatedEvent_; /**< Event the guest is associated with */
};