#include "Activity.h"
#include "Guest.h"

/**
 * @brief Default constructor for Guest.
 */
Guest::Guest(){};

/**
 * @brief Constructor for Guest with ID and name.
 *
 * @param id The unique ID of the guest.
 * @param name The full name of the guest.
 */
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

/**
 * @brief Loads guest information based on guest ID.
 *
 * @param guestId The unique ID of the guest to load.
 * @return true if the guest was successfully loaded, false otherwise.
 */
bool Guest::loadGuest(int guestId)
{
    // Open JSON file
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
            return true; // Load guest successful
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
    return false; // Guest not found
}

/**
 * @brief Adds a new guest with the specified ID and name.
 *
 * @param id The unique ID of the guest.
 * @param name The full name of the guest.
 */
void Guest::addGuest(int id, std::string& name)
{
    // Open JSON file
    std::ifstream inFile("data/events.json");
    if (!inFile) {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }

    nlohmann::json eventsData;
    inFile >> eventsData;
    inFile.close();

    // Create new guest
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
            return true; // Conflict
        }
    }
    return false; // No conflicts
}

/**
 * @brief Gets the name of the guest.
 *
 * @return The full name of the guest as a string.
 */
std::string Guest::getName() const{
    return name_;
}

/**
 * @brief Converts the guest information to JSON format.
 *
 * @return The guest data in JSON form.
 */
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
    return {
        {"id", uniqueID_},
        {"name", name_},
        {"registeredActivities", activitiesJson}
    };
}

/**
 * @brief Sets the name of the guest.
 *
 * @param name The full name of the guest.
 */
void Guest::setName(std::string name){
    name_ = name;
}

/**
 * @brief Sets the unique ID of the guest.
 *
 * @param id The unique ID of the guest.
 */
void Guest::setId(int id){
    uniqueID_ = id;
}