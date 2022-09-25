#include <iostream>
#include "station.h"
#pragma once
class Train {
public:enum status{
        AT_THE_DEPARTURE_STATION,// на станции отправления
        AT_THE_STATION,      // на станции прибытия
        ARRIVAL,             // прибытие
        DEPART,              // отправление
        WAITING_FOR_FREE_SPACE      // ожидание свободного места
    };
private:
    std::string trainName;
    status trainStatus = AT_THE_DEPARTURE_STATION;
    int travelTime;
    int timeSpentOnTheRoad = 0;

public:
    Train (std::string name){
        trainName = name;
        int inTravelTime;
        std::cout << "Enter travel time: ";
        std::cin >> inTravelTime;
        setTravelTime(inTravelTime);
    }

    void setTravelTime (int time){
        travelTime = time;
    }
    std::string getTrainName (){
        return trainName;
    }
    void addOne_inTimeSpentOnTheRoad (){
        timeSpentOnTheRoad ++;
    }
    int getTravelTime (){
        return travelTime;
    }

    void setStatus (std::string& depart, Station &checkStation){
    if (depart == "depart") {
        trainStatus = DEPART;
    }
    if (timeSpentOnTheRoad == travelTime - 2 && checkStation.getStationIsBusy()){
        trainStatus = WAITING_FOR_FREE_SPACE;
    }
    if (timeSpentOnTheRoad == travelTime - 1 && !checkStation.getStationIsBusy()){
        trainStatus = ARRIVAL;
    }
    if (timeSpentOnTheRoad == travelTime) {
        trainStatus = AT_THE_STATION;
    }
    }

    status getStatus (){
        return trainStatus;
    }


};