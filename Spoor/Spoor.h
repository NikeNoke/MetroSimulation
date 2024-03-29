//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_SPOOR_H
#define METROSIMULATION_SPOOR_H

#include <string>

/**
 * Klasse Spoor. Een spoor maakt deel uit van een station. Een station kan meerdere sporen hebben waarmee
 * we meerdere lijnen kunnen hebben die door één station komen. Dit zijn de sporen.
 * **/
class Spoor {
public:

    /**
     * Default constructor van een Spoor object.
     * @post ENSURE(properlyInitialized(), "The Spoor has not been properly initialized")
     * @return Spoor object
     * **/
    Spoor();

    /**
     * Constructor met gegeven attributes.
     * @post ENSURE(properlyInitialized(), "The Spoor has not been properly initialized")
     * @param vorige station op deze spoor
     * @param volgende station op deze spoor
     * @param spoorNr nummer van de spoor
     * @return Spoor object
     * @note Deze constructor wordt vooral gebruikt bij het testen ipv bij het runnen.
     * Dit is omdat we al een vaste parser hebben die werkt met een default constructor.
     * **/
    Spoor(const std::string vorige, const std::string volgende, int spoorNr);

    /**
     * Controleert ofdat het spoor correct is geïnitialiseerd.
     * @return true of false
     * **/
    bool properlyInitialized() const;

    /**
     * Setter functie dat de naam van het volgende station set.
     * REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
     * @pre REQUIRE(!(Utils::is_int(v)), "The parameter volgende is a number")
     * @post ENSURE(getVolgende() == v, "The member variable volgende has not been properly initialized")
     * @param v Naam van het volgende station.
     * **/
    void setVolgende(std::string v);

    /**
     * Setter functie dat de naam van het vorige station set.
     * REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
     * @pre REQUIRE(!(Utils::is_int(v)), "The parameter vorige is a number")
     * @post ENSURE(getVorige() == v, "The member variable vorige has not been properly initialized")
     * @param v Naam van het vorige station.
     * **/
    void setVorige(std::string v);

    /**
     * Set het spoornummer van het station.
     * REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
     * @post ENSURE(getSpoorNr() == s, "The member variable spoorNr has not been properly initialized")
     * @param s Spoornummer waar het station deel van is.
     * **/
    void setSpoorNr(int s);

    /**
     * Getter functie dat de naam van het volgende station teruggeeft.
     * REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
     * @return De naam van het volgende station.
     * **/
    std::string getVolgende() const;

    /**
     * Getter functie dat de naam van het vorige station teruggeeft.
     * REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
     * @return De naam van het vorige station.
     * **/
    std::string getVorige() const;

    /**
     * Getter functie dat het spoorNr van de spoor teruggeeft.
     * REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
     * @return spoorNr
     * **/
    int getSpoorNr() const;

    /**
     * Getter functie dat de huidige station teruggeeft.
     * REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
     * @return huidig station
     * **/
    std::string getHuiding() const;

    /**
     * Setter functie dat de naam van het huidige station set.
     * REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
     * ENSURE(getHuiding() == h, "Not set properly");
     * @param h naam van het huidig station
     * **/
    void setHuidig(const std::string &h);

    /**
     * Functie dat controleerd ofdat een bepaald station verbonden is met een andere station op het MetroNet.
     * REQUIRE(properlyInitialized(), "The spoor is not properly initialized");
     * @param stationName
     * @return true or false
     * **/
    bool connectedToStation(const std::string &stationName) const;

private:
    std::string volgende;
    std::string vorige;
    std::string huidig;
    int spoorNr;
    Spoor *_fInitCheck;
};


#endif //METROSIMULATION_SPOOR_H
