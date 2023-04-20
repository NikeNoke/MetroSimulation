//
// Created by byamba on 20/03/23.
//

#include "ParseStation.h"
#include "../Utils/utils.h"
#include "ParseSpoor.h"

ParseStation::ParseStation(TiXmlElement *element)
        : element(element)
{
    REQUIRE(element != NULL, "TixmlElement is NULL");
    _fInitcheck = this;
    ENSURE(getElement() == element, "TixmlElement is not the element of the parser");
    ENSURE(properlyInitialized(), "ParseSpoor has been properly initialized");
}

void ParseStation::setElement(TiXmlElement *el) {
    REQUIRE(el != NULL, "TixmlElement is NULL");
    element = el;
    ENSURE(getElement() == element, "TixmlElement is not the element of the parser");
}

bool ParseStation::parseAll(Station* station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidStation() == true, "The Station tag is not correct");
// REQUIRE(checkValidNaam() == true, "The name tag is not correct in this Station tag");
// REQUIRE(checkValidVorige() == true, "The vorige tag is not correct in this Station tag");
// REQUIRE(checkValidSpoorNr() == true, "The spoorNr tag is not correct in this Station tag");
// REQUIRE(checkValidVolgende() == true, "The volgende tag is not correct in this Station tag");

    if(!parseNaam(station) || parseSpoor(station)
        || !parseTypeStation(station))
        return false;

    ENSURE(!station->getName().empty(), "The naam of station has not been correctly initialized");
//    for(unsigned int i = 0; i < station->getSporen().size(); i++){
//        ENSURE(station->getSporen()[i]->, "A spoor of Station is not properly")
//    }
    ENSURE(!station->getSporen().empty(), "The SPOOR's of station has not been correctly initialized");
    ENSURE(!station->getType().empty(), "The type of station has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");

    return true;
}

bool ParseStation::checkValidNaam() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfNamen = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "naam"){
            if(!Utils::is_int(innerText))
                amountOfNamen++;
            else
                return false;
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return amountOfNamen == 1;
}

bool ParseStation::checkValidStation() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    return checkValidNaam()  && checkValidTypeStation() && !checkNonValidAttributes();
}


bool ParseStation::parseNaam(Station* station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidNaam() == true, "The name tag is not correct in this Station tag");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "naam"){
            station->setName(innerText);
            return true;
        }
    }
    ENSURE(!station->getName().empty(), "The naam of station has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}


bool ParseStation::checkNonValidAttributes() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "naam")
            continue;
        if(innerElementName == "type")
            continue;
        if(innerElementName == "SPOOR")
            continue;
        return true;
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return false;
}

TiXmlElement *ParseStation::getElement() const {
    return element;
}

bool ParseStation::checkValidTypeStation() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfVolgende = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "type"){
            if(!Utils::is_int(innerText))
                amountOfVolgende++;
            else
                return false;
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return amountOfVolgende == 1;
}

bool ParseStation::parseTypeStation(Station *station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidTypeStation() == true, "The type tag is not correct in this Station tag");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "type"){
            station->setType(innerText);
            return true;
        }
    }
    ENSURE(!station->getType().empty(), "The type of station has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseStation::properlyInitialized() {
    return _fInitcheck == this;
}

bool ParseStation::parseSpoor(Station *station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "SPOOR"){
            Spoor* spoor = new Spoor;
            ParseSpoor parseSpoor(InnerElement);
            if (!parseSpoor.parseAll(spoor)){
                delete spoor;
                return false;
            }
            station->addSpoor(spoor);
        }
    }
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    ENSURE(!station->getSporen().empty(), "The sporen cannot be empty");
    return true;
}
