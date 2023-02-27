#include "MMY.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <set>

using namespace std;

MMY::MMY()
{
    ifstream file("MMY.csv");
    string line;

    while (getline(file, line)) {

        string make = line.substr(0, line.find(","));
        line = line.substr(line.find(",") + 1);

        string model = line.substr(0, line.find(","));
        line = line.substr(line.find(",") + 1);

        string year = line;

        data.push_back({ make, model, year });
    }
    // loop through csv then display available makes
    set<string> availableMakes;
    for (const auto& vehicle : data) {
        availableMakes.insert(vehicle.make);
    }
    cout << "Available makes: \n";

    for (const auto& make : availableMakes) {
        cout << make << ", ";
    }
    cout << "\n" << endl;

    // prompt user for make and then filter csv data
    string make_filter;
    cout << "Enter make: ";
    getline(cin, make_filter);
    vector<MMYData> make_filtered_data;

    for (const auto& vehicle : data) {
        if (vehicle.make == make_filter) {
            make_filtered_data.push_back(vehicle);
        }
    }

    // loop through filtered makes and display available models
    set<string> filtered_models;
    for (const auto& vehicle : make_filtered_data) {
        filtered_models.insert(vehicle.model);
    }
    cout << "\n Available models: \n" << "\n";
    
    for (const auto& model : filtered_models) {
        cout << model << ", ";
    }
    cout << "\n" << endl;

    // prompt user for model and then filter csv data
    string model_filter;
    cout << "Enter model: ";
    getline(cin, model_filter);
    vector<MMYData> model_filtered_data;

    for (const auto& vehicle : data) {
        if (vehicle.model == model_filter) {
            model_filtered_data.push_back(vehicle);
        }
    }

    // loop through filtered year and display available years
    set<string> filtered_years;
    for (const auto& vehicle : model_filtered_data) {
        filtered_years.insert(vehicle.year);
    }
    cout << "\n Available years: \n" << "\n";

    for (const auto& year : filtered_years) {
        cout << year << ", ";
    }
    cout << "\n" << endl;

    // prompt user for year and then filter csv data
    string year_filter;
    cout << "Enter year: ";
    getline(cin, year_filter);
    vector<MMYData> year_filtered_data;

    for (const auto& vehicle : data) {
        if (vehicle.year == year_filter) {
            year_filtered_data.push_back(vehicle);
        }
    }

    ofstream outFile("Filtered MMY.txt");
    if (outFile.is_open()) {
        outFile << "Saved Make: " << make_filtered_data[0].make << endl;
        outFile << "Saved Model: " << model_filtered_data[0].model << endl;
        outFile << "Saved year: " << year_filtered_data[0].year << endl;
        outFile.close();
        cout << "Selections Saved." << endl;
    } 
    else {
        cout << "Unable to create save file." << endl;
    }
}
