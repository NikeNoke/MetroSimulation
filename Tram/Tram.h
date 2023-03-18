//
// Created by Thomas on 02/03/2023.
//

#ifndef METROSIMULATION_TRAM_H
#define METROSIMULATION_TRAM_H

#include <string>

class Tram {
public:

    Tram();

    Tram(const std::string &beginStation, int snelheid, int lijnNr);

    std::string getBeginStation() const;

    int getSnelheid() const;

    int getLijnNr() const;

    std::string getHuidigStation() const;

    void setBeginStation(std::string bs);

    void setSnelheid(int s);

    void setLijnNr(int l);

    void setHuidigStation(std::string h);

    bool properlyInitialized();

private:
    std::string beginStation;
    int snelheid;
    int lijnNr;
    std::string huidigStation;
    Tram* _initCheck;
};


#endif //METROSIMULATION_TRAM_H
