//
// Created by byamba on 20/04/23.
//

#include "PCCTram.h"

void PCCTram::calculateSnelheid() {
    setSnelheid(40);
}

bool PCCTram::stationCanBeServiced(Station *s) {
    if (s->getTypeEnum() == TypeStation::MetroStation)
        return true;
    if (s->getTypeEnum() == TypeStation::Halte)
        return true;
    return false;
}

int PCCTram::getSnelheid() {
    calculateSnelheid();
    return snelheid;
}

int PCCTram::getAantalDefecten() const {
    return aantalDefecten;
}

void PCCTram::setAantalDefecten(int aantal) {
    aantalDefecten = aantal;
}

int PCCTram::getReparatieTijd() const {
    return reparatieTijd;
}

void PCCTram::setReparatieTijd(int aantal) {
    reparatieTijd = aantal;
}

int PCCTram::getReparatieKost() const {
    return reparatieKost;
}

void PCCTram::setReparatieKost(int aantal) {
    reparatieKost = aantal;
}

bool PCCTram::move(Station *station, Exporter &e) {
    return Tram::move(station, e);
}
