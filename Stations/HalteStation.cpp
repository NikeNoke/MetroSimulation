//
// Created by byamba on 20/04/23.
//

#include "HalteStation.h"
#include "../Spoor/Spoor.h"

TypeStation::StationType HalteStation::getTypeEnum() {
    return TypeStation::Halte;
}

HalteStation::~HalteStation() {
    for (unsigned long int i = 0; i < getSporen().size(); i++) {
        delete getSporen()[i];
    }
}
