#include <iostream>
#include "MetroNetGenerator//MetroNetGenerator.h"

int main() {
    //TODO MAKE it a while loop
    try{
        MetroNetGenerator generator("TestInputXML/ValidMetroNet/metroNet2.xml", "metroNetSpecs.txt");

        generator.generateMetroNet();

        generator.simulate(10);

    }catch(...) {
        std::cerr << "Error!!\n";
    }

}
