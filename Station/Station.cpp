//
// Created by Thomas on 02/03/2023.
//

#include "Station.h"

Station::Station() {}

Station::Station(const std::string &naam,const std::string& volgende,const std::string& vorige, int spoorNr) : naam(naam),
                                                                                                     volgende(volgende),
                                                                                                     vorige(vorige),
                                                                                                     spoorNr(spoorNr) {}

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
    naam = n;
}

void Station::setVolgende(std::string v) {
    volgende = v;
}

void Station::setVorige(std::string v) {
    vorige = v;
}

void Station::setSpoorNr(int s) {
    spoorNr = s;
}
