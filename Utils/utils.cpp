#include <iostream>
#include "utils.h"
#include <cstdlib>
#include "../DesignByContract.h"
#include <sys/stat.h>
#include <fstream>


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


bool FileCompare(const std::string& leftFileName, const std::string& rightFileName) {
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
    while (result && leftFile.good() && rightFile.good()) {
        leftFile.get(leftRead);
        rightFile.get(rightRead);
        result = (leftRead == rightRead);
    };
    if (result) {
        // last read was still equal; are we at the end of both files ?
        result = (!leftFile.good()) && (!rightFile.good());
    };

    leftFile.close();
    rightFile.close();
    return result;
}
