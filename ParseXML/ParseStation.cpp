//
// Created by byamba on 20/03/23.
//

#include <iostream>
#include "ParseStation.h"
#include "../Utils/utils.h"
#include "ParseSpoor.h"
#include "../Stations/MetronetStation.h"
#include "../Stations/HalteStation.h"

ParseStation::ParseStation(TiXmlElement *element)
        : element(element) {
    REQUIRE(element != NULL, "TixmlElement is NULL");
    _fInitcheck = this;
    ENSURE(getElement() == element, "TixmlElement is not the element of the parser");
    ENSURE(properlyInitialized(), "ParseSpoor has been properly initialized");
}

void ParseStation::setElement(TiXmlElement *el) {
    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    REQUIRE(el != NULL, "TixmlElement is NULL");
    element = el;
    ENSURE(getElement() == element, "TixmlElement is not the element of the parser");
}

bool ParseStation::parseAll(Exporter& e) {

    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(e.properlyInitialized(), "The exporter must be properly initialized");
    if(!checkValidStation(e))
        return false;

    Station *station;

    if (getStationType(e) == TypeStation::MetroStation)
        station = new MetronetStation;
    else if (getStationType(e) == TypeStation::Halte)
        station = new HalteStation;
    else {
        e.writeToError("The station type is not correct\n");
        return false;
    }

    if (!parseNaam(station, e) || !parseTypeStation(station, e) || !parseSpoor(station, e)) {
        delete station;
        return false;
    }

    setParsedStation(station);

    ENSURE(!station->getName().empty(), "The naam of station has not been correctly initialized");
    ENSURE(!station->getSporen().empty(), "The SPOOR's of station has not been correctly initialized");
    ENSURE(!station->getType().empty(), "The type of station has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    ENSURE(getParsedStation() != NULL, "parsedStation is Null");

    return true;
}

bool ParseStation::checkValidNaam(Exporter& e) const {
    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfNamen = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        if (innerElementName == "SPOOR")
            continue;
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "naam") {
            if (!Utils::is_int(innerText)) {
                amountOfNamen++;
            } else {
                e.writeToError("The name tag is not correct in this Station tag\n");
                return false;
            }
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    if(amountOfNamen != 1){
        e.writeToError("The name tag is not correct in this Station tag\n");
        return false;
    }
    return true;
}

bool ParseStation::checkValidStation(Exporter& e) const {
    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    bool one = checkValidNaam(e);
    bool two = checkValidTypeStation(e);
    bool three = !checkNonValidAttributes(e);
    bool four = checkSporen(e);
    return one && two && three && four;
}

bool ParseStation::checkSporen(Exporter& e) const {
    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    int spoorAantal = 0;
    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        if (innerElementName == "SPOOR") {
            ParseSpoor parseSpoor(InnerElement);
            if (!parseSpoor.checkValidSpoor(e)) {
                return false;
            }
            spoorAantal++;
        }


    }
    ENSURE(getElement() != NULL, "TixmlElement has become NULL");
    return spoorAantal > 0;
}

bool ParseStation::parseNaam(Station *station, Exporter& e) const {
    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidNaam(e) == true, "The name tag is not correct in this Station tag");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        if (innerElementName == "SPOOR")
            continue;
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "naam") {
            station->setName(innerText);
            return true;
        }
    }
    ENSURE(!station->getName().empty(), "The naam of station has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}


bool ParseStation::checkNonValidAttributes(Exporter& e) const {
    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        if (innerElementName == "SPOOR")
            continue;
        if (innerElementName == "naam")
            continue;
        if (innerElementName == "type")
            continue;
        e.writeToError("Station has non valid tag!\n");
        return true;
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return false;
}

TiXmlElement *ParseStation::getElement() const {
    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    return element;
}

bool ParseStation::checkValidTypeStation(Exporter& e) const {
    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfVolgende = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        if (innerElementName == "SPOOR")
            continue;
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "type") {
            if (!Utils::is_int(innerText)) {
                if(innerText == "Metrostation" || innerText == "Halte")
                    amountOfVolgende++;
                else{
                    e.writeToError("The type of STATION TAG is not known\n");
                    return false;
                }
            } else {
                e.writeToError("The type of STATION TAG is a number\n");
                return false;
            }
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    if(amountOfVolgende != 1){
        e.writeToError("The amount of type tag in STATION is not equal to one\n");
        return false;
    }
    return true;
}

bool ParseStation::parseTypeStation(Station *station, Exporter& e) const {
    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidTypeStation(e) == true, "The type tag is not correct in this Station tag");


    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        if (innerElementName == "SPOOR")
            continue;
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "type") {
            station->setType(innerText);
            return true;
        }
    }
    ENSURE(!station->getType().empty(), "The type of station has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseStation::properlyInitialized() const{
    return _fInitcheck == this;
}

bool ParseStation::parseSpoor(Station *station, Exporter& e) const {
    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    if(!checkSporen(e)){
        e.writeToError("The Station has no SPOOR\n");
        return false;
    }

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();

        if (innerElementName == "SPOOR") {
            Spoor *spoor = new Spoor;
            ParseSpoor parseSpoor(InnerElement);
            if (!parseSpoor.parseAll(spoor, e)) {
                delete spoor;
                return false;
            }
            spoor->setHuidig(station->getName());
            if (!station->addSpoor(spoor)) {
                e.writeToError("Halte kan enkel 1 spoor hebben!\n");
                return false;
            }
        }
    }
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    ENSURE(!station->getSporen().empty(), "The sporen cannot be empty");
    return true;
}

TypeStation::StationType ParseStation::getStationType(Exporter& e) const {
    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidTypeStation(e) == true, "The type tag is not correct in this Station tag");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        if (innerElementName == "SPOOR")
            continue;
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "type") {
            if (innerText == "Metrostation")
                return TypeStation::MetroStation;
            if (innerText == "Halte")
                return TypeStation::Halte;
            else
                return TypeStation::Invalid;
        }
    }
    return TypeStation::Invalid;
}

bool ParseStation::parseSuccessful(Exporter& e) {
    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    return parseAll(e);
}

void ParseStation::setParsedStation(Station *s) {
    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    parsedStation = s;
    ENSURE(getParsedStation() == s, "The setting was not successful");
}

Station *ParseStation::getParsedStation() const {
    REQUIRE(properlyInitialized(), "ParseSpoor has been properly initialized");
    return parsedStation;
}
