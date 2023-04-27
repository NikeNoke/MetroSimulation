//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_HALTESTATION_H
#define METROSIMULATION_HALTESTATION_H
#include "Station.h"

class HalteStation: public Station{

public:

    TypeStation::StationType getTypeEnum();

    ~HalteStation();

};


#endif //METROSIMULATION_HALTESTATION_H
