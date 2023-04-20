//
// Created by Thomas on 02/03/2023.
//

#ifndef METROSIMULATION_STATION_H
#define METROSIMULATION_STATION_H

#include <string>
#include <vector>
class Spoor;
/**
* Klasse Station. Een station is een object waarover Tram objecten zouden rijden. Station objecten vormen een
* spoornummer, beter gezegd, een lijn in het MetroNet. Stations zijn met elkaar verbonden, elk station heeft een
* fVolgende station en fVorige station.
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
     * @param volgende Het fVolgende station.
     * @param vorige Het fVorige station.
     * @param spoorNr Het nummer van de spoor waar het station deel van is.
     * @return Een Station object met attributen.
     * **/
//    Station(const std::string &naam,const std::string& volgende,const std::string& vorige, int spoorNr);

    /**
     * @return De fNaam van het station.
     * **/
    std::string getName() const;

    /**
     * @return De fNaam van het fVolgende station.
     * **/
    std::string getVolgende() const;

    /**
     * @return De fNaam van het fVorige station.
     * **/
    std::string getVorige() const;

    /**
     * @return De sporen
     * **/
    std::vector<Spoor*> getSpoorNr() const;

    /**
     * Set de fNaam van het station.
     * @param n Naam van het station.
     * **/
    void setName(std::string n);

    /**
    * Set de fNaam van het station.
     * @param v Naam van het fVolgende station.
    * **/
    void setVolgende(std::string v);

    /**
    * Set de fNaam van het station fVorige station.
     * @param v Naam van het fVorige station.
    * **/
    void setVorige(std::string v);

    /**
    * Set het spoornummer van het station.
    * @param s Spoornummer waar het station deel van is.
     * **/
    void setSpoorNr(int s);

    /**
     * Controleert ofdat het station correct is geïnitialiseerd.
     * @return true of false naarmate ofdat het correct is geïnitialiseerd of niet.
     * **/
    bool properlyInitialized();

    void setType(std::string s);

    std::string getType() const;

    ~Station();

    bool addSpoor(Spoor *s);

private:

    std::vector<Spoor*> sporen;
    std::string fNaam;
    std::string fType;
    Station* _fInitCheck;
};


#endif //METROSIMULATION_STATION_H
