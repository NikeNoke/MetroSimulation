//
// Created by Thomas on 02/03/2023.
//

#include "Station.h"
#include "../DesignByContract.h"
#include "../Utils/utils.h"

Station::Station() {
    _initCheck = this;
}

Station::Station(const std::string &naam,const std::string& volgende,const std::string& vorige, int spoorNr) : naam(naam),
                                                                                                     volgende(volgende),
                                                                                                     vorige(vorige),
                                                                                                     spoorNr(spoorNr) {
    REQUIRE(!(Utils::is_int(naam)), "The parameter naam is a number");
    REQUIRE(!(Utils::is_int(volgende)), "The parameter volgende is a number");
    REQUIRE(!(Utils::is_int(vorige)), "The parameter vorige is a number");
    _initCheck = this;
}

std::string Station::getName() const {
    return naam;
}

std::string Station::getVolgende() const {
    return volgende;
}

std::string Station::getVorige() const {
    return vorige;
}

int Station::getSpoorNr() const {
    return spoorNr;
}

void Station::setName(std::string n) {
    REQUIRE(!(Utils::is_int(n)), "The parameter naam is a number");
    naam = n;
}

void Station::setVolgende(std::string v) {
    REQUIRE(!(Utils::is_int(v)), "The parameter volgende is a number");
    volgende = v;
}

void Station::setVorige(std::string v) {
    REQUIRE(!(Utils::is_int(v)), "The parameter vorige is a number");
    vorige = v;
}

void Station::setSpoorNr(int s) {
    spoorNr = s;
}

bool Station::properlyInitialized() {
    return _initCheck == this;
}
