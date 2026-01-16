#ifndef VEHICLE_H
#define VEHICLE_H

#include<bits/stdc++.h>
#include<ctime>
using namespace std;

class Vehicle
{
protected:
    string vehicle_number;
    int vehicle_size;
    string entry_time;
    string exit_time;

    string currentTime();

    //0->empty space
    //1->bike
    //2->car, auto
    //4->bus,truck

public:
    Vehicle();
    Vehicle(string vehicle_number, int vehicle_size);

    ~Vehicle();

    string get_vehicle_number();
    int get_vehicle_Size();
    string get_entry_time();
    string get_exit_time();

    void setExitTime();
        
};

class Bike : public Vehicle
{
public:

    Bike(string vehicle_number) : Vehicle(vehicle_number, 1){

    }


};

class Car : public Vehicle
{
public:

    Car(string vehicle_number) : Vehicle(vehicle_number, 2){

    }


};

class Bus : public Vehicle
{
public:

    Bus(string vehicle_number) : Vehicle(vehicle_number, 4){

    }

};


#endif

