# Multi-Level Parking Lot Management System

An Object-Oriented C++ system designed to simulate dynamic parking slot allocation, entry/exit timestamp tracking, dynamic fee computation, and persistent CSV logging for multi-level parking facilities.

---

## Key Features

* **Custom Space Optimization:** Implements a Best-Fit allocation heuristic (`searchSingly`, `searchDoubly`, `searchFour`) to prevent external space fragmentation by prioritizing smaller vehicles into isolated open spots.
* **Object-Oriented Design (OOD):** Built on C++ inheritance and pure virtual functions (`getRatePerHour()`) to handle polymorphic fee calculations across vehicle types.
* **Real-Time Tracking:** Uses standard library associative containers (`std::map`) for $O(1)$ license plate lookup and spot mapping.
* **Persistent History Logging:** Appends entry/exit timestamps, vehicle dimensions, and total billing costs into structured CSV files (`history.csv`).
* **Interactive Command-Line Interface:** Provides a CLI menu to park, unpark, search records, and view system history at runtime.

---

## Class Architecture



             +-------------------+
             |      Vehicle      | (Abstract Base)
             +-------------------+
             | - vehicle_number  |
             | - vehicle_size    |
             | - entry_time      |
             | - exit_time       |
             +-------------------+
                       ^
                       |
   +-------------------+-------------------+
   |                   |                   |
+--------------+    +--------------+    +--------------+
|     Bike     |    |     Car      |    |     Bus      |
+--------------+    +--------------+    +--------------+
| Size: 1      |    | Size: 2      |    | Size: 4      |
| Rate: $10/hr |    | Rate: $20/hr |    | Rate: $40/hr |
+--------------+    +--------------+    +--------------+

---

## Allocation Heuristic (Fragmentation Prevention)

Standard naive allocators place small vehicles into the first available contiguous slots, blocking large vehicles from parking. This system resolves external fragmentation using targeted searches:

1. **Bikes (Size 1):** Scans isolated 1-spot gaps (`searchSingly`) first. Cascades to 2-spot (`searchDoubly`) or 4-spot (`searchFour`) gaps only if isolated spots are filled.
2. **Cars (Size 2):** Checks 2-spot contiguous gaps first before falling back to 4-spot gaps.
3. **Buses/Trucks (Size 4):** Strictly requires 4 contiguous open spots (`searchFour`).

---

## Build & Run Instructions

### Prerequisites
* C++17 compliant compiler (`g++` / MinGW / Clang)
* CMake (Version 3.10+) *(Optional)*

### Option 1: Direct Build (Recommended)
```powershell
g++ -std=c++17 src/*.cpp -o parking_system
.\parking_system.exe

Option 2: CMake Build

PowerShell
cmake -B build -G "MinGW Makefiles"
cmake --build build
.\build\parking_system.exe

File Structure

PARKING_LOT_MANAGEMENT_SYSTEM/
├── CMakeLists.txt         # CMake build configuration
├── README.md              # Project documentation
├── .gitignore             # File exclusion rules
└── src/
    ├── main.cpp            # Interactive menu driver
    ├── parking_lot.h       # Parking management declarations
    ├── parkingLot.cpp      # Grid allocation & search logic
    ├── vehicle.h          # Vehicle class hierarchy
    ├── vehicle.cpp        # Vehicle timestamp & cost handling
    ├── history_manager.h  # File exporter headers
    └── history_manager.cpp# CSV persistence & search module