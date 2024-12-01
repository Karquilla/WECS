#include "Activity.h"
#include "Guest.h"

Guest::Guest(){};

Guest::Guest(int id, const std::string name)
{
    uniqueID_ = id;
    name_ = name;
}
/**
 * @brief Registers the guest for a specific activity.
 * 
 * @param activity The activity to register for.
 */
void Guest::registerForActivity(Activity activity) {
    // Logic to register the guest for the activity

}

bool Guest::loadGuest(int guestId)
{
    //Open json file
    std::ifstream inFile("data/events.json");
    if (!inFile) {
        std::cerr << "Unable to open file" << std::endl;
        return false;
    }

    nlohmann::json eventsData;
    inFile >> eventsData;
    inFile.close();

    for (const auto& guestJson : eventsData["guests"]) {
        if(guestJson["id"] == guestId) {
            uniqueID_ = guestJson["id"];
            name_ = guestJson["name"];
            registeredActivities_.clear();


            std::ofstream outFile("data/events.json");   
            if (!outFile) {
                std::cerr << "Unable to open file." << std::endl;
                return false;
            }
            outFile << eventsData.dump(4); // Save with indentation
            outFile.close();
            return true; //load guest successful
        }
    }

    std::cerr << "Guest ID not found" << std::endl;
    std::ofstream outFile("data/events.json");   
    if (!outFile) {
        std::cerr << "Unable to open file." << std::endl;
        return false;
    }
    outFile << eventsData.dump(4); // Save with indentation
    outFile.close();
    return false; //guest not found
}

void Guest::addGuest(int id, std::string& name)
{
    //Open json file
    std::ifstream inFile("data/events.json");
    if (!inFile) {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }

    nlohmann::json eventsData;
    inFile >> eventsData;
    inFile.close();

    //Create new guest
    nlohmann::json newGuest = {
        {"id", id},
        {"name", name},
        {"registeredActivities", nlohmann::json::array()}
    };

    eventsData["guests"].push_back(newGuest);

    std::ofstream outFile("data/events.json");   
    if (!outFile) {
        std::cerr << "Unable to open file." << std::endl;
        return;
    }
    outFile << eventsData.dump(4); // Save with indentation
    outFile.close();
}

/**
 * @brief Checks if the guest has a scheduling conflict with the specified activity.
 * 
 * @param activity The activity to check against.
 * @return true if there is a conflict, false otherwise.
 */
bool Guest::checkConflicts(Activity activity) {
    // Logic to check for conflicts
    for(const auto& registeredActivity : registeredActivities_){
        if((activity.getStartTime() < registeredActivity.getEndTime()) && (activity.getEndTime() > registeredActivity.getStartTime())){
            return true; //conflict
        }
    }
    return false; //no conflicts
}

std::string Guest::getName() const{
    return name_;
}

nlohmann::json Guest::toJson() const {
    nlohmann::json activitiesJson = nlohmann::json::array();
    for(const auto& activity : registeredActivities_){
        activitiesJson.push_back({
            {"activityName", activity.getName()},
            {"type", activity.getType()},
            {"start", activity.getStartTime()},
            {"end", activity.getEndTime()}
        });
    }
    return{
    {"id", uniqueID_},
    {"name", name_},
    {"registeredActivities", activitiesJson}
};
}

void Guest::setName(std::string name){
    name_ = name;
}

void Guest::setId(int id){
    uniqueID_ = id;
}