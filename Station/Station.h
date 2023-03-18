//
// Created by Thomas on 02/03/2023.
//

#ifndef METROSIMULATION_STATION_H
#define METROSIMULATION_STATION_H

#include <string>

class Station {
public:

    Station();

    Station(const std::string &naam,const std::string& volgende,const std::string& vorige, int spoorNr);

    std::string getName() const;

    std::string getVolgende() const;

    std::string getVorige() const;

    int getSpoorNr() const;

    void setName(std::string n);

    void setVolgende(std::string v);

    void setVorige(std::string v);

    void setSpoorNr(int s);

private:

    std::string naam;
    std::string volgende;
    std::string vorige;
    int spoorNr;
};


#endif //METROSIMULATION_STATION_H
