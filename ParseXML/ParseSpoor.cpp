//
// Created by byamba on 20/04/23.
//

#include "ParseSpoor.h"
#include "../Utils/utils.h"

ParseSpoor::ParseSpoor(TiXmlElement *element)
        : element(element) {
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

        if (innerElementName == "vorige") {
            if (!Utils::is_int(innerText))
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

        if (innerElementName == "volgende") {
            if (!Utils::is_int(innerText))
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

        if (innerElementName == "spoorNr") {
            if (Utils::is_int(innerText))
                amountOfSpoorNr++;
            else
                return false;
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return amountOfSpoorNr == 1;
}

bool ParseSpoor::parseVorige(Spoor *spoor) const {

    REQUIRE(spoor->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidVorige() == true, "The vorige tag is not correct in this Station tag");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "vorige") {
            spoor->setVorige(innerText);
            return true;
        }
    }
    ENSURE(!spoor->getVorige().empty(), "The vorige of station has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseSpoor::parseVolgende(Spoor *spoor) const {

    REQUIRE(spoor->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
// REQUIRE(checkValidVolgende() == true, "The volgende tag is not correct in this Station tag");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "volgende") {
            spoor->setVolgende(innerText);
            return true;
        }
    }
    ENSURE(!spoor->getVolgende().empty(), "The volgende of spoor has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseSpoor::parseSpoorNr(Spoor *spoor) const {

    REQUIRE(spoor->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidSpoorNr() == true, "The spoorNr tag is not correct in this Station tag");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "spoorNr") {
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            spoor->setSpoorNr(temp);
            return true;
        }
    }
    ENSURE(spoor->getSpoorNr() == -1, "The spoorNr of Spoor has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseSpoor::checkNonValidAttributesAmount() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    int amountSpoorNr = 0;
    int amountVolgende = 0;
    int amountVorige = 0;
    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "spoorNr") {
            amountSpoorNr++;
        }
        if (innerElementName == "volgende") {
            amountVolgende++;
        }

        if (innerElementName == "vorige") {
            amountVorige++;
        }
    }
    return amountSpoorNr == 1 && amountVolgende == 1 && amountVorige == 1;
}

bool ParseSpoor::checkNonValidAttributes() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "spoorNr")
            continue;
        if (innerElementName == "volgende")
            continue;
        if (innerElementName == "vorige")
            continue;
        return true;
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return false;
}

TiXmlElement *ParseSpoor::getElement() const {
    return element;
}

bool ParseSpoor::parseAll(Spoor *spoor) const {

    REQUIRE(spoor->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidSpoor() == true, "The Station tag is not correct");

    if (!parseSpoorNr(spoor) || !parseVolgende(spoor) || !parseVorige(spoor))
        return false;

    ENSURE(!spoor->getVorige().empty(), "The vorige of spoor has not been correctly initialized");
    ENSURE(!spoor->getVolgende().empty(), "The volgende of spoor has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");

    return true;
}
