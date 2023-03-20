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

class ParseTram {

public:

    explicit ParseTram(TiXmlElement *element);

    void setElement(TiXmlElement *el);

    bool parseAll(MetroNet &metroNet, Tram* tram) const;

    bool parseLijnNr(MetroNet &metroNet, Tram* tram) const;

    bool parseBeginStation(MetroNet &metroNet, Tram* tram) const;

    bool parseSnelheid(MetroNet &metroNet, Tram* tram) const;

    bool checkValidTram() const;

    bool checkValidLijnNr() const;

    bool checkValidBeginStation() const;

    bool checkValidSnelheid() const;


private:
    TiXmlElement *element;

};


#endif //METROSIMULATION_PARSETRAM_H
