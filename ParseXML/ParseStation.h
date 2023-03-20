//
// Created by byamba on 20/03/23.
//

#ifndef METROSIMULATION_PARSESTATION_H
#define METROSIMULATION_PARSESTATION_H
#include "../DesignByContract.h"
#include "../Station/Station.h"
#include "../MetroNet/MetroNet.h"
#include "../TinyXML/tinyxml.h"

class ParseStation {

public:

    bool parseNaam(TiXmlElement *element) const;

    bool parseVorige(TiXmlElement *element) const;

    bool parseVolgende(TiXmlElement *element) const;

    bool parseSpoorNr(TiXmlElement *element) const;


private:

};


#endif //METROSIMULATION_PARSESTATION_H
