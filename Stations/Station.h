//
// Created by Thomas on 02/03/2023.
//

#ifndef METROSIMULATION_STATION_H
#define METROSIMULATION_STATION_H

#include <string>
#include <vector>
class Spoor;

namespace TypeStation{

    enum StationType{MetroStation, Halte, Invalid};

}

/**
* Klasse Station. Een station is een object waarover Tram objecten zouden rijden. Station objecten vormen een
* spoornummer, beter gezegd, een lijn in het MetroNet. Stations zijn met elkaar verbonden, elk station heeft een
* volgende station en vorige station.
* **/
class Station {
public:

    /**
     * Default constructor voor Station.
     * @return Een Station object zonder attributen.
     * **/
    Station();

    /**
     * Constructor voor Station.
     * @param naam Naam van het station.
     * @param volgende Het volgende station.
     * @param vorige Het vorige station.
     * @param spoorNr Het nummer van de spoor waar het station deel van is.
     * @return Een Station object met attributen.
     * **/
//    Station(const std::string &naam,const std::string& volgende,const std::string& vorige, int spoorNr);

    /**
     * @return De naam van het station.
     * **/
    std::string getName() const;

    /**
     * @return De sporen
     * **/
    std::vector<Spoor*> getSporen() const;

    /**
     * Set de naam van het station.
     * @param n Naam van het station.
     * **/
    void setName(std::string& n);


    /**
     * Controleert ofdat het station correct is geïnitialiseerd.
     * @return true of false naarmate ofdat het correct is geïnitialiseerd of niet.
     * **/
    bool properlyInitialized();

    void setType(std::string& s);

    std::string getType() const;

    virtual ~Station(){};

    bool addSpoor(Spoor *s);

    virtual TypeStation::StationType getTypeEnum() = 0;

    Spoor* getSpoor(int nr) const;

    bool hasUniqueSporen() const;

    bool hasSpoor(int nr) const;

    bool aSpoorConnectedToStation(const std::string& stationName, int lijnNr) const;

    std::string nextOfSpoor(int lijnNr) const;

    std::string previousOfSpoor(int lijnNr) const;

    int getVisitedByTrams() const;

    void setVisitedByTrams(int amount);

private:

    std::vector<Spoor*> sporen;
    std::string fNaam;
    std::string fType;
    Station* _fInitCheck;

    int visitedByTrams;
};


#endif //METROSIMULATION_STATION_H
