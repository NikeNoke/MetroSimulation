#ifndef METRONET_XXX
#define METRONET_XXX

#include <vector>
#include "../Stations/Station.h"
#include "../Trams/Tram.h"
#include "../Exporter/Exporter.h"
#include <string>
#include <fstream>

/**
* Klasse MetroNet, een MetroNet object waarin alle Tram en Station objecten zouden geplaatst worden en waarover
* gesimuleert zal worden.
* **/
class MetroNet {
public:

    /**
     * Constructor voor MetroNet.
     * @return Een MetroNet object.
     * **/
    MetroNet(Exporter& e);

    /**
     * Destructor voor MetroNet.
     * **/
    ~MetroNet();


    /**
     * Method stationRegistered die controleert dat station attribute "naam" correct ingelezen wordt.
     * @pre REQUIRE(!(Utils::is_int(name)), "The parameter name is a number")
     * @param name wordt gecontroleert.
     * @return true of false afhankelijk ofdat het station correct werd ingelezen.
     * **/
    bool stationRegistered(const std::string &name) const;
    //bool tramRegistered(std::string& name) const;

    /**
     * Voegt station toe bij MetroNet.
     * @pre REQUIRE(station->properlyInitialized(), "The parameter station is not properly initialized")
     * @pre REQUIRE(!stationRegistered(station->getName()), "The station is already in the metroNet")
     * @pre REQUIRE(station->getName() != "", "The station needs have a name.")
     * @pre REQUIRE(!station->getSporen().empty(), "Station must have sporen.")
     * @post ENSURE(stationRegistered(station->getName()), "The station was not successfully added")
     * @param station station dat toegevoegd wordt.
     * **/
    void addStation(Station *const station);

    /**
     * Voegt tram toe bij MetroNet.
     * @pre REQUIRE(tram->properlyInitialized(), "The parameter tram is not properly initialized")
     * @param tram tram dat toegevoegd wordt.
     * */
    void addTram(Tram *const tram);

    /**
     * Getter dat het station returned met parameter name.
     * @pre REQUIRE(!(Utils::is_int(name)), "The parameter name is a number")
     * @pre REQUIRE(stationRegistered(name), "The station is not Registered!")
     * @param name Naam van het station dat gezocht wordt.
     * @return Geeft station terug dat als naam "name" heeft of als die niet bestaat geeft het NULL terug.
     * **/
    Station *getStation(const std::string &name);

    /**
     * Getter dat de tram returned met parameter name.
     * @param name
     * @return Geeft tram terug dat als naam "name" heeft of als die niet bestaat geeft het NULL terug.
     * @note Functie is nog niet geïmplementeerd.
     * **/
    Tram *getTram(int voertuigNr);

    bool tramExists(int voertuigNr);

    /**
     * @return een vector met daarin alle stations.
     * **/
    std::vector<Station *> getStations();

    /**
     * @return een vector met daarin alle trammen.
     * **/
    std::vector<Tram *> getTrams();

//    /**
//     * Functie dat een tram verplaatst naar een station.
//     * @param tram De tram die verplaatst zou worden.
//     * @param nameStation De string die overeenkomt met de naam van een station en waarnaar de tram zal verplaatst
//     * worden.
//     * @return true of false afhankelijk ofdat de move gaat of niet gaat.
//     * **/
//    bool moveTram(Tram *const tram, const std::string &nameStation);

    /**
     * Functie dat test ofdat MetroNet correct geïnitialiseerd is.
     * @return true of false als het correct geïnitialiseerd is of als het niet correct geïnitialiseerd is.
     * **/
    bool properlyInitialized() const;

    /**
     * Functie dat test ofdat de MetroNet dat we maken wel degelijk een valid MetroNet is.
     * @return true of false
     * **/
    bool isValidMetroNet();

    bool isValidMetroNetSilent();

    /**
     * Functie dat een MetroNet zal simuleren.
     * @param seconds Hoe lang de simulatie zal runnen.
     * @attention De simulatie maakt gebruik van ctime.h en diens ingebouwde functies om het verloop van een simulatie
     * in computer tijd te kunnen runnen ipv in real time de simulatie te runnen.
     * Deze functie roept de moveAllTramsOnce methode op om elke tram te bewegen naar zijn volgende station.
     * **/
    void simulateMetroNet(int seconds);

