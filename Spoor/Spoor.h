//
// Created by byamba on 20/04/23.
//

#ifndef METROSIMULATION_SPOOR_H
#define METROSIMULATION_SPOOR_H
#include <string>

class Spoor {
public:
    Spoor();

    /**
    * Controleert ofdat het spoor correct is geïnitialiseerd.
    * @return true of false naarmate ofdat het correct is geïnitialiseerd of niet.
    * **/
    bool properlyInitialized();


private:
    std::string volgende;
    std::string vorige;
    int spoorNr;
    Spoor* _fInitCheck;
};


#endif //METROSIMULATION_SPOOR_H
