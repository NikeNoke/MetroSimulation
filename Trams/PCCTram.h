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
class PCCTram: public Tram {
public:

    /**
     * Functie die de snelheid van een Tram object van type PCCTram bepaald.
     * **/
    void calculateSnelheid();

    /**
     * Functie dat nagaat ofdat een Station geserviced kan worden.
     * @param s Station dat men controleerd.
     * @return true or false
     * **/
    bool stationCanBeServiced(Station *s);

    /**
     * Getter functie die de snelheid van een Tram object van type PCCTram teruggeeft.
     * @return snelheid
     * **/
    int getSnelheid();

    /**
     * Destructor van een PCCTram object.
     * **/
    ~PCCTram(){};

    /**
     * Getter functie die het aantal defecten zal teruggeven van een Tram object van type PCCTram.
     * @return aantaldefecten
     * **/
    int getAantalDefecten() const;

    /**
     * Setter functie die het aantal defecten zal zetten van een Tram object van type PCCTram.
     * @param aantal defecten, ergo om de hoeveel tijd een tram in de panne zal staan wegens een defect.
     * **/
    void setAantalDefecten(int aantal);

    /**
     * Getter functie die de reparatie tijd van een Tram object van type PCCTram teruggeeft.
     * @return reparatie tijd
     * **/
    int getReparatieTijd() const;

    /**
     * Setter functie die de reparatie tijd van een Tram object van type PCCTram zal zetten.
     * @param aantal Duur van een reparatie.
     * **/
    void setReparatieTijd(int aantal);

    /**
     * Getter functie die de reparatie kost van een Tram object van type PCCTram teruggeeft.
     * @return reparatie kost
     * **/
    int getReparatieKost() const;

    /**
     * Setter functie die de reparatie kost van een Tram objec van type PCCTram zal zetten.
     * @param aantal reparatie kost
     * **/
    void setReparatieKost(int aantal);
};


#endif //METROSIMULATION_PCCTRAM_H
