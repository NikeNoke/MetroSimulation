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
     * @pre REQUIRE(metroNet.properlyInitialized(), "The metroNet is not properly initialized")
     * @pre REQUIRE(!path.empty(), "Path to write is empty")
     * @post ENSURE(Utils::fileExists(path), "The file was not even created!")
     * @param metroNet Het metroNet dat geëxporteerd zal zijn.
     * @param path van de file.
     * @return true or false
     * **/
    bool exportFile(MetroNet &metroNet, const std::string& path) const;

    /**
     * Helperfunctie om een index van het volgende spoor.
     * @param container De vector waarin alle sporen zijn gelegen.
     * @param naam Naam van het spoor.
     * @return Index van het spoor of default -1 als er iets mis gaat.
     * **/
    int indexVolgende(std::vector<Spoor *> &container, const std::string &naam) const;

private:

};


#endif //METROSIMULATION_ADVANCEDEXPORT_H
