#pragma once

#include "QualifiedPersonnel.h"
#include "Resource.h"
#include "Schedule.h"
#include "Guest.h"
#include <string>

/**
 * @class Activity
 * @brief Represents an activity with scheduling, personnel, and resource assignment.
 */
class Activity {
public:
    Activity();
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

    std::string getStartTime() const;

    std::string getEndTime() const;

    std::string getName() const;

    std::string getType() const;

    void setActivityType(const std::string& type);

    void setActivityName(const std::string& name);
    void setActivityStartTime(const std::string& startTime);
    void setActivityEndTime(const std::string& endTime);

private:
    std::string activityType_; /**< Type of activity */
    std::string startTime_; /**< Start time of the activity */
    std::string endTime_; /**< End time of the activity */
    std::string activityName_; /**<Name of activity> */
    std::list<Guest> guest; /**<List of registered guests */
    std::list<QualifiedPersonnel> qualifiedPersonnel; /**< List of assigned personnel */
    std::list<Resource> resources; /**< List of assigned resources */
};