//
// Created by byamba on 22/03/23.
//

#include "Exporter.h"
#include "../MetroNet/MetroNet.h"
#include "../DesignByContract.h"
#include "../Utils/utils.h"

bool Exporter::exportFile(MetroNet& metroNet) const {

    REQUIRE(metroNet.properlyInitialized(), "The metroNet is not properly initialized");
    REQUIRE(!getPathToFile().empty(), "Path to write is empty");
//    REQUIRE(Utils::)

    std::ofstream file;

    file.open(getPathToFile().c_str());

    file << "Stations: \n";

    std::vector<Station *> tempStations = metroNet.getStations();
    std::vector<Tram *> tempTrams = metroNet.getTrams();

    for (long unsigned int i = 0; i < tempStations.size(); i++) {
        file << "\tstation" << i << ":\n";
        file << "\t\tNaam: " << tempStations[i]->getName() << "\n";
        file << "\t\tVorige Station: " << tempStations[i]->getVorige() << "\n";
        file << "\t\tVolgende Station: " << tempStations[i]->getVolgende() << "\n";
    }

    file << "Trams: \n";

    for (long unsigned int i = 0; i < tempTrams.size(); i++) {
        file << "\ttram" << i << ":\n";
        file << "\t\tLijnNr: " << tempTrams[i]->getLijnNr() << "\n";
        file << "\t\tSnelheid: " << tempTrams[i]->getSnelheid() << "\n";
        file << "\t\tBegin station: " << tempTrams[i]->getBeginStation() << "\n";
        file << "\t\tHuidig station: " << tempTrams[i]->getHuidigStation() << "\n";
    }

    ENSURE(Utils::fileExists(getPathToFile()), "The file was not even created!");
    ENSURE(!Utils::fileIsEmpty(getPathToFile()), "The written file is empty");
    return true;
}

Exporter::Exporter(std::string pathToF) {
//    REQUIRE(Utils::fileExists("../" + pathToF), "The file does not exist!");
    setPathToFile(pathToF);
    _fInitCheck = this;
    ENSURE(getPathToFile() == pathToF, "pathToFile could not be opened");
    ENSURE(this->properlyInitialized(), "exporter is not properly initialized");
}

void Exporter::setPathToFile(std::string f) {
//    REQUIRE(Utils::fileExists(f), "The file does not exist!");
    pathToFile = f;
    ENSURE(getPathToFile() == f, "The set operation was a failure");
}

std::string Exporter::getPathToFile() const {
    return pathToFile;
}

bool Exporter::properlyInitialized() const {
    return this == _fInitCheck;
}

Exporter::Exporter() {
    _fInitCheck = this;
    ENSURE(this->properlyInitialized(), "exporter is not properly initialized");
}
