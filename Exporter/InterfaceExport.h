//
// Created by byamba on 21/04/23.
//

#ifndef METROSIMULATION_INTERFACEEXPORT_H
#define METROSIMULATION_INTERFACEEXPORT_H


//#include "../MetroNet/MetroNet.h"
#include <fstream>

class MetroNet;

/*
 * Pure virtual klasse dat dient voor files te exporten.
 * */
class InterfaceExport {

public:
    /**
     * Pure virtual methode.
     * Methode om een metroNet te exporteren naar een file.
        REQUIRE(metroNet.properlyInitialized(), "The metroNet is not properly initialized");
        REQUIRE(properlyInitialized(), "This simple exporter isn ot properly initialized");
        REQUIRE(!path.empty(), "Path to write is empty");
        ENSURE(Utils::fileExists(path), "The file was not even created!");
     * @return true or false
     * **/
    virtual bool exportFile(MetroNet &metroNet, const std::string& path) const = 0;

private:
};


#endif //METROSIMULATION_INTERFACEEXPORT_H
