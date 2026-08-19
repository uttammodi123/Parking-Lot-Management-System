#include "history_manager.h"
#include <fstream>
#include <iostream>

void saveToCSV(Vehicle &v) {
    std::ifstream check("history.csv");
    bool exists = check.good();
    check.close();

    std::ofstream out("history.csv", std::ios::app);
    if (!out.is_open()) return;

    if (!exists) {
        out << "VehicleNumber,VehicleSize,EntryTime,ExitTime,TotalCost\n";
    }

    out << v.get_vehicle_number() << ","
        << v.get_vehicle_Size() << ","
        << "\"" << v.get_entry_time() << "\","
        << "\"" << v.get_exit_time() << "\","
        << v.get_cost() << "\n";

    out.close();
}

void searchVehicle(string& vehicleNumber) {
    std::ifstream in("history.csv");
    std::string line;
    bool found = false;

    while (getline(in, line)) {
        if (line.find(vehicleNumber) != std::string::npos) {
            std::cout << "Record found: " << line << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No history found for " << vehicleNumber << std::endl;
    }
    in.close();
}

void showHistory() {
    std::ifstream in("history.csv");
    if (!in.is_open()) {
        std::cout << "No history found.\n";
        return;
    }

    std::string line;
    std::cout << "\n--- Parking History (CSV) ---\n";
    while (getline(in, line)) {
        std::cout << line << std::endl;
    }
    in.close();
}