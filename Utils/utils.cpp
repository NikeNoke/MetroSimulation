#include <iostream>
#include "utils.h"
#include <cstdlib>
#include "../DesignByContract.h"


//Source stackoverflow
bool Utils::is_int(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool Utils::parseStation(MetroNet &metroNet, TiXmlElement *element) {
    REQUIRE(metroNet.properlyInitialized(), "The metroNet is not properly initialized");
    Station *tempStation = new Station;
    REQUIRE(tempStation->properlyInitialized(), "The new potential station is not properly initialized");
    bool broken = false;
    bool nameFound = false;
    bool volgendeFound = false;
    bool vorigeFound = false;
    bool spoorNrFound = false;

    for (TiXmlElement *InnerElement = element->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();
        if (innerElementName == "naam" && !nameFound) {
            if (metroNet.stationRegistered(innerText)) {
                broken = true;
                std::cerr << "Deze station bestaat al in de MetroNet!\n";
                break;
            }
            tempStation->setName(innerText);
            nameFound = true;
        } else if (innerElementName == "vorige" && !vorigeFound) {

            tempStation->setVorige(innerText);
            vorigeFound = true;
        } else if (innerElementName == "volgende" && !volgendeFound) {

            tempStation->setVolgende(innerText);
            volgendeFound = true;
        } else if (innerElementName == "spoorNr" && !spoorNrFound) {
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            tempStation->setSpoorNr(temp);
            spoorNrFound = true;
        } else {
            broken = true;
            std::cerr << "Ongeldige attribuut in Station XML!\n";
            break;
        }
    }
    if (!broken) {
        if (!nameFound || !vorigeFound || !volgendeFound || !spoorNrFound) {
            std::cerr << "De ingelezen station is incompleet!\n";
            std::cerr << "Naam van de station is " << Utils::boolToText(nameFound) << ", Vorige station is "
                      << Utils::boolToText(vorigeFound)
                      << ", Volgende station is " << Utils::boolToText(volgendeFound) << ", spoorNr is "
                      << Utils::boolToText(spoorNrFound) << "\n";

            std::cerr << "Na deze error gaan we naar de volgende XML childElement!\n";
            delete tempStation;
            return false;
        }
        metroNet.addStation(tempStation);
        return true;
    }
    std::cerr << "Na deze error gaan we naar de volgende XML childElement!\n";
    delete tempStation;
    return false;
}


bool Utils::parseTram(MetroNet &metroNet, TiXmlElement *element) {
    REQUIRE(metroNet.properlyInitialized(), "The metroNet is not properly initialized");
    Tram *tempTram = new Tram;
    REQUIRE(tempTram->properlyInitialized(), "The new potential tram is not properly initialized");
    bool broken = false;

    bool lijnNrFound = false;
    bool snelheidFound = false;
    bool beginStationFound = false;

    for (TiXmlElement *InnerElement = element->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "lijnNr" && !lijnNrFound) {
            if (!Utils::is_int(innerText)) {
                broken = true;
                std::cerr << "lijnNr van ingelezen trams is niet een nummer!\n";
                break;
            }
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            tempTram->setLijnNr(temp);
            lijnNrFound = true;

        } else if (innerElementName == "snelheid" && !snelheidFound) {
            if (!Utils::is_int(innerText)) {
                broken = true;
                std::cerr << "snelheid van ingelezen trams is niet een nummer!\n";
                break;
            }
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            tempTram->setSnelheid(temp);
            snelheidFound = true;

        } else if (innerElementName == "beginStation" && !beginStationFound) {
            tempTram->setBeginStation(innerText);
            tempTram->setHuidigStation(innerText);
            beginStationFound = true;
        } else {
            broken = true;
            std::cerr << "Ongekende attribuut in Tram\n";
        }
    }
    if (!broken) {
        if (!lijnNrFound || !snelheidFound || !beginStationFound) {
            std::cerr << "De ingelezen tram is incompleet!\n";
            std::cerr << "De begin station is " << Utils::boolToText(beginStationFound) << ", lijnNr is "
                      << Utils::boolToText(lijnNrFound)
                      << ", de snelheid is " << Utils::boolToText(snelheidFound) << "\n";

            std::cerr << "Na deze error gaan we naar de volgende XML childElement!\n";
            delete tempTram;
            return false;
        }
        metroNet.addTram(tempTram);
        return true;
    }
    std::cerr << "Na deze error gaan we naar de volgende XML childElement!\n";
    delete tempTram;
    return false;
}

