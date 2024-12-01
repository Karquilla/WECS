#include "Activity.h"

/**
 * @brief Default constructor for Activity.
 */
Activity::Activity() {
    // Initialization logic if needed
}

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

/**
 * @brief Gets the start time of the activity.
 *
 * @return The start time of the activity as a string.
 */
std::string Activity::getStartTime() const {
    return startTime_;
}

/**
 * @brief Gets the end time of the activity.
 *
 * @return The end time of the activity as a string.
 */
std::string Activity::getEndTime() const {
    return endTime_;
}

/**
 * @brief Gets the name of the activity.
 *
 * @return The name of the activity as a string.
 */
std::string Activity::getName() const {
    return activityName_;
}

/**
 * @brief Gets the type of the activity.
 *
 * @return The type of the activity as a string.
 */
std::string Activity::getType() const {
    return activityType_;
}

/**
 * @brief Sets the type of the activity.
 *
 * @param type The type of the activity as a string.
 */
void Activity::setActivityType(const std::string& type) {
    activityType_ = type;
}

/**
 * @brief Sets the name of the activity.
 *
 * @param name The name of the activity as a string.
 */
void Activity::setActivityName(const std::string& name) {
    activityName_ = name;
}

/**
 * @brief Sets the start time of the activity.
 *
 * @param startTime The start time of the activity as a string.
 */
void Activity::setActivityStartTime(const std::string& startTime) {
    startTime_ = startTime;
}

/**
 * @brief Sets the end time of the activity.
 *
 * @param endTime The end time of the activity as a string.
 */
void Activity::setActivityEndTime(const std::string& endTime) {
    endTime_ = endTime;
}