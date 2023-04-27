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

    int getAantalDefecten() const;

    void setAantalDefecten(int aantal);

    int getReparatieTijd() const;

    void setReparatieTijd(int aantal);

    int getReparatieKost() const;

    void setReparatieKost(int aantal);
};


#endif //METROSIMULATION_STADSLIJNERTRAM_H
