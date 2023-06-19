//
// Created by byamba on 22/03/23.
//

#ifndef METROSIMULATION_EXPORTER_H
#define METROSIMULATION_EXPORTER_H


#include <cstdio>
#include <string>
#include "AdvancedExport.h"
#include "SimpleExport.h"
#include <fstream>
#include "Metronet/MetronetFileLogger.h"

class Station;
class Spoor;
class Tram;

class MetroNet;

/**
 * Exporter klasse voor files te creëren en exporten.
 * **/
class Exporter {
public:

    /**
        REQUIRE(!pathToSimple.empty(), "The path to simple may not be empty");
        REQUIRE(!pathToAdvanced.empty(), "The path t0 advanced may not be empty");
        ENSURE(getPathToSimple() == pathToSimple, "This exporter's path to simple was not set properly");
        ENSURE(getPathToAdvanced() == pathToAdvanced, "This exporter's path to advanced was not set properly");
        ENSURE(getOperationStream() == op, "This exporter's operation stream was not set properly");
        ENSURE(getErrorStream() == err, "This exporter's error stream was not set properly");
        ENSURE(properlyInitialized(), "The exporter is not properly initialized");
        ENSURE(getMetroNetLogger().properlyInitialized(), "MetronetLogger is not properly initialized");
     * **/
    explicit Exporter(std::string pathToSimple, std::string pathToAdvanced, std::ostream& op, std::ostream& err);


    /**
     * REQUIRE(properlyInitialized(), "The exporter is not properly initialized");
        REQUIRE(simpleExporter.properlyInitialized(), "Simple exporter is not properly initialized");
        REQUIRE(simpleExporter.properlyInitialized(), "Advanced exporter is not properly initialized");
        ENSURE(Utils::fileExists(getPathToSimple()), "File for simple was not created");
        ENSURE(Utils::fileExists(getPathToAdvanced()), "File for advanced was not created");
     * **/
    bool exportFile(MetroNet &metroNet) const;

    /**
     * Controleerd ofdat de exporter correct geïnitialiseerd werd.
     * @return true or false
     * **/
    bool properlyInitialized() const;

    /**
     * Write to operation
     * @param load
     */
    void writeToOperation(const std::string& load);

    /**
     */
    void writeToError(const std::string& load);


    /**
     * Getter dat de pathToAdvanded teruggeeft.
     * REQUIRE(properlyInitialized(), "The exporter is not properly initialized");
     * @return pathToAdvanced
     * **/
    std::string getPathToAdvanced() const;

    /**
     * Setter dat de pathToAdvanced set.
     * REQUIRE(properlyInitialized(), "The exporter is not properly initialized");
     * ENSURE(getPathToAdvanced() == p, "Setting of path to advanced was not done properly");
     * **/
    void setPathToAdvanced(const std::string &pathToAdvanced);


    /**
     * Getter dat de pathToSimple teruggeeft.
     * REQUIRE(properlyInitialized(), "The exporter is not properly initialized");
     * @return pathToAdvanced
     * **/
    std::string getPathToSimple() const;

    /**
     * Setter dat de pathToSimple set.
     * REQUIRE(properlyInitialized(), "The exporter is not properly initialized");
     * ENSURE(getPathToSimple() == p, "Setting of path to simple was not done properly");
     * **/
    void setPathToSimple(const std::string &pathToSimple);

    /**
     * get operation stream
     * @return
     */
    std::ostream &getOperationStream();

    /**
     * get error stream
     * @return
     */
    std::ostream &getErrorStream();

    /**
     * REQUIRE(metronetFileLogger.properlyInitialized(), "MetronetLogger is not properly initialized");
     */
    MetronetFileLogger& getMetroNetLogger();

//    ~Exporter();

    //TODO all kinds of message display!
//    virtual void nonUniqueStations();
//
//    virtual void stationNotValid(Station* );
//
//    virtual void tramsNotUnique();
//
//    virtual void tramNotValid();
//
//    virtual void metronetInvalid();
//
//    virtual void nonUniqueSporenInStation(Station* );
//
//    virtual void nonValidSpoor();
//
//    virtual void spoorHasNoTram(Spoor*);
//
//    virtual void beginStationOfTramNotRegistered(Tram* );
//
//    virtual void beginStationOfTramLijnNrWrong(Tram* );
//
//    virtual void previousStationOfSpoorNotRegistered(Spoor* );
//
//    virtual void nextStationOfSpoorNotRegistered(Spoor* );
//
//    virtual void nextStationOfSpoorNotSameNr(Spoor* );
//
//    virtual void previousStationOfSpoorNotSameNr(Spoor* );
//
//    virtual void tramNotCorrect(Tram* );
//
//    virtual void tramHasNoStation(Tram* );
//
//    virtual void tramMoveNotCTram(int tramSpoorAtStation, const std::string& stationName, int currentTram);
//
//    virtual void statReport(const std::vector<Tram*>& trams, const std::vector<Station* >& stations);
//
//    virtual void stationNotUnique(const std::string& name, int amount);

private:

    std::string pathToSimple; //TODO change to streams
    std::string pathToAdvanced;
    std::ostream& operationStream;
    std::ostream& errorLog;
    Exporter *_fInitCheck;
public:
    MetronetFileLogger metronetFileLogger;

};


#endif //METROSIMULATION_EXPORTER_H
