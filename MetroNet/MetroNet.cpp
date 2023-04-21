#include <iostream>
#include "MetroNet.h"
#include "../Utils/utils.h"
#include "../DesignByContract.h"
#include "../Spoor/Spoor.h"
#include <set>

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
//        if(fTrams[i].lijnNr == name)
//            return true;
//    }
//    return false;
//}

void MetroNet::addStation(Station *const station) {
    REQUIRE(station->properlyInitialized(), "The parameter station is not properly initialized");
    REQUIRE(!stationRegistered(station->getName()), "The station is already in the metroNet");
    fStations.push_back(station);
    ENSURE(stationRegistered(station->getName()), "The station was not successfully added");
}

void MetroNet::addTram(Tram *const tram) {
    REQUIRE(tram->properlyInitialized(), "The parameter tram is not properly initialized");
//    Require not registered
    fTrams.push_back(tram);
    //Ensure registered
}

Station *MetroNet::getStation(const std::string &name) {
    REQUIRE(!(Utils::is_int(name)), "The parameter name is a number");
    REQUIRE(stationRegistered(name), "The station is not Registered!");
    for (long unsigned int i = 0; i < fStations.size(); i++) {
        if (fStations[i]->getName() == name)
            return fStations[i];
    }
    return NULL;
}

//Tram *MetroNet::getTram(std::string &name) {
//    for(int i = 0; i < fTrams.size(); i++){
//        if(fTrams[i].naam == name)
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

//
//bool MetroNet::moveTram(Tram *const tram, const std::string &nameStation) {
//
//    REQUIRE(tram->properlyInitialized(), "The parameter tram is not properly initialized");
//    REQUIRE(!(Utils::is_int(nameStation)), "The parameter nameStation is a number");
//    Station *current = getStation(tram->getHuidigStation());
//
//    if (nameStation != current->getVorige() && nameStation != current->getVolgende()) {
//        std::cerr << "De tram kan niet verplaatst worden naar " << nameStation << "\n";
//        return false;
//    }
//
//    if (nameStation == current->getVorige()) {
//        std::cout << "De tram " << tram->getLijnNr() << " reed van station " << tram->getHuidigStation()
//                  << " naar station " << current->getVorige() << "\n";
//        tram->setHuidigStation(current->getVorige());
//        return true;
//    } else {
//        std::cout << "De tram " << tram->getLijnNr() << " reed van station " << tram->getHuidigStation()
//                  << " naar station " << current->getVolgende() << "\n";
//        tram->setHuidigStation(current->getVolgende());
//        return true;
//    }
//}

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

bool MetroNet::properlyInitialized() const {
    return _fInitCheck == this;
}

bool MetroNet::isValidMetroNet() {

    REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");

    std::vector<Station *> tempStations = this->getStations();
    std::vector<Tram *> tempTrams = this->getTrams();

    for (long unsigned int i = 0; i < tempStations.size(); i++) {
        REQUIRE(tempStations[i]->properlyInitialized(), "A station of the metroNet is not properly initialized");

        if (!controlStation(tempStations[i])) {
            return false;
        };

    }

    for (long unsigned int i = 0; i < tempTrams.size(); i++) {
        REQUIRE(tempTrams[i]->properlyInitialized(), "A tram of the metroNet is not properly initialized");

        if (!controlTram(tempTrams[i])) {
            return false;
        }

    }

    return true;
}

