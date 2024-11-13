#pragma once

#include "StaffMember.h"
#include <list>

class Event;

/**
 * @class Manager
 * @brief Represents a manager who can manage events.
 */
class Manager : public StaffMember {
public:
    /**
     * @brief Manages the associated events.
     */
    void manageEvent();

private:
    std::list<Event> managedEvents_; /**< List of events managed by the manager */
};