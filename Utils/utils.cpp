#include <iostream>
#include "utils.h"
#include <cstdlib>



bool Utils::is_int(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void Utils::parseStation(MetroNet &metroNet, TiXmlElement *element) {
    Station tempStation;

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
            if(metroNet.stationRegistered(innerText)){
                broken = true;
                std::cerr << "Deze station bestaat al in de MetroNet!\n";
                break;
            }
            tempStation.naam = innerText;
            nameFound = true;
        } else if (innerElementName == "vorige" && !vorigeFound) {

            tempStation.vorige = innerText;
            vorigeFound = true;
        } else if (innerElementName == "volgende" && !volgendeFound) {

            tempStation.volgende = innerText;
            volgendeFound = true;
        } else if (innerElementName == "spoorNr" && !spoorNrFound) {
            sscanf(innerText.c_str(), "%d", &tempStation.spoorNr);
            spoorNrFound = true;
        } else {
            broken = true;
            std::cerr << "Ongeldige attribuut in Station XML!\n";
            break;
        }
    }
    if(!broken){
        if(!nameFound || !vorigeFound || !volgendeFound || !spoorNrFound){
            std::cerr << "De ingelezen station is incompleet!\n";
            std::cerr << "Naam van de station is " << Utils::boolToText(nameFound) << ", Vorige station is " << Utils::boolToText(vorigeFound)
                      << ", Volgende station is " << Utils::boolToText(volgendeFound) << ", spoorNr is " << Utils::boolToText(spoorNrFound) << "\n";

            std::cerr << "Na deze error gaan we naar de volgende XML childElement!\n";

            return;
        }
        metroNet.addStation(tempStation);
        return;
    }
    std::cerr << "Na deze error gaan we naar de volgende XML childElement!\n";
}


void Utils::parseTram(MetroNet &metroNet, TiXmlElement *element) {
    Tram tempTram;
    bool broken = false;

    bool lijnNrFound = false;
    bool snelheidFound = false;
    bool beginStationFound = false;

    for (TiXmlElement *InnerElement = element->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "lijnNr" && !lijnNrFound) {
            if(!Utils::is_int(innerText)){
                broken = true;
                std::cerr << "lijnNr van ingelezen trams is niet een nummer!\n";
                break;
            }
            sscanf(innerText.c_str(), "%d", &tempTram.lijnNr);
            lijnNrFound = true;

        } else if (innerElementName == "snelheid" && !snelheidFound) {
            if(!Utils::is_int(innerText)){
                broken = true;
                std::cerr << "snelheid van ingelezen trams is niet een nummer!\n";
                break;
            }
            sscanf(innerText.c_str(), "%d", &tempTram.snelheid);
            snelheidFound = true;

        } else if (innerElementName == "beginStation" && !beginStationFound) {
            tempTram.beginStation = innerText;
            tempTram.huidigStation = innerText;
            beginStationFound = true;
        } else {
            broken = true;
            std::cerr << "Ongekende attribuut in Tram\n";
        }
    }
    if(!broken){
        if(!lijnNrFound || !snelheidFound || !beginStationFound){
            std::cerr << "De ingelezen tram is incompleet!\n";
            std::cerr << "De begin station is " << Utils::boolToText(beginStationFound) << ", lijnNr is " << Utils::boolToText(lijnNrFound)
                      << ", de snelheid is " << Utils::boolToText(snelheidFound) << "\n";

            std::cerr << "Na deze error gaan we naar de volgende XML childElement!\n";

            return;
        }
        metroNet.addTram(tempTram);
        return;
    }
    std::cerr << "Na deze error gaan we naar de volgende XML childElement!\n";
}

void Utils::writeSpecs(std::ofstream &file, MetroNet &metroNet) {


    file << "Stations: \n";


    for(long unsigned int i = 0; i < metroNet.stations.size(); i++){
        file << "\tstation" << i << ":\n";
        file << "\t\tNaam: " << metroNet.stations[i].naam << "\n";
        file << "\t\tVorige Station: " << metroNet.stations[i].vorige << "\n";
        file << "\t\tVolgende Station: " << metroNet.stations[i].volgende << "\n";
    }

    file << "Trams: \n";

    for(long unsigned int i = 0; i < metroNet.trams.size(); i++){
        file << "\ttram" << i << ":\n";
        file << "\t\tLijnNr: " << metroNet.trams[i].lijnNr << "\n";
        file << "\t\tSnelheid: " << metroNet.trams[i].snelheid << "\n";
        file << "\t\tBegin station: " << metroNet.trams[i].beginStation << "\n";
    }

}


bool Utils::validMetroNet(MetroNet &metroNet) {


    for(long unsigned int i = 0; i < metroNet.stations.size(); i++){

        Station current = metroNet.stations[i];

        if(!metroNet.stationRegistered(current.vorige)){
            std::cerr << "De vorige station " << current.vorige << "van station " << current.naam << " is niet geregistreerd "
            << "in de metroNet\n";
            return false;
        }

        if(!metroNet.stationRegistered(current.volgende)){
            std::cerr << "De volgende station " << current.volgende << "van station " << current.naam << " is niet geregistreerd "
                      << "in de metroNet\n";
            return false;
        }

        Station* vorige = metroNet.getStation(current.vorige);
        Station* volgende = metroNet.getStation(current.volgende);

        if(current.spoorNr != vorige->spoorNr){
            std::cerr << "De spoorNr van station " << current.naam << " komt niet overeen met de spoorNr van zijn vorige "
            << "station " << vorige->naam << "\n";
            return false;
        }

        if(current.spoorNr != volgende->spoorNr){
            std::cerr << "De spoorNr van station " << current.naam << " komt niet overeen met de spoorNr van zijn volgende "
                      << "station " << volgende->naam << "\n";
            return false;
        }

        bool spoorHeeftTram = false;
        for(long unsigned int j = 0; i< metroNet.trams.size(); i++) {

            if(current.spoorNr == metroNet.trams[j].lijnNr){
                spoorHeeftTram = true;
                break;
            }
        }

        if(!spoorHeeftTram){
            std::cerr << "De spoorNr van station " << current.naam << " heeft geen TRAM!!!!\n";
            return false;
        }

    }

    for(long unsigned int i = 0; i< metroNet.trams.size(); i++){
        Tram current = metroNet.trams[i];

        if(!metroNet.stationRegistered(current.beginStation)){
            std::cerr << "De begin station " << current.beginStation << "van tram met lijnNr " << current.lijnNr << " is niet geregistreerd "
                      << "in de metroNet\n";
            return false;
        }
        Station* beginStation = metroNet.getStation(current.beginStation);

        if(beginStation->spoorNr != current.lijnNr){
            std::cerr << "De spoorNr van de begin station " << beginStation->naam << " komt niet overeen met de spoorNr van de tram met "
            << "lijNr " << current.lijnNr << "\n";
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


//    std::vector<Tram>* trams = metroNet.getTrams();

    for(int i = 0; i< amountOfMove; i++){
        int index = Utils::getRandomInt(metroNet.trams.size()-1);
        Station* current = metroNet.getStation(metroNet.trams[index].huidigStation);
        if(Utils::getRandomInt(1)){
            metroNet.moveTram(metroNet.trams[index], current->volgende);
        }else{
            metroNet.moveTram(metroNet.trams[index], current->vorige);
        }
    }


}

int Utils::getRandomInt(int max){
    int min = 0;
    int output;
    output = min + (std::rand() % static_cast<int>(max - min + 1));
    return output;
}