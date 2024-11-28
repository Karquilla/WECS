#pragma once

#include "QualifiedPersonnel.h"
#include "Resource.h"
#include "Schedule.h"
#include <string>

/**
 * @class Activity
 * @brief Represents an activity with scheduling, personnel, and resource assignment.
 */
class Activity {
public:
    /**
     * @brief Schedules the activity with a start and end time.
     * 
     * @param startTime The start time of the activity.
     * @param endTime The end time of the activity.
     */
    void scheduleActivity();

    /**
     * @brief Assigns qualified personnel to the activity.
     * 
     * @param personnel The QualifiedPersonnel to assign.
     */
    void assignPersonnel(QualifiedPersonnel personnel);

    /**
     * @brief Assigns a resource to the activity.
     * 
     * @param resource The Resource to assign.
     */
    void assignResource(Resource resource);

private:
    std::string activityType_; /**< Type of activity */
    std::string startTime_; /**< Start time of the activity */
    std::string endTime_; /**< End time of the activity */
    std::list<QualifiedPersonnel> qualifiedPersonnel; /**< List of assigned personnel */
    std::list<Resource> resources; /**< List of assigned resources */
};