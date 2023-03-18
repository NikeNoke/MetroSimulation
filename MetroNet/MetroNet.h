#ifndef METRONET_XXX
#define METRONET_XXX

#include <vector>
#include "../Station/Station.h"
#include "../Tram/Tram.h"
#include <string>

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
    MetroNet();

    /**
     * Destructor voor MetroNet.
     * **/
    ~MetroNet();


    /**
     * Method stationRegistered die controleert dat station attribute "naam" correct ingelezen wordt.
     * @param name wordt gecontroleert.
     * @return true of false afhankelijk ofdat het station correct werd ingelezen.
     * **/
    bool stationRegistered(const std::string &name) const;
    //bool tramRegistered(std::string& name) const;

    /**
     * Voegt station toe bij MetroNet.
     * @param station station dat toegevoegd wordt.
     * **/
    void addStation(Station *const station);

    /**
     * Voegt tram toe bij MetroNet.
     * @param tram tram dat toegevoegd wordt.
     * */
    void addTram(Tram *const tram);

    /**
     * Getter dat het station returned met parameter name.
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
    Tram *getTram(const std::string &name);

    /**
     * @return een vector met daarin alle stations.
     * **/
    std::vector<Station *> getStations();

    /**
     * @return een vector met daarin alle trammen.
     * **/
    std::vector<Tram *> getTrams();

    /**
     * Functie dat een tram verplaatst naar een station.
     * @param tram De tram die verplaatst zou worden.
     * @param nameStation De string die overeenkomt met de naam van een station en waarnaar de tram zal verplaatst
     * worden.
     * @return true of false afhankelijk ofdat de move gaat of niet gaat.
     * **/
    bool moveTram(Tram *const tram, const std::string &nameStation);

    /**
     * Functie dat test ofdat MetroNet correct geïnitialiseerd is.
     * @return true of false als het correct geïnitialiseerd is of als het niet correct geïnitialiseerd is.
     * **/
    bool properlyInitialized();

private:
    std::vector<Station *> stations;
    std::vector<Tram *> trams;
    MetroNet *_initCheck;
};


#endif //METRONET_XXX