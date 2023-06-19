//
// Created by byamba on 20/04/23.
//

#include "HalteStation.h"
#include "../Spoor/Spoor.h"
#include "../DesignByContract.h"

TypeStation::StationType HalteStation::getTypeEnum() {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    return TypeStation::Halte;
}

HalteStation::~HalteStation() {
    for (unsigned long int i = 0; i < getSporen().size(); i++) {
        delete getSporen()[i];
    }
}
