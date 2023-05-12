//
// Created by byamba on 22/03/23.
//

#ifndef METROSIMULATION_PARSEMETRONET_H
#define METROSIMULATION_PARSEMETRONET_H


#include <string>
#include "../TinyXML/tinyxml.h"
class Exporter;

class MetroNet;

/**
 * Klasse ParseMetroNet dat een MetroNet zal parsen vanuit een XML file en daarvan een MetroNet object van maken
 * in de memory om daarmee verder dingen te doen zoals een MetroNet simuleren.
 * **/
class ParseMetroNet {
public:

    /**
     * Explicit ParseMetroNet constructor.
       REQUIRE(!pathToInput.empty(), "Path to xml is empty");
       REQUIRE(Utils::fileExists(pathToInput), "The file does not exist!");
       ENSURE(getPathToInput() != NULL, "pathToFile could not be opened");
     * **/
    explicit ParseMetroNet(const std::string &pathToFile);

    /**
     * Functie die effectief de MetroNet zal parsen.
     * @pre REQUIRE(loadFile(), "The file could not be loaded")
     * @param metroNet die geparsed wordt.
     * **/
    bool parseMetroNet(MetroNet &metroNet, Exporter& e);

    /**
     * Functie die controleert ofdat de file waarnaar we weg willen schrijven ingelezen kan worden.
     * @pre REQUIRE(getPathToInput() != NULL, "pathToFile is NULL")
     * @post ENSURE(success, "File could not be loaded")
     * @return success of true als de file ingelezen kon worden.
     * **/
    bool loadFile();

    /**
     * Getter functie die een document returned van type TiXmlDocument.
     * @return doc
     * **/
    TiXmlDocument &getDoc();

    /**
     * Getter functie die een pathToInput terug zal geven.
     * @return pathToInput
     * **/
    FILE *getPathToInput() const;

    /**
     * Setter functie die de path van de file zal zetten.
     * @pre REQUIRE(f != NULL, "The File prt is NULL")
     * @post ENSURE(getPathToInput() == f, "setting was not successful")
     * @return true or false
     * **/
    bool setPathToInput(FILE *f);

    /**
     * Destructor of parser, closes stream
     */
    ~ParseMetroNet();


private:
    TiXmlDocument doc;
    FILE *pathToInput;
//    FILE* pathToLog;
};


#endif //METROSIMULATION_PARSEMETRONET_H
