//
// Created by byamba on 20/03/23.
//

#include "ParseTram.h"
#include "../Utils/utils.h"

ParseTram::ParseTram(TiXmlElement *element)
    : element(element)
{
    REQUIRE(element != NULL, "TixmlElement is NULL");
    ENSURE(this->element == element, "TixmlElement is not the element of the parser");
}

void ParseTram::setElement(TiXmlElement *el) {
    REQUIRE(el != NULL, "TixmlElement is NULL");
    element = el;
    ENSURE(this->element == element, "TixmlElement is not the element of the parser");
}

bool ParseTram::checkValidBeginStation() const {

    REQUIRE(element != NULL, "TixmlElement is NULL");

    int amountOfBeginStation = 0;

    for (TiXmlElement *InnerElement = element->FirstChildElement();
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

    ENSURE(element != NULL, "TixmlElement has become NULL");

    return amountOfBeginStation == 1;
}

bool ParseTram::checkValidSnelheid() const {

    REQUIRE(element != NULL, "TixmlElement is NULL");

    int amountOfSnelheid = 0;

    for (TiXmlElement *InnerElement = element->FirstChildElement();
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

    ENSURE(element != NULL, "TixmlElement has become NULL");

    return amountOfSnelheid == 1;
}

bool ParseTram::checkValidLijnNr() const {

    REQUIRE(element != NULL, "TixmlElement is NULL");

    int amountOfLijnNr = 0;

    for (TiXmlElement *InnerElement = element->FirstChildElement();
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

    ENSURE(element != NULL, "TixmlElement has become NULL");

    return amountOfLijnNr == 1;
}

bool ParseTram::checkValidTram() const {

    REQUIRE(element != NULL, "TixmlElement is NULL");

    return checkValidLijnNr() && checkValidSnelheid() && checkValidBeginStation();
}

bool ParseTram::parseSnelheid(MetroNet &metroNet, Tram* tram) const {

    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(element != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidSnelheid() == true, "The snelheid tag is not correct in this Tram tag");


    for (TiXmlElement *InnerElement = element->FirstChildElement();
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
    ENSURE(element != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseTram::parseBeginStation(MetroNet &metroNet, Tram *tram) const {

    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(element != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidBeginStation() == true, "The beginStation tag is not correct in this Tram tag");

    for (TiXmlElement *InnerElement = element->FirstChildElement();
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
    ENSURE(element != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseTram::parseLijnNr(MetroNet &metroNet, Tram *tram) const {

    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(element != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidLijnNr() == true, "The lijnNr tag is not correct in this Tram tag");


    for (TiXmlElement *InnerElement = element->FirstChildElement();
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
    ENSURE(element != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseTram::parseAll(MetroNet &metroNet, Tram *tram) const {

    REQUIRE(tram->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(element != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidTram() == true, "The Station tag is not correct");
//    REQUIRE(checkValidNaam() == true, "The name tag is not correct in this Station tag");
//    REQUIRE(checkValidVorige() == true, "The vorige tag is not correct in this Station tag");
//    REQUIRE(checkValidSpoorNr() == true, "The spoorNr tag is not correct in this Station tag");
//    REQUIRE(checkValidVolgende() == true, "The volgende tag is not correct in this Station tag");

    if(!parseBeginStation(metroNet, tram) || !parseLijnNr(metroNet, tram) || !parseSnelheid(metroNet, tram))
        return false;

    ENSURE(tram->getLijnNr() != -1, "The lijnNr of tram has not been correctly initialized");
    ENSURE(!tram->getBeginStation().empty(), "The beginStation of Tram has not been correctly initialized");
    ENSURE(!tram->getHuidigStation().empty(), "The huidigStation of Tram has not been correctly initialized");
    ENSURE(tram->getSnelheid() != -1, "The snelheid of tram has not been correctly initialized");
    ENSURE(element != NULL, "TixmlElement is NULL");

    return true;
}

