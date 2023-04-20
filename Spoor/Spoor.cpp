//
// Created by byamba on 20/04/23.
//

#include "Spoor.h"
#include "../DesignByContract.h"

Spoor::Spoor() {
    _fInitCheck = this;
    ENSURE(properlyInitialized(), "The Spoor has not been properly initialized");
}

bool Spoor::properlyInitialized() {
    return _fInitCheck == this;
}
