//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_SIMPLEEXPORT_H
#define METROSIMULATION_SIMPLEEXPORT_H
#include "../MetroNet/MetroNet.h"

class SimpleExport {
public:
    bool exportFile(MetroNet& metroNet, std::string path) const;
private:

};


#endif //METROSIMULATION_SIMPLEEXPORT_H
