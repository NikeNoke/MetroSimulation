//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_SIMPLEEXPORT_H
#define METROSIMULATION_SIMPLEEXPORT_H
#include "../MetroNet/MetroNet.h"
#include "InterfaceExport.h"

class SimpleExport: public InterfaceExport {
public:
    bool exportFile(MetroNet& metroNet, std::string path) const;
private:

};


#endif //METROSIMULATION_SIMPLEEXPORT_H
