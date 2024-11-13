#pragma once

#include "Activity.h"
#include "DateTime.h"
#include "Manager.h"
#include "Report.h"
#include "Resource.h"
#include "QualifiedPersonnel.h"
#include <string>

// Class to represent a problem report related to activities and resources
class ProblemReport : public Report {
public:
    // Creates a problem report for an activity and resource
    void createReport(Activity, Resource);

private:
    Activity activity_; // Activity associated with the report
    Resource resource_; // Resource associated with the report
    std::string timeStamp_; // Timestamp of the report creation
    std::string severity_; // Severity level of the problem
    Manager assignedManager_; // Manager assigned to the problem
    QualifiedPersonnel reportedBy_; // Personnel who reported the problem
};