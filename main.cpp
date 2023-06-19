#include <iostream>
#include "MetroNetGenerator//MetroNetGenerator.h"
#include <sstream>


//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

int main() {
    //also clears its content, perfect
//    freopen("OperationLog.txt", "w", stdout);
//    freopen("ErrorLog.txt", "w", stderr);

//    std::vector<std::string> directories;
//    directories.push_back("TestInputXML/InValidMetroNet/");
//    directories.push_back("TestInputXML/InValidTram/");
//    directories.push_back("TestInputXML/InValidStation/");
//    directories.push_back("TestInputXML/InValidSpoor/");
//
//    int dHolder = 3;
//    int holder = 3;
    std::ofstream operation;
    std::ofstream error;
//    operation.open("OperationLog.txt");
//    std::string temp = directories[dHolder] + "metroNetErr" + SSTR(holder) + ".txt";
//    error.open(temp.c_str());
    std::string outputAd = "metroNetSpecs2.txt";
////    std::string outputAd = "TestInputXML/ValidMetroNet/metroNet2Advanced.txt";
////    std::string outputS = "metroNetSpecs.txt";
    std::string outputS = "metroNetSpecs.txt";
//    std::string input = directories[dHolder] + "metroNet" + SSTR(holder) + ".xml";
//    try {
//        MetroNetGenerator generator(input, outputS, outputAd, operation, error);
//
//        generator.generateMetroNet();
//
////        generator.simulate(1);
//
//    } catch (...) {
//        std::cerr << "Error from main!\n";
//    }

    MetroNetGenerator generator("metronet.xml", outputS, outputAd, operation, error);

    generator.generateMetroNet();

    generator.simulate(1);

}
