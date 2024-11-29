#include "Schedule.h"

#include <iomanip>
#include <iostream>

#include "../include/Event.h"
#include "../include/Activity.h"
class Event;
class Schedule;
class Activity;

#include "Schedule.h"
#include "../include/Event.h"
#include "../include/Activity.h"

std::tm parseTimeString(const std::string& timeString) {
    std::tm timeStruct = {};
    std::istringstream ss(timeString);
    ss >> std::get_time(&timeStruct, "%H%M");
    return timeStruct;
}

/**
 * @brief Schedules an event at the specified date and time.
 * 
 * @param event Pointer to the Event object to be scheduled.
 * @param eventDateTime Date and time for the event (in std::tm format).
 */
void Schedule::scheduleEvent(Event* event, std::tm& eventDateTime) {
    // Logic to schedule an event
}

/**
 * @brief Schedules an activity with specified start and end times.
 * 
 * @param activity Pointer to the Activity object to be scheduled.
 * @param startTime Start time for the activity (in std::tm format).
 * @param endTime End time for the activity (in std::tm format).
 */
void Schedule::scheduleActivity(Activity* activity, std::tm& startTime, std::tm& endTime) {
    // Check for time conflict
    if (checkConflict(startTime, endTime)) {
        std::cerr << "Conflict detected, unable to schedule activity." << std::endl;
        return;
    }

    // Add activity to the list if no conflict
    activities.push_back(*activity);
    std::cout << "Activity scheduled successfully." << std::endl;
}

/**
 * @brief Checks if the specified date and time conflicts with existing scheduled items.
 * 
 * @param dateTime The date and time to check for conflicts (in std::tm format).
 * @return true if there is a conflict with existing schedules, false otherwise.
 */
bool Schedule::checkConflict(std::tm& startTime, std::tm& endTime) {
    auto toTimeT = [](std::tm& timeStructure) {
        return std::mktime(&timeStructure);
    };

    // Convert new activity times to time_t
    time_t newStart = toTimeT(startTime);
    time_t newEnd = toTimeT(endTime);

    // Check conflicts with scheduled activities
    for (const auto& activity : activities) {
        std::tm activityStart = parseTimeString(activity.getStartTime());
        std::tm activityEnd = parseTimeString(activity.getEndTime());

        time_t activityStartT = toTimeT(activityStart);
        time_t activityEndT = toTimeT(activityEnd);

        if (newStart < activityEndT && newEnd > activityStartT) {
            return true;  // Conflict detected
        }
    }

    return false;  // No conflict
}