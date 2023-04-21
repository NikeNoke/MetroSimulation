//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_STADSLIJNERTRAM_H
#define METROSIMULATION_STADSLIJNERTRAM_H
#include "Tram.h"

class StadslijnerTram: public Tram {
public:
    void calculateSnelheid();

    bool stationCanBeServiced(Station *s);

    int getSnelheid();

    ~StadslijnerTram(){};
};


#endif //METROSIMULATION_STADSLIJNERTRAM_H
