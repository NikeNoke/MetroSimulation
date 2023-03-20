//
// Created by Thomas on 02/03/2023.
//

#include "Station.h"
#include "../DesignByContract.h"
#include "../Utils/utils.h"

Station::Station() {
    _fInitCheck = this;
}

Station::Station(const std::string &naam,const std::string& volgende,const std::string& vorige, int spoorNr) : fNaam(naam),
                                                                                                               fVolgende(volgende),
                                                                                                               fVorige(vorige),
                                                                                                               fSpoorNr(spoorNr) {
    REQUIRE(!(Utils::is_int(naam)), "The parameter fNaam is a number");
    REQUIRE(!(Utils::is_int(volgende)), "The parameter fVolgende is a number");
    REQUIRE(!(Utils::is_int(vorige)), "The parameter fVorige is a number");
    _fInitCheck = this;
}

std::string Station::getName() const {
    return fNaam;
}

std::string Station::getVolgende() const {
    return fVolgende;
}

std::string Station::getVorige() const {
    return fVorige;
}

int Station::getSpoorNr() const {
    return fSpoorNr;
}

void Station::setName(std::string n) {
    REQUIRE(!(Utils::is_int(n)), "The parameter fNaam is a number");
    fNaam = n;
}

void Station::setVolgende(std::string v) {
    REQUIRE(!(Utils::is_int(v)), "The parameter fVolgende is a number");
    fVolgende = v;
}

void Station::setVorige(std::string v) {
    REQUIRE(!(Utils::is_int(v)), "The parameter fVorige is a number");
    fVorige = v;
}

void Station::setSpoorNr(int s) {
    fSpoorNr = s;
}

bool Station::properlyInitialized() {
    return _fInitCheck == this;
}
