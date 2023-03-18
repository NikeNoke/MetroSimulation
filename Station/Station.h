//
// Created by Thomas on 02/03/2023.
//

#ifndef METROSIMULATION_STATION_H
#define METROSIMULATION_STATION_H

#include <string>
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
    Station(const std::string &naam,const std::string& volgende,const std::string& vorige, int spoorNr);

    /**
     * @return De naam van het station.
     * **/
    std::string getName() const;

    /**
     * @return De naam van het volgende station.
     * **/
    std::string getVolgende() const;

    /**
     * @return De naam van het vorige station.
     * **/
    std::string getVorige() const;

    /**
     * @return Het spoornummer waar het station deel van is.
     * **/
    int getSpoorNr() const;

    /**
     * Set de naam van het station.
     * @param n Naam van het station.
     * **/
    void setName(std::string n);

    /**
    * Set de naam van het station.
     * @param v Naam van het volgende station.
    * **/
    void setVolgende(std::string v);

    /**
    * Set de naam van het station vorige station.
     * @param v Naam van het vorige station.
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

private:

    std::string naam;
    std::string volgende;
    std::string vorige;
    int spoorNr;
    Station* _initCheck;
};


#endif //METROSIMULATION_STATION_H
