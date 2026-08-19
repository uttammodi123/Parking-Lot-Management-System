#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Vehicle {
protected:
    string vehicle_number;
    int vehicle_size;
    string entry_time;
    string exit_time;
    double total_cost;

    string currentTime();

public:
    Vehicle();
    Vehicle(string vehicle_number, int vehicle_size);
    virtual ~Vehicle();

    virtual double getRatePerHour() const = 0;

    string get_vehicle_number();
    int get_vehicle_Size();
    string get_entry_time();
    string get_exit_time();
    double get_cost() const;

    void setExitTime();
    void setCost(double cost);
};

class Bike : public Vehicle {
public:
    Bike(string vehicle_number) : Vehicle(vehicle_number, 1) {}
    double getRatePerHour() const override { return 10.0; }
};

class Car : public Vehicle {
public:
    Car(string vehicle_number) : Vehicle(vehicle_number, 2) {}
    double getRatePerHour() const override { return 20.0; }
};

class Bus : public Vehicle {
public:
    Bus(string vehicle_number) : Vehicle(vehicle_number, 4) {}
    double getRatePerHour() const override { return 40.0; }
};

#endif