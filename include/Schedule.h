#pragma once

#include <vector>
#include <string>
#include <ctime>

class Event;
class Activity;

/**
 * @class Schedule
 * @brief Manages a schedule for maintaining event coordination, including events and activities.
 */
class Schedule {
public:
    /**
     * @brief Schedules a new event at the specified date and time.
     * 
     * @param event Pointer to the Event object to be scheduled.
     * @param eventDateTime Date and time for the event (in std::tm format).
     */
    void scheduleEvent(Event* event, std::tm& eventDateTime);

    /**
     * @brief Schedules a new activity within a specific time range.
     * 
     * @param activity Pointer to the Activity object to be scheduled.
     * @param startTime Start time for the activity (in std::tm format).
     * @param endTime End time for the activity (in std::tm format).
     */
    void scheduleActivity(Activity* activity, std::tm& startTime, std::tm& endTime);

    /**
     * @brief Checks if a specified date and time conflicts with existing scheduled items.
     * 
     * @param dateTime The date and time to check for conflicts (in std::tm format).
     * @return true if there is a conflict with existing schedules, false otherwise.
     */
    bool checkConflict(std::tm& dateTime);

private:
    std::vector<Event*> events; /**< Vector containing all scheduled events */
    std::vector<Activity*> activities; /**< Vector containing all scheduled activities */
};
