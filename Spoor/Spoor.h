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

    /**
* Set de naam van het station.
 * @param v Naam van het volgende station.
* **/
    void setVolgende(std::string v);

    /**
    * Set de naam van het station vorige station.
     * @param v Naam van het vorige station.
    * **/
    void setVorige(std::string v);

    /**
    * Set het spoornummer van het station.
    * @param s Spoornummer waar het station deel van is.
     * **/
    void setSpoorNr(int s);

    /**
 * @return De naam van het volgende station.
 * **/
    std::string getVolgende() const;

    /**
     * @return De naam van het vorige station.
     * **/
    std::string getVorige() const;

    int getSpoorNr() const;

private:
    std::string volgende;
    std::string vorige;
    int spoorNr;
    Spoor* _fInitCheck;
};


#endif //METROSIMULATION_SPOOR_H
