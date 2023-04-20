#include <iostream>
#include "MetroNetGenerator//MetroNetGenerator.h"

int main() {
    //TODO MAKE it a while loop
    try{
        MetroNetGenerator generator("TestInputXML/temp.xml", "metroNetSpecs.txt");

        generator.generateMetroNet();

        generator.simulate(10);

    }catch(...) {
        std::cerr << "Error!!\n";
    }

}
