#include <iostream>
#include "train.h"
#include "station.h"
#include <thread>

void trainTraffic (Train & train, Station &station, Station &arrivalStation, std::mutex &mtx){

    std::string start;
    mtx.lock();
    std::cout << "Train: "<< train.getTrainName() <<". Type depart to start the train :";
    std::cin >> start;
    mtx.unlock();
    if (start == "depart"){
        train.setStatus(station, arrivalStation);
        while (train.getStatus() != Train::AT_THE_STATION){

            std::this_thread::sleep_for(std::chrono::seconds(1));
            if(train.getStatus() != Train::WAITING_FOR_FREE_SPACE){
                train.addOne_inTimeSpentOnTheRoad();
                train.setStatus (station,arrivalStation);
            }
            if (train.getStatus() == Train::WAITING_FOR_FREE_SPACE && !arrivalStation.getStationIsBusy()){
                mtx.lock();
                train.addOne_inTimeSpentOnTheRoad();
                train.setStatus (station,arrivalStation);
                mtx.unlock();
            }
        }
            mtx.lock();
        std::cout << "Train " << train.getTrainName() << " waiting to depart. \nType depart to start the train : "<< std::endl;
        std::cin >> start;
        mtx.unlock();
        if (start == "depart"){
            train.setStatus(station,arrivalStation);
        }
    } else {std::cout << "Train " << train.getTrainName() << " stay at the station : " << station.getStationName()<< std::endl;}
}

int main() {
        std::mutex mtxMain;
    //create 3 busy station
    Station Moscow = *new Station("busy","Moscow");
    Train Moscow_NN = *new Train ("Moscow_NN");
    Station StPetersburg = *new Station("busy","StPetersburg");
    Train StPetersburg_NN = *new Train ("StPetersburg_NN");
    Station Vologda = *new Station("busy","Vologda");
    Train Vologda_NN = *new Train ("Vologda_NN");

    // create finish station
    Station NNovgorod = *new Station("free","NNovgorod");

        std::thread Moscow_NNTrain (trainTraffic,std::ref(Moscow_NN),std::ref(Moscow),std::ref(NNovgorod), std::ref(mtxMain));
        std::thread StPetersburg_NNTrain (trainTraffic,std::ref(StPetersburg_NN),std::ref(StPetersburg),std::ref(NNovgorod),std::ref(mtxMain));
        std::thread Vologda_NNTrain (trainTraffic,std::ref(Vologda_NN),std::ref(Vologda),std::ref(NNovgorod),std::ref(mtxMain));

    Moscow_NNTrain.join ();
    StPetersburg_NNTrain.join();
    Vologda_NNTrain.join();
}