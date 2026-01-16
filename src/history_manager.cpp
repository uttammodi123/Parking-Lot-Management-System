#include "history_manager.h"
#include <fstream>

void save(Vehicle &v) {

    ofstream out("history.json", ios::app);
    if(!out.is_open()) return;

    out << "{\n";
    out << "  \"vehicle_number\" : \"" << v.get_vehicle_number() << "\",\n";
    out << "  \"vehicle_size\"   : "  << v.get_vehicle_Size() << ",\n";
    out << "  \"entry_time\"     : \"" << v.get_entry_time() << "\",\n";
    out << "  \"exit_time\"      : \"" << v.get_exit_time() << "\"\n";
    out << "}\n\n";

    out.close();
}

void searchVehicle(string& vehicleNumber) {
    std::ifstream in("history.json");
    std::string line;
    bool found = false;

    while (getline(in, line)) {
        if (line.find(vehicleNumber) != std::string::npos) {
            std::cout << "Record found:\n";
            std::cout << line << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No history found for " << vehicleNumber << std::endl;
    }

    in.close();
}

void showHistory() {
    std::ifstream in("history.json");

    if (!in.is_open()) {
        std::cout << "No history found.\n";
        return;
    }

    std::string line;
    std::cout << "\n--- Parking History ---\n";

    while (getline(in, line)) {
        std::cout << line << std::endl;
    }

    in.close();
}

