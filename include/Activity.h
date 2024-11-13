#pragma once

#include "QualifiedPersonnel.h"
#include "Resource.h"
#include "Schedule.h"
#include <chrono>

// Class to represent an activity with scheduling, personnel, and resource assignment
class Activity {
public:
    // Schedules the activity with a start and end time
    void scheduleActivity(std::chrono::system_clock::time_point, std::chrono::system_clock::time_point);

    // Assigns qualified personnel to the activity
    void assignPersonnel(QualifiedPersonnel);

    // Assigns a resource to the activity
    void assignResource(Resource);

private:
    std::string activityType_; // Type of activity
    std::chrono::system_clock::time_point startTime_; // Start time of the activity
    std::chrono::system_clock::time_point endTime_; // End time of the activity
    std::list<QualifiedPersonnel> qualifiedPersonnel; // List of assigned personnel
    std::list<Resource> resources; // List of assigned resources
};