//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_ADVANCEDEXPORT_H
#define METROSIMULATION_ADVANCEDEXPORT_H
#include "../MetroNet/MetroNet.h"
#include "InterfaceExport.h"

class AdvancedExport: public InterfaceExport{
public:
    bool exportFile(MetroNet& metroNet, std::string path) const;

    int indexVolgende(std::vector<Spoor* >&, const std::string& naam) const;

private:

};


#endif //METROSIMULATION_ADVANCEDEXPORT_H
