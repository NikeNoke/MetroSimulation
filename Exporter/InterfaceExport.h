//
// Created by byamba on 21/04/23.
//

#ifndef METROSIMULATION_INTERFACEEXPORT_H
#define METROSIMULATION_INTERFACEEXPORT_H


#include "../MetroNet/MetroNet.h"

class InterfaceExport {
public:
    virtual bool exportFile(MetroNet& metroNet, std::string path) const = 0;
private:
};


#endif //METROSIMULATION_INTERFACEEXPORT_H
