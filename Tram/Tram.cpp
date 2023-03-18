//
// Created by Thomas on 02/03/2023.
//

#include "Tram.h"

Tram::Tram() {}

Tram::Tram(const std::string &beginStation, int snelheid, int lijnNr) : beginStation(beginStation), snelheid(snelheid),
                                                                        lijnNr(lijnNr), huidigStation(beginStation) {}

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
    beginStation = bs;
}

void Tram::setSnelheid(int s) {
    snelheid = s;
}

void Tram::setLijnNr(int l) {
    lijnNr = l;
}

void Tram::setHuidigStation(std::string h) {
    huidigStation = h;
}
