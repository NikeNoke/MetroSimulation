//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_STADSLIJNERTRAM_H
#define METROSIMULATION_STADSLIJNERTRAM_H

#include "Tram.h"

/**
 * Klasse StadslijnerTram, een sub-klasse van Tram. Deze klasse of type tram heeft attributen die uniek zijn voor
 * dit type van tram specifiek.
 * **/
class StadslijnerTram : public Tram {
public:

    /**
     * Functie die de snelheid van een Tram object van type StadslijnerTram bepaald.
     * **/
    void calculateSnelheid();

    /**
     * Functie dat nagaat ofdat een Station geserviced kan worden.
    REQUIRE(s->properlyInitialized(), "The station must be properly initialized");
     * **/
    bool stationCanBeServiced(Station *s);

    /**
     * Getter functie die de snelheid van een Tram object van type StadslijnerTram teruggeeft.
     * @return snelheid
     * **/
    int getSnelheid();

    /**
     * Destructor van een StadslijnerTram object.
     * **/
    ~StadslijnerTram() {};

    /**
     * Getter functie die het aantal defecten zal teruggeven van een Tram object van type StadslijnerTram.
     * @return aantaldefecten
     * **/
    int getAantalDefecten() const;

    /**
     * Setter functie die het aantal defecten zal zetten van een Tram object van type StadslijnerTram.
    ENSURE(getAantalDefecten() == 0, "Set not correct");
     * **/
    void setAantalDefecten(int aantal);

    /**
     * Getter functie die de reparatie tijd van een Tram object van type StadslijnerTram teruggeeft.
     * @return reparatie tijd
     * **/
    int getReparatieTijd() const;

    /**
     * Setter functie die de reparatie tijd van een Tram object van type StadslijnerTram zal zetten.
      ENSURE(getReparatieTijd() == 0, "The set not correct");
     * **/
    void setReparatieTijd(int aantal);

    /**
     * Getter functie die de reparatie kost van een Tram object van type StadslijnerTram teruggeeft.
     * @return reparatie kost
     * **/
    int getReparatieKost() const;

    /**
     * Setter functie die de reparatie kost van een Tram objec van type StadslijnerTram zal zetten.
    ENSURE(getReparatieKost() == 0, "The set not correct");
     **/
    void setReparatieKost(int aantal);

    /**
     * Move Tram
     * REQUIRE(properlyInitialized(), "The tram must be properly initialized");
       REQUIRE(targetStation->aSpoorConnectedToStation(getHuidigStation(), getLijnNr()),
            "Station to move to has no Spoor connected to the current Station of the tram!");
       REQUIRE(targetStation->hasSpoor(getLijnNr()), "The target station does not have the same lijnNr as this tram");
       ENSURE(getHuidigStation() == target, "The member huidigStation has not been changed properly");
       ENSURE(getHuidigStation() == temp, "The member huidigStation has changed");
     */
    bool move(Station *station, Exporter& e);
};


#endif //METROSIMULATION_STADSLIJNERTRAM_H
