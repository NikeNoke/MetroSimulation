//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_PARSESPOOR_H
#define METROSIMULATION_PARSESPOOR_H

#include "../DesignByContract.h"
#include "../Stations/Station.h"
#include "../MetroNet/MetroNet.h"
#include "../TinyXML/tinyxml.h"
#include "../Spoor/Spoor.h"
#include <string>

/**
 * Klasse ParseSpoor dat er voor zorgt dat een spoor correct geparsed kan worden.
 * **/
class ParseSpoor {

public:

    /**
     * Explicit constructor voor ParseSpoor.
     * @pre REQUIRE(element != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() == element, "TixmlElement is not the element of the parser")
     * @post ENSURE(properlyInitialized(), "ParseSpoor has been properly initialized")
     * @param element Element dat gebruikt wordt om te parsen vanuit een XML file. Een spoor zal een element
     * zijn van een MetroNet in de XML en daarom parsen we de element van MetroNet.
     * @return ParseSpoor object
     * **/
    explicit ParseSpoor(TiXmlElement *element);

    /**
     * Setter functie dat een element van type TiXmlElement zal setten.
     * @post ENSURE(getElement() == el, "The member variable element has not been properly set")
     * @param el Element dat gezet zal worden in de Spoor.
     * **/
    void setElement(TiXmlElement *el);

    /**
     * Functie parsed een Spoor object van een MetroNet object.
     * @pre REQUIRE(spoor->properlyInitialized(), "Station is not properlyInitialized")
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(!spoor->getVorige().empty(), "The vorige of spoor has not been correctly initialized")
     * @post ENSURE(!spoor->getVolgende().empty(), "The volgende of spoor has not been correctly initialized")
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @param spoor Spoor dat geparsed zal worden.
     * @return true or false
     * **/
    bool parseAll(Spoor *spoor, Exporter& e) const;

    /**
     * Functie dat gecalled wordt door parseAll om te checken ofdat Vorige geparsed kan worden.
     * @pre REQUIRE(spoor->properlyInitialized(), "Station is not properlyInitialized")
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL");
     * @pre REQUIRE(checkValidVorige() == true, "The vorige tag is not correct in this Station tag")
     * @post ENSURE(!spoor->getVorige().empty(), "The vorige of station has not been correctly initialized")
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @param spoor Huidige spoor dat gechecked wordt, vorige is dus spoor dat hiervoor komt.
     * @return true or false
     * **/
    bool parseVorige(Spoor *spoor, Exporter& e) const;

    /**
     * Functie dat gecalled wordt door parseAll om te checken ofdat Volgende geparsed kan worden.
    REQUIRE(spoor->properlyInitialized(), "Station is not properlyInitialized");
    REQUIRE(getElement() != NULL, "TixmlElement is NULL");
    REQUIRE(checkValidVolgende(e) == true, "The volgende tag is not correct in this Station tag");
     * @post ENSURE(!spoor->getVolgende().empty(), "The volgende of spoor has not been correctly initialized")
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @param spoor Huidige spoor dat gechecked wordt, volgende is dus spoor dat hierna komt.
     * @return true or false
     * **/
    bool parseVolgende(Spoor *spoor, Exporter& e) const;

    /**
     * Functie dat gecalled wordt door parseAll om te checken ofdat spoorNr geparsed kan worden.
     * @pre REQUIRE(spoor->properlyInitialized(), "Station is not properlyInitialized")
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @pre REQUIRE(checkValidSpoorNr() == true, "The spoorNr tag is not correct in this Station tag")
     * @post ENSURE(spoor->getSpoorNr() == -1, "The spoorNr of Spoor has not been correctly initialized")
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @param spoor waarvan spoorNr gecontroleerd wordt.
     * @return true or false
     * **/
    bool parseSpoorNr(Spoor *spoor, Exporter& e) const;

    /**
     * Functie dat controleerd ofdat een spoor valid is of niet.
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @return true or false
     * **/
    bool checkValidSpoor(Exporter& e) const;

    /**
     * Checked ofdat elke spoor de valid aantal attributen heeft en dat elk attribuut exact 1 keer geparsed wordt.
     * REQUIRE(getElement() != NULL, "TixmlElement is NULL");
     * @return true or false
     * **/
    bool checkNonValidAttributesAmount(Exporter& e) const;


    /**
     * Functie dat controleerd ofdat de vorige station valid is of niet.
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true or false
     * **/
    bool checkValidVorige(Exporter& e) const;

    /**
     * Functie dat controleerd ofdat de volgende station valid is of niet.
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true or false
     * **/
    bool checkValidVolgende(Exporter& e) const;

    /**
     * Functie dat controleerd ofdat de spoorNr valid is of niet.
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true or false
     * **/
    bool checkValidSpoorNr(Exporter& e) const;

    /**
     * Functie dat controleerd ofdatr er attriebuten zijn die niet behoren tot het Spoor object.
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true or false
     * **/
    bool checkNonValidAttributes(Exporter& e) const;

    /**
     * Getter functie dat een element geeft van het type TiXmlElement.
     * @return element
     * **/
    TiXmlElement *getElement() const;

    /**
     * Functie controleerd ofdat ParseSpoor correct werd geïnitialiseerd.
     * @return true or false
     * **/
    bool properlyInitialized();

private:
    TiXmlElement *element;
    std::string vorige;
    std::string volgende;
    int spoorNr;
    ParseSpoor *_fInitcheck;
};


#endif //METROSIMULATION_PARSESPOOR_H
