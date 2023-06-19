//
// Created by byamba on 20/04/23.
//

#include "MetronetStation.h"
#include "../Spoor/Spoor.h"
#include "../DesignByContract.h"

TypeStation::StationType MetronetStation::getTypeEnum() {
    REQUIRE(properlyInitialized(), "The station is not properly initialized");
    return TypeStation::MetroStation;
}

MetronetStation::~MetronetStation() {
    for (unsigned long int i = 0; i < getSporen().size(); i++) {
        delete getSporen()[i];
    }
}
