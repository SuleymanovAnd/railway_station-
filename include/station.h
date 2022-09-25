#include <iostream>
#include <utility>
#include <mutex>

#pragma once
class Station {

    std::string name;
    bool stationIsBusy;
    std::mutex * stationPlace;
public:

    Station (std::string stationStatus,std::string inName ){

        stationPlace = new std::mutex ();

        setStationName(inName);
        setStationStatus(std::move(stationStatus));
    }

    void setStationName (std::string inName){
        name = inName;
    }

    std::string getStationName (){
        return name;
    }

    void setStationStatus (std::string stationStatus){
        if (stationStatus == "busy"){
            stationPlace->lock();
            stationIsBusy = true;
        }
        else if (stationStatus == "free"){
            stationIsBusy = false;
            stationPlace->unlock();
        }

    }

    bool getStationIsBusy (){
        return stationIsBusy;
    }

    ~Station() = default;
};
