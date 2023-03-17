#include <iostream>
#include "DesignByContract.h"
#include "TinyXML/tinyxml.h"
#include "Tram/Tram.h"
#include "Station/Station.h"
#include "vector"
#include "./MetroNet/MetroNet.h"
#include "Utils/utils.h"
#include <fstream>

int main() {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet1.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return 1;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return 1;
    }
    MetroNet metroNet;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();
        if (current == "STATION") {

            Utils::parseStation(metroNet, element);

        } else if (current == "TRAM") {

            Utils::parseTram(metroNet, element);

        } else{
            std::cerr << "Deze element is ongekend!\n";
        }
    }
    //TODO maybe verification of viability of metroNet???
    doc.Clear();


    //2.2
//    std::ofstream metroNetSpecs;

//    metroNetSpecs.open("metroNetSpecs.txt");

//    Utils::writeSpecs(metroNetSpecs, metroNet);

//    metroNetSpecs.close();

    std::cout << "Hoeveel keer moeten we het simuleren: ";
    int amount;
    std::cin >> amount;
    Utils::simulateMetroNet(metroNet, amount);

}
