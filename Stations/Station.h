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
         ENSURE(properlyInitialized(), "Must be proerly initialized");
     * **/
    Station();

    /**
     * Getter functie dat de naam van het station gaat teruggeven.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * @return De naam van het station.
     * **/
    std::string getName() const;

    /**
     * Getter functie dat een vector van sporen zal teruggeven.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * @return vector van Spoor objecten.
     * **/
    std::vector<Spoor *> getSporen() const;

    /**
     * Setter functie dat de naam van het station set.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
    REQUIRE(!(Utils::is_int(n)), "The parameter naam is a number");
    ENSURE(getName() == n, "The member variable naam has not been properly initialized");
     * **/
    void setName(std::string n);


    /**
     * Controleert ofdat het station correct is geïnitialiseerd.
     * @return true or false
     * **/
    bool properlyInitialized() const;

    /**
     * Setter functie dat het type van een Station object zal setten.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * @pre REQUIRE(!(Utils::is_int(s)), "The parameter type is a number")
     * @pre REQUIRE(s == "Metrostation" || s == "Halte", "Type of Station is an invalid type.")
     * @post ENSURE(getType() == s, "The member variable type has not been properly initialized")
     * @param s Type
     * **/
    void setType(std::string s);

    /**
     * Getter functie dat het type van een Station object zal teruggeven.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * @return Type van een Station object.
     * **/
    std::string getType() const;

    /**
     * Virtual destructor van een Station object.
     * **/
    virtual ~Station() {};

    /**
     * Functie dat Spoor object zal bijvoegen aan het MetroNet object (steekt ze in een vector van Spoor objecten).
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
       ENSURE(hasSpoor(s->getSpoorNr()), "Spoor has not been added");
     * @return true or false
     * **/
    bool addSpoor(Spoor *s);

    /**
     * Virtual Enum
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * **/
    virtual TypeStation::StationType getTypeEnum() = 0;

    /**
     * Getter functie dat een Spoor object zal teruggeven.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * @param nr Spoor dat we willen.
     * @return Spoor object (of NULL pntr)
     * **/
    Spoor *getSpoor(int nr) const;

    /**
     * Functie controleerd ofdat een Station object alleen unieke sporen heeft.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * @return true or false
     * **/
    bool hasUniqueSporen() const;

    /**
     * Functie dat controleerd ofdat een bepaalde Spoor door het Station komt.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * @return true or false
     * **/
    bool hasSpoor(int nr) const;

    /**
     * Functie dat controleerd ofdat een Spoor geconnecteerd is met een Station.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * @param stationName
     * @param lijnNr
     * @return true or false
     * **/
    bool aSpoorConnectedToStation(const std::string &stationName, int lijnNr) const;

    /**
     * Functie controleerd ofdat de volgende Station ook dezelfde Spoor heeft
     * en geeft dan de naam van het volgende Station.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * @pre REQUIRE(tempSporen[i]->getHuiding() == getName(), "Spoor in station is wrong")
     * @param lijnNr
     * @return naam van het volgende Station van de spoor.
     * **/
    std::string nextOfSpoor(int lijnNr) const;

    /**
     * Functie controleerd ofdat de vorige Station ook dezelfde Spoor heeft
     * en geeft dan de naam van het vorige Station.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * @pre REQUIRE(tempSporen[i]->getHuiding() == getName(), "Spoor in station is wrong")
     * @param lijnNr
     * @return naam van het vorige Station van de spoor.
     * **/
    std::string previousOfSpoor(int lijnNr) const;

    /**
     * Getter functie dat teruggeeft hoeveel keer een bepaalde Station bezocht werd door trammen.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * @return Hoeveel keer trammen een Station hebben bezocht.
     * **/
    int getVisitedByTrams() const;

    /**
     * Setter functie dat de hoeveelheid dat trammen een bepaalde Station hebben bezocht set.
     * REQUIRE(properlyInitialized(), "The station is not properly initialized");
     * ENSURE(getVisitedByTrams() == amount, "The setting was not successful");
     * **/
    void setVisitedByTrams(int amount);

private:

    std::vector<Spoor *> sporen;
    std::string fNaam;
    std::string fType;
    Station *_fInitCheck;
    std::vector<std::string> types;
    int visitedByTrams;
};


#endif //METROSIMULATION_STATION_H
