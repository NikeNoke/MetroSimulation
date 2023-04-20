//
// Created by Thomas on 02/03/2023.
//

#ifndef METROSIMULATION_TRAM_H
#define METROSIMULATION_TRAM_H

#include <string>
/**
* Klasse Tram. Een tram object is een object dat in een MetroNet zal zijn.
* **/
class Tram {
public:

    /**
     * Default constructor van een tram object.
     * @return Een tram object zonder attributen.
     * **/
    Tram();

    /**
     * Constructor van een tram object.
     * @param beginStation De beginstation waarin de tram zich bevindt.
     * @param lijnNr Het nummer van de lijn, komt overeen met spoornummer van een station.
     * @param snelheid De fSnelheid dat deze type tram kan halen.
     * @return Een tram object met attributen
     * @note Type van trammen is nog niet geïmplementeerd. Snelheid is ook nutteloos op dit moment omdat we geen
     * afstand hebben waarover we de fSnelheid kunnen gebruiken. Verdere aanpassingen nodig.
     * **/
    Tram(const std::string &beginStation, int snelheid, int lijnNr);

    /**
     * @return De beginstation van een tram.
     * **/
    std::string getBeginStation() const;

    /**
     * @return De fSnelheid van een tram.
     * **/
    int getSnelheid() const;

    /**
     * @return Het lijnnummer van een tram.
     * **/
    int getLijnNr() const;


    /**
     * @return Huidig station waarin de tram zich bevindt.
     * **/
    std::string getHuidigStation() const;

    /**
     * Zet voor een tram object zijn beginstation.
     * @param bs De fNaam van het beginstation van een tram.
     * **/
    void setBeginStation(std::string bs);

    /**
     * Zet voor een tram object zijn fSnelheid
     * @param s Snelheid van een tram.
     * **/
    void setSnelheid(int s);

    /**
     * Zet voor een tram object zijn lijnnummer.
     * @param l Lijnnummer van een tram.
     * **/
    void setLijnNr(int l);

    /**
     * Zet voor een tram het huidige station.
     * @param h Het huidig station van een tram.
     * **/
    void setHuidigStation(std::string h);

    /**
     * Controleerd ofdat de tram object correct geïnitialiseerd is.
     * @return true of false afhankelijk ofdat de tram object correct geïnitialiseerd is of niet.
     * **/
    bool properlyInitialized();

    void moveTram(std::string targetStation);

private:
    std::string fBeginStation;
    int fSnelheid;
    int fLijnNr;
    std::string fHuidigStation;
    Tram* _fInitCheck;
};


#endif //METROSIMULATION_TRAM_H
