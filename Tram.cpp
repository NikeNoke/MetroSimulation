//
// Created by Thomas on 02/03/2023.
//

#include "Tram.h"

Tram::Tram() {}

Tram::Tram(const std::string &beginStation, int snelheid, int lijnNr) : beginStation(beginStation), snelheid(snelheid),
                                                                        lijnNr(lijnNr) {}
