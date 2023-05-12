//
// Created by byamba on 21/04/23.
//

#ifndef METROSIMULATION_INTERFACEEXPORT_H
#define METROSIMULATION_INTERFACEEXPORT_H


//#include "../MetroNet/MetroNet.h"
#include <fstream>

class MetroNet;

/*
 * Pure virtual klasse dat dient voor files te exporten.
 * */
class InterfaceExport {

public:
    /**
     * Pure virtual methode.
     * @param metroNet Het metroNet dat men zal exporten.
     * @param path van de file.
     * **/
    virtual bool exportFile(MetroNet &metroNet, const std::string& path) const = 0;

    virtual bool properlyInitialized() const = 0;

private:
};


#endif //METROSIMULATION_INTERFACEEXPORT_H
