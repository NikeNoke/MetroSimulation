//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_HALTESTATION_H
#define METROSIMULATION_HALTESTATION_H

#include "Station.h"


/**
 * Klasse HalteStation, erft over van Station.
 * **/
class HalteStation : public Station {

public:

    /**
     * Getter functie die het type _HalteStation_ teruggeeft van het Station.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * @return Type van het Station.
     * **/
    TypeStation::StationType getTypeEnum();

    /**
     * Destructor van HalteStation.
     * **/
    ~HalteStation();

};


#endif //METROSIMULATION_HALTESTATION_H
