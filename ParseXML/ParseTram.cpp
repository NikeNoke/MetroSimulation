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
    ENSURE(getElement() == element, "TixmlElement is not the element of the parser");
}

void ParseTram::setElement(TiXmlElement *el) {
    REQUIRE(el != NULL, "TixmlElement is NULL");
    fElement = el;
    ENSURE(getElement() == fElement, "TixmlElement is not the element of the parser");
}

bool ParseTram::checkValidBeginStation() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfBeginStation = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "beginStation"){
            if(!Utils::is_int(innerText))
                amountOfBeginStation++;
            else
                return false;
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return amountOfBeginStation == 1;
}

bool ParseTram::checkValidSnelheid() const { //TODO change to calculate snelheid

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfSnelheid = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "snelheid"){
            if(Utils::is_int(innerText))
                amountOfSnelheid++;
            else
                return false;
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return amountOfSnelheid == 1;
}

bool ParseTram::checkValidLijnNr() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfLijnNr = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "lijnNr"){
            if(Utils::is_int(innerText))
                amountOfLijnNr++;
            else
                return false;
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return amountOfLijnNr == 1;
}

bool ParseTram::checkValidTram() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    return checkValidLijnNr() && checkValidBeginStation() && checkValidTypeTram() && !checkNonValidAttributes();
}

bool ParseTram::parseSnelheid(Tram* tram) const {

    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidSnelheid() == true, "The snelheid tag is not correct in this Tram tag");


    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "snelheid"){
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            tram->setSnelheid(temp);
            return true;
        }
    }
    ENSURE(tram->getSnelheid() != -1, "The snelheid of tram has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseTram::parseBeginStation(Tram *tram) const {

    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidBeginStation() == true, "The beginStation tag is not correct in this Tram tag");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "beginStation"){
            tram->setBeginStation(innerText);
            tram->setHuidigStation(innerText);
            return true;
        }
    }
    ENSURE(!tram->getBeginStation().empty(), "The beginStation of Tram has not been correctly initialized");
    ENSURE(!tram->getHuidigStation().empty(), "The huidigStation of Tram has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseTram::parseLijnNr(Tram *tram) const {

    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidLijnNr() == true, "The lijnNr tag is not correct in this Tram tag");


    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "lijnNr"){
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            tram->setLijnNr(temp);
            return true;
        }
    }
    ENSURE(tram->getLijnNr() != -1, "The lijnNr of tram has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseTram::parseAll(Tram *tram) const {
//    std::cout << "Parse all is called\n";
    REQUIRE(tram->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidTram() == true, "The Tram tag is not correct");
//    REQUIRE(checkValidNaam() == true, "The name tag is not correct in this Station tag");
//    REQUIRE(checkValidVorige() == true, "The vorige tag is not correct in this Station tag");
//    REQUIRE(checkValidSpoorNr() == true, "The spoorNr tag is not correct in this Station tag");
//    REQUIRE(checkValidVolgende() == true, "The volgende tag is not correct in this Station tag");

    if(!parseBeginStation(tram) || !parseLijnNr(tram) || !parseTypeTram(tram) || !parserVoertuigNummer(tram))
        return false;
    //TODO setsnelheid
    ENSURE(tram->getLijnNr() != -1, "The lijnNr of tram has not been correctly initialized");
    ENSURE(!tram->getBeginStation().empty(), "The beginStation of Tram has not been correctly initialized");
    ENSURE(!tram->getHuidigStation().empty(), "The huidigStation of Tram has not been correctly initialized");
    ENSURE(tram->getSnelheid() != -1, "The snelheid of tram has not been correctly initialized");
    ENSURE(!tram->getType().empty(), "The type of Tram has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");

    return true;
}

bool ParseTram::checkNonValidAttributes() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");


    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "beginStation")
            continue;
        if(innerElementName == "lijnNr")
            continue;
//        if(innerElementName == "snelheid") //TODO snelheid att moet niet langer supported worden
//            continue;
        if(innerElementName == "type")
            continue;
        if(innerElementName == "voertuigNr")
            continue;
        return true;
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return false;
}

TiXmlElement *ParseTram::getElement() const {
    return fElement;
}

bool ParseTram::checkValidTypeTram() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfType = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "type"){
            if(!Utils::is_int(innerText)) //TODO add additional checks
                amountOfType++;
            else
                return false;
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return amountOfType == 1;
}

bool ParseTram::parseTypeTram(Tram* tram) const {

    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidTypeTram() == true, "The type tag is not correct in this Tram tag");


    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "type"){
            tram->setType(innerText);
            return true;
        }
    }
    ENSURE(!tram->getType().empty(), "The type of tram has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseTram::checkValidVoertuigNummer() const {

    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfVoertuigNr = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "voertuigNr"){
            if(Utils::is_int(innerText))
                amountOfVoertuigNr++;
            else
                return false;
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return amountOfVoertuigNr == 1;
}

bool ParseTram::parserVoertuigNummer(Tram *tram) const {

    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidVoertuigNummer() == true, "The lijnNr tag is not correct in this Tram tag");


    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if(innerElementName == "voertuigNr"){
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            tram->setVoertuigNummer(temp);
            return true;
        }
    }
    ENSURE(tram->getVoertuigNummer() != -1, "The lijnNr of tram has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

