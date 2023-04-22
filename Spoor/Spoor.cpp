//
// Created by byamba on 20/04/23.
//

#include "Spoor.h"
#include "../DesignByContract.h"
#include "../Utils/utils.h"

Spoor::Spoor() {
    _fInitCheck = this;
    ENSURE(properlyInitialized(), "The Spoor has not been properly initialized");
}

bool Spoor::properlyInitialized() {
    return _fInitCheck == this;
}

void Spoor::setVolgende(std::string v) {
    REQUIRE(!(Utils::is_int(v)), "The parameter volgende is a number");
    volgende = v;
    ENSURE(getVolgende() == v, "The member variable volgende has not been properly initialized");
}

void Spoor::setVorige(std::string v) {
    REQUIRE(!(Utils::is_int(v)), "The parameter vorige is a number");
    vorige = v;
    ENSURE(getVorige() == v, "The member variable vorige has not been properly initialized");
}

void Spoor::setSpoorNr(int s) {
    //TODO require pos spoornr??
    spoorNr = s;
    ENSURE(getSpoorNr() == s, "The member variable spoorNr has not been properly initialized");
}

std::string Spoor::getVolgende() const {
    return volgende;
}

std::string Spoor::getVorige() const {
    return vorige;
}

int Spoor::getSpoorNr() const {
    return spoorNr;
}

void Spoor::setHuidig(const std::string &h) {
    huidig = h;
}

std::string Spoor::getHuiding() const {
    return huidig;
}

bool Spoor::connectedToStation(const std::string &stationName) const {

    if(getVolgende() == stationName)
        return true;
    if(getVorige() == stationName)
        return true;

    return false;
}
