#include "RoutePlanner.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Array to help you out with name of the cities in order
const std::string cities[81] = {
    "Adana", "Adiyaman", "Afyon", "Agri", "Amasya", "Ankara", "Antalya", "Artvin", "Aydin", "Balikesir", "Bilecik",
    "Bingol", "Bitlis", "Bolu", "Burdur", "Bursa", "Canakkale", "Cankiri", "Corum", "Denizli", "Diyarbakir", "Edirne",
    "Elazig", "Erzincan", "Erzurum", "Eskisehir", "Gaziantep", "Giresun", "Gumushane", "Hakkari", "Hatay", "Isparta",
    "Mersin", "Istanbul", "Izmir", "Kars", "Kastamonu", "Kayseri", "Kirklareli", "Kirsehir", "Kocaeli", "Konya", "Kutahya",
    "Malatya", "Manisa", "Kaharamanmaras", "Mardin", "Mugla", "Mus", "Nevsehir", "Nigde", "Ordu", "Rize", "Sakarya",
    "Samsun", "Siirt", "Sinop", "Sivas", "Tekirdag", "Tokat", "Trabzon", "Tunceli", "Urfa", "Usak", "Van", "Yozgat",
    "Zonguldak", "Aksaray", "Bayburt", "Karaman", "Kirikkale", "Batman", "Sirnak", "Bartin", "Ardahan", "Igdir",
    "Yalova", "Karabuk", "Kilis", "Osmaniye", "Duzce"};

// Constructor to initialize and load constraints
RoutePlanner::RoutePlanner(const std::string &distance_data, const std::string &priority_data, const std::string &restricted_data, int maxDistance)
    : maxDistance(maxDistance), totalDistanceCovered(0), numPriorityProvinces(0), numWeatherRestrictedProvinces(0)
{

    // TO DO:
    // Load map data from file
    // Mark all provinces as unvisited initially

    // Load priority provinces
    // Load restricted provinces
}

// Load priority provinces from txt file to an array of indices
void RoutePlanner::loadPriorityProvinces(const std::string &filename)
{
    // TODO: Your code here
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        int start_pos = line.find("(") + 1;
        int end_pos = line.find(")");
        int province = std::stoi(line.substr(start_pos, end_pos - start_pos));
        priorityProvinces[numPriorityProvinces++] = province;
    }
}

// Load weather-restricted provinces from txt file to an array of indices
void RoutePlanner::loadWeatherRestrictedProvinces(const std::string &filename)
{
    // TODO: Your code here
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        int start_pos = line.find("(") + 1;
        int end_pos = line.find(")");
        int province = std::stoi(line.substr(start_pos, end_pos - start_pos));
        weatherRestrictedProvinces[numWeatherRestrictedProvinces++] = province;
    }
}

// Checks if a province is a priority province
bool RoutePlanner::isPriorityProvince(int province) const
{
    // TODO: Your code here
    for (int i = 0; i < numPriorityProvinces; i++)
    {
        if (priorityProvinces[i] == province)
        {
            return true;
        }
    }
    return false;
}

// Checks if a province is weather-restricted
bool RoutePlanner::isWeatherRestricted(int province) const
{
    // TODO: Your code here
    for (int i = 0; i < numWeatherRestrictedProvinces; i++)
    {
        if (weatherRestrictedProvinces[i] == province)
        {
            return true;
        }
    }
    return false;
}

// Begins the route exploration from the starting point
void RoutePlanner::exploreRoute(int startingCity)
{
    // TODO: Your code here
}

// Helper function to explore from a specific province
void RoutePlanner::exploreFromProvince(int province)
{
    // TODO: Your code here
}

void RoutePlanner::enqueueNeighbors(int province)
{
    // TO DO: Enqueue priority & non-priority neighbors to the queue according to given constraints
}

void RoutePlanner::backtrack()
{
    // If you reach a dead-end province
    // TODO: Your code here
}

bool RoutePlanner::isExplorationComplete() const
{
    // TODO: Your code here
    return false;
}

void RoutePlanner::displayResults() const
{
    // TODO: Your code here
    // Display "Journey Completed!" message
    // Display the total number of provinces visited
    // Display the total distance covered
    // Display the route in the order visited
    // Priority Province Summary
}
