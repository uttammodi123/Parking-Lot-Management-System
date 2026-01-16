#ifndef PARKINGLOT_H
#define PARKING_LOT_H

#include "vehicle.h"

class ParkingLot
{
private:
    int Lot_size = 50;
    int floors;

    vector<vector<int>> Lot;
    map<string, pair<int, int>> position;
    map<string, Vehicle*> activeVehicles;

public:

    ParkingLot(int floors, int lot_size);

    ParkingLot(int f) {
        floors = f;
        Lot.assign(floors, vector<int>(Lot_size, 0));
    }

    pair<int, int> searchSingly(){
        for(int i=0; i<floors; i++){
            for(int j=0; j<Lot_size; j++){
                if(j+1<Lot_size && Lot[i][j]==0 && Lot[i][j+1]!=0){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }

    pair<int, int> searchDoubly(){
        for(int i=0; i<floors; i++){
            for(int j=0; j<Lot_size; j++){
                if(j+2<Lot_size && Lot[i][j]==0 && Lot[i][j+1]==0 && Lot[i][j+2]!=0){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }

    pair<int, int> searchFour(){
        for(int i=0; i<floors; i++){
            for(int j=0; j<Lot_size; j++){
                if(j+3<Lot_size && Lot[i][j]==0 && Lot[i][j+1]==0 && Lot[i][j+2]==0 && Lot[i][j+3]==0){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }

    bool park(int size, string number);
    bool unPark(string number);
    
    void calculateCost(const Vehicle& v);
    

};


#endif