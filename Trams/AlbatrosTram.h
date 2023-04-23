//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_ALBATROSTRAM_H
#define METROSIMULATION_ALBATROSTRAM_H
#include "Tram.h"

class AlbatrosTram: public Tram{
public:
    void test() const;

    void calculateSnelheid();

    bool stationCanBeServiced(Station *s);

    int getSnelheid();

    ~AlbatrosTram(){};

    int getAantalDefecten() const;

    void setAantalDefecten(int aantal);

    int getReparatieTijd() const;

    void setReparatieTijd(int aantal);

    int getReparatieKost() const;

    void setReparatieKost(int aantal);
};


#endif //METROSIMULATION_ALBATROSTRAM_H
