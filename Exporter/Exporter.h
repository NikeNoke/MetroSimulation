//
// Created by byamba on 22/03/23.
//

#ifndef METROSIMULATION_EXPORTER_H
#define METROSIMULATION_EXPORTER_H


#include <cstdio>
#include <string>

class MetroNet;

class Exporter {
public:

    explicit Exporter(std::string pathToF);

    Exporter();

    bool exportFile(MetroNet& metroNet) const;

    std::string getPathToFile() const;

    void setPathToFile(std::string f);

    bool properlyInitialized() const;


private:

    std::string pathToFile;
    Exporter* _fInitCheck;

};


#endif //METROSIMULATION_EXPORTER_H
