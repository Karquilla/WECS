#pragma once

#include "Event.h"
#include <string>

/**
 * @class CostCalc
 * @brief Handles cost calculation for events based on guest count and other factors.
 */
class CostCalc {
public:
    /**
     * @brief Calculates the total cost of the event.
     * 
     * @return The total cost as a double.
     */
    double calculateTotalCost();

    /**
     * @brief Updates the guest count for cost calculation.
     * 
     * @param guestCount The updated number of guests.
     */
    void updateGuestCount(int guestCount);

    /**
     * @brief Provides a breakdown of the costs.
     * 
     * @return The cost breakdown as a string.
     */
    std::string getBreakdown();
    
private:
    Event event_; /**< Associated event for cost calculation */
    int guestCount_; /**< Number of guests */
};