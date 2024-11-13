#pragma once

#include "Activity.h"
#include "DateTime.h"
#include "Manager.h"
#include "Report.h"
#include "Resource.h"
#include "QualifiedPersonnel.h"
#include <string>

/**
 * @class ProblemReport
 * @brief Represents a problem report related to activities and resources.
 */
class ProblemReport : public Report {
public:
    /**
     * @brief Creates a problem report for a specific activity and resource.
     * 
     * @param activity The activity associated with the problem.
     * @param resource The resource associated with the problem.
     */
    void createReport(Activity activity, Resource resource);

private:
    Activity activity_; /**< Activity associated with the report */
    Resource resource_; /**< Resource associated with the report */
    std::string timeStamp_; /**< Timestamp of the report creation */
    std::string severity_; /**< Severity level of the problem */
    Manager assignedManager_; /**< Manager assigned to handle the problem */
    QualifiedPersonnel reportedBy_; /**< Personnel who reported the problem */
};