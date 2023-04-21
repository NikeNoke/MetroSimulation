//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_PCCTRAM_H
#define METROSIMULATION_PCCTRAM_H
#include "Tram.h"

class PCCTram: public Tram {
public:
    void calculateSnelheid();

    bool stationCanBeServiced(Station *s);

    int getSnelheid();

    ~PCCTram(){};
};


#endif //METROSIMULATION_PCCTRAM_H
