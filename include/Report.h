#pragma once

#include "DateTime.h"
#include <string>

enum class Status {

};

// Base class for reports with a timestamp and status
class Report {
public:
    // Generates the report
    void generateReport();

    // Gets the timestamp of the report
    std::string getTimeStamp();

    // Updates the status of the report
    void updateStatus(Status);

private:
    std::string reportID_; // ID of the report
    std::string timeStamp_; // Timestamp of the report
    std::string details_; // Details of the report
    Status status_; // Status of the report
};