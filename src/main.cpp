#include <iostream>
#include <string>
#include <limits>
#include "parkinglot.h"
#include "history_manager.h"

using namespace std;

void displayMenu() {
    cout << "\n=====================================\n";
    cout << "   PARKING LOT MANAGEMENT SYSTEM     \n";
    cout << "=====================================\n";
    cout << "1. Park a Vehicle\n";
    cout << "2. Unpark a Vehicle\n";
    cout << "3. Search Vehicle History\n";
    cout << "4. Show All Parking Logs (CSV)\n";
    cout << "5. Exit\n";
    cout << "-------------------------------------\n";
    cout << "Enter your choice (1-5): ";
}

int main() {
    // Initialize Parking Lot: 3 Floors, 10 Spots per floor
    ParkingLot lot(3, 10);
    int choice = 0;

    while (true) {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1 and 5.\n";
            continue;
        }

        if (choice == 5) {
            cout << "\nExiting System. Good luck !\n";
            break;
        }

        switch (choice) {
            case 1: {
                string vehicleNumber;
                int typeChoice;

                cout << "\nEnter Vehicle Number (e.g., KA-01-AB-1234): ";
                cin >> vehicleNumber;

                cout << "Select Vehicle Type:\n";
                cout << "  1. Bike (Size 1)\n";
                cout << "  2. Car (Size 2)\n";
                cout << "  3. Bus/Truck (Size 4)\n";
                cout << "Enter choice (1-3): ";
                cin >> typeChoice;

                int size = 1;
                if (typeChoice == 2) size = 2;
                else if (typeChoice == 3) size = 4;
                else if (typeChoice != 1) {
                    cout << "Invalid vehicle type selected! Defaulting to Bike (Size 1).\n";
                }

                if (lot.park(size, vehicleNumber)) {
                    cout << "\n[SUCCESS] Vehicle " << vehicleNumber << " parked successfully!\n";
                } else {
                    cout << "\n[FAILED] Could not park " << vehicleNumber << ". (Lot full or vehicle already parked).\n";
                }
                break;
            }

            case 2: {
                string vehicleNumber;
                cout << "\nEnter Vehicle Number to unpark: ";
                cin >> vehicleNumber;

                if (lot.unPark(vehicleNumber)) {
                    cout << "\n[SUCCESS] Vehicle " << vehicleNumber << " unparked successfully!\n";
                    cout << "[LOGGED] Receipt saved to history.csv\n";
                } else {
                    cout << "\n[FAILED] Vehicle " << vehicleNumber << " not found in active parking lot.\n";
                }
                break;
            }

            case 3: {
                string vehicleNumber;
                cout << "\nEnter Vehicle Number to search in history: ";
                cin >> vehicleNumber;
                cout << "\n--- Search Result ---\n";
                searchVehicle(vehicleNumber);
                break;
            }

            case 4: {
                showHistory();
                break;
            }

            default:
                cout << "Invalid option! Please choose between 1 and 5.\n";
                break;
        }
    }

    return 0;
}