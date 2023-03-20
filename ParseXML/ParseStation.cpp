//
// Created by byamba on 20/03/23.
//

#include "ParseStation.h"
#include "../Utils/utils.h"

ParseStation::ParseStation(TiXmlElement *element)
    : fElement(element)
{
    REQUIRE(element != NULL, "TixmlElement is NULL");
    ENSURE(this->fElement == element, "TixmlElement is not the fElement of the parser");
}

void ParseStation::setElement(TiXmlElement *el) {
    REQUIRE(el != NULL, "TixmlElement is NULL");
    fElement = el;
    ENSURE(this->fElement == fElement, "TixmlElement is not the fElement of the parser");
}

bool ParseStation::parseAll(MetroNet &metroNet, Station* station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(fElement != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidStation() == true, "The Station tag is not correct");
//    REQUIRE(checkValidNaam() == true, "The name tag is not correct in this Station tag");
//    REQUIRE(checkValidVorige() == true, "The fVorige tag is not correct in this Station tag");
//    REQUIRE(checkValidSpoorNr() == true, "The fSpoorNr tag is not correct in this Station tag");
//    REQUIRE(checkValidVolgende() == true, "The fVolgende tag is not correct in this Station tag");

    if(!parseNaam(metroNet, station) || !parseSpoorNr(metroNet, station) || !parseVolgende(metroNet, station) || !parseVorige(metroNet, station))
        return false;

    ENSURE(!station->getName().empty(), "The fNaam of station has not been correctly initialized");
    ENSURE(!station->getVorige().empty(), "The fVorige of station has not been correctly initialized");
    ENSURE(!station->getVolgende().empty(), "The fVolgende of station has not been correctly initialized");
    ENSURE(station->getSpoorNr() != -1, "The fSpoorNr of station has not been correctly initialized");
    ENSURE(fElement != NULL, "TixmlElement is NULL");

    return true;
}

bool ParseStation::checkValidNaam() const {

    REQUIRE(fElement != NULL, "TixmlElement is NULL");

    int amountOfNamen = 0;

    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fNaam"){
            if(!Utils::is_int(innerText))
                amountOfNamen++;
            else
                return false;
        }
    }

    ENSURE(fElement != NULL, "TixmlElement has become NULL");

    return amountOfNamen == 1;
}

bool ParseStation::checkValidVorige() const {

    REQUIRE(fElement != NULL, "TixmlElement is NULL");

    int amountOfVorige = 0;

    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fVorige"){
            if(!Utils::is_int(innerText))
                amountOfVorige++;
            else
                return false;
        }
    }

    ENSURE(fElement != NULL, "TixmlElement has become NULL");

    return amountOfVorige == 1;
}

bool ParseStation::checkValidStation() const {

    REQUIRE(fElement != NULL, "TixmlElement is NULL");

    return checkValidNaam() && checkValidVorige() && checkValidSpoorNr() && checkValidVolgende() && !checkNonValidAttributes();
}

bool ParseStation::checkValidVolgende() const {

    REQUIRE(fElement != NULL, "TixmlElement is NULL");

    int amountOfVolgende = 0;

    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fVolgende"){
            if(!Utils::is_int(innerText))
                amountOfVolgende++;
            else
                return false;
        }
    }

    ENSURE(fElement != NULL, "TixmlElement has become NULL");

    return amountOfVolgende == 1;
}

bool ParseStation::checkValidSpoorNr() const {

    REQUIRE(fElement != NULL, "TixmlElement is NULL");

    int amountOfSpoorNr = 0;

    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fSpoorNr"){
            if(Utils::is_int(innerText))
                amountOfSpoorNr++;
            else
                return false;
        }
    }

    ENSURE(fElement != NULL, "TixmlElement has become NULL");

    return amountOfSpoorNr == 1;
}

bool ParseStation::parseNaam(MetroNet &metroNet, Station* station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(fElement != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidNaam() == true, "The name tag is not correct in this Station tag");


    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fNaam"){
            station->setName(innerText);
            return true;
        }
    }
    ENSURE(!station->getName().empty(), "The fNaam of station has not been correctly initialized");
    ENSURE(fElement != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseStation::parseVorige(MetroNet &metroNet, Station *station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(fElement != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidVorige() == true, "The fVorige tag is not correct in this Station tag");


    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fVorige"){
            station->setVorige(innerText);
            return true;
        }
    }
    ENSURE(!station->getVorige().empty(), "The fVorige of station has not been correctly initialized");
    ENSURE(fElement != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseStation::parseVolgende(MetroNet &metroNet, Station *station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(fElement != NULL, "TixmlElement is NULL");
//    REQUIRE(checkValidVolgende() == true, "The fVolgende tag is not correct in this Station tag");

    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fVolgende"){
            station->setVolgende(innerText);
            return true;
        }
    }
//    ENSURE(!station->getVolgende().empty(), "The fVolgende of station has not been correctly initialized");
    ENSURE(fElement != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseStation::parseSpoorNr(MetroNet &metroNet, Station *station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(fElement != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidSpoorNr() == true, "The fSpoorNr tag is not correct in this Station tag");


    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fSpoorNr"){
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            station->setSpoorNr(temp);
            return true;
        }
    }
    ENSURE(station->getSpoorNr() != -1, "The fSpoorNr of station has not been correctly initialized");
    ENSURE(fElement != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseStation::checkNonValidAttributes() const {

    REQUIRE(fElement != NULL, "TixmlElement is NULL");


    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fSpoorNr")
            continue;
        if(innerElementName == "fVolgende")
            continue;
        if(innerElementName == "fVorige")
            continue;
        if(innerElementName == "fNaam")
            continue;
        return true;
    }

    ENSURE(fElement != NULL, "TixmlElement has become NULL");

    return false;
}






