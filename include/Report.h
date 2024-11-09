#pragma once

#include "DateTime.h"
#include <string>

enum class Status {

};

class Report {
public:
    void generateReport();

    std::string getTimeStamp();

    void updateStatus(Status);
private:
    std::string reportID_;
    std::string timeStamp_;
    std::string details_;
    Status status_;
};