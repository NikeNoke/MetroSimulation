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

            ParseStation parseStation(element);
            if(parseStation.parseSuccessful())
                metroNet.addStation(parseStation.getParsedStation());
            else
                continue; //TODO message display?

        } else if (current == "TRAM") {

            ParseTram parseTram(element);
            if(parseTram.parseSuccessful())
                metroNet.addTram(parseTram.getParsedTram());
            else
                continue;

        } else{
            std::cerr << "Deze element is ongekend!\n";
        }
    }

    getDoc().Clear();

    if(metroNet.isValidMetroNet())
        return true;
    else
        return false;

}

bool ParseMetroNet::loadFile() {
    REQUIRE(getPathToInput() != NULL, "pathToFile is NULL");
    bool success = getDoc().LoadFile(getPathToInput());
    ENSURE(success, "File could not be loaded");
    return success;
}

ParseMetroNet::ParseMetroNet(const std::string& pathToInput) {
    REQUIRE(Utils::fileExists(pathToInput), "The file does not exist!");
//    REQUIRE(!pathToLog.empty(), "Path to log is empty");
    setPathToInput(std::fopen(pathToInput.c_str(), "r"));

//    std::ofstream file;
//
//    file.open(path.c_str());
//    setPathToLog(std::fopen(pathToLog.c_str(), "r"));
    ENSURE(getPathToInput() != NULL, "pathToFile could not be opened");
}

TiXmlDocument &ParseMetroNet::getDoc() {
    return doc;
}

FILE *ParseMetroNet::getPathToInput() const {
    return pathToInput;
}

bool ParseMetroNet::setPathToInput(FILE *f) {
    REQUIRE(f != NULL, "The File prt is NULL");
    pathToInput = f;
    ENSURE(getPathToInput() == f, "setting was not successful");
    return true;
}

//FILE *ParseMetroNet::getPathToLog() const {
//    return pathToLog;
//}
//
//bool ParseMetroNet::setPathToLog(FILE *f) {
//    REQUIRE(f != NULL, "The File prt is NULL");
//    pathToLog = f;
//    ENSURE(getPathToLog() == f, "setting was not successful");
//    return true;
//}
