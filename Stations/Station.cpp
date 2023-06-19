//
// Created by Thomas on 02/03/2023.
//

#include <set>
#include "Station.h"
#include "../DesignByContract.h"
#include "../Utils/utils.h"
#include "../Spoor/Spoor.h"

Station::Station() {
    _fInitCheck = this;
    visitedByTrams = 0;
    ENSURE(properlyInitialized(), "Must be proerly initialized");
}

//Station::Station(const std::string &naam,const std::string& volgende,const std::string& vorige, int spoorNr) : fNaam(naam),
//                                                                                                               fVolgende(volgende),
//                                                                                                               fVorige(vorige),
//                                                                                                               fSpoorNr(spoorNr) {
//    REQUIRE(!(Utils::is_int(naam)), "The parameter naam is a number");
//    REQUIRE(!(Utils::is_int(volgende)), "The parameter volgende is a number");
//    REQUIRE(!(Utils::is_int(vorige)), "The parameter vorige is a number");
//    _fInitCheck = this;
//}

std::string Station::getName() const {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    return fNaam;
}

//std::string Station::getVolgende() const {
//    return fVolgende;
//}
//
//std::string Station::getVorige() const {
//    return fVorige;
//}

std::vector<Spoor *> Station::getSporen() const {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    return sporen;
}

void Station::setName(std::string n) {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    REQUIRE(!(Utils::is_int(n)), "The parameter naam is a number");
    fNaam = n;
    ENSURE(getName() == n, "The member variable naam has not been properly initialized");
}

bool Station::properlyInitialized() const{
    return _fInitCheck == this;
}

void Station::setType(std::string s) {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    REQUIRE(!(Utils::is_int(s)), "The parameter type is a number");
    REQUIRE(s == "Metrostation" || s == "Halte", "Type of Station is an invalid type.");
    fType = s;
    ENSURE(getType() == s, "The member variable type has not been properly initialized");
}

std::string Station::getType() const {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    return fType;
}

bool Station::addSpoor(Spoor *s) {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    if (getType() == "Metrostation")
        sporen.push_back(s);
    else if (getType() == "Halte") {
        if (sporen.size() >= 1)
            return false;
        sporen.push_back(s);
    }
    ENSURE(hasSpoor(s->getSpoorNr()), "Spoor has not been added");
    return true;
}

Spoor *Station::getSpoor(int nr) const {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    for (unsigned int i = 0; i < sporen.size(); i++) {

        if (sporen[i]->getSpoorNr() == nr)
            return sporen[i];

    }
    return NULL;
}

bool Station::hasUniqueSporen() const {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    std::vector<int> spoorNrs;


    for (unsigned int i = 0; i < this->getSporen().size(); i++) {

        spoorNrs.push_back(this->getSporen()[i]->getSpoorNr());

    }

    std::set<int> spoorNrs2(spoorNrs.begin(), spoorNrs.end());

    return spoorNrs.size() == spoorNrs2.size();
}

bool Station::hasSpoor(int nr) const {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    for (unsigned int i = 0; i < sporen.size(); i++) {

        if (sporen[i]->getSpoorNr() == nr)
            return true;

    }
    return false;
}

bool Station::aSpoorConnectedToStation(const std::string &stationName, int lijnNr) const {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    std::vector<Spoor *> tempSporen = this->getSporen();

    for (unsigned int i = 0; i < tempSporen.size(); i++) {

        if (tempSporen[i]->getSpoorNr() != lijnNr)
            continue;

        if (tempSporen[i]->connectedToStation(stationName))
            return true;

    }
    return false;
}

std::string Station::nextOfSpoor(int lijnNr) const {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    std::vector<Spoor *> tempSporen = this->getSporen();

    for (unsigned int i = 0; i < tempSporen.size(); i++) {

        if (tempSporen[i]->getSpoorNr() != lijnNr)
            continue;

        REQUIRE(tempSporen[i]->getHuiding() == getName(), "Spoor in station is wrong");
        return tempSporen[i]->getVolgende();

    }
    return "";
}

std::string Station::previousOfSpoor(int lijnNr) const {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    std::vector<Spoor *> tempSporen = this->getSporen();

    for (unsigned int i = 0; i < tempSporen.size(); i++) {

        if (tempSporen[i]->getSpoorNr() != lijnNr)
            continue;

        REQUIRE(tempSporen[i]->getHuiding() == getName(), "Spoor in station is wrong");
        return tempSporen[i]->getVorige();

    }
    return "";
}

int Station::getVisitedByTrams() const {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    return visitedByTrams;
}

void Station::setVisitedByTrams(int amount) {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    visitedByTrams = amount;
    ENSURE(getVisitedByTrams() == amount, "The setting was not successful");
}
