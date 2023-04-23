//
// Created by byamba on 20/04/23.
//

#include "AlbatrosTram.h"

void AlbatrosTram::test() const {
    this->getType();
}

void AlbatrosTram::calculateSnelheid() {
    setSnelheid(70);
}

bool AlbatrosTram::stationCanBeServiced(Station *s) {
    if(s->getTypeEnum() == TypeStation::MetroStation)
        return true;
    return false;
}

int AlbatrosTram::getSnelheid() {
    calculateSnelheid();
    return snelheid;
}

int AlbatrosTram::getAantalDefecten() const {
    return 0;
}

void AlbatrosTram::setAantalDefecten(int aantal) {
    aantalDefecten = 0;
}

int AlbatrosTram::getReparatieTijd() const {
    return 0;
}

void AlbatrosTram::setReparatieTijd(int aantal) {
    reparatieTijd = 0;
}

int AlbatrosTram::getReparatieKost() const {
    return 0;
}

void AlbatrosTram::setReparatieKost(int aantal) {
    reparatieKost = 0;
}
