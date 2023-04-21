//
// Created by byamba on 22/03/23.
//

#ifndef METROSIMULATION_METRONETGENERATOR_H
#define METROSIMULATION_METRONETGENERATOR_H
#include <string>
#include "../MetroNet/MetroNet.h"
#include "../Stations/Station.h"
#include "../ParseXML/ParseMetroNet.h"
#include "../ParseXML/ParseTram.h"
#include "../ParseXML/ParseStation.h"
#include "../Trams/Tram.h"
#include "../Utils/utils.h"
#include "../Exporter/Exporter.h"


class MetroNetGenerator {
public:

    explicit MetroNetGenerator(std::string pathToXml, std::string pathToWrite, std::string pathToWrite2);

    void generateMetroNet();

    MetroNet& getMetroNet();

    std::string getPathToOpenXml() const;

    std::string getPathToWrite() const;

    void setPathToOpenXml(std::string& p);

    void setPathToWrite(std::string& p);

    void simulate(int seconds);

    Exporter& getExporter();

//    std::string getPathToLog() const;

//    void setPathToLog(std::string& p);

private:
    std::string pathToOpenXml;
    std::string pathToWrite;
//    std::string pathToLog;
    MetroNet metroNet;
    Exporter exporter;
};


#endif //METROSIMULATION_METRONETGENERATOR_H
