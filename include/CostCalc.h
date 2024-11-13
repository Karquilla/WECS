#pragma once

#include "Event.h"
#include <string>

// Class to handle cost calculation for events based on guest count and other factors
class CostCalc {
public:
    // Calculates the total cost of the event
    double calculateTotalCost();

    // Updates the guest count for cost calculation
    void updateGuestCount(int);

    // Provides a breakdown of the cost
    std::string getBreakdown();
    
private:
    Event event_; // Associated event for cost calculation
    int guestCount_; // Number of guests
};