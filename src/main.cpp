#include <iostream>
#include "train.h"
#include "station.h"
#include <thread>

void trainTraffic (Train & train, Station &station){
    std::string start;
    std::cout << "Type depart to start the train";
    std::cin >> start;
    if (start == "depart"){
        train.setStatus(start,station);
        std::cout << "Train : "<<train.getTrainName() << " depart at the station : " << station.getStationName() <<std::endl;
        while (train.getStatus() != Train::AT_THE_STATION){

            std::this_thread::sleep_for(std::chrono::seconds(1));
            train.addOne_inTimeSpentOnTheRoad();


        }


    }

}

int main() {

    //create 3 busy station
    Station Moscow = *new Station("busy","Moscow");
    Train Moscow_NN = *new Train ("Moscow_NN");
    Station StPetersburg = *new Station("busy","StPetersburg");
    Train StPetersburg_NN = *new Train ("StPetersburg_NN");
    Station Vologda = *new Station("busy","Vologda");
    Train Vologda_NN = *new Train ("Vologda_NN");

    // create finish station
    Station NNovgorod = *new Station("free","NNovgorod");

        std::thread Moscow_NNTrain (trainTraffic,std::ref(Moscow_NN),std::ref(Moscow));

    Moscow_NNTrain.join ();
}