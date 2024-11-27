#pragma once

#include <string>

enum class Status {

};

/**
 * @class Report
 * @brief Base class for reports with a timestamp and status.
 */
class Report {
public:
    /**
     * @brief Generates the report with specified details.
     */
    void generateReport();

    /**
     * @brief Gets the timestamp of the report.
     * 
     * @return The timestamp as a string.
     */
    std::string getTimeStamp();

    /**
     * @brief Updates the status of the report.
     * 
     * @param status The new status to set for the report.
     */
    void updateStatus(Status status);

private:
    std::string reportID_; /**< ID of the report */
    std::string timeStamp_; /**< Timestamp of the report */
    std::string details_; /**< Details of the report */
    Status status_; /**< Status of the report */
};