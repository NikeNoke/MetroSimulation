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

class ParseStation {

public:

    explicit ParseStation(TiXmlElement *element);

    void setElement(TiXmlElement *el);

    bool parseAll(MetroNet &metroNet, Station* station) const;

    bool parseNaam(MetroNet &metroNet, Station* station) const;

    bool parseVorige(MetroNet &metroNet, Station* station) const;

    bool parseVolgende(MetroNet &metroNet, Station* station) const;

    bool parseSpoorNr(MetroNet &metroNet, Station* station) const;

    bool checkValidStation() const;

    bool checkValidNaam() const;

    bool checkValidVorige() const;

    bool checkValidVolgende() const;

    bool checkValidSpoorNr() const;


private:
    TiXmlElement *element;
    std::string  naam;

};


#endif //METROSIMULATION_PARSESTATION_H
