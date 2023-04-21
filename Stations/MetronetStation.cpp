//
// Created by byamba on 20/04/23.
//

#include "MetronetStation.h"
#include "../Spoor/Spoor.h"

TypeStation::StationType MetronetStation::getTypeEnum() {
    return TypeStation::MetroStation;
}

MetronetStation::~MetronetStation() {
    for (unsigned long int i = 0; i < getSporen().size(); i++) {
        delete getSporen()[i];
    }
}
