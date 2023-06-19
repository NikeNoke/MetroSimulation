//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_PCCTRAM_H
#define METROSIMULATION_PCCTRAM_H

#include "Tram.h"


/**
 * Klasse PCCTram, sub-klasse van Tram. Deze klasse of type tram heeft attributen die uniek zijn voor
 * dit type van tram specifiek.
 * **/
class PCCTram : public Tram {
public:

    /**
     * Functie die de snelheid van een Tram object van type PCCTram bepaald.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
     * **/
    void calculateSnelheid();

    /**
     * Functie dat nagaat ofdat een Station geserviced kan worden.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    REQUIRE(s->properlyInitialized(), "The station must be properly initialized");
     * @param s Station dat men controleerd.
     * @return true or false
     * **/
    bool stationCanBeServiced(Station *s);

    /**
     * Getter functie die de snelheid van een Tram object van type PCCTram teruggeeft.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
     * @return snelheid
     * **/
    int getSnelheid();

    /**
     * Destructor van een PCCTram object.
     * **/
    ~PCCTram() {};

    /**
     * Getter functie die het aantal defecten zal teruggeven van een Tram object van type PCCTram.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
     * @return aantaldefecten
     * **/
    int getAantalDefecten() const;

    /**
     * Setter functie die het aantal defecten zal zetten van een Tram object van type PCCTram.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    ENSURE(getAantalDefecten() == aantal, "The set not correct");
     * **/
    void setAantalDefecten(int aantal);

    /**
     * Getter functie die de reparatie tijd van een Tram object van type PCCTram teruggeeft.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
     * @return reparatie tijd
     * **/
    int getReparatieTijd() const;

    /**
     * Setter functie die de reparatie tijd van een Tram object van type PCCTram zal zetten.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    ENSURE(getReparatieTijd() == aantal, "The set not corerct");
     * **/
    void setReparatieTijd(int aantal);

    /**
     * Getter functie die de reparatie kost van een Tram object van type PCCTram teruggeeft.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
     * @return reparatie kost
     * **/
    int getReparatieKost() const;

    /**
     * Setter functie die de reparatie kost van een Tram objec van type PCCTram zal zetten.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    ENSURE(getReparatieKost() == aantal, "The set not correct");
     * **/
    void setReparatieKost(int aantal);

    /**
        Move the Tram
     REQUIRE(properlyInitialized(), "The tram must be properly initialized");
     REQUIRE(targetStation->aSpoorConnectedToStation(getHuidigStation(), getLijnNr()),
            "Station to move to has no Spoor connected to the current Station of the tram!");
     REQUIRE(targetStation->hasSpoor(getLijnNr()), "The target station does not have the same lijnNr as this tram");
     ENSURE(getHuidigStation() == temp, "The member huidigStation has changed");
     ENSURE(getHuidigStation() == target, "The member huidigStation has not been changed properly");
     ENSURE(getHuidigStation() == temp, "The member huidigStation has changed");
     */
    bool move(Station *station, Exporter& e);


    /**
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
     * @return type of tram
     */
    TramType::TypeTram getType() const;
};


#endif //METROSIMULATION_PCCTRAM_H
