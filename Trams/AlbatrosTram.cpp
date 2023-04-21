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