void Utils::writeSpecs(std::ofstream &file, MetroNet &metroNet) {

    REQUIRE(metroNet.properlyInitialized(), "The metroNet is not properly initialized");

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

}


bool Utils::validMetroNet(MetroNet &metroNet) {

    REQUIRE(metroNet.properlyInitialized(), "The metroNet is not properly initialized");

    std::vector<Station *> tempStations = metroNet.getStations();
    std::vector<Tram *> tempTrams = metroNet.getTrams();

    for (long unsigned int i = 0; i < tempStations.size(); i++) {
        REQUIRE(tempStations[i]->properlyInitialized(), "A station of the metroNet is not properly initialized");
        if (!metroNet.stationRegistered(tempStations[i]->getVorige())) {
            std::cerr << "De vorige station " << tempStations[i]->getVorige() << "van station "
                      << tempStations[i]->getName()
                      << " is niet geregistreerd "
                      << "in de metroNet\n";
            return false;
        }

        if (!metroNet.stationRegistered(tempStations[i]->getVolgende())) {
            std::cerr << "De volgende station " << tempStations[i]->getVolgende() << "van station "
                      << tempStations[i]->getName()
                      << " is niet geregistreerd "
                      << "in de metroNet\n";
            return false;
        }

        Station *vorige = metroNet.getStation(tempStations[i]->getVorige());
        Station *volgende = metroNet.getStation(tempStations[i]->getVolgende());

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
        for (long unsigned int j = 0; i < tempTrams.size(); i++) {
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
        if (!metroNet.stationRegistered(tempTrams[i]->getBeginStation())) {
            std::cerr << "De begin station " << tempTrams[i]->getBeginStation() << "van tram met lijnNr "
                      << tempTrams[i]->getLijnNr() << " is niet geregistreerd " << "in de metroNet\n";
            return false;
        }
        Station *beginStation = metroNet.getStation(tempTrams[i]->getBeginStation());

        if (beginStation->getSpoorNr() != tempTrams[i]->getLijnNr()) {
            std::cerr << "De spoorNr van de begin station " << beginStation->getName()
                      << " komt niet overeen met de spoorNr van de tram met "
                      << "lijNr " << tempTrams[i]->getLijnNr() << "\n";
            return false;
        }

    }

    return true;
}


std::string Utils::boolToText(bool b) {
    if (b)
        return "gevonden";
    else
        return "niet gevonden";
}


void Utils::simulateMetroNet(MetroNet &metroNet, int amountOfMove) {

    REQUIRE(metroNet.properlyInitialized(), "The metroNet is not properly initialized");

    std::vector<Tram*> tempTrams = metroNet.getTrams();

    for (int i = 0; i < amountOfMove; i++) {
        int index = Utils::getRandomInt(tempTrams.size() - 1);
        Station *current = metroNet.getStation(tempTrams[index]->getHuidigStation());
        REQUIRE(current->properlyInitialized(), "The station to move the tram is not properly initialized");
        REQUIRE(tempTrams[index]->properlyInitialized(), "The tram to move is not properly initialized");
        if (Utils::getRandomInt(1)) {
            metroNet.moveTram(tempTrams[index], current->getVolgende());
        } else {
            metroNet.moveTram(tempTrams[index], current->getVorige());
        }
    }

}
//Source Stackoverflow
int Utils::getRandomInt(int max) {
    int min = 0;
    int output;
    output = min + (std::rand() % static_cast<int>(max - min + 1));
    return output;
}