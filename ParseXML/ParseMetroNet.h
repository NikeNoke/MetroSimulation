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

    explicit ParseMetroNet(std::string pathToFile);

    bool parseMetroNet(MetroNet& metroNet);

    bool loadFile();

    TiXmlDocument& getDoc();

    FILE* getPathToFile() const;

    bool setPathToFile(FILE* f);


private:
    TiXmlDocument doc;
    FILE* pathToFile;
};


#endif //METROSIMULATION_PARSEMETRONET_H
