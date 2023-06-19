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

bool Spoor::properlyInitialized() const{
    return _fInitCheck == this;
}

void Spoor::setVolgende(std::string v) {
    REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
    REQUIRE(!(Utils::is_int(v)), "The parameter volgende is a number");
    volgende = v;
    ENSURE(getVolgende() == v, "The member variable volgende has not been properly initialized");
}

void Spoor::setVorige(std::string v) {
    REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
    REQUIRE(!(Utils::is_int(v)), "The parameter vorige is a number");
    vorige = v;
    ENSURE(getVorige() == v, "The member variable vorige has not been properly initialized");
}

void Spoor::setSpoorNr(int s) {
    REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
    spoorNr = s;
    ENSURE(getSpoorNr() == s, "The member variable spoorNr has not been properly initialized");
}

std::string Spoor::getVolgende() const {
    REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
    return volgende;
}

std::string Spoor::getVorige() const {
    REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
    return vorige;
}

int Spoor::getSpoorNr() const {
    REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
    return spoorNr;
}

void Spoor::setHuidig(const std::string &h) {
    REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
    huidig = h;
    ENSURE(getHuiding() == h, "Not set properly");
}

std::string Spoor::getHuiding() const {
    REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
    return huidig;
}

bool Spoor::connectedToStation(const std::string &stationName) const {
    REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
    if (getVolgende() == stationName)
        return true;
    if (getVorige() == stationName)
        return true;

    return false;
}

Spoor::Spoor(const std::string vorige, const std::string volgende, int spoorNr) : volgende(volgende), vorige(vorige),
                                                                                  spoorNr(spoorNr) {
    _fInitCheck = this;
    ENSURE(properlyInitialized(), "The Spoor has not been properly initialized");
}
