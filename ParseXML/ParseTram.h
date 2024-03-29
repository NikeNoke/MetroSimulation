//
// Created by byamba on 20/03/23.
//

#ifndef METROSIMULATION_PARSETRAM_H
#define METROSIMULATION_PARSETRAM_H
#include "../DesignByContract.h"
#include "../Trams/Tram.h"
#include "../MetroNet/MetroNet.h"
#include "../TinyXML/tinyxml.h"
#include <string>

/**
 * Klasse om een Tram object met een welbepaalde type te parsen.
 */
class ParseTram {

public:

    /**
     * Explicit constructor voor een ParseTram object.
     * @pre REQUIRE(element != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() == element, "TixmlElement is not the element of the parser")
     * ENSURE(properlyInitialized(), "Not properly initialized");
     * @param element Element dat geparsed zal worden.
     * @return Een ParseTram object.
     **/
    explicit ParseTram(TiXmlElement *element);

    /**
     * Setter functie om een element van type TiXmlElement te zetten.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(el != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() == fElement, "TixmlElement is not the element of the parser")
     * @param el Element dat gezet gaat worden.
     * **/
    void setElement(TiXmlElement *el);

    /**
     * Parsed de Tram object met een specifieke type van een MetroNet object.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
    ENSURE(tram->getLijnNr() != -1, "The lijnNr of tram has not been correctly initialized");
    ENSURE(!tram->getBeginStation().empty(), "The beginStation of Tram has not been correctly initialized");
    ENSURE(!tram->getHuidigStation().empty(), "The huidigStation of Tram has not been correctly initialized");
    ENSURE(tram->getSnelheid() != -1, "The snelheid of tram has not been correctly initialized");
    ENSURE(tram->getType() != TramType::InvalidTram, "The type of Tram has not been correctly initialized");
    ENSURE(getParsedTram() == tram, "GG");
    ENSURE(getElement() != NULL, "TixmlElement is NULL");
     * @return true or false
     * **/
    bool parseAll(Exporter& e);

    /**
     * Methode dat gecalled wordt door parseAll of te checken ofdat lijnNr geparsed kan worden.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized")
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @pre REQUIRE(checkValidLijnNr() == true, "The lijnNr tag is not correct in this Tram tag")
     * @post ENSURE(tram->getLijnNr() != -1, "The lijnNr of tram has not been correctly initialized")
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @param tram waarvan men de lijnNr gaan parsen.
     * @return true or false
     * **/
    bool parseLijnNr(Tram* tram, Exporter& e) const;

    /**
     * Methode dat gecalled wordt door parseAll of te checken ofdat beginStation geparsed kan worden.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized")
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @pre REQUIRE(checkValidBeginStation() == true, "The beginStation tag is not correct in this Tram tag")
        ENSURE(tram->getLijnNr() != -1, "The lijnNr of tram has not been correctly initialized");
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @param tram  waarvan men beginStation gaan parsen.
     * @return true or false
     * **/
    bool parseBeginStation(Tram* tram, Exporter& e) const;

    /**
     * Functie controleerd ofdat het Tram object valid is.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @return true or false
     * **/
    bool checkValidTram(Exporter& e) const;

    /**
     * Functie controleerd ofdat de lijnNr attribuut van het Tram object valid is.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true of false
     * **/
    bool checkValidLijnNr(Exporter& e) const;

    /**
     * Functie controleerd ofdat de beginStation attribuut van het Tram object valid is.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true of false
     * **/
    bool checkValidBeginStation(Exporter& e) const;


    /**
     * Functie controleerd ofdat er geen attributen zijn die niet behoren tot het Tram object.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true of false
     * **/
    bool checkNonValidAttributes(Exporter& e) const;

    /**
     * Functie controleerd ofdat de Type attribuut van het Tram object valid is.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true or false
     * **/
    bool checkValidTypeTram(Exporter& e) const;

    /**
     * Methode dat gecalled wordt door parseAll om de Type attribuut te parsen.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized")
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @pre REQUIRE(checkValidTypeTram() == true, "The type tag is not correct in this Tram tag")
     * @post ENSURE(!tram->getType().empty(), "The type of tram has not been correctly initialized")
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @param tram waarvan men het Type attribuut gaan parsen.
     * @return true or false
     * **/
    bool parseTypeTram(Tram* tram, Exporter& e) const;

    /**
     * Functie contro ofdat de voertuigNr attribuut valid is.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true or false
     * **/
    bool checkValidVoertuigNummer(Exporter& e) const;

