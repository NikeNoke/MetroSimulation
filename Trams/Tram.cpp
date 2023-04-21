//
// Created by Thomas on 02/03/2023.
//

#include "Tram.h"
#include "../DesignByContract.h"
#include "../Utils/utils.h"

Tram::Tram() {
    _initCheck = this;
    ENSURE(properlyInitialized(), "Tram has not been properly initialized");
}

Tram::Tram(const std::string &beginStation, int snelheid, int lijnNr) : snelheid(snelheid), beginStation(beginStation),
                                                                        lijnNr(lijnNr), huidigStation(beginStation) {
    REQUIRE(!(Utils::is_int(beginStation)), "The parameter beginStation is a number");
    _initCheck = this;
    ENSURE(properlyInitialized(), "Tram has not been properly initialized");
}

std::string Tram::getBeginStation() const {
    return beginStation;
}

int Tram::getSnelheid(){
    return -1;
}

int Tram::getLijnNr() const {
    return lijnNr;
}

std::string Tram::getHuidigStation() const {
    return huidigStation;
}

void Tram::setBeginStation(std::string& bs) {
    REQUIRE(!(Utils::is_int(bs)), "The parameter beginStation is a number");
    beginStation = bs;
    ENSURE(getBeginStation() == bs, "The member beginStation type has not been set properly");
}

void Tram::setSnelheid(int s) {
    snelheid = s;
//    ENSURE(getSnelheid() == s, "The member snelheid type has not been set properly");
}

void Tram::setLijnNr(int l) {
    lijnNr = l;
    ENSURE(getLijnNr() == l, "The member lijnNr type has not been set properly");
}

void Tram::setHuidigStation(std::string& h) {
    REQUIRE(!(Utils::is_int(h)), "The parameter huidigStation is a number");
    huidigStation = h;
    ENSURE(getHuidigStation() == h, "The member huidigStation type has not been set properly");
}

bool Tram::properlyInitialized() {
    return _initCheck == this;
}

void Tram::moveTram(std::string& targetStation) {
    huidigStation = targetStation;
    ENSURE(getHuidigStation() == targetStation, "The member huidigStation type has not been set properly");
}

void Tram::setType(std::string& t) {
    REQUIRE(!(Utils::is_int(t)), "The parameter type is a number");
    type = t;
    ENSURE(getType() == t, "The member variable type has not been set properly");
}

std::string Tram::getType() const {
    return type;
}

void Tram::setVoertuigNummer(int n) {
    voertuigNummer = n;
    ENSURE(getVoertuigNummer() == n, "The member variable voertuigNummer has not been set properly");
}

int Tram::getVoertuigNummer() const {
    return voertuigNummer;
}
