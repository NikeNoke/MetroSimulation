//
// Created by Thomas on 02/03/2023.
//

#include "Tram.h"
#include "../DesignByContract.h"
#include "../Utils/utils.h"

Tram::Tram() {
    _fInitCheck = this;
}

Tram::Tram(const std::string &beginStation, int snelheid, int lijnNr) : fBeginStation(beginStation), fSnelheid(snelheid),
                                                                        fLijnNr(lijnNr), fHuidigStation(beginStation) {
    REQUIRE(!(Utils::is_int(beginStation)), "The parameter fBeginStation is a number");
    _fInitCheck = this;
}

std::string Tram::getBeginStation() const {
    return fBeginStation;
}

int Tram::getSnelheid() const {
    return fSnelheid;
}

int Tram::getLijnNr() const {
    return fLijnNr;
}

std::string Tram::getHuidigStation() const {
    return fHuidigStation;
}

void Tram::setBeginStation(std::string bs) {
    REQUIRE(!(Utils::is_int(bs)), "The parameter fBeginStation is a number");
    fBeginStation = bs;
}

void Tram::setSnelheid(int s) {
    fSnelheid = s;
}

void Tram::setLijnNr(int l) {
    fLijnNr = l;
}

void Tram::setHuidigStation(std::string h) {
    REQUIRE(!(Utils::is_int(h)), "The parameter fHuidigStation is a number");
    fHuidigStation = h;
}

bool Tram::properlyInitialized() {
    return _fInitCheck == this;
}

void Tram::moveTram(std::string targetStation) {
    huidigStation = targetStation;
}
