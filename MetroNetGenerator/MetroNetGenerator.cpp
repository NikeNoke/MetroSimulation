//
// Created by byamba on 22/03/23.
//

#include "MetroNetGenerator.h"
#include "../Exporter/Exporter.h"

MetroNetGenerator::MetroNetGenerator(std::string pathToXml, std::string pathToWrit) {
    REQUIRE(Utils::fileExists(pathToXml), "Path to xml is wrong or file does not exist");
    setPathToOpenXml(pathToXml);
    setPathToWrite(pathToWrit);
//    exporter.setPathToFile(pathToWrit);
}

MetroNet &MetroNetGenerator::getMetroNet() {
    return metroNet;
}

std::string MetroNetGenerator::getPathToOpenXml() const {
    return pathToOpenXml;
}

std::string MetroNetGenerator::getPathToWrite() const {
    return pathToWrite;
}

void MetroNetGenerator::setPathToOpenXml(std::string p) {
    REQUIRE(Utils::fileExists(p), "Path to xml is wrong or file does not exist");
    pathToOpenXml = p;
    ENSURE(getPathToOpenXml() ==  p, "The set was a failure");

}

void MetroNetGenerator::setPathToWrite(std::string p) {
    pathToWrite = p;
    ENSURE(getPathToWrite() == p, "The setting was failure");
}

void MetroNetGenerator::generateMetroNet() {

    REQUIRE(Utils::fileExists(getPathToOpenXml()), "The file to open does not exist");

    ParseMetroNet metroNetParser(getPathToOpenXml());

    metroNetParser.parseMetroNet(metroNet);

    Exporter exporter(getPathToWrite());

    exporter.exportFile(metroNet);

    ENSURE(metroNet.isValidMetroNet(), "The metroNet is not valid");
    ENSURE(Utils::fileExists(getPathToWrite()), "The file was not even created");

}
