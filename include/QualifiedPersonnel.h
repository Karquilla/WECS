#pragma once

#include "StaffMember.h"
#include <list>

class Activity;
class ProblemReport;

/**
 * @class QualifiedPersonnel
 * @brief Represents qualified personnel who can be assigned to activities and report issues.
 */
class QualifiedPersonnel : public StaffMember {
public:
    /**
     * @brief Reports an issue by creating a problem report.
     * 
     * @param report The problem report to create.
     */
    void reportIssue(ProblemReport report);

    /**
     * @brief Assigns the personnel to a specified activity.
     * 
     * @param activity The activity to assign the personnel to.
     */
    void assignActivity(Activity activity);

private:
    std::list<Activity> assignedActivity_; /**< List of activities assigned to the personnel */
};