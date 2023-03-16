

#ifndef METROSIMULATION_UTILS_H
#define METROSIMULATION_UTILS_H
#include <string>
#include "../TinyXML/tinyxml.h"
#include "../MetroNet/MetroNet.h"
#include "../Station/Station.h"
#include "../Tram/Tram.h"
#include <fstream>
#include <vector>
#include <random>

namespace Utils{
    //Source StackOverFlow
    bool is_int(const std::string &s);

    void parseStation(MetroNet& metroNet, TiXmlElement* element);

    void parseTram(MetroNet& metroNet, TiXmlElement* element);

    void writeSpecs(std::ofstream& file, MetroNet& metroNet);

    bool validMetroNet(MetroNet& metroNet);

    std::string boolToText(bool b);

    void simulateMetroNet(MetroNet& metroNet, int amountOfMove);

    int getRandomInt(int max);

}

#endif //METROSIMULATION_UTILS_H