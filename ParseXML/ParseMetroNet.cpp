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
#include "../Exporter/Exporter.h"

bool ParseMetroNet::parseMetroNet(MetroNet &metroNet, Exporter& e) {

    REQUIRE(loadFile(), "The file could not be loaded");

    TiXmlElement *root = getDoc().FirstChildElement();
    if (root == NULL) {
        e.writeToError("Failed to load file: No root element.\n");
        getDoc().Clear();
        return false;
    }

    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();
        if (current == "STATION") {

            ParseStation parseStation(element);
            if (parseStation.parseSuccessful(e))
                metroNet.addStation(parseStation.getParsedStation());
            else {
                e.writeToError("STATION TAG COULD NOT BE PARSED\n");
                continue;
            }

        } else if (current == "TRAM") {

            ParseTram parseTram(element);
            if (parseTram.parseSuccessful(e))
                metroNet.addTram(parseTram.getParsedTram());
            else{
                e.writeToError("TRAM TAG COULD NOT BE PARSED\n");
                continue;
            }

        } else {
            e.writeToError("This tag in the metronet is unknown\n");
        }
    }

    getDoc().Clear();

    if (metroNet.isValidMetroNet()) {
        metroNet.initializeStat();
        return true;
    } else
        return false;

}

bool ParseMetroNet::loadFile() {
    REQUIRE(getPathToInput() != NULL, "pathToFile is NULL");
    bool success = getDoc().LoadFile(getPathToInput());
    ENSURE(success, "File could not be loaded");
    return success;
}

ParseMetroNet::ParseMetroNet(const std::string &pathToInput) {
    REQUIRE(!pathToInput.empty(), "Path to xml is empty");
    REQUIRE(Utils::fileExists(pathToInput), "The file does not exist!");
    setPathToInput(std::fopen(pathToInput.c_str(), "r"));
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

ParseMetroNet::~ParseMetroNet() {
    fclose(getPathToInput());
}
