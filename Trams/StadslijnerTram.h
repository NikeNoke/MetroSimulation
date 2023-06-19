//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_STADSLIJNERTRAM_H
#define METROSIMULATION_STADSLIJNERTRAM_H

#include "BigTram.h"

/**
 * Klasse StadslijnerTram, een sub-klasse van Tram. Deze klasse of type tram heeft attributen die uniek zijn voor
 * dit type van tram specifiek.
 * **/
class StadslijnerTram : public BigTram {
    /**
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
     */
    TramType::TypeTram getType() const;
};


#endif //METROSIMULATION_STADSLIJNERTRAM_H
