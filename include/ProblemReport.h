#pragma once

#include "Activity.h"
#include "DateTime.h"
#include "Manager.h"
#include "Report.h"
#include "Resource.h"
#include "QualifiedPersonnel.h"
#include <string>

class ProblemReport : public Report {
public:
    void createReport(Activity,Resource);

private:
    Activity activity_; 
    Resource resource_; 
    std::string timeStamp_; 
    std::string severity_; 
    Manager assignedManager_; 
    QualifiedPersonnel reportedBy_; 
};