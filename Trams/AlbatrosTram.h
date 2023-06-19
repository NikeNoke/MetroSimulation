//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_ALBATROSTRAM_H
#define METROSIMULATION_ALBATROSTRAM_H

#include "BigTram.h"


/**
 * Klasse AlbatrosTram, een sub-klasse van Tram. Deze klasse of type tram heeft attributen die uniek zijn voor
 * dit type van tram specifiek.
 * **/
class AlbatrosTram : public BigTram {
    /**
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
     */
    TramType::TypeTram getType() const;
};


#endif //METROSIMULATION_ALBATROSTRAM_H
