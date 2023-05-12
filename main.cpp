#include <iostream>
#include "MetroNetGenerator//MetroNetGenerator.h"

int main() {
    //also clears its content, perfect
//    freopen("OperationLog.txt", "w", stdout);
//    freopen("ErrorLog.txt", "w", stderr);

    std::ofstream operation;
    std::ofstream error;
    operation.open("OperationLog.txt");
    error.open("ErrorLog.txt");
    std::string outputAd = "metroNetSpecs2.txt";
//    std::string outputAd = "TestInputXML/ValidMetroNet/metroNet2Advanced.txt";
//    std::string outputS = "metroNetSpecs.txt";
    std::string outputS = "metroNetSpecs.txt";
    try {
        MetroNetGenerator generator("metronet.xml", outputS, outputAd, operation, error);

        generator.generateMetroNet();

//        generator.simulate(1);

    } catch (...) {
        std::cerr << "Error from main!\n";
    }

}
