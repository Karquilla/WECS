#include <iostream>
#include <fstream>
#include <filesystem>
#include "Event.h"

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

void addEvent(int id, const std::string& name, const std::string& start, const std::string& end) {
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
        {"rooms",},
        {"start", start},
        {"end", end},
    };

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

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "enter start time and end time seperated by a spece\n";
        std::cout << "24 hr format - 1100 1300\n";
        getline(std::cin, timeInput);

        // add check for correct input
        startTime = timeInput.substr(0,4);
        endTime = timeInput.substr(5);

        int id = getNewId();

        addEvent(id, name, startTime, endTime);
        

    }else if (opt == "1") {

    }else {

    }
    

    return 0;
}