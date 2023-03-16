//
// Created by Thomas on 02/03/2023.
//

#ifndef METROSIMULATION_STATION_H
#define METROSIMULATION_STATION_H

#include <string>

class Station {
public:
    std::string naam;
    std::string volgende;
    std::string vorige;
    int spoorNr;

    Station();

    Station(const std::string &naam,const std::string& volgende,const std::string& vorige, int spoorNr);
};


#endif //METROSIMULATION_STATION_H
