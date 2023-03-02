//
// Created by Thomas on 02/03/2023.
//

#ifndef METROSIMULATION_STATION_H
#define METROSIMULATION_STATION_H
#include <string>

class Station {
std::string naam;
std::string* volgende;
std::string* vorige;
int spoorNr;
public:
    Station();

    Station(const std::string &naam, std::string *volgende, std::string *vorige, int spoorNr);
};


#endif //METROSIMULATION_STATION_H
