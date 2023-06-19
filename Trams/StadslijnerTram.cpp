//
// Created by byamba on 20/04/23.
//

#include "StadslijnerTram.h"
#include "../DesignByContract.h"

TramType::TypeTram StadslijnerTram::getType() const {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    return TramType::StadsLijner;
}
