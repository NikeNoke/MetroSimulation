//
// Created by byamba on 22/03/23.
//

#include <iostream>
#include "Exporter.h"
#include "../DesignByContract.h"
#include "../Spoor/Spoor.h"
#include "../Utils/utils.h"

bool Exporter::exportFile(MetroNet &metroNet) const {

    SimpleExport simpleExporter;
    REQUIRE(simpleExporter.properlyInitialized(), "Simple exporter is not properly initialized");
    simpleExporter.exportFile(metroNet, getPathToSimple());
    AdvancedExport advancedExport;
    REQUIRE(simpleExporter.properlyInitialized(), "Advanced exporter is not properly initialized");
    advancedExport.exportFile(metroNet, getPathToAdvanced());
    ENSURE(Utils::fileExists(getPathToSimple()), "File for simple was not created");
    ENSURE(Utils::fileExists(getPathToAdvanced()), "File for advanced was not created");
    return true;
}

bool Exporter::properlyInitialized() const {
    return this == _fInitCheck;
}

void Exporter::writeToOperation(const std::string &load) {
    getOperationStream() << load << std::flush;
}

Exporter::Exporter(std::string pathToSimple, std::string pathToAdvanced, std::ostream &op, std::ostream &err)
    : pathToSimple(pathToSimple), pathToAdvanced(pathToAdvanced), operationStream(op), errorLog(err), _fInitCheck(this)
{
    REQUIRE(!pathToSimple.empty(), "The path to simple may not be empty");
    REQUIRE(!pathToAdvanced.empty(), "The path t0 advanced may not be empty");
    ENSURE(getPathToSimple() == pathToSimple, "This exporter's path to simple was not set properly");
    ENSURE(getPathToAdvanced() == pathToAdvanced, "This exporter's path to advanced was not set properly");
    ENSURE(getOperationStream() == op, "This exporter's operation stream was not set properly");
    ENSURE(getErrorStream() == err, "This exporter's error stream was not set properly");
    ENSURE(properlyInitialized(), "The exporter is not properly initialized");
}

void Exporter::writeToError(const std::string &load) {
    getErrorStream() << load << std::flush;
}

std::ostream &Exporter::getOperationStream() {
    return operationStream;
}

std::ostream &Exporter::getErrorStream() {
    return errorLog;
}

std::string Exporter::getPathToAdvanced() const {
    return pathToAdvanced;
}

void Exporter::setPathToAdvanced(const std::string &p) {
    Exporter::pathToAdvanced = p;
    ENSURE(getPathToAdvanced() == p, "Setting of path to advanced was not done properly");
}

std::string Exporter::getPathToSimple() const {
    return pathToSimple;
}

void Exporter::setPathToSimple(const std::string &p) {
    Exporter::pathToSimple = p;
    ENSURE(getPathToAdvanced() == p, "Setting of path to simple was not done properly");
}
