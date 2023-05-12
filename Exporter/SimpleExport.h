//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_SIMPLEEXPORT_H
#define METROSIMULATION_SIMPLEEXPORT_H

//#include "../MetroNet/MetroNet.h"
#include "InterfaceExport.h"

class MetroNet;

/**
 * Klasse SimpleExport dat van InterfaceExport overerft.
 *
 * **/
class SimpleExport : public InterfaceExport {
public:

    /**
     * Methode om een metroNet te exporteren naar een file.
        REQUIRE(metroNet.properlyInitialized(), "The metroNet is not properly initialized");
        REQUIRE(properlyInitialized(), "This simple exporter isn ot properly initialized");
        REQUIRE(!path.empty(), "Path to write is empty");
        ENSURE(Utils::fileExists(path), "The file was not even created!");
     * @return true or false
     * **/
    bool exportFile(MetroNet &metroNet, const std::string& path) const;

    bool properlyInitialized() const;


    /**
     * ENSURE(properlyInitialized() == true, "Simple exporter was not initialized properly");
     */
    SimpleExport();

private:
    SimpleExport* _initCheck;
};


#endif //METROSIMULATION_SIMPLEEXPORT_H
