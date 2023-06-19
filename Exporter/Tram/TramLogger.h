//
// Created by byamba on 19/06/23.
//

#ifndef METROSIMULATION_TRAMLOGGER_H
#define METROSIMULATION_TRAMLOGGER_H
#include <fstream>

class TramLogger {
public:
    TramLogger(std::ostream& op, std::ostream& err);

private:
    std::ostream& operationStream;
    std::ostream& errorLog;
    TramLogger* _fInitcheck;
};


#endif //METROSIMULATION_TRAMLOGGER_H
