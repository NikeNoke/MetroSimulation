//
// Created by byamba on 22/03/23.
//

#include "MetroNetGenerator.h"
#include "../Exporter/Exporter.h"

MetroNetGenerator::MetroNetGenerator(std::string pathToXml, std::string pathToWrite, std::string pathToWrite2
        , std::ostream& op, std::ostream& err)
        : exporter(pathToWrite, pathToWrite2, op, err), metroNet(exporter), _fInitcheck(this)
        {
    REQUIRE(!pathToXml.empty(), "Path to xml is empty");
    REQUIRE(!pathToWrite.empty(), "Path to simple is empty");
    REQUIRE(!pathToWrite2.empty(), "Path to advanced is empty");
    REQUIRE(Utils::fileExists(pathToXml), "Path to xml is wrong or file does not exist");
    setPathToOpenXml(pathToXml);
    setPathToSimple(pathToWrite);
    setPathToAdvanced(pathToWrite2);
    ENSURE(getPathToSimple() == pathToWrite, "Simple path was not set properly");
    ENSURE(getPathToAdvanced() == pathToWrite2, "Advanced path was not set properly");
    ENSURE(getPathToOpenXml() == pathToXml, "XML path was not set properly");
    ENSURE(getExporter().properlyInitialized(), "The exporter is not properly initialized");
    ENSURE(properlyInitialized(), "MetroNetGenerator is not properly initialized");
}

MetroNet &MetroNetGenerator::getMetroNet() {
    REQUIRE(properlyInitialized(), "MetroNetGenerator is not properly initialized");
    return metroNet;
}

std::string MetroNetGenerator::getPathToOpenXml() const {
    REQUIRE(properlyInitialized(), "MetroNetGenerator is not properly initialized");
    return pathToOpenXml;
}

void MetroNetGenerator::setPathToOpenXml(std::string &p) {
    REQUIRE(properlyInitialized(), "MetroNetGenerator is not properly initialized");
    REQUIRE(Utils::fileExists(p), "Path to xml is wrong or file does not exist");
    pathToOpenXml = p;
    ENSURE(getPathToOpenXml() == p, "The set was a failure");
}

void MetroNetGenerator::generateMetroNet(bool noStat) {
    REQUIRE(properlyInitialized(), "MetroNetGenerator is not properly initialized");
    REQUIRE(Utils::fileExists(getPathToOpenXml()), "The file to open does not exist");
    REQUIRE(getExporter().properlyInitialized(), "The exporter is not properly initialized");

    ParseMetroNet metroNetParser(getPathToOpenXml());

    metroNetParser.parseMetroNet(getMetroNet(), getExporter());

    getExporter().exportFile(getMetroNet());

    if (!noStat) {
        getMetroNet().getStatReport();
    }

    ENSURE(getMetroNet().isValidMetroNet(), "The metroNet is not valid");
}

void MetroNetGenerator::simulate(int seconds) {
    REQUIRE(properlyInitialized(), "MetroNetGenerator is not properly initialized");
    REQUIRE(getMetroNet().isValidMetroNet(), "The metroNet is not Valid");
    REQUIRE(getExporter().properlyInitialized(), "The exporter is not properly initialized");

    getMetroNet().simulateMetroNet(seconds);
    getExporter().exportFile(getMetroNet());
    getMetroNet().getStatReport();

    ENSURE(getMetroNet().isValidMetroNet(), "The metroNet is not Valid");
}

std::string MetroNetGenerator::getPathToAdvanced() const {
    REQUIRE(properlyInitialized(), "MetroNetGenerator is not properly initialized");
    return pathToWriteAdvanced;
}

void MetroNetGenerator::setPathToAdvanced(const std::string &s) {
    REQUIRE(properlyInitialized(), "MetroNetGenerator is not properly initialized");
    pathToWriteAdvanced = s;
    ENSURE(getPathToAdvanced() == s, "Not correctly set");
}

std::string MetroNetGenerator::getPathToSimple() const {
    REQUIRE(properlyInitialized(), "MetroNetGenerator is not properly initialized");
    return pathToWriteSimple;
}

void MetroNetGenerator::setPathToSimple(const std::string& s) {
    REQUIRE(properlyInitialized(), "MetroNetGenerator is not properly initialized");
    pathToWriteSimple = s;
    ENSURE(getPathToSimple() == s, "Not correctly set");
}

Exporter &MetroNetGenerator::getExporter() {
    REQUIRE(properlyInitialized(), "MetroNetGenerator is not properly initialized");
    REQUIRE(exporter.properlyInitialized(), "exporter is not properlyInitialized");
    return exporter;
}

bool MetroNetGenerator::properlyInitialized() const {
    return _fInitcheck == this;
}
