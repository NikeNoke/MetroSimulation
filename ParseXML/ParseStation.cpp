//
// Created by byamba on 20/03/23.
//

#include "ParseStation.h"
#include "../Utils/utils.h"

ParseStation::ParseStation(TiXmlElement *element)
    : element(element)
{
    REQUIRE(element != NULL, "TixmlElement is NULL");
    ENSURE(this->element == element, "TixmlElement is not the element of the parser");
}

void ParseStation::setElement(TiXmlElement *el) {
    REQUIRE(el != NULL, "TixmlElement is NULL");
    element = el;
    ENSURE(this->element == element, "TixmlElement is not the element of the parser");
}

bool ParseStation::parseAll(MetroNet &metroNet, Station* station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(element != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidStation() == true, "The Station tag is not correct");
//    REQUIRE(checkValidNaam() == true, "The name tag is not correct in this Station tag");
//    REQUIRE(checkValidVorige() == true, "The vorige tag is not correct in this Station tag");
//    REQUIRE(checkValidSpoorNr() == true, "The spoorNr tag is not correct in this Station tag");
//    REQUIRE(checkValidVolgende() == true, "The volgende tag is not correct in this Station tag");

    if(!parseNaam(metroNet, station) || !parseSpoorNr(metroNet, station) || !parseVolgende(metroNet, station) || !parseVorige(metroNet, station))
        return false;

    ENSURE(!station->getName().empty(), "The naam of station has not been correctly initialized");
    ENSURE(!station->getVorige().empty(), "The vorige of station has not been correctly initialized");
    ENSURE(!station->getVolgende().empty(), "The volgende of station has not been correctly initialized");
    ENSURE(station->getSpoorNr() != -1, "The spoorNr of station has not been correctly initialized");
    ENSURE(element != NULL, "TixmlElement is NULL");

    return true;
}

bool ParseStation::checkValidNaam() const {

    REQUIRE(element != NULL, "TixmlElement is NULL");

    int amountOfNamen = 0;

    for (TiXmlElement *InnerElement = element->FirstChildElement();
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

    ENSURE(element != NULL, "TixmlElement has become NULL");

    return amountOfNamen == 1;
}

bool ParseStation::checkValidVorige() const {

    REQUIRE(element != NULL, "TixmlElement is NULL");

    int amountOfVorige = 0;

    for (TiXmlElement *InnerElement = element->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "vorige"){
            if(!Utils::is_int(innerText))
                amountOfVorige++;
            else
                return false;
        }
    }

    ENSURE(element != NULL, "TixmlElement has become NULL");

    return amountOfVorige == 1;
}

bool ParseStation::checkValidStation() const {

    REQUIRE(element != NULL, "TixmlElement is NULL");

    return checkValidNaam() && checkValidVorige() && checkValidSpoorNr() && checkValidVolgende() && !checkNonValidAttributes();
}

bool ParseStation::checkValidVolgende() const {

    REQUIRE(element != NULL, "TixmlElement is NULL");

    int amountOfVolgende = 0;

    for (TiXmlElement *InnerElement = element->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "volgende"){
            if(!Utils::is_int(innerText))
                amountOfVolgende++;
            else
                return false;
        }
    }

    ENSURE(element != NULL, "TixmlElement has become NULL");

    return amountOfVolgende == 1;
}

bool ParseStation::checkValidSpoorNr() const {

    REQUIRE(element != NULL, "TixmlElement is NULL");

    int amountOfSpoorNr = 0;

    for (TiXmlElement *InnerElement = element->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "spoorNr"){
            if(Utils::is_int(innerText))
                amountOfSpoorNr++;
            else
                return false;
        }
    }

    ENSURE(element != NULL, "TixmlElement has become NULL");

    return amountOfSpoorNr == 1;
}

bool ParseStation::parseNaam(MetroNet &metroNet, Station* station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(element != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidNaam() == true, "The name tag is not correct in this Station tag");


    for (TiXmlElement *InnerElement = element->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "naam"){
            station->setName(innerText);
            return true;
        }
    }
    ENSURE(!station->getName().empty(), "The naam of station has not been correctly initialized");
    ENSURE(element != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseStation::parseVorige(MetroNet &metroNet, Station *station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(element != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidVorige() == true, "The vorige tag is not correct in this Station tag");


    for (TiXmlElement *InnerElement = element->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "vorige"){
            station->setVorige(innerText);
            return true;
        }
    }
    ENSURE(!station->getVorige().empty(), "The vorige of station has not been correctly initialized");
    ENSURE(element != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseStation::parseVolgende(MetroNet &metroNet, Station *station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(element != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidVolgende() == true, "The volgende tag is not correct in this Station tag");

    for (TiXmlElement *InnerElement = element->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "volgende"){
            station->setVolgende(innerText);
            return true;
        }
    }
    ENSURE(!station->getVolgende().empty(), "The volgende of station has not been correctly initialized");
    ENSURE(element != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseStation::parseSpoorNr(MetroNet &metroNet, Station *station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(element != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidSpoorNr() == true, "The spoorNr tag is not correct in this Station tag");


    for (TiXmlElement *InnerElement = element->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "spoorNr"){
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            station->setSpoorNr(temp);
            return true;
        }
    }
    ENSURE(station->getSpoorNr() != -1, "The spoorNr of station has not been correctly initialized");
    ENSURE(element != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseStation::checkNonValidAttributes() const {

    REQUIRE(element != NULL, "TixmlElement is NULL");


    for (TiXmlElement *InnerElement = element->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "spoorNr")
            continue;
        if(innerElementName == "volgende")
            continue;
        if(innerElementName == "vorige")
            continue;
        if(innerElementName == "naam")
            continue;
        return true;
    }

    ENSURE(element != NULL, "TixmlElement has become NULL");

    return false;
}






