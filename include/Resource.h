#pragma once

#include <list>

class Room;
class Activity;

/**
 * @class Resource
 * @brief Represents a resource that can be allocated to activities.
 */
class Resource {
public:
    /**
     * @brief Allocates the resource to an activity.
     * 
     * @param activity The activity to allocate the resource to.
     */
    void allocateToActivity(Activity activity);

    /**
     * @brief Tracks the usage of the resource for a specified activity.
     * 
     * @param activity The activity to track usage for.
     */
    void trackUsage(Activity activity);

private:
    bool availabilityStatus; /**< Availability status of the resource */
    std::list<Room> associatedRooms; /**< Rooms associated with the resource */
    std::list<Activity> associatedActivities; /**< Activities associated with the resource */
};