//
// Created by byamba on 20/04/23.
//

#include "PCCTram.h"

void PCCTram::calculateSnelheid() {
    setSnelheid(40);
}

bool PCCTram::stationCanBeServiced(Station *s) {
    if(s->getTypeEnum() == TypeStation::MetroStation)
        return true;
    if(s->getTypeEnum() == TypeStation::Halte)
        return true;
    return false;
}

int PCCTram::getSnelheid() {
    calculateSnelheid();
    return snelheid;
}
