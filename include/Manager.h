#pragma once

#include "StaffMember.h"
#include <list>

class Event;

// define methods in h
class Manager : public StaffMember {
public:
    void manageEvent();

private:
    std::list<Event> managedEvents_;
};