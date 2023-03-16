#include <iostream>
#include "MetroNet.h"


bool MetroNet::stationRegistered(std::string &name) const {
    for (long unsigned int i = 0; i < stations.size(); i++) {
        if (stations[i].naam == name)
            return true;
    }
    return false;
}

//bool MetroNet::tramRegistered(std::string &name) const { //
//    for(int i = 0; i < trams.size(); i++){
//        if(trams[i].lijnNr == name)
//            return true;
//    }
//    return false;
//}

void MetroNet::addStation(Station &station) {
    stations.push_back(station);
}

void MetroNet::addTram(Tram &tram) {
    trams.push_back(tram);
}

Station *MetroNet::getStation(std::string &name) {
    for (long unsigned int i = 0; i < stations.size(); i++) {
        if (stations[i].naam == name)
            return &stations[i];
    }
    return NULL;
}

//Tram *MetroNet::getTram(std::string &name) {
//    for(int i = 0; i < trams.size(); i++){
//        if(trams[i].naam == name)
//            return &trams[i];
//    }
//    return NULL;
//}

std::vector<Station> &MetroNet::getStations() {
    return stations;
}

std::vector<Tram> &MetroNet::getTrams() {
    return trams;
}

bool MetroNet::moveTram(Tram &tram, std::string &nameStation) {

    Station *current = getStation(tram.huidigStation);

    if (nameStation != current->vorige && nameStation != current->volgende) {
        std::cerr << "De tram kan niet verplaatst worden naar " << nameStation << "\n";
        return false;
    }

    if (nameStation == current->vorige) {
        std::cerr << "De tram " << tram.lijnNr << "reed van station " << tram.huidigStation << "naar station " << current->vorige << "\n";
        tram.huidigStation = current->vorige;
        return true;
    }

    else{
        std::cerr << "De tram " << tram.lijnNr << "reed van station " << tram.huidigStation << "naar station " << current->volgende << "\n";
        tram.huidigStation = current->volgende;
        return true;
    }

}
