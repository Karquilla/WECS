#pragma once

#include "Event.h"
#include <string>

class CostCalc {
public:
    double calculateTotalCost();

    void updateGuestCount(int);

    std::string getBreakdown();
    
private:
    Event event_;
    int guestCount_;
};