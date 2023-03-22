#include <iostream>
#include "utils.h"
#include <cstdlib>
#include "../DesignByContract.h"
#include <sys/stat.h>
#include <fstream>


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
                std::cerr << "lijnNr van ingelezen fTrams is niet een nummer!\n";
                break;
            }
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            tempTram->setLijnNr(temp);
            lijnNrFound = true;

        } else if (innerElementName == "snelheid" && !snelheidFound) {
            if (!Utils::is_int(innerText)) {
                broken = true;
                std::cerr << "snelheid van ingelezen fTrams is niet een nummer!\n";
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

}


std::string Utils::boolToText(bool b) {
    if (b)
        return "gevonden";
    else
        return "niet gevonden";
}


//Source Stackoverflow
int Utils::getRandomInt(int max) {
    int min = 0;
    int output;
    output = min + (std::rand() % static_cast<int>(max - min + 1));
    return output;
}

/**
Auxiliary functions for file manipulation.
*/
bool Utils::directoryExists(const std::string dirname) {
    struct stat st;
    return stat(dirname.c_str(), &st) == 0;
}

bool Utils::fileExists(const std::string filename) {
    struct stat st;
    if (stat(filename.c_str(), &st) != 0) return false;
    std::ifstream f(filename.c_str());
    if (f.good()) {
        f.close();
        return true;
    } else {
        f.close();
        return false;
    }
}

bool Utils::fileIsEmpty(const std::string filename) {
    struct stat st;
    if (stat(filename.c_str(), &st) != 0) return true; // File does not exist; thus it is empty
    return st.st_size == 0;
}

