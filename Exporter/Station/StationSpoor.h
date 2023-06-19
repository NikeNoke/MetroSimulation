//
// Created by byamba on 19/06/23.
//

#ifndef METROSIMULATION_STATIONSPOOR_H
#define METROSIMULATION_STATIONSPOOR_H
#include <fstream>

class StationSpoor {
public:
    StationSpoor(std::ostream& op, std::ostream& err);

private:
    std::ostream& operationStream;
    std::ostream& errorLog;
    StationSpoor* _fInitcheck;
};


#endif //METROSIMULATION_STATIONSPOOR_H
