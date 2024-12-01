#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include "Event.h"
#include "Room.h"
#include "Activity.h"
#include "utility.h"
#include "json.hpp"


int getNewId() {
    // Load the JSON data from the file
    std::ifstream inFile("data/idList.json");
    if (!inFile) {
        std::cerr << "Unable to open file" << std::endl;
        return -1; // Return -1 to indicate an error
    }
    nlohmann::json idList;
    inFile >> idList;
    inFile.close();

    int newId = -1;  // Default to -1 to indicate no ID found

    // Find the first available ID and mark it as used
    for (auto& id : idList["ids"]) {
        if (id["status"] == "available") {
            id["status"] = "used";
            newId = id["id"];
            break;
        }
    }

    // Save the updated JSON data back to the file
    std::ofstream outFile("data/idList.json");
    if (!outFile) {
        std::cerr << "Unable to open file for writing" << std::endl;
        return -1;  // Return -1 in case of an error saving the file
    }
    outFile << idList.dump(4);  // Save with 4 spaces indentation for readability
    outFile.close();

    return newId;
}


void addEvent(int id, const std::string& name, const std::string& start, const std::string& end, std::vector<Room> rooms) {
    // Load the existing JSON data
    std::ifstream inFile("data/events.json");
    if (!inFile) {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }
    
    nlohmann::json eventsData;
    inFile >> eventsData;
    inFile.close();

    // Create a new event
    nlohmann::json newEvent = {
        {"id", id},
        {"name", name},
        {"rooms",nlohmann::json::array()},
        {"start", start},
        {"end", end},
        {"activities", nlohmann::json::array()}
    };

    for (auto& room : rooms) {
        nlohmann::json roomInfo = {
            {"type", room.getType()},
            {"length", std::to_string(room.getLength())},
            {"cost", std::to_string(room.getCost())}
        };
        newEvent["rooms"].push_back(roomInfo);
    }
    // Add the new event to the "events" array
    eventsData["events"].push_back(newEvent);

    // Save the updated JSON data back to the file
    std::ofstream outFile("data/events.json");
    if (!outFile) {
        std::cerr << "Unable to open file for writing" << std::endl;
        return;
    }
    outFile << eventsData.dump(4); // Save with 4 spaces indentation for readability
    outFile.close();
}

void addEventActivities(int id, Activity activity) {
    // Load the existing JSON data
    std::ifstream inFile("data/events.json");
    if (!inFile) {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }
    nlohmann::json eventsData;
    try{
            inFile >> eventsData;
    }
    catch(nlohmann::json::parse_error& e) {
        std::cout << "Error parsing JSON: " << e.what() <<std::endl;
        return;
    }
    inFile.close();

    //get event by ID
    if (!eventsData.contains("events") || !eventsData["events"].is_array()) {
        std::cout << "'events' key is missing or not an array." << std::endl;
        return;
    }


    for(auto& event: eventsData["events"]) {
        if(event["id"] == id) {
            nlohmann::json activityInfo = {
                {"id", getNewId()},
                {"type", activity.getType()},
                {"start", activity.getStartTime()},
                {"end", activity.getEndTime()},
                {"activityName", activity.getName()},
                {"guestCount", 0}
            };

            if(!event.contains("activities") || !event["activities"].is_array()){
                event["activities"] = nlohmann::json::array();
            }

            event["activities"].push_back(activityInfo);
        }
    }

    //Save the updated JSON data back to the file
    std::ofstream outFile("data/events.json");
    if (!outFile) {
        std::cout << "Unable to open file for writing" << std::endl;
        return;
    }
    outFile << eventsData.dump(4); // Save with 4 spaces indentation for readability
    outFile.close();
}

std::vector<Event> loadEvents() {
    std::string directoryPath = "data/";
    std::vector<Event> events;

    //Iterate over all .txt files in the directory
    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
        if (entry.path().extension() == ".txt") {
            Event event;
            event.loadFromFile(entry.path().string());
            events.push_back(event);
        }
    }
    return events;
}

