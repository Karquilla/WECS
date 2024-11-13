#include "Schedule.h"
#include "../include/Event.h"
#include "../include/Activity.h"
class Event;
class Schedule;
class Activity;

void Schedule::scheduleEvent(Event* event, std::tm& eventDateTime) {
    // Need to add logic to schedule an event
}

void Schedule::scheduleActivity(Activity* activity, std::tm& startTime, std::tm& endTime) {
    // Need to add logic to schedule an activity
}

bool Schedule::checkConflict(std::tm& dateTime) {
    // Need to add logic to check if the given time has a conflict in the schedule

    return false;  // No conflict
}