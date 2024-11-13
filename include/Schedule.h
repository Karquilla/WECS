#pragma once

#include <vector>
#include <string>
#include <ctime>

class Event;
class Activity;

class Schedule {
public:
    // Schedule a new event at the given date and time
    void scheduleEvent(Event* event, std::tm& eventDateTime);

    // Schedule a new activity within a specific event
    void scheduleActivity(Activity* activity, std::tm& startTime, std::tm& endTime);

    // Check if an event or activity conflicts with the existing schedule
    bool checkConflict(std::tm& dateTime);
private:
    std::vector<Event*> events;      // All scheduled events
    std::vector<Activity*> activities;  // All scheduled activities
};
