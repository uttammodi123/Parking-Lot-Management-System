#ifndef HISTORY_MANAGER_H
#define HISTORY_MANAGER_H

#include "vehicle.h"

void saveToCSV(Vehicle& v);
void searchVehicle(string& vehicleNumber);
void showHistory();

#endif