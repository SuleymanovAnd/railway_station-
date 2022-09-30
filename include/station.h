#include <iostream>
#include <utility>
#include <mutex>

#pragma once
class Station {

    std::string name;
    bool stationIsBusy;
    std::mutex * stationPlace;
public:

    Station (std::string stationStatus,std::string inName );

    void setStationName (std::string inName);

    std::string getStationName ();

    void setStationStatus (std::string stationStatus);

    bool getStationIsBusy ();

    ~Station() = default;
};
