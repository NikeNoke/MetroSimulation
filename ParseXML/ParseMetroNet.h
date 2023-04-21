//
// Created by byamba on 22/03/23.
//

#ifndef METROSIMULATION_PARSEMETRONET_H
#define METROSIMULATION_PARSEMETRONET_H


#include <string>
#include "../TinyXML/tinyxml.h"
class MetroNet;

class ParseMetroNet {
public:

    explicit ParseMetroNet(const std::string& pathToFile);

    bool parseMetroNet(MetroNet& metroNet);

    bool loadFile();

    TiXmlDocument& getDoc();

    FILE* getPathToInput() const;

    bool setPathToInput(FILE* f);

//    bool setPathToLog(FILE* f);

//    FILE* getPathToLog() const;


private:
    TiXmlDocument doc;
    FILE* pathToInput;
//    FILE* pathToLog;
};


#endif //METROSIMULATION_PARSEMETRONET_H
