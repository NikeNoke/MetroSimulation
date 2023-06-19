//
// Created by byamba on 20/03/23.
//

#include <iostream>
#include "ParseTram.h"
#include "../Utils/utils.h"
#include "../Trams/PCCTram.h"
#include "../Trams/AlbatrosTram.h"
#include "../Trams/StadslijnerTram.h"

ParseTram::ParseTram(TiXmlElement *element)
        : fElement(element), _fInitCheck(this) {
    REQUIRE(element != NULL, "TixmlElement is NULL");
    ENSURE(getElement() == element, "TixmlElement is not the element of the parser");
    ENSURE(properlyInitialized(), "Not properly initialized");
}

void ParseTram::setElement(TiXmlElement *el) {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(el != NULL, "TixmlElement is NULL");
    fElement = el;
    ENSURE(getElement() == fElement, "TixmlElement is not the element of the parser");
}

bool ParseTram::checkValidBeginStation(Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfBeginStation = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "beginStation") {
            if (!Utils::is_int(innerText))
                amountOfBeginStation++;
            else{
                e.writeToError("The beginStation of this TRAM is an int\n");
                return false;
            }
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    if(amountOfBeginStation != 1){
        e.writeToError("The amount of beginStation of this TRAM is not equal to one\n");
        return false;
    }
    return true;
}


bool ParseTram::checkValidLijnNr(Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfLijnNr = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "lijnNr") {
            if (Utils::is_int(innerText))
                amountOfLijnNr++;
            else{
                e.writeToError("The lijnNr of this TRAM is not an int\n");
                return false;
            }
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    if(amountOfLijnNr != 1){
        e.writeToError("The amount of lijnNr of this TRAM is not equal to one\n");
        return false;
    }
    return true;
}

bool ParseTram::checkValidTram(Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    if (getTramType(e) != TramType::PCC){
        bool one = checkValidLijnNr(e);
        bool two = checkValidBeginStation(e);
        bool three = checkValidTypeTram(e);
        bool four = !checkNonValidAttributes(e);
        bool five = checkTramTypeExists(e);
        bool six = checkValidVoertuigNummer(e);
        return one && two && three && four && five && six;
    }
    bool one = checkValidLijnNr(e);
    bool two = checkValidBeginStation(e);
    bool three = checkValidTypeTram(e);
    bool four = !checkNonValidAttributes(e);
    bool five = checkTramTypeExists(e);
    bool six = checkValidVoertuigNummer(e);
    bool seven = checkValidReparatieTijd(e);
    bool eight = checkValidReparatieKosten(e);
    bool nine =  checkValidAantalDefecten(e);
    return one && two && three && four && five && six && seven && eight && nine;
}

bool ParseTram::checkTramTypeExists(Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    bool exists = false;
    for (TiXmlElement *innerElement = getElement()->FirstChildElement();
         innerElement != NULL; innerElement = innerElement->NextSiblingElement()) {

        std::string innerElementName = innerElement->Value();
        if (innerElementName == "type") {
            exists = true;
        }
    }
    if(!exists)
        e.writeToError("The tag 'type' of this TRAM does not exist\n");
    return exists;
}

bool ParseTram::parseBeginStation(Tram *tram, Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidBeginStation(e) == true, "The beginStation tag is not correct in this Tram tag");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "beginStation") {
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

bool ParseTram::parseLijnNr(Tram *tram, Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidLijnNr(e) == true, "The lijnNr tag is not correct in this Tram tag");


    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "lijnNr") {
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

bool ParseTram::parseAll(Exporter& e) {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
//    REQUIRE(checkValidTram(e) == true, "The Tram tag is not correct");
    if(!checkValidTram(e))
        return false;
    Tram *tram;

    if (getTramType(e) == TramType::PCC)
        tram = new PCCTram;
    else if (getTramType(e) == TramType::StadsLijner)
        tram = new StadslijnerTram;
    else if (getTramType(e) == TramType::Albatros)
        tram = new AlbatrosTram;
    else {
        e.writeToError("Tram type is invalid!\n");
        return false;
    }

    if (!parseBeginStation(tram, e) || !parseLijnNr(tram, e) || !parseTypeTram(tram, e) || !parserVoertuigNummer(tram, e)) {
        delete tram;
        return false;
    }
    if (getTramType(e) == TramType::PCC) {
        if (!parseAantalDefecten(tram, e) || !parseReparatieTijd(tram, e) || !parseReparatieKosten(tram, e)) {
            delete tram;
            return false;
        }
    }
    setParsedTram(tram);
    //TODO setsnelheid
    tram->calculateSnelheid();
    ENSURE(tram->getLijnNr() != -1, "The lijnNr of tram has not been correctly initialized");
    ENSURE(!tram->getBeginStation().empty(), "The beginStation of Tram has not been correctly initialized");
    ENSURE(!tram->getHuidigStation().empty(), "The huidigStation of Tram has not been correctly initialized");
    ENSURE(tram->getSnelheid() != -1, "The snelheid of tram has not been correctly initialized");
    ENSURE(tram->getType() != TramType::InvalidTram, "The type of Tram has not been correctly initialized");
    ENSURE(getParsedTram() == tram, "GG");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");

    return true;
}

bool ParseTram::checkNonValidAttributes(Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");


    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "beginStation")
            continue;
        if (innerElementName == "lijnNr")
            continue;
//        if(innerElementName == "snelheid") //TODO snelheid att moet niet langer supported worden
//            continue;
        if (innerElementName == "type")
            continue;
        if (innerElementName == "voertuigNr")
            continue;
        if (getTramType(e) == TramType::PCC) {
            if (innerElementName == "reparatieKost")
                continue;
            if (innerElementName == "reparatieTijd")
                continue;
            if (innerElementName == "aantalDefecten")
                continue;
        }
        e.writeToError("This TRAM has an invalid attrubute tag\n");
        return true;
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    return false;
}

