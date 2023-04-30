//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_ALBATROSTRAM_H
#define METROSIMULATION_ALBATROSTRAM_H
#include "Tram.h"


/**
 * Klasse AlbatrosTram, een sub-klasse van Tram. Deze klasse of type tram heeft attributen die uniek zijn voor
 * dit type van tram specifiek.
 * **/
class AlbatrosTram: public Tram{
public:
    
    /**
     * Helper functie die het type teruggeeft.
     * @return type
     * **/
    void test() const;

    /**
     * Functie die de snelheid van een Tram object van type AlbatrosTram bepaald.
     * **/
    void calculateSnelheid();

    /**
     * Functie dat nagaat ofdat een Station geserviced kan worden.
     * @param s Station dat men controleerd.
     * @return true or false
     * **/
    bool stationCanBeServiced(Station *s);

    /**
     * Getter functie die de snelheid van een Tram object van type AlbatrosTram teruggeeft.
     * @return snelheid
     * **/
    int getSnelheid();

    /**
     * Destructor van een AlbatrosTram object.
     * **/
    ~AlbatrosTram(){};

    /**
     * Getter functie die het aantal defecten zal teruggeven van een Tram object van type AlbatrosTram.
     * @return aantaldefecten
     * **/
    int getAantalDefecten() const;

    /**
     * Setter functie die het aantal defecten zal zetten van een Tram object van type AlbatrosTram.
     * @param aantal defecten, ergo om de hoeveel tijd een tram in de panne zal staan wegens een defect.
     * **/
    void setAantalDefecten(int aantal);

    /**
     * Getter functie die de reparatie tijd van een Tram object van type AlbatrosTram teruggeeft.
     * @return reparatie tijd
     * **/
    int getReparatieTijd() const;

    /**
     * Setter functie die de reparatie tijd van een Tram object van type AlbatrosTram zal zetten.
     * @param aantal Duur van een reparatie.
     * **/
    void setReparatieTijd(int aantal);

    /**
     * Getter functie die de reparatie kost van een Tram object van type AlbatrosTram teruggeeft.
     * @return reparatie kost
     * **/
    int getReparatieKost() const;

    /**
     * Setter functie die de reparatie kost van een Tram objec van type AlbatrosTram zal zetten.
     * @param aantal reparatie kost
     * **/
    void setReparatieKost(int aantal);
};


#endif //METROSIMULATION_ALBATROSTRAM_H
