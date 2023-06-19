//
// Created by byamba on 19/06/23.
//

#ifndef METROSIMULATION_SPOORLOGGER_H
#define METROSIMULATION_SPOORLOGGER_H
#include <fstream>

class SpoorLogger {
public:
    SpoorLogger(std::ostream& op, std::ostream& err);

private:
    std::ostream& operationStream;
    std::ostream& errorLog;
    SpoorLogger* _fInitcheck;
};


#endif //METROSIMULATION_SPOORLOGGER_H