//bool MetroNet::isValidMetroNetSilent() {
//
//    REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
//
//    std::vector<Station *> tempStations = this->getStations();
//    std::vector<Tram *> tempTrams = this->getTrams();
//
//    for (long unsigned int i = 0; i < tempStations.size(); i++) {
//        REQUIRE(tempStations[i]->properlyInitialized(), "A station of the metroNet is not properly initialized");
//        if (!this->stationRegistered(tempStations[i]->getVorige())) {
//            return false;
//        }
//
//        if (!this->stationRegistered(tempStations[i]->getVolgende())) {
//            return false;
//        }
//
//        Station *vorige = this->getStation(tempStations[i]->getVorige());
//        Station *volgende = this->getStation(tempStations[i]->getVolgende());
//
//        if (vorige->getVolgende() != tempStations[i]->getName())
//            return false;
//        if (volgende->getVorige() != tempStations[i]->getName())
//            return false;
//
//        if (tempStations[i]->getSporen() != vorige->getSporen()) {
//            return false;
//        }
//
//        if (tempStations[i]->getSporen() != volgende->getSporen()) {
//            return false;
//        }
//
//        bool spoorHeeftTram = false;
//        for (long unsigned int j = 0; j < tempTrams.size(); j++) {
//            REQUIRE(tempTrams[j]->properlyInitialized(), "A tram of the metroNet is not properly initialized");
//            if (tempStations[i]->getSporen() == tempTrams[j]->getLijnNr()) {
//                spoorHeeftTram = true;
//                break;
//            }
//        }
//
//        if (!spoorHeeftTram) {
//            return false;
//        }
//
//    }
//
//    for (long unsigned int i = 0; i < tempTrams.size(); i++) {
//        REQUIRE(tempTrams[i]->properlyInitialized(), "A tram of the metroNet is not properly initialized");
//        if (!this->stationRegistered(tempTrams[i]->getBeginStation())) {
//            return false;
//        }
//        Station *beginStation = this->getStation(tempTrams[i]->getBeginStation());
//
//        if (beginStation->getSporen() != tempTrams[i]->getLijnNr()) {
//            return false;
//        }
//
//    }
//
//    return true;
//}

//void MetroNet::simulateMetroNet() {
//
//    REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
//
//    std::vector<Tram *> tempTrams = this->getTrams();
//
//    for (unsigned long int j = 0; j < tempTrams.size(); j++) {
//        Station *current = this->getStation(tempTrams[j]->getHuidigStation());
//        REQUIRE(current->properlyInitialized(), "The station to move the tram is not properly initialized");
//        REQUIRE(tempTrams[j]->properlyInitialized(), "The tram to move is not properly initialized");
//        REQUIRE(stationRegistered(current->getName()), "The current station of the tram is not registered");
//
//        REQUIRE(stationRegistered(current->getVolgende()), "The station to move is not registered");
//
//        tempTrams[j]->moveTram(current->getVolgende());
//
//        std::cout << "The tram " << tempTrams[j]->getLijnNr() << " moved from station "
//                  << current->getName() << " to station " << current->getVolgende() << ".\n";
//
//        ENSURE(tempTrams[j]->getHuidigStation() == current->getVolgende(), "The moving of the tram was not successful");
//    }
//}

bool MetroNet::controlStation(Station *station) {

    std::vector<Spoor *> sporen = station->getSporen();

    if (!uniqueSporen(station)) {
        std::cerr << "Sporen in de station " << station->getName() << " is niet uniek\n";
        return false;
    }

    for (unsigned int i = 0; i < sporen.size(); i++) {

        Spoor *current = sporen[i];

        if (!validSpoor(current)) {
            std::cerr << "Spoor is niet correct\n";
            return false;
        }

        if (!spoorHasTram(current)) {
            std::cerr << "Spoor heeft geen tram\n";
            return false;
        }
    }

    return true;

}

bool MetroNet::tramAtStation(const std::string &stationName) {

    std::vector<Tram *> trams = getTrams();

    for (unsigned int i = 0; i < trams.size(); i++) {

        if (trams[i]->getHuidigStation() == stationName)
            return true;
    }

    return false;
}

bool MetroNet::uniqueSporen(Station *s) {

    std::vector<int> spoorNrs;


    for (unsigned int i = 0; i < s->getSporen().size(); i++) {

        spoorNrs.push_back(s->getSporen()[i]->getSpoorNr());

    }

    std::set<int> spoorNrs2(spoorNrs.begin(), spoorNrs.end());

    return spoorNrs.size() == spoorNrs2.size();
}

