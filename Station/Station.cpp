//
// Created by Thomas on 02/03/2023.
//

#include "Station.h"

Station::Station() {}

Station::Station(const std::string &naam,const std::string& volgende,const std::string& vorige, int spoorNr) : naam(naam),
                                                                                                     volgende(volgende),
                                                                                                     vorige(vorige),
                                                                                                     spoorNr(spoorNr) {}
