#pragma once

#include "QualifiedPersonnel.h"
#include "Resource.h"
#include "Schedule.h"
#include "Guest.h"
#include <string>
#include <list>

/**
 * @class Activity
 * @brief Represents an activity with scheduling, personnel, and resource assignment.
 */
class Activity {
public:
    /**
     * @brief Default constructor for Activity.
     */
    Activity();

    /**
     * @brief Schedules the activity with a start and end time.
     *
     * This function sets the schedule for the activity by assigning the start and end time.
     */
    void scheduleActivity();

    /**
     * @brief Assigns qualified personnel to the activity.
     *
     * @param personnel The QualifiedPersonnel to assign to the activity.
     */
    void assignPersonnel(QualifiedPersonnel personnel);

    /**
     * @brief Assigns a resource to the activity.
     *
     * @param resource The Resource to assign to the activity.
     */
    void assignResource(Resource resource);

    /**
     * @brief Gets the start time of the activity.
     *
     * @return The start time of the activity as a string.
     */
    std::string getStartTime() const;

    /**
     * @brief Gets the end time of the activity.
     *
     * @return The end time of the activity as a string.
     */
    std::string getEndTime() const;

    /**
     * @brief Gets the name of the activity.
     *
     * @return The name of the activity as a string.
     */
    std::string getName() const;

    /**
     * @brief Gets the type of the activity.
     *
     * @return The type of the activity as a string.
     */
    std::string getType() const;

    /**
     * @brief Sets the type of the activity.
     *
     * @param type The type of the activity as a string.
     */
    void setActivityType(const std::string& type);

    /**
     * @brief Sets the name of the activity.
     *
     * @param name The name of the activity as a string.
     */
    void setActivityName(const std::string& name);

    /**
     * @brief Sets the start time of the activity.
     *
     * @param startTime The start time of the activity as a string.
     */
    void setActivityStartTime(const std::string& startTime);

    /**
     * @brief Sets the end time of the activity.
     *
     * @param endTime The end time of the activity as a string.
     */
    void setActivityEndTime(const std::string& endTime);

private:
    std::string activityType_; /**< Type of activity */
    std::string startTime_; /**< Start time of the activity */
    std::string endTime_; /**< End time of the activity */
    std::string activityName_; /**< Name of activity */
    std::list<Guest> guest; /**< List of registered guests */
    std::list<QualifiedPersonnel> qualifiedPersonnel; /**< List of assigned personnel */
    std::list<Resource> resources; /**< List of assigned resources */
};