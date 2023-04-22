#include <iostream>
#include "MetroNetGenerator//MetroNetGenerator.h"

int main() {
    //also clears its content, perfect
    freopen("OperationLog.txt", "w", stdout);
    freopen("ErrorLog.txt", "w", stderr);

    //TODO MAKE it a while loop
    try{
        MetroNetGenerator generator("metronet.xml", "metroNetSpecs.txt", "metroNetSpecs2.txt");

        generator.generateMetroNet();

        generator.simulate(10);

    }catch(...) {
        std::cerr << "Error from main!\n";
    }

}
