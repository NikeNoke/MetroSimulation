//
// Created by byamba on 20/03/23.
//

#ifndef METROSIMULATION_PARSESTATION_H
#define METROSIMULATION_PARSESTATION_H
#include "../DesignByContract.h"
#include "../Station/Station.h"
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
    bool parseAll(MetroNet &metroNet, Station* station) const;

    /**
     * Methode dat gecalled wordt door parseAll om te checken ofdat naam geparsed kan worden
     * @param metroNet Naam van het MetroNet.
     * @param station Naam van het Station.
     * @return true of false
     */
    bool parseNaam(MetroNet &metroNet, Station* station) const;

    /**
     * Methode dat gecalled wordt door parseAll om te checken ofdat Vorige geparsed kan worden
     * @param metroNet Naam van het MetroNet.
     * @param station Naam van het Station.
     * @return true of false
     */
    bool parseVorige(MetroNet &metroNet, Station* station) const;

    /**
     * Methode dat gecalled wordt door parseAll om te checken ofdat Volgende geparsed kan worden
     * @param metroNet Naam van het MetroNet.
     * @param station Naam van het Station.
     * @return true of false
     */
    bool parseVolgende(MetroNet &metroNet, Station* station) const;

    /**
     * Methode dat gecalled wordt door parseAll om te checken ofdat spoorNr geparsed kan worden
     * @param metroNet Naam van het MetroNet.
     * @param station Naam van het Station.
     * @return true of false
     */
    bool parseSpoorNr(MetroNet &metroNet, Station* station) const;

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
     * Methode dat gecalled wordt door checkValidStation of te controleren ofdat Vorige valid is.
     * @return true of false
     */
    bool checkValidVorige() const;

    /**
     * Methode dat gecalled wordt door checkValidStation of te controleren ofdat Volgende valid is.
     * @return true of false
     */
    bool checkValidVolgende() const;

    /**
     * Methode dat gecalled wordt door checkValidStation of te controleren ofdat spoorNr valid is.
     * @return true of false
     */
    bool checkValidSpoorNr() const;

    /**
     * Checked ofdat er onverwachte attributes zijn.
     * @return true of false
     */
    bool checkNonValidAttributes() const;


private:
    TiXmlElement *element;
    std::string  naam;

};


#endif //METROSIMULATION_PARSESTATION_H
