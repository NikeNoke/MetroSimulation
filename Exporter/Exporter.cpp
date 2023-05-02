//
// Created by byamba on 22/03/23.
//

#include "Exporter.h"
#include "../DesignByContract.h"
#include "../Utils/utils.h"
#include "../Spoor/Spoor.h"

bool Exporter::exportFile(MetroNet &metroNet) const {

    SimpleExport simpleExporter;
    simpleExporter.exportFile(metroNet, getPathToSimple());
    AdvancedExport advancedExport;
    advancedExport.exportFile(metroNet, getPathToAdvanced());
    return true;
}

Exporter::Exporter(std::string &pathS, std::string &pathA) {
//    REQUIRE(Utils::fileExists("../" + pathToF), "The file does not exist!");
    setPathToAdvanced(pathA);
    setPathToSimple(pathS); //TODO more ensures and requires
    _fInitCheck = this;
    ENSURE(getPathToAdvanced() == pathA, "pathToFile could not be opened");
    ENSURE(this->properlyInitialized(), "exporter is not properly initialized");
}

//void Exporter::setPathToFile(std::string f) {
////    REQUIRE(Utils::fileExists(f), "The file does not exist!");
//    pathToFile = f;
//    ENSURE(getPathToFile() == f, "The set operation was a failure");
//}
//
//std::string Exporter::getPathToFile() const {
//    return pathToFile;
//}

bool Exporter::properlyInitialized() const {
    return this == _fInitCheck;
}

Exporter::Exporter() {
    _fInitCheck = this;
    ENSURE(this->properlyInitialized(), "exporter is not properly initialized");
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
