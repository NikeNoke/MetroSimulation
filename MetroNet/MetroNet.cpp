#include <iostream>
#include "MetroNet.h"
#include "../Utils/utils.h"
#include "../DesignByContract.h"

bool MetroNet::stationRegistered(const std::string &name) const {
    REQUIRE(!(Utils::is_int(name)), "The parameter name is a number");
    for (long unsigned int i = 0; i < fStations.size(); i++) {
        if (fStations[i]->getName() == name)
            return true;
    }
    return false;
}

//bool MetroNet::tramRegistered(std::string &name) const { //
//    for(int i = 0; i < fTrams.size(); i++){
//        if(fTrams[i].lijnNr == name)
//            return true;
//    }
//    return false;
//}

void MetroNet::addStation(Station *const station) {
    REQUIRE(station->properlyInitialized(), "The parameter station is not properly initialized");
    REQUIRE(!stationRegistered(station->getName()), "The station is already in the metroNet");
    fStations.push_back(station);
    ENSURE(stationRegistered(station->getName()), "The station was not successfully added");
}

void MetroNet::addTram(Tram *const tram) {
    REQUIRE(tram->properlyInitialized(), "The parameter tram is not properly initialized");
//    Require not registered
    fTrams.push_back(tram);
    //Ensure registered
}

Station *MetroNet::getStation(const std::string &name) {
    REQUIRE(!(Utils::is_int(name)), "The parameter name is a number");
    for (long unsigned int i = 0; i < fStations.size(); i++) {
        if (fStations[i]->getName() == name)
            return fStations[i];
    }
    return NULL;
}

//Tram *MetroNet::getTram(std::string &name) {
//    for(int i = 0; i < fTrams.size(); i++){
//        if(fTrams[i].naam == name)
//            return &fTrams[i];
//    }
//    return NULL;
//}

std::vector<Station *> MetroNet::getStations() {
    return fStations;
}

std::vector<Tram *> MetroNet::getTrams() {
    return fTrams;
}


bool MetroNet::moveTram(Tram *const tram, const std::string &nameStation) {

    REQUIRE(tram->properlyInitialized(), "The parameter tram is not properly initialized");
    REQUIRE(!(Utils::is_int(nameStation)), "The parameter nameStation is a number");
    Station *current = getStation(tram->getHuidigStation());

    if (nameStation != current->getVorige() && nameStation != current->getVolgende()) {
        std::cerr << "De tram kan niet verplaatst worden naar " << nameStation << "\n";
        return false;
    }

    if (nameStation == current->getVorige()) {
        std::cout << "De tram " << tram->getLijnNr() << " reed van station " << tram->getHuidigStation()
                  << " naar station " << current->getVorige() << "\n";
        tram->setHuidigStation(current->getVorige());
        return true;
    } else {
        std::cout << "De tram " << tram->getLijnNr() << " reed van station " << tram->getHuidigStation()
                  << " naar station " << current->getVolgende() << "\n";
        tram->setHuidigStation(current->getVolgende());
        return true;
    }
}

MetroNet::~MetroNet() {
    for (unsigned long int i = 0; i < fStations.size(); i++) {
        delete fStations[i];
    }
    for (unsigned long int i = 0; i < fTrams.size(); i++) {
        delete fTrams[i];
    }
}

MetroNet::MetroNet() {
    _fInitCheck = this;
}

bool MetroNet::properlyInitialized() const{
    return _fInitCheck == this;
}

