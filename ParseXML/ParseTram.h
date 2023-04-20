//
// Created by byamba on 20/03/23.
//

#ifndef METROSIMULATION_PARSETRAM_H
#define METROSIMULATION_PARSETRAM_H
#include "../DesignByContract.h"
#include "../Tram/Tram.h"
#include "../MetroNet/MetroNet.h"
#include "../TinyXML/tinyxml.h"
#include <string>

/**
 * Klasse om een Tram object te parsen.
 */
class ParseTram {

public:

    /**
     * Constructor voor ParseTram.
     * @param element Element dat geparsed zal worden.
     */
    explicit ParseTram(TiXmlElement *element);

    /**
     * @brief Set Element
     * Zet element in ParseTram
     * @param el Element dat gezet zal worden
     */
    void setElement(TiXmlElement *el);

    /**
     * Parsed de Tram object van een MetroNet object.
     * @param metroNet Naam van het MetroNet.
     * @param tram Naam van de Tram.
     * @return true of false afhankelijk of het gelukt is of niet.
     */
    bool parseAll(Tram* tram) const;

    /**
     * Methode dat gecalled wordt door parseAll of te checken ofdat lijnNr geparsed kan worden.
     * @param metroNet Naam van het MetroNet.
     * @param tram  Naam van de Tram.
     * @return true of false afhankelijk ofdat het lijNr geparsed kon worden.
     */
    bool parseLijnNr(Tram* tram) const;

    /**
    * Methode dat gecalled wordt door parseAll of te checken ofdat beginStation geparsed kan worden.
    * @param metroNet Naam van het MetroNet.
    * @param tram  Naam van de Tram.
    * @return true of false afhankelijk ofdat het beginStation geparsed kon worden.
    */
    bool parseBeginStation(Tram* tram) const;

    /**
    * Methode dat gecalled wordt door parseAll of te checken ofdat snelheid geparsed kan worden.
    * @param metroNet Naam van het MetroNet.
    * @param tram  Naam van de Tram.
    * @return true of false afhankelijk ofdat het snelheid geparsed kon worden.
    */
    bool parseSnelheid(Tram* tram) const;

    /**
     * @brief Check valid Tram.
     * @return true of false
     */
    bool checkValidTram() const;

    /**
     * @brief Check valid lijNr.
     * Methode dat gecalled wordt door checkValidTram om te controlleren ofdat lijNr correct is.
     * @return true of false
     */
    bool checkValidLijnNr() const;

    /**
     * @brief Check valid beginStation.
     * Methode dat gecalled wordt door checkValidTram om te controlleren ofdat beginStation correct is.
     * @return true of false
     */
    bool checkValidBeginStation() const;

    /**
     * @brief Check valid snelheid.
     * Methode dat gecalled wordt door checkValidTram om te controlleren ofdat snelheid correct is.
     * @return true of false
     */
    bool checkValidSnelheid() const;

    /**
    * Checked ofdat er onverwachte attributen zijn.
    * @return true of false
    */
    bool checkNonValidAttributes() const;

    bool checkValidTypeTram() const;

    bool parseTypeTram(Tram* tram) const;

    bool checkValidVoertuigNummer() const;

    bool parserVoertuigNummer(Tram* tram) const;

    TiXmlElement* getElement() const;


private:
    TiXmlElement * fElement;

};


#endif //METROSIMULATION_PARSETRAM_H
