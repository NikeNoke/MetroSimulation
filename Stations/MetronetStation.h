//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_METRONETSTATION_H
#define METROSIMULATION_METRONETSTATION_H
#include "./Station.h"

/**
 * Klasse MetronetStation, erft over van Station.
 * **/
class MetronetStation: public Station{
public:

    /**
     * Getter functie dat het type _MetronetStation_ van de Station teruggeeft.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * @return Type van het Station.
     * **/
    TypeStation::StationType getTypeEnum();

    /**
     * Destructor van MetronetStation.
     * */
    ~MetronetStation();


};


#endif //METROSIMULATION_METRONETSTATION_H
