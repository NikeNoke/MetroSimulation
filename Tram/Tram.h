//
// Created by Thomas on 02/03/2023.
//

#ifndef METROSIMULATION_TRAM_H
#define METROSIMULATION_TRAM_H

#include <string>

class Tram {
public:
    std::string beginStation;
    int snelheid;
    int lijnNr;
    std::string huidigStation;

    Tram();

    Tram(const std::string &beginStation, int snelheid, int lijnNr);
};


#endif //METROSIMULATION_TRAM_H