    /**
     * Methode dat gecalled wordt door parseAll om de voertuigNr te parsen.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized")
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @pre REQUIRE(checkValidVoertuigNummer() == true, "The lijnNr tag is not correct in this Tram tag")
     * @post ENSURE(tram->getVoertuigNummer() != -1, "The lijnNr of tram has not been correctly initialized")
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @param tram waarvan men het voertuigNr attribuut gaan parsen
     * @return true or false
     * **/
    bool parserVoertuigNummer(Tram* tram, Exporter& e) const;

    /**
     * Getter functie die een element teruggeeft van type TiXmlElement.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @return fElement
     * **/
    TiXmlElement* getElement() const;

    /**
     * Functie controleerd ofdat parseAll succesvol was.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @return true or false
     * @see parseAll
     * **/
    bool parseSuccessful(Exporter& e);

    /**
     * Setter functie dat een Tram object plaatst in een MetroNet object.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
       ENSURE(getParsedTram() == t, "The setting has gone wrong");
     * **/
    void setParsedTram(Tram* t);

    /**
     * Getter functie dat een Tram object teruggeeft dat geparsed werd.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @return Tram object
     * **/
    Tram* getParsedTram() const;

    /**
     * Getter functie dat het Type van een Tram object teruggeeft.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @pre REQUIRE(checkValidTypeTram() == true, "The type tag is not correct in this Station tag")
     * @return Type van een Tram object.
     * **/
    TramType::TypeTram getTramType(Exporter& e) const;

    /**
     * Functie controleerd ofdat het aantalDefecten attribuut valid is.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true or false
     * **/
    bool checkValidAantalDefecten(Exporter& e) const;

    /**
     * Functie controleerd ofdat het reparatieTijd attribuut valid is.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true or false
     * **/
    bool checkValidReparatieTijd(Exporter& e) const;

    /**
     * Functie controleerd ofdat het reparatieKost attribuut valid is.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true or false
     * **/
    bool checkValidReparatieKosten(Exporter& e) const;

    /**
     * Methode dat gecalled wordt door parseAll om het aantalDefecten attribuut te parsen.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(getTramType() == TramType::PCC, "Will not work on other types")
     * @pre REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized")
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @pre REQUIRE(checkValidAantalDefecten() == true, "The aantalDefecten tag is not correct in this Tram tag")
     * @post ENSURE(tram->getAantalDefecten() != -1, "The aantalDefecten of tram has not been correctly initialized")
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @param tram waarvan men het aantalDefecten attribuut gaan parsen.
     * @return true or false
     * **/
    bool parseAantalDefecten(Tram* tram, Exporter& e);

    /**
     * Methode dat gecalled wordt door parseAll om het aantalDefecten attribuut te parsen.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(getTramType() == TramType::PCC, "Will not work on other types")
     * @pre REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized")
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @pre REQUIRE(checkValidReparatieTijd() == true, "The reparatieTijd tag is not correct in this Tram tag")
     * @post ENSURE(tram->getReparatieTijd() != -1, "The reparatieTijd of tram has not been correctly initialized")
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @param tram waarvan men het reparatieTijd attribuut gaan parsen.
     * @return true or false
     * **/
    bool parseReparatieTijd(Tram* tram, Exporter& e);

    /**
     * Methode dat gecalled wordt door parseAll om het reparatieKost attribuut te parsen.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @pre REQUIRE(getTramType() == TramType::PCC, "Will not work on other types")
     * @pre REQUIRE(tram->properlyInitialized(), "Tram is not properlyInitialized")
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @pre REQUIRE(checkValidReparatieKosten() == true, "The reparatieKost tag is not correct in this Tram tag")
     * @post ENSURE(tram->getReparatieTijd() != -1, "The reparatieKost of tram has not been correctly initialized")
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @param tram waarvan men het reparatieKost attribuut gaan parsen.
     * @return true or false
     * **/
    bool parseReparatieKosten(Tram* tram, Exporter& e);

    /**
     * Methode controleert ofdat er een type is tijdens het parsen.
     * REQUIRE(properlyInitialized(), "This is not properly initialzed");
     * @return true or false
     * REQUIRE(getElement() != NULL, "TixmlElement is NULL");
     * @attention Deze methode is niet hetzelfde als checkValidTramType. Deze functie checkt namelijk ofdat er uberhaubt
     * een type is. checkValidTramType checked dat er niet meer dan één zijn.
     * **/
    bool checkTramTypeExists(Exporter& e) const;

    /**
     * @return properlyInitialized?
     */
    bool properlyInitialized() const;

private:
    TiXmlElement * fElement;
    Tram* parsedTram;
    ParseTram* _fInitCheck;

};


#endif //METROSIMULATION_PARSETRAM_H
