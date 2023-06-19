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
        ENSURE(properlyInitialized(), "The metroNet is not properly initialized");
     * @return Een MetroNet object.
     * **/
    MetroNet(Exporter& e);

    /**
     * Destructor voor MetroNet.
     * **/
    ~MetroNet();

    /**
     * Method stationRegistered die controleert dat station attribute "naam" correct ingelezen wordt.
     * REQUIRE(properlyInitialized(), "The metroNet is not properly initialized");
     * @pre REQUIRE(!(Utils::is_int(name)), "The parameter name is a number")
     * @param name wordt gecontroleert.
     * @return true of false afhankelijk ofdat het station correct werd ingelezen.
     * **/
    bool stationRegistered(const std::string &name) const;

    /**
     * Voegt station toe bij MetroNet.
     * REQUIRE(properlyInitialized(), "The metroNet is not properly initialized");
     * @pre REQUIRE(station->properlyInitialized(), "The parameter station is not properly initialized")
     * @pre REQUIRE(station->getName() != "", "The station needs have a name.")
     * @pre REQUIRE(!station->getSporen().empty(), "Station must have sporen.")
     * @post ENSURE(stationRegistered(station->getName()), "The station was not successfully added")
     * @param station station dat toegevoegd wordt.
     * **/
    void addStation(Station *const station);

    /**
     * Voegt tram toe bij MetroNet.
     * REQUIRE(properlyInitialized(), "The metroNet is not properly initialized");
     * @pre REQUIRE(tram->properlyInitialized(), "The parameter tram is not properly initialized")
     * ENSURE(getTram(tram->getVoertuigNummer()) == tram, "The tram has not been added");
     * @param tram tram dat toegevoegd wordt.
     * */
    void addTram(Tram *const tram);

    /**
     * Getter dat het station returned met parameter name.
     * REQUIRE(properlyInitialized(), "The metroNet is not properly initialized");
     * @pre REQUIRE(!(Utils::is_int(name)), "The parameter name is a number")
     * @param name Naam van het station dat gezocht wordt.
     * @return Geeft station terug dat als naam "name" heeft of als die niet bestaat geeft het NULL terug.
     * **/
    Station *getStation(const std::string &name);

    /**
     * Getter dat de tram returned met parameter voertuigNr.
     * REQUIRE(properlyInitialized(), "The metroNet is not properly initialized");
     * REQUIRE(tramExists(voertuigNr), "The tram with this nummer must exist");
     * @return Geeft tram terug dat als naam "name" heeft of als die niet bestaat geeft het NULL terug.
     * @note Functie is nog niet geïmplementeerd.
     * **/
    Tram *getTram(int voertuigNr);

    /**
     * Does tram with nr exist?
     * REQUIRE(properlyInitialized(), "The metroNet is not properly initialized");
     */
    bool tramExists(int voertuigNr);

    /**
     * REQUIRE(properlyInitialized(), "The metroNet is not properly initialized");
     * @return een vector met daarin alle stations.
     * **/
    std::vector<Station *> getStations();

    /**
     * REQUIRE(properlyInitialized(), "The metroNet is not properly initialized");
     * @return een vector met daarin alle trammen.
     * **/
    std::vector<Tram *> getTrams();

    /**
     * Functie dat test ofdat MetroNet correct geïnitialiseerd is.
     * @return true of false als het correct geïnitialiseerd is of als het niet correct geïnitialiseerd is.
     * **/
    bool properlyInitialized() const;

    /**
     * Functie dat test ofdat de MetroNet dat we maken wel degelijk een valid MetroNet is.
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     * REQUIRE(tempStations[i]->properlyInitialized(), "A station of the metroNet is not properly initialized");
     * REQUIRE(tempTrams[i]->properlyInitialized(), "A tram of the metroNet is not properly initialized");
     * @return true of false
     * **/
    bool isValidMetroNet();

    /**
     * Functie dat een MetroNet zal simuleren.
     * REQUIRE(properlyInitialized(), "Metronet must be properly initialized");
       REQUIRE(isValidMetroNet(), "The metronet must be valid");
       ENSURE(isValidMetroNet(), "The metronet must still be valid");
     * @attention De simulatie maakt gebruik van ctime.h en diens ingebouwde functies om het verloop van een simulatie
     * in computer tijd te kunnen runnen ipv in real time de simulatie te runnen.
     * Deze functie roept de moveAllTramsOnce methode op om elke tram te bewegen naar zijn volgende station.
     * **/
    void simulateMetroNet(int seconds);

    /**
     * Functie dat kijkt in ofdat er op een gegeven station er een tram zich bevindt.
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     * @param stationName naam van het station dat we gaan controleren.
     * @return true or false.
     * **/
    bool aTramAtStation(const std::string stationName);

    /**
     * Functie dat kijkt ofdar er op een gegeven station er een tram zich bevindt (advanced).
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     * @pre REQUIRE(stationRegistered(stationName), "stationName must be valid")
     * @pre REQUIRE(getStation(stationName)->hasSpoor(lijnNr), "Station must have lijnNr")
     * @param stationName naam van het station dat we gaan controleren.
     * @param lijnNr lijnNr dat we gaan controleren ofdat die overeenkomt met die van een tram.
     * @return true or false
     * **/
    bool aTramAtStationSpoor(const std::string &stationName, int lijnNr);

    /**
     * Functie dat een tram van zijn huidige station gaat moven naar zijn volgende station.
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     * @pre REQUIRE(!aTramAtStationSpoor(targetStationName, tram->getLijnNr()),"There cannot be a tram at targetStation SpoorNr to move Tram!")
     * @param t Tram dat we gaan moven
     * @param TargetStationName Station waar we de tram naar willen verplaatsen.
     * @return true or false
     * **/
    bool moveTram(Tram *t, std::string TargetStationName);

    /**
     * Functie dat alle trammen zal verplaatsen naar hun volgende station als dat mogelijk is.
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     * @pre REQUIRE(isValidMetroNet(), "Cannot move trams in a invalid metronet")
     * @pre REQUIRE(!targetStationName.empty(), "TargetStationName cannot be empty to move Tram")
       ENSURE(isValidMetroNet(), "The metronet must still be valid");
     * **/
    void moveAllTramsOnce();

    /**
     * Getter functie dat de Tram zal teruggeven dat op zich bevindt op de gegeven station.
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     * @pre REQUIRE(aTramAtStationSpoor(stationName, lijnNr), "There must be a tram at station SpoorNr")
     * @param stationName naam van het station dat we gaan controleren.
     * @param lijnNr lijnNr dat we gaan controleren ofdat die overeenkomt met die van een tram.
     * **/
    Tram *getTramAtStationSpoor(const std::string &stationName, int lijnNr);

    /**
     * Getter functie dat de totale reparatie kost zal teruggeven.
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     * @return Totale reparatie kost.
     * **/
    int getTotaalMetroNetReparatieKost();

    /**
     * Functie wordt gebruikt om te checken hoeveel keer een bepaald station bezoekt werd door trammen.
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     * @pre REQUIRE(isValidMetroNet(), "The metronet must be valid")
       REQUIRE(getInitializeStatCalled() == false, "This function must only be called once");
       ENSURE(isValidMetroNet(), "The metronet must still be valid");
     * **/
    void initializeStat();

    /**
     * Geeft een status report van een gesimuleerde MetroNet. Wordt gebruikt om in een file belangrijke informatie
     * weg te schrijven zoals: totale reparatiekosten, welke station door welke tram bezocht werd etc.
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     * **/
    void getStatReport();

    /**
     * get Exporter
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     */
    Exporter& getExporter();

