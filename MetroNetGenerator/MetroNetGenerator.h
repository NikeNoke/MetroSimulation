//
// Created by byamba on 22/03/23.
//

#ifndef METROSIMULATION_METRONETGENERATOR_H
#define METROSIMULATION_METRONETGENERATOR_H
#include <string>
#include <iostream>
#include "../MetroNet/MetroNet.h"
#include "../Stations/Station.h"
#include "../ParseXML/ParseMetroNet.h"
#include "../ParseXML/ParseTram.h"
#include "../ParseXML/ParseStation.h"
#include "../Trams/Tram.h"
#include "../Utils/utils.h"
#include "../Exporter/Exporter.h"

/**
 * Klasse MetroNetGenerator dat gebruikt wordt om een MetroNet simulatie te genereren en die dan weg te schrijven
 * naar een file van keuze.
 *
 * **/
class MetroNetGenerator {
public:

    /**
     * Explicit MetroNetGenerator constructor.
     * @pre REQUIRE(Utils::fileExists(pathToXml), "Path to xml is wrong or file does not exist")
     * @param pathToWrite Gebruikt om weg te schrijven met gebruik van de SimpleExport.
     * @param pathToWrite2 Gebruikt om weg te schrijven met gebruik van de AdvancedExport.
     * @param pathToXml XML file dat gebruikt zou worden om daarven een MetroNet uit te halen.
     * **/
    explicit MetroNetGenerator(std::string pathToXml, std::string pathToSimple, std::string pathToAdvanced
                                , std::ostream& op, std::ostream& err);

    /**
     * Functie dat de MetroNet zal genereren en die dan wegschrijven.
     * @pre REQUIRE(Utils::fileExists(getPathToOpenXml()), "The file to open does not exist")
     * @post ENSURE(getMetroNet().isValidMetroNet(), "The metroNet is not valid")
     * @post ENSURE(Utils::fileExists(getPathToWrite()), "The file was not even created")
     * @param noStat boolean dat op default op false staat. Als ze op true wordt gezet dan zal er geen stat
     * report afgedrukt worden. (Handig voor testsen waar we geen bloat willen).
     * @note Roept de methode metroNetParser van ParseMetroNet om de MetroNet van de XML file te parsen.
     * **/
    void generateMetroNet(bool noStat=false);

    /**
     * Getter functie om MetroNet te returnen.
     * @return metroNet
     * **/
    MetroNet& getMetroNet();

    /**
     * Getter functie om de path naar the XML file te verkrijgen.
     * @return pathToOpenXml
     * **/
    std::string getPathToOpenXml() const;


    /**
     * Zet de path van de XML file dat we gaan openen om daaruit de MetroNet te parsen.
     * @pre REQUIRE(Utils::fileExists(p), "Path to xml is wrong or file does not exist")
     * @post ENSURE(getPathToOpenXml() ==  p, "The set was a failure")
     * @param p Path van de XML file dat geparsed zal worden.
     * **/
    void setPathToOpenXml(std::string& p);

    /**
     * Functie dat onze MetroNet zal simuleren.
     * @pre REQUIRE(getMetroNet().isValidMetroNet(), "The metroNet is not Valid")
     * @post ENSURE(getMetroNet().isValidMetroNet(), "The metroNet is not Valid")
     * @param seconds Duur van de simulatie.
     * **/
    void simulate(int seconds);

    /**
     * Getter functie dat de exporter terug gaat geven.
     * @pre REQUIRE(exporter.properlyInitialized(), "exporter is not properlyInitialized")
     * @return exporter
     * **/
    Exporter& getExporter();


    std::string getPathToAdvanced() const;

    void setPathToAdvanced(const std::string& s);

    std::string getPathToSimple() const;

    void setPathToSimple(const std::string& s);

private:
    std::string pathToOpenXml;
    std::string pathToWriteSimple;
    std::string pathToWriteAdvanced;
    Exporter exporter;
    MetroNet metroNet;
};


#endif //METROSIMULATION_METRONETGENERATOR_H
