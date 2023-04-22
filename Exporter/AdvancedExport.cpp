//
// Created by byamba on 20/04/23.
//

#include "AdvancedExport.h"
#include "../Utils/utils.h"
#include "../DesignByContract.h"
#include "../Spoor/Spoor.h"
#include <map>
#include <vector>

bool AdvancedExport::exportFile(MetroNet &metroNet, std::string path) const {

    REQUIRE(metroNet.properlyInitialized(), "The metroNet is not properly initialized");
    REQUIRE(!path.empty(), "Path to write is empty");
//    REQUIRE(Utils::)

    std::ofstream file;

    file.open(path.c_str());

//    file << "--== STATIONS ==--\n";

    std::vector<Station *> tempStations = metroNet.getStations();
    std::vector<Tram *> tempTrams = metroNet.getTrams();

    std::map<int, std::vector<Spoor* > > spoorMap;

    for (long unsigned int i = 0; i < tempStations.size(); i++) {
//        Station* currentStation = tempStations[i];
        for(unsigned int j = 0; j < tempStations[i]->getSporen().size(); j++){
            Spoor* currentSpoor = tempStations[i]->getSporen()[j];
            const int nr = currentSpoor->getSpoorNr();

            spoorMap[nr].push_back(currentSpoor);
        }
    }

    std::map<int, std::vector<Spoor* > >::iterator it;

    for(it = spoorMap.begin(); it != spoorMap.end(); it++){

        std::vector<std::string> correctOrder;

        correctOrder.push_back(it->second[0]->getVorige());
        correctOrder.push_back(it->second[0]->getHuiding());
        correctOrder.push_back(it->second[0]->getVolgende());

        std::string toSearch = it->second[0]->getVolgende();

        while(correctOrder.size() < it->second.size()){

            int index = indexVolgende(it->second, toSearch);

            toSearch = it->second[index]->getVolgende();

            correctOrder.push_back(toSearch);

        }

        for(unsigned int j = 0; j < correctOrder.size(); j++){

            file << "=" << correctOrder[j] << "=";

        }
        file << "\n";

        for(unsigned int j = 0; j < correctOrder.size(); j++){

            if(metroNet.aTramAtStation(correctOrder[j]))
                file << " T ";
            else
                file << "   ";
        }
        file << "\n";

        file << "\n";
    }


    ENSURE(Utils::fileExists(path), "The file was not even created!");
//    ENSURE(!Utils::fileIsEmpty(getPathToFile()), "The written file is empty");
    return true;
}

int AdvancedExport::indexVolgende(std::vector<Spoor* >&container, const std::string& naam) const {

    for(unsigned int i = 0; i < container.size(); i++){
        if(container[i]->getHuiding() == naam)
            return i;
    }

    return -1;
}
