#include "parkingLot.h"
#include "history_manager.h"

ParkingLot::ParkingLot(int floors, int lot_size) {
    this->floors = floors;
    this->Lot_size = lot_size;
    Lot.assign(floors, vector<int>(lot_size, 0));
}


bool ParkingLot::park(int sz, string num){
        
    if(activeVehicles.count(num)) return false;

    Vehicle* v;
    if(sz==1) v = new Bike(num);
    else if(sz==2) v = new Car(num);
    else v = new Bus(num);
        
    bool flag = true;
    pair<int,int> p = {-1,-1};

    if(sz==1) {
        p = searchSingly();
        if(p.first==-1) p = searchDoubly();
        if(p.first==-1) p = searchFour();
    }
    else if(sz==2) {
        p = searchDoubly();
        if(p.first==-1) p = searchFour();
    }
    else {
        p = searchFour();
    }

    if(p.first == -1) {
        delete v;
        return false;
    }

    int r = p.first, c = p.second;
    for(int i=0;i<sz;i++) Lot[r][c+i] = sz;

    position[num] = {r,c};
    activeVehicles[num] = v;

    return true;          
        
}

bool ParkingLot::unPark(string num){

    if(!activeVehicles.count(num)) return false;

    Vehicle* v = activeVehicles[num];
    v->setExitTime();
    calculateCost(*v);
    save(*v);
        
    int r = position[num].first;
    int c = position[num].second;
    int sz = v->get_vehicle_Size();

    for(int i=0; i<sz; i++){
        Lot[r][c+i] = 0;
    }

    position.erase(num);
    activeVehicles.erase(num);
    delete v;
        
    return true;
}