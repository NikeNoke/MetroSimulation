//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_ADVANCEDEXPORT_H
#define METROSIMULATION_ADVANCEDEXPORT_H

//#include "../MetroNet/MetroNet.h"
#include "InterfaceExport.h"
#include <vector>

class MetroNet;
class Spoor;
/**
 * Klasse AdvancedExport dat overerft van InterfaceExport. Zorgt ervoor dat we files kunnen creëren
 * met een advanced path.
 * **/
class AdvancedExport : public InterfaceExport {
public:

    /**
     * Methode om een metroNet te exporteren naar een file.
     * REQUIRE(metroNet.properlyInitialized(), "The metroNet is not properly initialized");
     * REQUIRE(!path.empty(), "Path to write is empty");
     * REQUIRE(properlyInitialized(), "Advanced exporter is not properly initialized");
     * ENSURE(Utils::fileExists(path), "The file was not even created!");
     * **/
    bool exportFile(MetroNet &metroNet, const std::string& path) const;

    /**
     * Helperfunctie om een index van het volgende spoor.
     * @param container De vector waarin alle sporen zijn gelegen.
     * @param naam Naam van het spoor.
     * @return Index van het spoor of default -1 als er iets mis gaat.
     * **/
    int indexVolgende(std::vector<Spoor *> &container, const std::string &naam) const;

    bool properlyInitialized() const;

    /**
     * ENSURE(properlyInitialized() == true, "Advanced exporter was not initialized properly");
     */
    AdvancedExport();

private:
    AdvancedExport* _initCheck;
};


#endif //METROSIMULATION_ADVANCEDEXPORT_H
