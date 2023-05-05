//
// Created by byamba on 22/03/23.
//

#include "MetroNetGenerator.h"
#include "../Exporter/Exporter.h"

MetroNetGenerator::MetroNetGenerator(std::string pathToXml, std::string pathToWrite, std::string pathToWrite2) {
    REQUIRE(Utils::fileExists(pathToXml), "Path to xml is wrong or file does not exist");
    setPathToOpenXml(pathToXml);
    setPathToWrite(pathToWrite);
//    exporter = Exporter(pathToWrit);
//    exporter.setPathToFile(pathToWrit);
    //ENSURE NEEDED? --> set op does it already!
    exporter.setPathToSimple(pathToWrite);
    exporter.setPathToAdvanced(pathToWrite2);
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

void MetroNetGenerator::setPathToOpenXml(std::string &p) {
    REQUIRE(Utils::fileExists(p), "Path to xml is wrong or file does not exist");
    pathToOpenXml = p;
    ENSURE(getPathToOpenXml() == p, "The set was a failure");

}

void MetroNetGenerator::setPathToWrite(std::string &p) {
    pathToWrite = p;
    ENSURE(getPathToWrite() == p, "The setting was failure");
}

void MetroNetGenerator::generateMetroNet(bool noStat) {

    REQUIRE(Utils::fileExists(getPathToOpenXml()), "The file to open does not exist");

    ParseMetroNet metroNetParser(getPathToOpenXml());

    metroNetParser.parseMetroNet(getMetroNet());

    getExporter().exportFile(getMetroNet());

    if (!noStat) {
        getMetroNet().getStatReport();
    }

    ENSURE(getMetroNet().isValidMetroNet(), "The metroNet is not valid");
    ENSURE(Utils::fileExists(getPathToWrite()), "The file was not even created");

}

void MetroNetGenerator::simulate(int seconds) {
    REQUIRE(getMetroNet().isValidMetroNet(), "The metroNet is not Valid");

    getMetroNet().simulateMetroNet(seconds);
    getExporter().exportFile(getMetroNet());
    getMetroNet().getStatReport();

    ENSURE(getMetroNet().isValidMetroNet(), "The metroNet is not Valid");
}

Exporter &MetroNetGenerator::getExporter() {
    REQUIRE(exporter.properlyInitialized(), "exporter is not properlyInitialized");
    return exporter;
}

//std::string MetroNetGenerator::getPathToLog() const {
//    return pathToLog;
//}
//
//void MetroNetGenerator::setPathToLog(std::string &p) {
//    pathToLog = p;
//}
