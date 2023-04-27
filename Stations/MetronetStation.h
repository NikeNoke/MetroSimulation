//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_METRONETSTATION_H
#define METROSIMULATION_METRONETSTATION_H
#include "./Station.h"

class MetronetStation: public Station{
public:

    TypeStation::StationType getTypeEnum();

    ~MetronetStation();


};


#endif //METROSIMULATION_METRONETSTATION_H
