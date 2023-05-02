//
// Created by byamba on 20/04/23.
//

#include "SimpleExport.h"
#include "../Utils/utils.h"
#include "../DesignByContract.h"
#include "../Spoor/Spoor.h"

bool SimpleExport::exportFile(MetroNet &metroNet, std::string path) const {

    REQUIRE(metroNet.properlyInitialized(), "The metroNet is not properly initialized");
    REQUIRE(!path.empty(), "Path to write is empty");
//    REQUIRE(Utils::)

    std::ofstream file;

    file.open(path.c_str());

    file << "--== STATIONS ==--\n";

    std::vector<Station *> tempStations = metroNet.getStations();
    std::vector<Tram *> tempTrams = metroNet.getTrams();

    for (long unsigned int i = 0; i < tempStations.size(); i++) {
        file << "= Station " << tempStations[i]->getName() << " =\n";
//        file << "\t\tVorige Station: " << tempStations[i]->getVorige() << "\n";
//        file << "\t\tVolgende Station: " << tempStations[i]->getVolgende() << "\n";
        for (unsigned int j = 0; j < tempStations[i]->getSporen().size(); j++) {
            file << "* Spoor " << tempStations[i]->getSporen()[j]->getSpoorNr() << ":\n";
            file << "\t-> Station " << tempStations[i]->getSporen()[j]->getVolgende() << "\n";
            file << "\t<- Station  " << tempStations[i]->getSporen()[j]->getVorige() << "\n";
            file << "\n";
        }
    }

    file << "--== TRAMS ==--\n";

    for (long unsigned int i = 0; i < tempTrams.size(); i++) {
        Tram *currentTram = tempTrams[i];
        file << "Tram " << currentTram->getLijnNr() << " nr " << currentTram->getVoertuigNummer() << "\n";
        file << "\ttype: " << currentTram->getType() << "\n";
        file << "\tsnelheid: " << currentTram->getSnelheid() << "\n";
        file << "\thuidig station: " << currentTram->getHuidigStation() << "\n";
        //reparatie kosten
        file << "\n";
    }

    ENSURE(Utils::fileExists(path), "The file was not even created!");
//    ENSURE(!Utils::fileIsEmpty(getPathToFile()), "The written file is empty");
    return true;
}
