//
// Created by Thomas on 02/03/2023.
//

#ifndef METROSIMULATION_TRAM_H
#define METROSIMULATION_TRAM_H

#include <string>
#include "../Stations/Station.h"
namespace TramType{

    enum TypeTram {PCC, StadsLijner, Albatros, InvalidTram};

}

/**
* Klasse Tram. Een basis klasse waarvan meerdere sub-klasses (types van trammen) overerven.
* **/
class Tram {
public:

    /**
     * Default constructor van een tram object.
     * @post ENSURE(properlyInitialized(), "Tram has not been properly initialized")
     * @return Een tram object zonder attributen.
     * **/
    Tram();

    /**
     * Constructor van een tram object.
     * @pre REQUIRE(!(Utils::is_int(beginStation)), "The parameter beginStation is a number")
     * @post ENSURE(properlyInitialized(), "Tram has not been properly initialized")
     * @param beginStation De beginstation waarin de tram zich bevindt.
     * @param lijnNr Het nummer van de lijn, komt overeen met spoornummer van een station.
     * @param snelheid De snelheid dat deze type tram kan halen.
     * @return Een tram object met attributen
     * @note Type van trammen is geïmplementeerd. Tram wordt nu een virtual klasse waarvan de types gaan overerven.
     * **/
    Tram(const std::string &beginStation, int snelheid, int lijnNr);

    /**
     * @return De beginstation van een tram.
     * **/
    std::string getBeginStation() const;

    /**
     * @return De snelheid van een tram.
     * **/
    virtual int getSnelheid();

    /**
     * @return Het lijnnummer van een tram.
     * **/
    int getLijnNr() const;


    /**
     * @return Huidig station waarin de tram zich bevindt.
     * **/
    std::string getHuidigStation() const;

    /**
     * Setter functie voor een tram object zijn beginstation te zetten.
     * @pre REQUIRE(!(Utils::is_int(bs)), "The parameter beginStation is a number")
     * @post ENSURE(getBeginStation() == bs, "The member beginStation type has not been set properly")
     * @param bs De naam van het beginstation van een tram.
     * **/
    void setBeginStation(std::string& bs);

    /**
     * Setter functie voor een tram object zijn snelheid te zetten.
     * @param s Snelheid van een tram.
     * **/
    void setSnelheid(int s);

    /**
     * Setter functie voor een tram object zijn lijnnummer te zetten.
     * @post ENSURE(getLijnNr() == l, "The member lijnNr type has not been set properly")
     * @param l Lijnnummer van een tram.
     * **/
    void setLijnNr(int l);

    /**
     * Setter functie voor een tram het huidige station te zetten.
     * @pre REQUIRE(!(Utils::is_int(h)), "The parameter huidigStation is a number")
     * @post ENSURE(getHuidigStation() == h, "The member huidigStation type has not been set properly")
     * @param h Het huidig station van een tram.
     * **/
    void setHuidigStation(std::string& h);

    /**
     * Controleerd ofdat de tram object correct geïnitialiseerd is.
     * @return true or false
     * **/
    bool properlyInitialized();

    /**
     * Functie die een Tram object van de ene Station object naar de volgende Station object verplaatst.
     * @pre REQUIRE(targetStation->aSpoorConnectedToStation(getHuidigStation(), getLijnNr()), "Station to move to has no Spoor connected to the current Station of the tram!")
     * @pre REQUIRE(targetStation->hasSpoor(getLijnNr()), "The target station does not have the same lijnNr as this tram")
     * @post ENSURE(getHuidigStation() == temp, "The member huidigStation has changed")
     * @post ENSURE(getHuidigStation() == target, "The member huidigStation has not been changed properly")
     * @param station naar waar de Tram object verplaatst zal worden.
     * @return true or false
     * @attention De eerste ENSURE wordt opgeroepen in geval dat een Tram object **NIET** verplaatst kan worden
     * naar een volgende Station. De tweede ENSURE wordt opgeroepen in geval dat een Tram wel naar een volgende Station
     * verplaatst kan worden. In de tweede ENSURE zal die dan ook een ERROR throwen als er tog iets mis gaat.
     * **/
    bool move(Station* station);

    /**
     * Setter functie die het Type attribuut zet voor een Tram object.
     * @pre REQUIRE(!(Utils::is_int(t)), "The parameter type is a number")
     * @post ENSURE(getType() == t, "The member variable type has not been set properly")
     * @param type van het Tram object.
     * **/
    void setType(std::string& type);

    /**
     * Getter functie die het Type van een Tram object zal teruggeven.
     * @return Type van het Tram object.
     * **/
    std::string getType() const;

    /**
     * Setter functie die het voertuigNr attribuut zet voor een Tram object.
     * @post ENSURE(getVoertuigNummer() == n, "The member variable voertuigNummer has not been set properly")
     * @param n voertuignummer van het Tram object.
     * **/
    void setVoertuigNummer(int n);

    /**
     * Getter functie die het voertuignummer van een Tram object zal teruggeven.
     * @return Voertuignummer van het Tram object.
     * **/
    int getVoertuigNummer() const;

    /**
     * Virtual calculateSnelheid
     * **/
    virtual void calculateSnelheid() = 0;

    /**
     * Virtual stationCanBeServiced
     * @param s Station
     * **/
    virtual bool stationCanBeServiced(Station* s) = 0;

    /**
     * Virtual destructor.
     * **/
    virtual ~Tram(){};

    /**
     * Virtual getAantalDefecten
     * **/
    virtual int getAantalDefecten() const = 0;

    /**
     * Virtual setAantalDefecten
     * @param aantal defecten
     * **/
    virtual void setAantalDefecten(int aantal) = 0;

    /**
     * Virtual getReparatieTijd
     * **/
    virtual int getReparatieTijd() const = 0;

    /**
     * Virtual setReparatieTijd
     * @param aantal Duur van reparatie
     * **/
    virtual void setReparatieTijd(int aantal) = 0;

    /**
     * Virtual getReparatieKost
     * **/
    virtual int getReparatieKost() const = 0;

    /**
     * Virtual setReparatieKost
     * @param aantal Kost van reparatie.
     * **/
    virtual void setReparatieKost(int aantal) = 0;

    /**
     * Functie controleerd ofdat een Tram object een defect heeft of niet.
     * @return true or false
     * **/
    bool tramDefect() const;

    /**
     * Functie controleerd wat de totale reparatiekost is van een Tram object.
     * @return Totale reparatiekost van type int.
     * **/
    int getTotalReparatieKost() const;

protected:
    int snelheid;
    int aantalDefecten;
    int reparatieTijd;
    int reparatieKost; //gwn + reparatieTijd of + reparatieTijd bij elke defect???? TODO ask

private:
    std::string beginStation;
    int lijnNr;
    std::string huidigStation;
    std::string type; //TODO make enum
    int voertuigNummer;
    Tram* _initCheck;

    int defectWatcher;

    int getDefectWatcher() const;

    void setDefectWatcher(int defectWatcher);

    int reparatieTijdWatcher;

    int getReparatieTijdWatcher() const;

    void setReparatieTijdWatcher(int reparatieTijdWatcher);

    bool tramCanMove();
};


#endif //METROSIMULATION_TRAM_H
