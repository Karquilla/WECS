#pragma once

#include "QualifiedPersonnel.h"
#include "Resource.h"
#include <chrono>

class Activity {
public:
    void scheduleActivity(std::chrono::system_clock::time_point ,
                         std::chrono::system_clock::time_point );

    void assignPersonnel(QualifiedPersonnel); 

    void assignResource(Resource);

private:
    std::string activityType_;
    std::chrono::system_clock::time_point startTime_; 
    std::chrono::system_clock::time_point endTime_; 
    std::list<QualifiedPersonnel> qualifiedPersonnel; 
    std::list<Resource> resources; 
};