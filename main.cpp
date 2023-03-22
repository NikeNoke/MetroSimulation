#include <iostream>
#include "DesignByContract.h"
#include "TinyXML/tinyxml.h"
#include "Tram/Tram.h"
#include "Station/Station.h"
#include "vector"
#include "./MetroNet/MetroNet.h"
#include "Utils/utils.h"
#include "ParseXML/ParseStation.h"
#include "ParseXML/ParseTram.h"
#include <fstream>
#include "ParseXML/ParseMetroNet.h"

int main() {

    REQUIRE(Utils::fileExists("TestInputXML/metronet1.xml"), "The file does not exist");

    ParseMetroNet metroNetParser("TestInputXML/metronet1.xml");

    MetroNet metroNet;

    metroNetParser.parseMetroNet(metroNet);


    if(!metroNet.isValidMetroNet()){
        std::cerr << "The MetroNet is not Valid\n";
        return 1;
    }


}
