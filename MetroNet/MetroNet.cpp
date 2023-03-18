#include <iostream>
#include "MetroNet.h"
#include "../Utils/utils.h"
#include "../DesignByContract.h"

bool MetroNet::stationRegistered(const std::string &name) const {
    REQUIRE(!(Utils::is_int(name)), "The parameter name is a number");
    for (long unsigned int i = 0; i < stations.size(); i++) {
        if (stations[i]->getName() == name)
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

void MetroNet::addStation(Station *const station) {
    REQUIRE(station->properlyInitialized(), "The parameter station is not properly initialized");
    stations.push_back(station);
}

void MetroNet::addTram(Tram *const tram) {
    REQUIRE(tram->properlyInitialized(), "The parameter tram is not properly initialized");
    trams.push_back(tram);
}

Station *MetroNet::getStation(const std::string &name) {
    REQUIRE(!(Utils::is_int(name)), "The parameter name is a number");
    for (long unsigned int i = 0; i < stations.size(); i++) {
        if (stations[i]->getName() == name)
            return stations[i];
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

std::vector<Station *> MetroNet::getStations() {
    return stations;
}

std::vector<Tram *> MetroNet::getTrams() {
    return trams;
}


bool MetroNet::moveTram(Tram *const tram, const std::string &nameStation) {

    REQUIRE(tram->properlyInitialized(), "The parameter tram is not properly initialized");
    REQUIRE(!(Utils::is_int(nameStation)), "The parameter nameStation is a number");
    Station *current = getStation(tram->getHuidigStation());

    if (nameStation != current->getVorige() && nameStation != current->getVolgende()) {
        std::cerr << "De tram kan niet verplaatst worden naar " << nameStation << "\n";
        return false;
    }

    if (nameStation == current->getVorige()) {
        std::cout << "De tram " << tram->getLijnNr() << " reed van station " << tram->getHuidigStation()
                  << " naar station " << current->getVorige() << "\n";
        tram->setHuidigStation(current->getVorige());
        return true;
    } else {
        std::cout << "De tram " << tram->getLijnNr() << " reed van station " << tram->getHuidigStation()
                  << " naar station " << current->getVolgende() << "\n";
        tram->setHuidigStation(current->getVolgende());
        return true;
    }
}

MetroNet::~MetroNet() {
    for (unsigned long int i = 0; i < stations.size(); i++) {
        delete stations[i];
    }
    for (unsigned long int i = 0; i < trams.size(); i++) {
        delete trams[i];
    }
}

MetroNet::MetroNet() {
    _initCheck = this;
}

bool MetroNet::properlyInitialized() {
    return _initCheck == this;
}


