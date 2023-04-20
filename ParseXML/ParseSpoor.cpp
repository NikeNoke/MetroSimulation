//
// Created by byamba on 20/04/23.
//

#include "ParseSpoor.h"
#include "../Utils/utils.h"

ParseSpoor::ParseSpoor(TiXmlElement *element)
    : element(element)
{
    REQUIRE(element != NULL, "TixmlElement is NULL");
    _fInitcheck = this;
    ENSURE(getElement() == element, "TixmlElement is not the element of the parser");
    ENSURE(properlyInitialized(), "ParseSpoor has been properly initialized");
}

bool ParseSpoor::properlyInitialized() {
    return _fInitcheck == this;
}

bool ParseSpoor::checkValidVorige() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfVorige = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
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

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return amountOfVorige == 1;
}


bool ParseSpoor::checkValidVolgende() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfVolgende = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
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

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return amountOfVolgende == 1;
}

void ParseSpoor::setElement(TiXmlElement *el) {
    element = el;
    ENSURE(getElement() == el, "The member variable element has not been properly set");
}

bool ParseSpoor::checkValidSpoor() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    return checkValidVorige() && checkValidSpoorNr() && checkValidVolgende() && !checkNonValidAttributes();
}

bool ParseSpoor::checkValidSpoorNr() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfSpoorNr = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
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

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return amountOfSpoorNr == 1;
}

bool ParseSpoor::parseVorige(Station *station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidVorige() == true, "The vorige tag is not correct in this Station tag");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "vorige"){
            station->setVorige(innerText);
            return true;
        }
    }
    ENSURE(!station->getVorige().empty(), "The vorige of station has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseSpoor::parseVolgende(Station *station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
// REQUIRE(checkValidVolgende() == true, "The volgende tag is not correct in this Station tag");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "volgende"){
            station->setVolgende(innerText);
            return true;
        }
    }
// ENSURE(!station->getVolgende().empty(), "The volgende of station has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseSpoor::parseSpoorNr(Station *station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidSpoorNr() == true, "The spoorNr tag is not correct in this Station tag");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
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
    ENSURE(!station->getSpoorNr().empty(), "The SPOOR's of station has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseSpoor::checkNonValidAttributes() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "spoorNr")
            continue;
        if(innerElementName == "volgende")
            continue;
        if(innerElementName == "vorige")
            continue;
        return true;
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return false;
}

TiXmlElement *ParseSpoor::getElement() const {
    return element;
}

bool ParseSpoor::parseAll(Station *station) const {

    REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidSpoor() == true, "The Station tag is not correct");

    if(!parseSpoorNr(station) || parseVolgende(station) || !parseVorige(station))
        return false;

    ENSURE(!station->getVorige().empty(), "The vorige of station has not been correctly initialized");
    ENSURE(!station->getVolgende().empty(), "The volgende of station has not been correctly initialized");
    ENSURE(!station->getSpoorNr().empty(), "The SPOOR's of station has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");

    return true;
}
