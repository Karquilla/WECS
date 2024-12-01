#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include "Activity.h"
#include "Event.h"
#include <string>
#include <list>
#include "json.hpp"

/**
 * @class Guest
 * @brief Represents a guest participating in an event and its activities.
 */
class Guest {
public:
    Guest();
    Guest(int id, const std::string name);
    /**
     * @brief Registers the guest for a specific activity.
     * 
     * @param activity The activity to register for.
     */
    void registerForActivity(Activity activity);

    bool loadGuest(int guestId);

    void addGuest(int id, std::string& name);
    /**
     * @brief Checks if there are scheduling conflicts with the specified activity.
     * 
     * @param activity The activity to check against.
     * @return true if there is a conflict, false otherwise.
     */
    bool checkConflicts(Activity activity);

    std::string getName() const;
    /**
     * @brief Converts guest to json
     * 
     * @return guest data in json form
     */
    nlohmann::json toJson() const;

    void setName(std::string name);
    void setId(int id);

private:
    int uniqueID_; /**< Unique ID for the guest */
    std::string name_; /** Guests full name */
    std::list<Activity> registeredActivities_; /**< Activities the guest has registered for */
};