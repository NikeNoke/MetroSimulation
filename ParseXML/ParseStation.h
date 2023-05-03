//
// Created by byamba on 20/03/23.
//

#ifndef METROSIMULATION_PARSESTATION_H
#define METROSIMULATION_PARSESTATION_H

#include "../DesignByContract.h"
#include "../Stations/Station.h"
#include "../MetroNet/MetroNet.h"
#include "../TinyXML/tinyxml.h"
#include <string>

/**
* Klasse om een Station object te parsen.
*/
class ParseStation {

public:

    /**
     * Explicit constructor voor een ParseStation object.
     * @pre REQUIRE(element != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() == element, "TixmlElement is not the element of the parser")
     * @post ENSURE(properlyInitialized(), "ParseSpoor has been properly initialized")
     * @param element van het type TiXmlElement
     * @return ParseStation object.
     * **/
    explicit ParseStation(TiXmlElement *element);

    /**
     * Setter functie dat een element van type TiXmlElement set.
     * @pre REQUIRE(el != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() == element, "TixmlElement is not the element of the parser")
     * @param el element van type TiXmlElement
     * **/
    void setElement(TiXmlElement *el);

    /**
     * Functie dat het Station object parsed van een MetroNet object.
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @pre REQUIRE(checkValidStation() == true, "The Station tag is not correct")
     * @post ENSURE(!station->getName().empty(), "The naam of station has not been correctly initialized")
     * @post ENSURE(!station->getSporen().empty(), "The SPOOR's of station has not been correctly initialized")
     * @post ENSURE(!station->getType().empty(), "The type of station has not been correctly initialized")
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getParsedStation() != NULL, "akfjdajkfl");
     * @return true or false
     * **/
    bool parseAll();

    /**
     * Functie dat gecalled wordt door parseAll om ervoor te zorgen dat de naam van een spoor geparsed kan worden.
     * @pre REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized")
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @pre REQUIRE(checkValidNaam() == true, "The name tag is not correct in this Station tag")
     * @post ENSURE(!station->getName().empty(), "The naam of station has not been correctly initialized")
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @param station dat men gaat parsen
     * @return true or false
     * **/
    bool parseNaam(Station *station) const;

    /**
     * Functie dat nakijkt ofdat het Station object valid is.
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @return true or false
     * **/
    bool checkValidStation() const;

    /**
     * Functie dat controleerd ofdat naam valid is.
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true or false
     * **/
    bool checkValidNaam() const;

    /**
     * Functie dat controleerd ofdat er attriebuten zijn die niet deel zijn van een Station object.
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true or false
     * **/
    bool checkNonValidAttributes() const;

    /**
     * Functie dat controleerd ofdat het type van het Station object valid is.
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement has become NULL")
     * @return true or false
     * **/
    bool checkValidTypeStation() const;

    /**
     * Functie dat het type van een station parsed.
     * @pre REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized")
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @pre REQUIRE(checkValidTypeStation() == true, "The type tag is not correct in this Station tag")
     * @post ENSURE(!station->getType().empty(), "The type of station has not been correctly initialized")
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @param station waarven we het type willen parsen.
     * @return true or false
     * **/
    bool parseTypeStation(Station *station) const;

    /**
     * Getter functie dat een element teruggeeft van type TiXmlElement.
     * @return element van type TiXmlElement.
     * **/
    TiXmlElement *getElement() const;

    /**
     * Functie dat controleerd ofdat het ParseStation object correct werd geïnitialiseerd.
     * @return true or false
     * **/
    bool properlyInitialized();

    /**
     * Functie dat het Spoor object zal parsen.
     * @pre REQUIRE(station->properlyInitialized(), "Station is not properlyInitialized")
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(getElement() != NULL, "TixmlElement is NULL")
     * @post ENSURE(!station->getSporen().empty(), "The sporen cannot be empty")
     * @param station dat we gaan parsen.
     * @return true or false
     * **/
    bool parseSpoor(Station *station) const;

    /**
     * Getter functie het Station type gaat teruggeven.
     * @pre REQUIRE(getElement() != NULL, "TixmlElement is NULL")
     * @pre REQUIRE(checkValidTypeStation() == true, "The type tag is not correct in this Station tag")
     * @return StationType
     * **/
    TypeStation::StationType getStationType() const;

    /**
     * Functie dat controleert ofdat en parse succesvol was of niet.
     * @return true or false
     * **/
    bool parseSuccessful();

    /**
     * Setter functie dat Station set.
     * @param s Station dat geset wordt.
     * **/
    void setParsedStation(Station *s);

    /**
     * Getter functie dat het parsed Station zal teruggeven.
     * @return parsedStation
     * **/
    Station *getParsedStation() const;

    /**
     * Functie dat controleert ofdat er sporen aanwezig zijn en die valid zijn.
     * @return true or false
     * **/
    bool checkSporen() const;

private:
    TiXmlElement *element;
    ParseStation *_fInitcheck;
    Station *parsedStation;

};

#endif //METROSIMULATION_PARSESTATION_H



