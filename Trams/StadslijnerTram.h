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
     * @param s Station dat men controleerd.
     * @return true or false
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
     * @param aantal defecten, ergo om de hoeveel tijd een tram in de panne zal staan wegens een defect.
     * **/
    void setAantalDefecten(int aantal);

    /**
     * Getter functie die de reparatie tijd van een Tram object van type StadslijnerTram teruggeeft.
     * @return reparatie tijd
     * **/
    int getReparatieTijd() const;

    /**
     * Setter functie die de reparatie tijd van een Tram object van type StadslijnerTram zal zetten.
     * @param aantal Duur van een reparatie.
     * **/
    void setReparatieTijd(int aantal);

    /**
     * Getter functie die de reparatie kost van een Tram object van type StadslijnerTram teruggeeft.
     * @return reparatie kost
     * **/
    int getReparatieKost() const;

    /**
     * Setter functie die de reparatie kost van een Tram objec van type StadslijnerTram zal zetten.
     * @param aantal reparatie kost
     * **/
    void setReparatieKost(int aantal);

    bool move(Station *station, Exporter& e);
};


#endif //METROSIMULATION_STADSLIJNERTRAM_H