    /**
     * Functie dat kijkt in ofdat er op een gegeven station er een tram zich bevindt.
     * @param stationName naam van het station dat we gaan controleren.
     * @return true or false.
     * **/
    bool aTramAtStation(const std::string stationName);

    /**
     * Functie dat kijkt ofdar er op een gegeven station er een tram zich bevindt (advanced).
     * @pre REQUIRE(stationRegistered(stationName), "stationName must be valid")
     * @pre REQUIRE(getStation(stationName)->hasSpoor(lijnNr), "Station must have lijnNr")
     * @param stationName naam van het station dat we gaan controleren.
     * @param lijnNr lijnNr dat we gaan controleren ofdat die overeenkomt met die van een tram.
     * @return true or false
     * **/
    bool aTramAtStationSpoor(const std::string &stationName, int lijnNr);

    /**
     * Functie dat een tram van zijn huidige station gaat moven naar zijn volgende station.
     * @pre REQUIRE(!aTramAtStationSpoor(targetStationName, tram->getLijnNr()),"There cannot be a tram at targetStation SpoorNr to move Tram!")
     * @param t Tram dat we gaan moven
     * @param TargetStationName Station waar we de tram naar willen verplaatsen.
     * @return true or false
     * **/
    bool moveTram(Tram *t, std::string TargetStationName);

    /**
     * Functie dat alle trammen zal verplaatsen naar hun volgende station als dat mogelijk is.
     * @pre REQUIRE(isValidMetroNet(), "Cannot move trams in a invalid metronet")
     * @pre REQUIRE(!targetStationName.empty(), "TargetStationName cannot be empty to move Tram")
     * **/
    void moveAllTramsOnce();

    /**
     * Getter functie dat de Tram zal teruggeven dat op zich bevindt op de gegeven station.
     * @pre REQUIRE(aTramAtStationSpoor(stationName, lijnNr), "There must be a tram at station SpoorNr")
     * @param stationName naam van het station dat we gaan controleren.
     * @param lijnNr lijnNr dat we gaan controleren ofdat die overeenkomt met die van een tram.
     * **/
    Tram *getTramAtStationSpoor(const std::string &stationName, int lijnNr);

    /**
     * Getter functie dat de totale reparatie kost zal teruggeven.
     * @return Totale reparatie kost.
     * **/
    int getTotaalMetroNetReparatieKost();

    /**
     * Functie wordt gebruikt om te checken hoeveel keer een bepaald station bezoekt werd door trammen.
     * @pre REQUIRE(isValidMetroNet(), "The metronet must be valid")
     * **/
    void initializeStat();

    /**
     * Geeft een status report van een gesimuleerde MetroNet. Wordt gebruikt om in een file belangrijke informatie
     * weg te schrijven zoals: totale reparatiekosten, welke station door welke tram bezocht werd etc.
     * **/
    void getStatReport();

    /**
     * Zelfde functie als moveTram maar zonder print statements speciaal voor test case usage.
     * @pre REQUIRE(!aTramAtStationSpoor(targetStationName, tram->getLijnNr()),"There cannot be a tram at targetStation SpoorNr to move Tram!")
     * @param t Tram dat we gaan moven
     * @param TargetStationName Station waar we de tram naar willen verplaatsen.
     * @return true or false
     * @see moveTram
     * **/
    bool _moveTest(Tram *tram, std::string targetStationName);

    Exporter& getExporter();

private:

    bool controlStation(Station *s);

    bool spoorLineHasTram(Spoor *s);

    bool tramLineHasSpoor(Tram *t);

    bool beginStationTramCorrect(Tram *t);

    bool uniqueTram(Tram *t);

    bool validSpoor(Spoor *s);

    bool controlTram(Tram *t);

private:
    std::vector<Station *> fStations;
    std::vector<Tram *> fTrams;
    MetroNet *_fInitCheck;

    bool initializeStatCalled;

    bool getInitializeStatCalled() const;

    void setInitializeStatCalled(bool b);

    Exporter exporter;
};


#endif //METRONET_XXX