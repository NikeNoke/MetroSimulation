//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_PARSESPOOR_H
#define METROSIMULATION_PARSESPOOR_H
#include "../DesignByContract.h"
#include "../Station/Station.h"
#include "../MetroNet/MetroNet.h"
#include "../TinyXML/tinyxml.h"
#include "../Spoor/Spoor.h"
#include <string>

class ParseSpoor {

public: //TODO change documentation!!Q

    /**
    * Constructor voor ParseStation.
    * @param element Een TiXmlEmlement dat geparsed zal worden.
    */
    explicit ParseSpoor(TiXmlElement *element);

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
    bool parseAll(Spoor* spoor) const;


    /**
    * Methode dat gecalled wordt door parseAll om te checken ofdat Vorige geparsed kan worden
    * @param metroNet Naam van het MetroNet.
    * @param station Naam van het Station.
    * @return true of false
    */
    bool parseVorige(Spoor* spoor) const;

    /**
    * Methode dat gecalled wordt door parseAll om te checken ofdat Volgende geparsed kan worden
    * @param metroNet Naam van het MetroNet.
    * @param station Naam van het Station.
    * @return true of false
    */
    bool parseVolgende(Spoor* spoor) const;

    /**
    * Methode dat gecalled wordt door parseAll om te checken ofdat spoorNr geparsed kan worden
    * @param metroNet Naam van het MetroNet.
    * @param station Naam van het Station.
    * @return true of false
    */
    bool parseSpoorNr(Spoor* spoor) const;

    /**
    * Checked ofdat het Station object correct is.
    * @return true of false
    */
    bool checkValidSpoor() const;


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

    TiXmlElement * getElement() const;

    bool properlyInitialized();

private:
    TiXmlElement *element;
    std::string vorige;
    std::string volgende;
    int spoorNr;
    ParseSpoor* _fInitcheck;
};


#endif //METROSIMULATION_PARSESPOOR_H