bool MetroNet::isValidMetroNet() {

    REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");

    std::vector<Station *> tempStations = this->getStations();
    std::vector<Tram *> tempTrams = this->getTrams();

    for (long unsigned int i = 0; i < tempStations.size(); i++) {
        REQUIRE(tempStations[i]->properlyInitialized(), "A station of the metroNet is not properly initialized");
        if (!this->stationRegistered(tempStations[i]->getVorige())) {
            std::cerr << "De vorige station " << tempStations[i]->getVorige() << "van station "
                      << tempStations[i]->getName()
                      << " is niet geregistreerd "
                      << "in de metroNet\n";
            return false;
        }

        if (!this->stationRegistered(tempStations[i]->getVolgende())) {
            std::cerr << "De volgende station " << tempStations[i]->getVolgende() << "van station "
                      << tempStations[i]->getName()
                      << " is niet geregistreerd "
                      << "in de metroNet\n";
            return false;
        }

        Station *vorige = this->getStation(tempStations[i]->getVorige());
        Station *volgende = this->getStation(tempStations[i]->getVolgende());

        if(vorige->getVolgende() != tempStations[i]->getName())
            return false;
        if(volgende->getVorige() != tempStations[i]->getName())
            return false;

        if (tempStations[i]->getSpoorNr() != vorige->getSpoorNr()) {
            std::cerr << "De spoorNr van station " << tempStations[i]->getName()
                      << " komt niet overeen met de spoorNr van zijn vorige "
                      << "station " << vorige->getName() << "\n";
            return false;
        }

        if (tempStations[i]->getSpoorNr() != volgende->getSpoorNr()) {
            std::cerr << "De spoorNr van station " << tempStations[i]->getName()
                      << " komt niet overeen met de spoorNr van zijn volgende "
                      << "station " << volgende->getName() << "\n";
            return false;
        }

        bool spoorHeeftTram = false;
        for (long unsigned int j = 0; j < tempTrams.size(); j++) {
            REQUIRE(tempTrams[j]->properlyInitialized(), "A tram of the metroNet is not properly initialized");
            if (tempStations[i]->getSpoorNr() == tempTrams[j]->getLijnNr()) {
                spoorHeeftTram = true;
                break;
            }
        }

        if (!spoorHeeftTram) {
            std::cerr << "De spoorNr van station " << tempStations[i]->getName() << " heeft geen TRAM!!!!\n";
            return false;
        }

    }

    for (long unsigned int i = 0; i < tempTrams.size(); i++) {
        REQUIRE(tempTrams[i]->properlyInitialized(), "A tram of the metroNet is not properly initialized");
        if (!this->stationRegistered(tempTrams[i]->getBeginStation())) {
            std::cerr << "De begin station " << tempTrams[i]->getBeginStation() << "van tram met lijnNr "
                      << tempTrams[i]->getLijnNr() << " is niet geregistreerd " << "in de metroNet\n";
            return false;
        }
        Station *beginStation = this->getStation(tempTrams[i]->getBeginStation());

        if (beginStation->getSpoorNr() != tempTrams[i]->getLijnNr()) {
            std::cerr << "De spoorNr van de begin station " << beginStation->getName()
                      << " komt niet overeen met de spoorNr van de tram met "
                      << "lijNr " << tempTrams[i]->getLijnNr() << "\n";
            return false;
        }

    }

    return true;
}

bool MetroNet::isValidMetroNetSilent() {

    REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");

    std::vector<Station *> tempStations = this->getStations();
    std::vector<Tram *> tempTrams = this->getTrams();

    for (long unsigned int i = 0; i < tempStations.size(); i++) {
        REQUIRE(tempStations[i]->properlyInitialized(), "A station of the metroNet is not properly initialized");
        if (!this->stationRegistered(tempStations[i]->getVorige())) {
            return false;
        }

        if (!this->stationRegistered(tempStations[i]->getVolgende())) {
            return false;
        }

        Station *vorige = this->getStation(tempStations[i]->getVorige());
        Station *volgende = this->getStation(tempStations[i]->getVolgende());

        if(vorige->getVolgende() != tempStations[i]->getName())
            return false;
        if(volgende->getVorige() != tempStations[i]->getName())
            return false;

        if (tempStations[i]->getSpoorNr() != vorige->getSpoorNr()) {
            return false;
        }

        if (tempStations[i]->getSpoorNr() != volgende->getSpoorNr()) {
            return false;
        }

        bool spoorHeeftTram = false;
        for (long unsigned int j = 0; j < tempTrams.size(); j++) {
            REQUIRE(tempTrams[j]->properlyInitialized(), "A tram of the metroNet is not properly initialized");
            if (tempStations[i]->getSpoorNr() == tempTrams[j]->getLijnNr()) {
                spoorHeeftTram = true;
                break;
            }
        }

        if (!spoorHeeftTram) {
            return false;
        }

    }

    for (long unsigned int i = 0; i < tempTrams.size(); i++) {
        REQUIRE(tempTrams[i]->properlyInitialized(), "A tram of the metroNet is not properly initialized");
        if (!this->stationRegistered(tempTrams[i]->getBeginStation())) {
            return false;
        }
        Station *beginStation = this->getStation(tempTrams[i]->getBeginStation());

        if (beginStation->getSpoorNr() != tempTrams[i]->getLijnNr()) {
            return false;
        }

    }

    return true;
}

void MetroNet::simulateMetroNet(int seconds) {

    REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");

    std::vector<Tram*> tempTrams = this->getTrams();

    for (int i = 0; i < seconds; i++) {

        for(unsigned long int j = 0; j < tempTrams.size(); j++){
            Station *current = this->getStation(tempTrams[j]->getHuidigStation());
            REQUIRE(current->properlyInitialized(), "The station to move the tram is not properly initialized");
            REQUIRE(tempTrams[j]->properlyInitialized(), "The tram to move is not properly initialized");
            REQUIRE(stationRegistered(current->getName()), "The current station of the tram is not registered");

            REQUIRE(stationRegistered(current->getVolgende()), "The station to move is not registered");

            tempTrams[j]->moveTram(current->getVolgende());

            ENSURE(tempTrams[j]->getHuidigStation() == current->getVolgende(), "The moving of the tram was not successful");
        }
    }
}


