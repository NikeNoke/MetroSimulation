//
// Created by Thomas on 02/03/2023.
//

#include "Tram.h"
#include "../DesignByContract.h"
#include "../Utils/utils.h"

Tram::Tram() {
    _initCheck = this;
}

Tram::Tram(const std::string &beginStation, int snelheid, int lijnNr) : beginStation(beginStation), snelheid(snelheid),
                                                                        lijnNr(lijnNr), huidigStation(beginStation) {
    REQUIRE(!(Utils::is_int(beginStation)), "The parameter beginStation is a number");
    _initCheck = this;
}

std::string Tram::getBeginStation() const {
    return beginStation;
}

int Tram::getSnelheid() const {
    return snelheid;
}

int Tram::getLijnNr() const {
    return lijnNr;
}

std::string Tram::getHuidigStation() const {
    return huidigStation;
}

void Tram::setBeginStation(std::string bs) {
    REQUIRE(!(Utils::is_int(bs)), "The parameter beginStation is a number");
    beginStation = bs;
}

void Tram::setSnelheid(int s) {
    snelheid = s;
}

void Tram::setLijnNr(int l) {
    lijnNr = l;
}

void Tram::setHuidigStation(std::string h) {
    REQUIRE(!(Utils::is_int(h)), "The parameter huidigStation is a number");
    huidigStation = h;
}

bool Tram::properlyInitialized() {
    return _initCheck == this;
}

void Tram::moveTram(std::string targetStation) {
    huidigStation = targetStation;
}
