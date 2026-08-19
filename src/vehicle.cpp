#include "vehicle.h"

Vehicle::Vehicle() : vehicle_number(""), vehicle_size(0), total_cost(0.0) {}

Vehicle::Vehicle(string vehicle_number, int vehicle_size) {
    this->vehicle_size = vehicle_size;
    this->vehicle_number = vehicle_number;
    this->entry_time = currentTime();
    this->total_cost = 0.0;
}

Vehicle::~Vehicle() {}

int Vehicle::get_vehicle_Size() { return vehicle_size; }
string Vehicle::get_vehicle_number() { return vehicle_number; }
string Vehicle::get_entry_time() { return entry_time; }
string Vehicle::get_exit_time() { return exit_time; }
double Vehicle::get_cost() const { return total_cost; }

void Vehicle::setExitTime() { exit_time = currentTime(); }
void Vehicle::setCost(double cost) { total_cost = cost; }

string Vehicle::currentTime() {
    time_t now = time(0);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}