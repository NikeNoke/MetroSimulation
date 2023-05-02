//
// Created by byamba on 20/04/23.
//

#include "StadslijnerTram.h"

void StadslijnerTram::calculateSnelheid() {
    setSnelheid(70);
}

bool StadslijnerTram::stationCanBeServiced(Station *s) {
    if (s->getTypeEnum() == TypeStation::MetroStation)
        return true;
    return false;
}

int StadslijnerTram::getSnelheid() {
    calculateSnelheid();
    return snelheid;
}

int StadslijnerTram::getAantalDefecten() const {
    return 0;
}

void StadslijnerTram::setAantalDefecten(int aantal) {
    aantalDefecten = 0;
}

int StadslijnerTram::getReparatieTijd() const {
    return 0;
}

void StadslijnerTram::setReparatieTijd(int aantal) {
    reparatieTijd = aantal;
}

int StadslijnerTram::getReparatieKost() const {
    return 0;
}

void StadslijnerTram::setReparatieKost(int aantal) {
    reparatieKost = aantal;
}
