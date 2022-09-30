#include "station.h"


void Station::setStationName (std::string inName){
    name = inName;
}
std::string Station::getStationName (){
    return name;
}

bool Station::getStationIsBusy (){
    return stationIsBusy;
}

Station::Station (std::string stationStatus,std::string inName ){

stationPlace = new std::mutex ();

setStationName(inName);
setStationStatus(std::move(stationStatus));
}

void    Station::setStationStatus (std::string stationStatus){
    if (stationStatus == "busy"){
        stationPlace->lock();
        stationIsBusy = true;
    }
    else if (stationStatus == "free"){
        stationIsBusy = false;
        stationPlace->unlock();
    }

}