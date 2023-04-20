//
// Created by byamba on 22/03/23.
//

#include <iostream>
#include "ParseMetroNet.h"
#include "../Utils/utils.h"
#include "../DesignByContract.h"
#include <cstdio>
#include "../ParseXML/ParseStation.h"
#include "../ParseXML/ParseTram.h"

bool ParseMetroNet::parseMetroNet(MetroNet &metroNet) {

    REQUIRE(loadFile(), "The file could not be loaded");

    TiXmlElement *root = getDoc().FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        getDoc().Clear();
        return false;
    }

    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();
        if (current == "STATION") {

            Station* station = new Station();
            ParseStation parseStation(element);
            if(!parseStation.parseAll(station))
                delete station; //In testing een foutboodschap gegeven?
            else
                metroNet.addStation(station);

        } else if (current == "TRAM") {

            Tram* tram = new Tram();
            ParseTram parseTram(element);
            if(!parseTram.parseAll(tram))
                delete tram;
            else
                metroNet.addTram(tram);

        } else{
            std::cerr << "Deze element is ongekend!\n";
        }
    }

    getDoc().Clear();

    if(metroNet.isValidMetroNetSilent())
        return true;
    else
        return false;

}

bool ParseMetroNet::loadFile() {
    REQUIRE(getPathToFile() != NULL, "pathToFile is NULL");
    bool success = getDoc().LoadFile(getPathToFile());
    ENSURE(success, "File could not be loaded");
    return success;
}

ParseMetroNet::ParseMetroNet(std::string pathToFil) {
    REQUIRE(Utils::fileExists(pathToFil), "The file does not exist!");
    setPathToFile(std::fopen(pathToFil.c_str(), "r"));
    ENSURE(getPathToFile() != NULL, "pathToFile could not be opened");
}

TiXmlDocument &ParseMetroNet::getDoc() {
    return doc;
}

FILE *ParseMetroNet::getPathToFile() const {
    return pathToFile;
}

bool ParseMetroNet::setPathToFile(FILE *f) {
    REQUIRE(f != NULL, "The File prt is NULL");
    pathToFile = f;
    ENSURE(pathToFile == f, "setting was not successful");
    return true;
}
