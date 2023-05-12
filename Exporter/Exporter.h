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

class MetroNet;

/**
 * Exporter klasse voor files te creëren en exporten.
 * **/
class Exporter {
public:

    /**
     * Explicit constructor van ons met variabelen.
     * @post ENSURE(getPathToAdvanced() == pathA, "pathToFile could not be opened");
     * @post ENSURE(this->properlyInitialized(), "exporter is not properly initialized");
     * @param pathToSimple
     * @param pathToAdvanced
     * **/
    explicit Exporter(std::string pathToSimple, std::string pathToAdvanced, std::ostream& op, std::ostream& err);

    /**
     * Default constructor van de klasse Exporter.
     * @post ENSURE(this->properlyInitialized(), "exporter is not properly initialized")
     * @return Exporter object.
     * **/
//    explicit Exporter(std::ostream & s);

    /**
     * Creërt een file dat oveereenkomt met metroNet en exporteerd deze.
     * @param metroNet Het metroNet dat geëxporteerd zal worden.
     * @return true or false
     * **/
    bool exportFile(MetroNet &metroNet) const;

//    std::string getPathToFile() const;

//    void setPathToFile(std::string f);

    /**
     * Controleerd ofdat de exporter correct geïnitialiseerd werd.
     * @return true or false
     * **/
    bool properlyInitialized() const;

    void writeToOperation(const std::string& load);

    void writeToError(const std::string& load);


    /**
     * Getter dat de pathToAdvanded teruggeeft.
     * @return pathToAdvanced
     * **/
    std::string getPathToAdvanced() const;

    /**
     * Setter dat de pathToAdvanced set.
     * @param pathToAdvanced
     * **/
    void setPathToAdvanced(const std::string &pathToAdvanced);


    /**
     * Getter dat de pathToSimple teruggeeft.
     * @return pathToAdvanced
     * **/
    std::string getPathToSimple() const;

    /**
     * Setter dat de pathToSimple set.
     * @param pathToSimple
     * **/
    void setPathToSimple(const std::string &pathToSimple);

//    const std::ofstream& getStream() const;

//    void setStream(std::ofstream& s);

//    ~Exporter();

    std::ostream &getOperationStream();

    std::ostream &getErrorStream();

//    void setWriteStream(std::ostream& s);

private:

    std::string pathToSimple; //TODO change to streams
    std::string pathToAdvanced;
    std::ostream& operationStream;
    std::ostream& errorLog;
    Exporter *_fInitCheck;

};


#endif //METROSIMULATION_EXPORTER_H
