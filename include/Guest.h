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
    /**
     * @brief Default constructor for Guest.
     */
    Guest();

    /**
     * @brief Constructor for Guest with ID and name.
     *
     * @param id The unique ID of the guest.
     * @param name The full name of the guest.
     */
    Guest(int id, const std::string name);

    /**
     * @brief Registers the guest for a specific activity.
     *
     * @param activity The activity to register for.
     */
    void registerForActivity(Activity activity);

    /**
     * @brief Loads guest information based on guest ID.
     *
     * @param guestId The unique ID of the guest to load.
     * @return true if the guest was successfully loaded, false otherwise.
     */
    bool loadGuest(int guestId);

    /**
     * @brief Adds a new guest with the specified ID and name.
     *
     * @param id The unique ID of the guest.
     * @param name The full name of the guest.
     */
    void addGuest(int id, std::string& name);

    /**
     * @brief Checks if there are scheduling conflicts with the specified activity.
     *
     * @param activity The activity to check against.
     * @return true if there is a conflict, false otherwise.
     */
    bool checkConflicts(Activity activity);

    /**
     * @brief Gets the name of the guest.
     *
     * @return The full name of the guest as a string.
     */
    std::string getName() const;

    /**
     * @brief Converts the guest information to JSON format.
     *
     * @return The guest data in JSON form.
     */
    nlohmann::json toJson() const;

    /**
     * @brief Sets the name of the guest.
     *
     * @param name The full name of the guest.
     */
    void setName(std::string name);

    /**
     * @brief Sets the unique ID of the guest.
     *
     * @param id The unique ID of the guest.
     */
    void setId(int id);

private:
    int uniqueID_; /**< Unique ID for the guest */
    std::string name_; /**< Guest's full name */
    std::list<Activity> registeredActivities_; /**< Activities the guest has registered for */
};