bool MetroNet::spoorHasTram(Spoor *s) {

    std::vector<Tram *> trams = this->getTrams();

    for (unsigned int i = 0; i < trams.size(); i++) {

        if (trams[i]->getLijnNr() == s->getSpoorNr())
            return true;

    }
    return false;
}

bool MetroNet::tramLineHasSpoor(Tram *t) {

    std::vector<Station*> stations = this->getStations();

    for(unsigned int i = 0; i < stations.size(); i++){

        if(stationHasSpoor(stations[i], t->getLijnNr()))
            return true;

    }
    return false;
}

bool MetroNet::beginStationTramCorrect(Tram *t) {

    std::string beginStation = t->getBeginStation();

    if(!stationRegistered(beginStation)){
        return false;
    }

    Station* bS = this->getStation(beginStation);

    if(!stationHasSpoor(bS, t->getLijnNr())){
        return false;
    }

    return true;
}

bool MetroNet::uniqueTram(Tram *t) {

    std::vector<int> tramVoertuigNrs;

    std::vector<Tram* > trams = this->getTrams();

    for (unsigned int i = 0; i < trams.size(); i++) {

        tramVoertuigNrs.push_back(trams[i]->getVoertuigNummer());

    }

    std::set<int> tramVoertuigNrs2(tramVoertuigNrs.begin(), tramVoertuigNrs.end());

    return tramVoertuigNrs.size() == tramVoertuigNrs2.size();
}

bool MetroNet::validSpoor(Spoor *s) {

    Station* huidigStation = getStation(s->getHuiding());

    if(!stationRegistered(s->getVorige())){
        return false;
    }

    Station* vorigeStation = getStation(s->getVorige());

    if(!stationRegistered(s->getVolgende())){
        return false;
    }

    Station* volgendeStation = getStation(s->getVolgende());

    std::vector<Spoor* > sporenVanHuidige = huidigStation->getSporen();
    std::vector<Spoor* > sporenVanVorige = vorigeStation->getSporen();
    std::vector<Spoor* > sporenVanVolgende = volgendeStation->getSporen();

    for(unsigned int i = 0; i < sporenVanHuidige.size(); i++){

        if(!stationHasSpoor(vorigeStation, sporenVanHuidige[i]->getSpoorNr())){
            return false;
        }

        if(!stationHasSpoor(volgendeStation, sporenVanHuidige[i]->getSpoorNr())){
            return false;
        }

        Spoor* spoorVorige = getSpoor(vorigeStation, s->getSpoorNr());

        if(spoorVorige->getVolgende() != s->getHuiding()){
            return false;
        }

        Spoor* spoorVolgende = getSpoor(volgendeStation, s->getSpoorNr());

        if(spoorVolgende->getVorige() != s->getHuiding()){
            return false;
        }

    }

    return true;
}


bool MetroNet::controlTram(Tram *t) {

    if (!uniqueTram(t)) {
        return false;
    }

    if (!beginStationTramCorrect(t)) {
        return false;
    }

    if (!tramLineHasSpoor(t)) {
        return false;
    }
    return true;
}

bool MetroNet::stationHasSpoor(Station* s ,int nr) {

    std::vector<Spoor* > sporen = s->getSporen();

    for(unsigned int i = 0; i < sporen.size(); i++){

        if(sporen[i]->getSpoorNr() == nr)
            return true;

    }
    return false;
}

Spoor *MetroNet::getSpoor(Station *s, int nr) {

    REQUIRE(stationHasSpoor(s, nr), "Station heeft het spoor zelfs niet!");

    std::vector<Spoor* > sporen = s->getSporen();

    for(unsigned int i = 0; i < sporen.size(); i++){

        if(sporen[i]->getSpoorNr() == nr)
            return sporen[i];

    }
    return NULL;
}
