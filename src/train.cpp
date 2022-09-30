#include "train.h"

void Train::setTravelTime (int time){
    travelTime = time;
}

std::string Train::getTrainName (){
    return trainName;
}

int Train::getTravelTime (){
    return travelTime;
}

void Train::addOne_inTimeSpentOnTheRoad (){
    timeSpentOnTheRoad ++;
}

Train::Train (std::string name){
    trainName = name;
    int inTravelTime;
    std::cout << trainName << ". Enter travel time: ";
    std::cin >> inTravelTime;
    setTravelTime(inTravelTime);
}


void Train::setStatus ( Station &departStation, Station &arrivalStation) {
    if(trainStatus == AT_THE_STATION){
        trainStatus = DEPART;
        std::cout << "Train : "<< getTrainName() << " depart at the station : " << arrivalStation.getStationName() <<std::endl;
        arrivalStation.setStationStatus ("free");
    }else {

        if ( timeSpentOnTheRoad < 1) {
            trainStatus = DEPART;
            std::cout << "Train : "<< getTrainName() << " depart at the station : " << departStation.getStationName() <<std::endl;
        }
        if (timeSpentOnTheRoad == 1){
            trainStatus = TRAVEL;
            std::cout << "Train : "<< getTrainName() << "  in Travel ! " <<std::endl;
        }
        if (timeSpentOnTheRoad == travelTime - 2 && arrivalStation.getStationIsBusy()) {
            trainStatus = WAITING_FOR_FREE_SPACE;
            std::cout << "Train : "<< getTrainName() << " waiting for free space in station : " << arrivalStation.getStationName() <<std::endl;
        }
        if (timeSpentOnTheRoad == travelTime - 1 && !arrivalStation.getStationIsBusy()) {
            trainStatus = ARRIVAL;
            std::cout << "Train : "<< getTrainName() << " arrival in the station : " << arrivalStation.getStationName() <<std::endl;
            arrivalStation.setStationStatus("busy");
        }
        if (timeSpentOnTheRoad == travelTime) {
            trainStatus = AT_THE_STATION;
            std::cout << "Train : "<< getTrainName() << " at the station : " << arrivalStation.getStationName() <<std::endl;
        }
    }

}

Train::status Train::getStatus (){
    return trainStatus;
}