private:
    /**
     * Check validity of Station
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     * REQUIRE(station->properlyInitialized(), "The station must be properly initialized");
     */
    bool controlStation(Station *s);

    /**
     * Does spoor have a tram with the same tramLine nummer?
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     * REQUIRE(s->properlyInitialized(), "The spoor must be properly initialized");
     */
    bool spoorLineHasTram(Spoor *s);

    /**
     * Does tram have spoor with the same tramLine nummer?
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     * REQUIRE(t->properlyInitialized(), "The tram must be properly initialized");
     */
    bool tramLineHasSpoor(Tram *t);

    /**
     * Is the start Station of the Tram correct?
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     * REQUIRE(t->properlyInitialized(), "The tram must be properly initialized");
     */
    bool beginStationTramCorrect(Tram *t);

    /**
     * Does the metroNet have unique trams?
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     */
    bool uniqueTram();

    /**
     * Is the spoor Valid?
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
       REQUIRE(s->properlyInitialized(), "The spoor must be properly initialized");
     */
    bool validSpoor(Spoor *s);

    /**
     * Check the validity of Tram
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
       REQUIRE(t->properlyInitialized(), "The tram must be properly initialized");
     */
    bool controlTram(Tram *t);

    /**
     * Does the metroNet have unique stations?
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     */
    bool uniqueStation();

private:
    std::vector<Station *> fStations;
    std::vector<Tram *> fTrams;
    MetroNet *_fInitCheck;

    bool initializeStatCalled;

    /**
     * get the member variable initializeStatCalled
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
     */
    bool getInitializeStatCalled() const;

    /**
     * get the member variable initializeStatCalled to param b
     * REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
       ENSURE(getInitializeStatCalled() == b, "The setting was not successful");
     */
    void setInitializeStatCalled(bool b);

    Exporter exporter;
};


#endif //METRONET_XXX