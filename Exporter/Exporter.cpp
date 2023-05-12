//
// Created by byamba on 22/03/23.
//

#include <iostream>
#include "Exporter.h"
#include "../DesignByContract.h"
#include "../Spoor/Spoor.h"

bool Exporter::exportFile(MetroNet &metroNet) const {

    SimpleExport simpleExporter;
    simpleExporter.exportFile(metroNet, getPathToSimple());
    AdvancedExport advancedExport;
    advancedExport.exportFile(metroNet, getPathToAdvanced());
    return true;
}

bool Exporter::properlyInitialized() const {
    return this == _fInitCheck;
}

void Exporter::writeToOperation(const std::string &load) {
    getOperationStream() << load;
}

Exporter::Exporter(std::string pathToSimple, std::string pathToAdvanced, std::ostream &op, std::ostream &err)
    : pathToSimple(pathToSimple), pathToAdvanced(pathToAdvanced), operationStream(op), errorLog(err)
{
//    ENSURE()
//    ENSURE()
//    ENSURE()
//    ENSURE()
}

void Exporter::writeToError(const std::string &load) {
    getErrorStream() << load;
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
}

std::string Exporter::getPathToSimple() const {
    return pathToSimple;
}

void Exporter::setPathToSimple(const std::string &p) {
    Exporter::pathToSimple = p;
}
