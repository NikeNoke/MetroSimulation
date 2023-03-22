//
// Created by byamba on 22/03/23.
//

#ifndef METROSIMULATION_METRONETGENERATOR_H
#define METROSIMULATION_METRONETGENERATOR_H
#include <string>
#include "../MetroNet/MetroNet.h"
#include "../Station/Station.h"
#include "../ParseXML/ParseMetroNet.h"
#include "../ParseXML/ParseTram.h"
#include "../ParseXML/ParseStation.h"
#include "../Tram/Tram.h"
#include "../Utils/utils.h"


class MetroNetGenerator {
public:

    explicit MetroNetGenerator(std::string pathToXml, std::string pathToWrite);

    MetroNet& getMetroNet();

    std::string getPathToOpenXml() const;

    std::string getPathToWrite() const;

    void setPathToOpenXml(std::string p);

    void setPathToWrite(std::string p);

private:
    std::string pathToOpenXml;
    std::string pathToWrite;
    MetroNet metroNet;
};


#endif //METROSIMULATION_METRONETGENERATOR_H
