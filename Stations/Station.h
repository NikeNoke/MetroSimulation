//
// Created by Thomas on 02/03/2023.
//

#ifndef METROSIMULATION_STATION_H
#define METROSIMULATION_STATION_H

#include <string>
#include <vector>

class Spoor;

namespace TypeStation {

    enum StationType {
        MetroStation, Halte, Invalid
    };

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

    /*/**
     * Constructor voor Station.
     * @param naam Naam van het station.
     * @param volgende Het volgende station.
     * @param vorige Het vorige station.
     * @param spoorNr Het nummer van de spoor waar het station deel van is.
     * @return Een Station object met attributen.
     * **/
//    Station(const std::string &naam,const std::string& volgende,const std::string& vorige, int spoorNr);

    /**
     * Getter functie dat de naam van het station gaat teruggeven.
     * @return De naam van het station.
     * **/
    std::string getName() const;

    /**
     * Getter functie dat een vector van sporen zal teruggeven.
     * @return vector van Spoor objecten.
     * **/
    std::vector<Spoor *> getSporen() const;

    /**
     * Setter functie dat de naam van het station set.
     * @param n Naam van het station.
     * **/
    void setName(std::string &n);


    /**
     * Controleert ofdat het station correct is geïnitialiseerd.
     * @return true or false
     * **/
    bool properlyInitialized();

    /**
     * Setter functie dat het type van een Station object zal setten.
     * @pre REQUIRE(!(Utils::is_int(s)), "The parameter type is a number")
     * @post ENSURE(getType() == s, "The member variable type has not been properly initialized")
     * @param s Type
     * **/
    void setType(std::string &s);

    /**
     * Getter functie dat het type van een Station object zal teruggeven.
     * @return Type van een Station object.
     * **/
    std::string getType() const;

    /**
     * Virtual destructor van een Station object.
     * **/
    virtual ~Station() {};

    /**
     * Functie dat Spoor object zal bijvoegen aan het MetroNet object (steekt ze in een vector van Spoor objecten).
     * @return true or false
     * **/
    bool addSpoor(Spoor *s);

    /**
     * Virtual Enum
     * **/
    virtual TypeStation::StationType getTypeEnum() = 0;

    /**
     * Getter functie dat een Spoor object zal teruggeven.
     * @param nr Spoor dat we willen.
     * @return Spoor object (of NULL pntr)
     * **/
    Spoor *getSpoor(int nr) const;

    /**
     * Functie controleerd ofdat een Station object alleen unieke sporen heeft.
     * @return true or false
     * **/
    bool hasUniqueSporen() const;

    /**
     * Functie dat controleerd ofdat een bepaalde Spoor door het Station komt.
     * @return true or false
     * **/
    bool hasSpoor(int nr) const;

    /**
     * Functie dat controleerd ofdat een Spoor geconnecteerd is met een Station.
     * @param stationName
     * @param lijnNr
     * @return true or false
     * **/
    bool aSpoorConnectedToStation(const std::string &stationName, int lijnNr) const;

    /**
     * Functie controleerd ofdat de volgende Station ook dezelfde Spoor heeft
     * en geeft dan de naam van het volgende Station.
     * @pre REQUIRE(tempSporen[i]->getHuiding() == getName(), "Spoor in station is wrong")
     * @param lijnNr
     * @return naam van het volgende Station van de spoor.
     * **/
    std::string nextOfSpoor(int lijnNr) const;

    /**
     * Functie controleerd ofdat de vorige Station ook dezelfde Spoor heeft
     * en geeft dan de naam van het vorige Station.
     * @pre REQUIRE(tempSporen[i]->getHuiding() == getName(), "Spoor in station is wrong")
     * @param lijnNr
     * @return naam van het vorige Station van de spoor.
     * **/
    std::string previousOfSpoor(int lijnNr) const;

    /**
     * Getter functie dat teruggeeft hoeveel keer een bepaalde Station bezocht werd door trammen.
     * @return Hoeveel keer trammen een Station hebben bezocht.
     * **/
    int getVisitedByTrams() const;

    /**
     * Setter functie dat de hoeveelheid dat trammen een bepaalde Station hebben bezocht set.
     * @param amount Hoeveel keer trammen een Station hebben bezocht.
     * **/
    void setVisitedByTrams(int amount);

private:

    std::vector<Spoor *> sporen;
    std::string fNaam;
    std::string fType;
    Station *_fInitCheck;

    int visitedByTrams;
};


#endif //METROSIMULATION_STATION_H
