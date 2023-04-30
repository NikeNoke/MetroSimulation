//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_SIMPLEEXPORT_H
#define METROSIMULATION_SIMPLEEXPORT_H
#include "../MetroNet/MetroNet.h"
#include "InterfaceExport.h"

/**
 * Klasse SimpleExport dat van InterfaceExport overerft.
 *
 * **/
class SimpleExport: public InterfaceExport {
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
    bool exportFile(MetroNet& metroNet, std::string path) const;
private:

};


#endif //METROSIMULATION_SIMPLEEXPORT_H
