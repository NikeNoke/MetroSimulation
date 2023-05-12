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

bool ParseSpoor::checkValidVorige(Exporter& e) const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfVorige = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "vorige") {
            if (!Utils::is_int(innerText))
                amountOfVorige++;
            else{
                e.writeToError("The vorige of SPOOR is a number\n");
                return false;
            }
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    if(amountOfVorige != 1){
        e.writeToError("The amount of vorige tags of SPOOR is not equal to one\n");
        return false;
    }
    return true;
}


bool ParseSpoor::checkValidVolgende(Exporter& e) const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfVolgende = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "volgende") {
            if (!Utils::is_int(innerText))
                amountOfVolgende++;
            else{
                e.writeToError("The volgende of SPOOR is an int\n");
                return false;
            }
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    if(amountOfVolgende != 1){
        e.writeToError("The amount volgende tags of SPOOR is not equal to one\n");
        return false;
    }
    return true;
}

void ParseSpoor::setElement(TiXmlElement *el) {
    element = el;
    ENSURE(getElement() == el, "The member variable element has not been properly set");
}

bool ParseSpoor::checkValidSpoor(Exporter& e) const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    bool one = checkValidVorige(e);
    bool two = checkValidSpoorNr(e);
    bool three = checkValidVolgende(e);
    bool four = !checkNonValidAttributes(e);
    return one && two && three && four;
}

bool ParseSpoor::checkValidSpoorNr(Exporter& e) const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfSpoorNr = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "spoorNr") {
            if (Utils::is_int(innerText))
                amountOfSpoorNr++;
            else{
                e.writeToError("The SpoorNr of SPOOR is not an int\n");
                return false;
            }
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    if(amountOfSpoorNr != 1){
        e.writeToError("The amount of SpoorNr of SPOOR is not equal to one\n");
        return false;
    }
    return true;
}

bool ParseSpoor::parseVorige(Spoor *spoor, Exporter& e) const {

    REQUIRE(spoor->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidVorige(e) == true, "The vorige tag is not correct in this Station tag");
//    if(!checkValidVorige(e))
//        return false;

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

bool ParseSpoor::parseVolgende(Spoor *spoor, Exporter& e) const {

    REQUIRE(spoor->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidVolgende(e) == true, "The volgende tag is not correct in this Station tag");
//    if(!checkValidVolgende(e))
//        return false;

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

bool ParseSpoor::parseSpoorNr(Spoor *spoor, Exporter& e) const {

    REQUIRE(spoor->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidSpoorNr(e) == true, "The spoorNr tag is not correct in this Station tag");
//    if(!checkValidSpoorNr(e))
//        return false;

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

bool ParseSpoor::checkNonValidAttributesAmount(Exporter& e) const {

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
    if(amountSpoorNr != 1 || amountVolgende != 1 || amountVorige != 1){
        e.writeToError("The expected amount of valid tags have exceeded\n");
        return false;
    }
    return true;
}

bool ParseSpoor::checkNonValidAttributes(Exporter& e) const {

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
        e.writeToError("There are non Valid attributes tags in Spoor\n");
        return true;
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return false;
}

TiXmlElement *ParseSpoor::getElement() const {
    return element;
}

bool ParseSpoor::parseAll(Spoor *spoor, Exporter& e) const {

    REQUIRE(spoor->properlyInitialized(), "Spoor is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidSpoor(e) == true, "The Spoor tag is not correct");
//    if(!checkValidSpoor(e))
//        return false;

    if (!parseSpoorNr(spoor, e) || !parseVolgende(spoor, e) || !parseVorige(spoor, e))
        return false;

    ENSURE(!spoor->getVorige().empty(), "The vorige of spoor has not been correctly initialized");
    ENSURE(!spoor->getVolgende().empty(), "The volgende of spoor has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");

    return true;
}