TiXmlElement *ParseTram::getElement() const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    return fElement;
}

bool ParseTram::checkValidTypeTram(Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfType = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "type") {
            if (!Utils::is_int(innerText)) //TODO add additional checks
                amountOfType++;
            else{
                e.writeToError("The type of this TRAM is an int\n");
                return false;
            }
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    if(amountOfType != 1){
        e.writeToError("The amount of type tag of TRAM is not equal to one\n");
        return false;
    }
    return true;
}

bool ParseTram::parseTypeTram(Tram *tram, Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidTypeTram(e) == true, "The type tag is not correct in this Tram tag");


    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "type") {
            tram->setType(innerText);
            return true;
        }
    }
    ENSURE(tram->getType() != TramType::InvalidTram, "The type of tram has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseTram::checkValidVoertuigNummer(Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int amountOfVoertuigNr = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "voertuigNr") {
            if (Utils::is_int(innerText))
                amountOfVoertuigNr++;
            else{
                e.writeToError("The voertuigNr of this TRAM is not an int\n");
                return false;
            }
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    if(amountOfVoertuigNr != 1){
        e.writeToError("The amount of voertuigNr tag of this TRAM is not equal to one\n");
        return false;
    }
    return true;
}

bool ParseTram::parserVoertuigNummer(Tram *tram, Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidVoertuigNummer(e) == true, "The lijnNr tag is not correct in this Tram tag");


    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "voertuigNr") {
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

TramType::TypeTram ParseTram::getTramType(Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidTypeTram(e) == true, "The type tag is not correct in this Tram tag");

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "type") {
            if (innerText == "PCC")
                return TramType::PCC;
            if (innerText == "Stadslijner")
                return TramType::StadsLijner;
            if (innerText == "Albatros")
                return TramType::Albatros;
            e.writeToError("The type of this tram is invalid\n");
            return TramType::InvalidTram;
        }
    }
    return TramType::InvalidTram;
}

void ParseTram::setParsedTram(Tram *t) {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    parsedTram = t;
    ENSURE(getParsedTram() == t, "The setting has gone wrong");
}

Tram *ParseTram::getParsedTram() const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    return parsedTram;
}

bool ParseTram::parseSuccessful(Exporter& e) {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    return parseAll(e);
}

bool ParseTram::checkValidAantalDefecten(Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int aantalDefecten = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "aantalDefecten") {
            if (Utils::is_int(innerText))
                aantalDefecten++;
            else{
                e.writeToError("The AantalDefecten of this TRAM is not an int\n");
                return false;
            }
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    if(aantalDefecten != 1){
        e.writeToError("The amount of AantalDefecten of this TRAM is not equal to one\n");
        return false;
    }
    return true;
}

bool ParseTram::checkValidReparatieTijd(Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int aantalReparatieTijd = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "reparatieTijd") {
            if (Utils::is_int(innerText))
                aantalReparatieTijd++;
            else{
                e.writeToError("The reparatieTijd of this TRAM is not an int\n");
                return false;
            }
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    if(aantalReparatieTijd != 1){
        e.writeToError("The amount of eparatieTijd of this TRAM is not equal to one\n");
        return false;
    }
    return true;
}

bool ParseTram::checkValidReparatieKosten(Exporter& e) const {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");

    int aantalReparatieKost = 0;

    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "reparatieKost") {
            if (Utils::is_int(innerText))
                aantalReparatieKost++;
            else{
                e.writeToError("The reparatieKost of this TRAM is not an int\n");
                return false;
            }
        }
    }

    ENSURE(getElement() != NULL, "TixmlElement has become NULL");

    if(aantalReparatieKost != 1){
        e.writeToError("The amount of ReparatieKost of this TRAM is not equal to one\n");
        return false;
    }
    return true;
}

bool ParseTram::parseAantalDefecten(Tram *tram, Exporter& e) {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getTramType(e) == TramType::PCC, "Will not work on other types");
    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidAantalDefecten(e) == true, "The aantalDefecten tag is not correct in this Tram tag");


    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "aantalDefecten") {
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            tram->setAantalDefecten(temp);
            return true;
        }
    }
    ENSURE(tram->getAantalDefecten() != -1, "The aantalDefecten of tram has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseTram::parseReparatieTijd(Tram *tram, Exporter& e) {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getTramType(e) == TramType::PCC, "Will not work on other types");
    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidReparatieTijd(e) == true, "The reparatieTijd tag is not correct in this Tram tag");


    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "reparatieTijd") {
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            tram->setReparatieTijd(temp);
            return true;
        }
    }
    ENSURE(tram->getReparatieTijd() != -1, "The reparatieTijd of tram has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseTram::parseReparatieKosten(Tram *tram, Exporter& e) {
    REQUIRE(properlyInitialized(), "This is not properly initialzed");
    REQUIRE(getTramType(e) == TramType::PCC, "Will not work on other types");
    REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidReparatieKosten(e) == true, "The reparatieKost tag is not correct in this Tram tag");


    for (TiXmlElement *InnerElement = getElement()->FirstChildElement();
         InnerElement != NULL; InnerElement = InnerElement->NextSiblingElement()) {

        std::string innerElementName = InnerElement->Value();
        std::string innerText = InnerElement->GetText();

        if (innerElementName == "reparatieKost") {
            int temp;
            sscanf(innerText.c_str(), "%d", &temp);
            tram->setReparatieKost(temp);
            return true;
        }
    }
    ENSURE(tram->getReparatieTijd() != -1, "The reparatieKost of tram has not been correctly initialized");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
    return false;
}

bool ParseTram::properlyInitialized() const {
    return _fInitCheck == this;
}

