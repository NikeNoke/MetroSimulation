//
// Created by byamba on 22/03/23.
//

#ifndef METROSIMULATION_EXPORTER_H
#define METROSIMULATION_EXPORTER_H


#include <cstdio>
#include <string>
#include "AdvancedExport.h"
#include "SimpleExport.h"

class MetroNet;

class Exporter {
public:

    explicit Exporter(std::string& pathToSimple, std::string& pathToAdvanced);

    Exporter();

    bool exportFile(MetroNet& metroNet) const;

//    std::string getPathToFile() const;

//    void setPathToFile(std::string f);

    bool properlyInitialized() const;

    std::string getPathToAdvanced() const;

    void setPathToAdvanced(const std::string &pathToAdvanced);

    std::string getPathToSimple() const;

    void setPathToSimple(const std::string &pathToSimple);

private:

    std::string pathToSimple;
    std::string pathToAdvanced;
    Exporter* _fInitCheck;

};


#endif //METROSIMULATION_EXPORTER_H
