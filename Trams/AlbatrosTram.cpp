//
// Created by byamba on 20/04/23.
//

#include "AlbatrosTram.h"
#include "../DesignByContract.h"

TramType::TypeTram AlbatrosTram::getType() const {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    return TramType::Albatros;
}
