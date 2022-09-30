#include <iostream>
#include "station.h"
#pragma once
class Train {
public:enum status{
        AT_THE_DEPARTURE_STATION,// на станции отправления
        AT_THE_STATION,      // на станции прибытия
        TRAVEL,              // в пути
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
    Train (std::string name);

    void setTravelTime (int time);

    std::string getTrainName ();

    void addOne_inTimeSpentOnTheRoad ();

    int getTravelTime ();

    void setStatus ( Station &departStation, Station &arrivalStation);

    status getStatus ();
    ~Train() = default;

};