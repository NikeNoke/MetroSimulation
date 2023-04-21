//
// Created by byamba on 20/04/23.
//

#include "StadslijnerTram.h"

void StadslijnerTram::calculateSnelheid() {
    setSnelheid(70);
}

bool StadslijnerTram::stationCanBeServiced(Station *s) {
    if(s->getTypeEnum() == TypeStation::MetroStation)
        return true;
    return false;
}

int StadslijnerTram::getSnelheid() {
    calculateSnelheid();
    return snelheid;
}
