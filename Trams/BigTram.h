//
// Created by byamba on 22/05/23.
//

#ifndef METROSIMULATION_BIGTRAM_H
#define METROSIMULATION_BIGTRAM_H
#include "../Stations/Station.h"
#include "../Exporter/Exporter.h"
#include "Tram.h"


class BigTram : public Tram{

    /**
     * Functie die de snelheid van een Tram object van type BigTram bepaald.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
     * **/
    void calculateSnelheid();

    /**
     * Functie dat nagaat ofdat een Station geserviced kan worden.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    REQUIRE(s->properlyInitialized(), "The station must be prperly initialized");
     * @param s Station dat men controleerd.
     * @return true or false
     * **/
    bool stationCanBeServiced(Station *s);

    /**
     * Getter functie die de snelheid
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
     * **/
    int getSnelheid();


    /**
     * Getter functie die het aantal defecten zal teruggeven van een Tram object van type BigTram.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
     * @return aantaldefecten
     * **/
    int getAantalDefecten() const;

    /**
     * Setter functie die het aantal defecten zal zetten van een Tram object van type BigTram.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    ENSURE(getAantalDefecten() == 0, "Set not correct");
     * @param aantal defecten, ergo om de hoeveel tijd een tram in de panne zal staan wegens een defect.
     * **/
    void setAantalDefecten(int aantal);

    /**
     * Getter functie die de reparatie tijd van een Tram object van type BigTram teruggeeft.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
     * @return reparatie tijd
     * **/
    int getReparatieTijd() const;

    /**
     * Setter functie die de reparatie tijd van een Tram object van type BigTram zal zetten.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    ENSURE(getReparatieTijd() == 0, "Set not correct");
     * @param aantal Duur van een reparatie.
     * **/
    void setReparatieTijd(int aantal);

    /**
     * Getter functie die de reparatie kost van een Tram object van type BigTram teruggeeft.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
     * @return reparatie kost
     * **/
    int getReparatieKost() const;

    /**
     * Setter functie die de reparatie kost van een Tram objec van type BigTram zal zetten.
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    ENSURE(getReparatieKost() == 0, "Set not correct");
     * @param aantal reparatie kost
     * **/
    void setReparatieKost(int aantal);

    /**
     * Move the tram
    REQUIRE(properlyInitialized(), "The tram must be properly initialized");
    REQUIRE(targetStation->aSpoorConnectedToStation(getHuidigStation(), getLijnNr()),
            "Station to move to has no Spoor connected to the current Station of the tram!");
    REQUIRE(targetStation->hasSpoor(getLijnNr()), "The target station does not have the same lijnNr as this tram");
    ENSURE(getHuidigStation() == target, "The member huidigStation has not been changed properly");
    ENSURE(getHuidigStation() == temp, "The member huidigStation has changed");
     */
    bool move(Station *station, Exporter& e);

    /**
     * REQUIRE(properlyInitialized(), "The tram is not properly initialized");
     */
    TramType::TypeTram getType() const = 0;
};


#endif //METROSIMULATION_BIGTRAM_H
