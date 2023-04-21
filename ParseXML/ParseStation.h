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
* Constructor voor ParseStation.
* @param element Een TiXmlEmlement dat geparsed zal worden.
*/
    explicit ParseStation(TiXmlElement *element);

/**
* @brief Set Element
* Zet de element van ParseStation.
* @param el Element dat gezet zal worden.
*/
    void setElement(TiXmlElement *el);

/**
* Parsed het Station object van een MetroNet object.
* @param metroNet Naam van het MetroNet.
* @param station Naam van het Station.
* @return true of false afhankelijk ofdat het Station object geparsed kon worden.
*/
    bool parseAll();

/**
* Methode dat gecalled wordt door parseAll om te checken ofdat naam geparsed kan worden
* @param metroNet Naam van het MetroNet.
* @param station Naam van het Station.
* @return true of false
*/
    bool parseNaam(Station* station) const;


/**
* Checked ofdat het Station object correct is.
* @return true of false
*/
    bool checkValidStation() const;

/**
* Methode dat gecalled wordt door checkValidStation of te controleren ofdat naam valid is.
* @return true of false
*/
    bool checkValidNaam() const;

/**
* Checked ofdat er onverwachte attributes zijn.
* @return true of false
*/
    bool checkNonValidAttributes() const;

    bool checkValidTypeStation() const;

    bool parseTypeStation(Station* station) const;

    TiXmlElement * getElement() const;

    bool properlyInitialized();

    bool parseSpoor(Station* station) const;

    TypeStation::StationType getStationType() const;

    bool parseSuccessful();

    void setParsedStation(Station*);

    Station* getParsedStation() const;

private:
    TiXmlElement *element;
    ParseStation* _fInitcheck;
    Station* parsedStation;

};

#endif //METROSIMULATION_PARSESTATION_H



