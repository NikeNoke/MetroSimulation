#include <iostream>
#include "utils.h"
#include <cstdlib>
#include "../DesignByContract.h"
#include "../MetroNetGenerator/MetroNetGenerator.h"
#include <sys/stat.h>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <sstream>


//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

//Source stackoverflow
bool Utils::is_int(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}


std::string Utils::boolToText(bool b) {
    if (b)
        return "gevonden";
    else
        return "niet gevonden";
}


//Source Stackoverflow
int Utils::getRandomInt(int max) {
    int min = 0;
    int output;
    output = min + (std::rand() % static_cast<int>(max - min + 1));
    return output;
}

/**
Auxiliary functions for file manipulation.
*/
bool Utils::directoryExists(const std::string dirname) {
    struct stat st;
    return stat(dirname.c_str(), &st) == 0;
}

bool Utils::fileExists(const std::string filename) {
    struct stat st;
    if (stat(filename.c_str(), &st) != 0) return false;
    std::ifstream f(filename.c_str());
    if (f.good()) {
        f.close();
        return true;
    } else {
        f.close();
        return false;
    }
}

bool Utils::isNegative(int n) {
    if (n - n != 0) {
        return true;
    } else { return false; }

}


bool Utils::FileCompare(const std::string& leftFileName, const std::string& rightFileName) {
    std::ifstream leftFile, rightFile;
    char leftRead, rightRead;
    bool result;

    // Open the two files.
    leftFile.open(leftFileName.c_str());
    if (!leftFile.is_open()) {
        return false;
    };
    rightFile.open(rightFileName.c_str());
    if (!rightFile.is_open()) {
        leftFile.close();
        return false;
    };

    result = true; // files exist and are open; assume equality unless a counterexamples shows up.
    bool left = leftFile.good();
    bool right = rightFile.good();
    while (result && leftFile.good() && rightFile.good()) {
        leftFile.get(leftRead);
        rightFile.get(rightRead);
        result = (leftRead == rightRead);
        left = leftFile.good();
        right = rightFile.good();
    };
    if(left || right)
        std::cout << "";
    if (result) {
        // last read was still equal; are we at the end of both files ?
        result = (!leftFile.good()) && (!rightFile.good());
    };

    leftFile.close();
    rightFile.close();
    return result;
}
//https://stackoverflow.com/questions/6163611/compare-two-files
bool Utils::compareFiles(const std::string& p1, const std::string& p2) {
    std::ifstream f1(p1.c_str(), std::ifstream::binary|std::ifstream::ate);
    std::ifstream f2(p2.c_str(), std::ifstream::binary|std::ifstream::ate);

    if (f1.fail() || f2.fail()) {
        return false; //file problem
    }

    if (f1.tellg() != f2.tellg()) {
        return false; //size mismatch
    }

    //seek back to beginning and use std::equal to compare contents
    f1.seekg(0, std::ifstream::beg);
    f2.seekg(0, std::ifstream::beg);
    return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                      std::istreambuf_iterator<char>(),
                      std::istreambuf_iterator<char>(f2.rdbuf()));
}

void Utils::makeReadyForTesting() {

    std::vector<std::string> directories;
    directories.push_back("TestInputXML/InValidMetroNet/");
    directories.push_back("TestInputXML/InValidTram/");
    directories.push_back("TestInputXML/InValidStation/");
    directories.push_back("TestInputXML/InValidSpoor/");

    for(unsigned int i = 0; i < directories.size(); i++){


        for(int j = 0; j < 4; j++){

            std::ofstream operation;
            std::ofstream error;
            operation.open("OperationLog.txt");
            std::string temp = directories[i] + "metroNetErr" + SSTR(j) + ".txt";
            error.open(temp.c_str());
            std::string outputAd = "metroNetSpecs2.txt";
//    std::string outputAd = "TestInputXML/ValidMetroNet/metroNet2Advanced.txt";
//    std::string outputS = "metroNetSpecs.txt";
            std::string outputS = "metroNetSpecs.txt";
            std::string input = directories[i] + "metroNet" + SSTR(j) + ".xml";
            try {
                MetroNetGenerator generator(input, outputS, outputAd, operation, error);

                generator.generateMetroNet();

//        generator.simulate(1);

            } catch (...) {
                std::cerr << "Error from main!\n";
            }

        }

    }
}