nlohmann::json getEvent(){
    std::ifstream inFile("data/events.json");
        if (!inFile) {
            std::cerr << "Unable to open file" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        
        nlohmann::json eventsData;
        inFile >> eventsData;
        inFile.close();

        int eventId;
        while(true)
        {
            //Get event information
            std::cout << "Enter event ID or enter '0' to quit: ";
            std::cin >> eventId;

            if(eventId == 0) {
                std::cout << "Exiting..." << std::endl;
                std::exit(EXIT_SUCCESS);
            }

            for(auto& event: eventsData["events"]) {
                if(event["id"] == eventId) {
                    return event;
                }
            }
        }
        //event not found
        std::cout << "Event ID not found. Exiting..." << std::endl;
        std::exit(EXIT_FAILURE);
}

void registerGuest(int guestId, int activityId, nlohmann::json& event)
{
    // Load existing JSON data
    std::ifstream inFile("data/events.json");
    if (!inFile) {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }

    nlohmann::json eventsData;
    inFile >> eventsData;
    inFile.close();

    // Ensure guests array exists
    if (!eventsData.contains("guests") || !eventsData["guests"].is_array()) {
        eventsData["guests"] = nlohmann::json::array();  // Initialize guests array if missing
    }

    // Check if guest exists
    nlohmann::json* guestPtr = nullptr;
    for (auto& guest : eventsData["guests"]) {
        if (guest["id"] == guestId) {
            guestPtr = &guest;
            break;
        }
    }

    if (!guestPtr) {
        std::cerr << "No guest found with matching ID" << std::endl;
        return;
    }

    // Find activity in event
    nlohmann::json* activityPtr = nullptr;
    for (auto& activity : event["activities"]) {
        if (activity["id"] == activityId) {
            activityPtr = &activity;
            break;
        }
    }

    if (!activityPtr) {
        std::cerr << "No activity found with matching ID" << std::endl;
        return;
    }

    // Register the activity to the guest
    if (!guestPtr->contains("registeredActivities") || !(*guestPtr)["registeredActivities"].is_array()) {
        (*guestPtr)["registeredActivities"] = nlohmann::json::array(); // Initialize if missing
    }

    nlohmann::json activityInfo = {
        {"activityId", activityId},
        {"activityName", (*activityPtr)["activityName"]}
    };

    (*guestPtr)["registeredActivities"].push_back(activityInfo);
    
    //increment guestCount in activities
    for(auto& activity: eventsData["events"][0]["activities"]) {
        if(activity["id"] == activityId){
            activity["guestCount"] = activity["guestCount"].get<int>() + 1;
            break;
        }
    }
    // Save updated JSON data back to file
    std::ofstream outFile("data/events.json");
    if (!outFile) {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }
    outFile << eventsData.dump(4); // Pretty print with indentation
    outFile.close();
}
/**
 * @brief Main function, entry point of the creating and scheduling event.
 * 
 * @return int Returns 0 if the program executes successfully.
 */

int main() {
    // place holder menu
    std::string opt;
    std::cout << " make selection" << std::endl;
    std::cout << " 0 - create event" << std::endl;
    std::cout << " 1 - edit event" << std::endl;
    std::cout << " 2 - schedule activity" << std::endl;
    std::cout << " 3 - register guest" << std::endl;
    std::cin >> opt;

    std::string name;
    std::fstream eventFile;
    if (opt == "0") {
        // create a new even in the json file

        // gather event information
        std::string timeInput; // string to hold time input
        std::string startTime; // string to hold start time
        std::string endTime;   // string to hold end time

        std::cout << " enter name of event" << std::endl;
        std::cin >> name;

        // gather room information.
        // right now no conflict checking.
        std::vector<Room> rooms;
        while(true) {
            Room newRoom;
            std::cout << " What rooms would you like to reserve?\n";
            std::cout << "---------------Options---------------\n";
            std::cout << "    Room Type              Price     \n";
            std::cout << "-------------------------------------\n";
            std::cout << "      Rome --------------- $300\n";
            std::cout << "      Paris -------------- $400\n";
            std::cout << "    LasVegas ------------ $500\n";
            std::cout << "-------------------------------------\n\n";
            std::cout << " Enter name of a room you would like to reserve\n";
            //std::cout << "";
            //std::cout << "";
            //std::cout << "";
            //std::cout << "";
            //std::cout << "";


            std::string roomInput;
            while ( roomInput != "rome" &&
                    roomInput != "paris" &&
                    roomInput != "lasvegas") {
                std::cin >> roomInput;
                roomInput = stringToLower(roomInput);  
            }
            newRoom.setType(roomInput);

            std::string strTime;
            std::cout << "How long would you like to reserve to room?\n";
            std::cin >> strTime;
            int intTime = stoi(strTime);
            newRoom.setLength(intTime);

            newRoom.setCost();

            rooms.push_back(newRoom);

            // ask for another room?
            break;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::cout << "enter start time and end time separated by a space\n";
        std::cout << "24 hr format - 1100 1300\n";
        getline(std::cin, timeInput);

        // add check for correct input
        startTime = timeInput.substr(0,4);
        endTime = timeInput.substr(5);

        int id = getNewId();

        addEvent(id, name, startTime, endTime, rooms);

        
    }else if (opt == "1") {

    }else if (opt == "2") {

        nlohmann::json event = getEvent();
        // Gather activity information
        std::string activityName, activityType;
        std::string timeInput; // string to hold time input
        std::string startTime; // string to hold start time
        std::string endTime;   // string to hold end time

        std::cout << "Enter name of activity: ";
        std::cin.ignore();
        std::getline(std::cin, activityName);

        std::cout << "Enter activity type: ";
        std::getline(std::cin, activityType);

        
        std::cout << "Enter start time and end time separated by a space\n";
        std::cout << "24 hr format - 1100 1300\n";
        getline(std::cin, timeInput);

        bool validTime = false;
        while(!validTime){
                if (timeInput.length() < 9 || timeInput[4] != ' ') {
                    std::cerr << "Invalid input format. Please enter times in the format 'HHMM HHMM'." << std::endl;
                }
                else {
                    validTime = true;
                }
        }
        // add check for correct input
        startTime = timeInput.substr(0,4);
        endTime = timeInput.substr(5);

        // Create Activity
        //Activity activity(activityType, activityName, startTime, endTime);
        Activity activity;
        activity.setActivityType(activityType);
        activity.setActivityName(activityName);
        activity.setActivityStartTime(startTime);
        activity.setActivityEndTime(endTime);

        //Add activity to Event
        addEventActivities(event["id"], activity);

    } else if(opt == "3") {
        std::string guestOpt, name;
        int guestId, activityId;

        std::cout << " make selection" << std::endl;
        std::cout << " 0 - register new guest" << std::endl;
        std::cout << " 1 - register existing guest" << std::endl;
        std::cin >> guestOpt;

        Guest guest;

        // New guest
        if (guestOpt == "0") {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter full name:" << std::endl;
            getline(std::cin, name);
            int guestId = getNewId();
            guest.setName(name);
            guest.setId(guestId);
            guest.addGuest(guestId, name);

        // Existing guest
        } else if (guestOpt == "1"){
            std::cout << "Enter Existing Guest ID: " << std::endl;
            std::cin >> guestId;

            if(!guest.loadGuest(guestId)){
                std::cerr << "Guest ID not found" << std::endl;
                return -1;
            }
        } else {
            std::cout << "Invalid entry." << std::endl;
            return -1;
        }

        std::cout<<"Welcome " << guest.getName() << std::endl;
        //Get Activities for given event
        nlohmann::json event = getEvent();     
        std::cout << "Activities for " << event["name"] <<std::endl;
        std::cout << "ID ------- Name\n";
        for(auto activity : event["activities"])
        {
            std::cout << activity["id"] << " ------ " << activity["activityName"] << std::endl;
            
        }
        std::cout << "Enter Activity ID to register" << std::endl;
        std::cin >> activityId;

        //add registration stuff

        registerGuest(guestId, activityId, event);


        
    } else {
    
    }
    return 0;
}