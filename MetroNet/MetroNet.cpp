#include <iostream>
#include "MetroNet.h"
#include "../Utils/utils.h"
#include "../DesignByContract.h"

bool MetroNet::stationRegistered(const std::string &name) const {
    REQUIRE(!(Utils::is_int(name)), "The parameter name is a number");
    for (long unsigned int i = 0; i < fStations.size(); i++) {
        if (fStations[i]->getName() == name)
            return true;
    }
    return false;
}

//bool MetroNet::tramRegistered(std::string &name) const { //
//    for(int i = 0; i < fTrams.size(); i++){
//        if(fTrams[i].fLijnNr == name)
//            return true;
//    }
//    return false;
//}

void MetroNet::addStation(Station *const station) {
    REQUIRE(station->properlyInitialized(), "The parameter station is not properly initialized");
    fStations.push_back(station);
}

void MetroNet::addTram(Tram *const tram) {
    REQUIRE(tram->properlyInitialized(), "The parameter tram is not properly initialized");
    fTrams.push_back(tram);
}

Station *MetroNet::getStation(const std::string &name) {
    REQUIRE(!(Utils::is_int(name)), "The parameter name is a number");
    for (long unsigned int i = 0; i < fStations.size(); i++) {
        if (fStations[i]->getName() == name)
            return fStations[i];
    }
    return NULL;
}

//Tram *MetroNet::getTram(std::string &name) {
//    for(int i = 0; i < fTrams.size(); i++){
//        if(fTrams[i].fNaam == name)
//            return &fTrams[i];
//    }
//    return NULL;
//}

std::vector<Station *> MetroNet::getStations() {
    return fStations;
}

std::vector<Tram *> MetroNet::getTrams() {
    return fTrams;
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
    for (unsigned long int i = 0; i < fStations.size(); i++) {
        delete fStations[i];
    }
    for (unsigned long int i = 0; i < fTrams.size(); i++) {
        delete fTrams[i];
    }
}

MetroNet::MetroNet() {
    _fInitCheck = this;
}

bool MetroNet::properlyInitialized() {
    return _fInitCheck == this;
}


