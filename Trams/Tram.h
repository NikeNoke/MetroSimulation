//
// Created by Thomas on 02/03/2023.
//

#ifndef METROSIMULATION_TRAM_H
#define METROSIMULATION_TRAM_H

#include <string>
#include "../Stations/Station.h"
namespace TramType{

    enum TypeTram {PCC, StadsLijner, Albatros, InvalidTram};

}

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
     * @param snelheid De snelheid dat deze type tram kan halen.
     * @return Een tram object met attributen
     * @note Type van trammen is nog niet geïmplementeerd. Snelheid is ook nutteloos op dit moment omdat we geen
     * afstand hebben waarover we de snelheid kunnen gebruiken. Verdere aanpassingen nodig.
     * **/
    Tram(const std::string &beginStation, int snelheid, int lijnNr);

    /**
     * @return De beginstation van een tram.
     * **/
    std::string getBeginStation() const;

    /**
     * @return De snelheid van een tram.
     * **/
    virtual int getSnelheid();

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
     * @param bs De naam van het beginstation van een tram.
     * **/
    void setBeginStation(std::string& bs);

    /**
     * Zet voor een tram object zijn snelheid
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
    void setHuidigStation(std::string& h);

    /**
     * Controleerd ofdat de tram object correct geïnitialiseerd is.
     * @return true of false afhankelijk ofdat de tram object correct geïnitialiseerd is of niet.
     * **/
    bool properlyInitialized();

    bool move(Station* station);

    void setType(std::string& type);

    std::string getType() const;

    void setVoertuigNummer(int n);

    int getVoertuigNummer() const;

    virtual void calculateSnelheid() = 0;

    virtual bool stationCanBeServiced(Station* s) = 0;

    virtual ~Tram(){};

protected:
    int snelheid;

private:
    std::string beginStation;
    int lijnNr;
    std::string huidigStation;
    std::string type; //TODO make enum
    int voertuigNummer;
    Tram* _initCheck;
};


#endif //METROSIMULATION_TRAM_H
