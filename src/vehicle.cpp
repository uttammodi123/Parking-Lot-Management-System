#include "vehicle.h"

Vehicle::Vehicle(string vehicle_number, int vehicle_size)
{
    this->vehicle_size = vehicle_size;
    this->vehicle_number = vehicle_number;
    this->entry_time = currentTime();

}

Vehicle::~Vehicle(){
    this->exit_time = currentTime();
}

int Vehicle :: get_vehicle_Size()
{
    return vehicle_size;
}

string Vehicle :: get_vehicle_number()
{
    return vehicle_number;
}

string Vehicle :: get_entry_time(){
    return entry_time;
}
    
string Vehicle :: get_exit_time(){
    return exit_time;
}

void Vehicle::setExitTime() {
    exit_time = currentTime();
}

string Vehicle :: currentTime(){
    time_t now = time(0);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}






