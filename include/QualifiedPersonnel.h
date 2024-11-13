#pragma once

#include "StaffMember.h"
#include <list>

class Activity;
class ProblemReport;

// Class to represent qualified personnel who can be assigned to activities and report issues
class QualifiedPersonnel : public StaffMember {
public:
    // Reports an issue and creates a problem report
    void reportIssue(ProblemReport);

    // Assigns the personnel to an activity
    void assignActivity(Activity);

private:
    std::list<Activity> assignedActivity_; // List of activities assigned to the personnel
};