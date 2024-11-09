#pragma once

#include "StaffMember.h"
#include <list>

class Activity;
class ProblemReport;

// define methods in h
class QualifiedPersonnel : public StaffMember {
public:
    void reportIssue(ProblemReport);

    void assignActivity(Activity);

private:
    std::list<Activity> assignedActivity_;
};