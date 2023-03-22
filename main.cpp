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
#include "MetroNetGenerator//MetroNetGenerator.h"

int main() {

    MetroNetGenerator generator("metronet.xml", "metroNetSpecs.txt");

}
