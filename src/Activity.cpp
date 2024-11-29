#include "Activity.h"

/**
 * @brief Assigns qualified personnel to the activity.
 * 
 * @param personnel The QualifiedPersonnel to assign.
 */
void Activity::assignPersonnel(QualifiedPersonnel personnel) {
    // Logic to assign personnel
}

/**
 * @brief Assigns a resource to the activity.
 * 
 * @param resource The Resource to assign.
 */
void Activity::assignResource(Resource resource) {
    // Logic to assign the resource
}

std::string Activity::getStartTime() const {
    return startTime_;
}

std::string Activity::getEndTime() const {
    return endTime_;
}

void Activity::setActivityType(const std::string& type) {
    activityType_ = type;
}