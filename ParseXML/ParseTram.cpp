//
// Created by byamba on 20/03/23.
//

#include <iostream>
#include "ParseTram.h"
#include "../Utils/utils.h"

ParseTram::ParseTram(TiXmlElement *element)
    : fElement(element)
{
    REQUIRE(element != NULL, "TixmlElement is NULL");
    ENSURE(this->fElement == element, "TixmlElement is not the fElement of the parser");
}

void ParseTram::setElement(TiXmlElement *el) {
    REQUIRE(el != NULL, "TixmlElement is NULL");
    fElement = el;
    ENSURE(this->fElement == fElement, "TixmlElement is not the fElement of the parser");
}

bool ParseTram::checkValidBeginStation() const {

    REQUIRE(fElement != NULL, "TixmlElement is NULL");

    int amountOfBeginStation = 0;

    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fBeginStation"){
            if(!Utils::is_int(innerText))
                amountOfBeginStation++;
            else
                return false;
        }
    }

    ENSURE(fElement != NULL, "TixmlElement has become NULL");

    return amountOfBeginStation == 1;
}

bool ParseTram::checkValidSnelheid() const {

    REQUIRE(fElement != NULL, "TixmlElement is NULL");

    int amountOfSnelheid = 0;

    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fSnelheid"){
            if(Utils::is_int(innerText))
                amountOfSnelheid++;
            else
                return false;
        }
    }

    ENSURE(fElement != NULL, "TixmlElement has become NULL");

    return amountOfSnelheid == 1;
}

bool ParseTram::checkValidLijnNr() const {

    REQUIRE(fElement != NULL, "TixmlElement is NULL");

    int amountOfLijnNr = 0;

    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fLijnNr"){
            if(Utils::is_int(innerText))
                amountOfLijnNr++;
            else
                return false;
        }
    }

    ENSURE(fElement != NULL, "TixmlElement has become NULL");

    return amountOfLijnNr == 1;
}

bool ParseTram::checkValidTram() const {

    REQUIRE(fElement != NULL, "TixmlElement is NULL");

    return checkValidLijnNr() && checkValidSnelheid() && checkValidBeginStation() && !checkNonValidAttributes();
}

bool ParseTram::parseSnelheid(MetroNet &metroNet, Tram* tram) const {

    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(fElement != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidSnelheid() == true, "The fSnelheid tag is not correct in this Tram tag");


    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fSnelheid"){
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            tram->setSnelheid(temp);
            return true;
        }
    }
    ENSURE(tram->getSnelheid() != -1, "The fSnelheid of tram has not been correctly initialized");
    ENSURE(fElement != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseTram::parseBeginStation(MetroNet &metroNet, Tram *tram) const {

    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(fElement != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidBeginStation() == true, "The fBeginStation tag is not correct in this Tram tag");

    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fBeginStation"){
            tram->setBeginStation(innerText);
            tram->setHuidigStation(innerText);
            return true;
        }
    }
    ENSURE(!tram->getBeginStation().empty(), "The fBeginStation of Tram has not been correctly initialized");
    ENSURE(!tram->getHuidigStation().empty(), "The fHuidigStation of Tram has not been correctly initialized");
    ENSURE(fElement != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseTram::parseLijnNr(MetroNet &metroNet, Tram *tram) const {

    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(fElement != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidLijnNr() == true, "The fLijnNr tag is not correct in this Tram tag");


    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fLijnNr"){
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            tram->setLijnNr(temp);
            return true;
        }
    }
    ENSURE(tram->getLijnNr() != -1, "The fLijnNr of tram has not been correctly initialized");
    ENSURE(fElement != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseTram::parseAll(MetroNet &metroNet, Tram *tram) const {
//    std::cout << "Parse all is called\n";
    REQUIRE(tram->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(fElement != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidTram() == true, "The Tram tag is not correct");
//    REQUIRE(checkValidNaam() == true, "The name tag is not correct in this Station tag");
//    REQUIRE(checkValidVorige() == true, "The fVorige tag is not correct in this Station tag");
//    REQUIRE(checkValidSpoorNr() == true, "The fSpoorNr tag is not correct in this Station tag");
//    REQUIRE(checkValidVolgende() == true, "The fVolgende tag is not correct in this Station tag");

    if(!parseBeginStation(metroNet, tram) || !parseLijnNr(metroNet, tram) || !parseSnelheid(metroNet, tram))
        return false;

    ENSURE(tram->getLijnNr() != -1, "The fLijnNr of tram has not been correctly initialized");
    ENSURE(!tram->getBeginStation().empty(), "The fBeginStation of Tram has not been correctly initialized");
    ENSURE(!tram->getHuidigStation().empty(), "The fHuidigStation of Tram has not been correctly initialized");
    ENSURE(tram->getSnelheid() != -1, "The fSnelheid of tram has not been correctly initialized");
    ENSURE(fElement != NULL, "TixmlElement is NULL");

    return true;
}

bool ParseTram::checkNonValidAttributes() const {

    REQUIRE(fElement != NULL, "TixmlElement is NULL");


    for (TiXmlElement *InnerElement = fElement->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "fBeginStation")
            continue;
        if(innerElementName == "fLijnNr")
            continue;
        if(innerElementName == "fSnelheid")
            continue;
        return true;
    }

    ENSURE(fElement != NULL, "TixmlElement has become NULL");

    return false;
}

