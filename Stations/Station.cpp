//
// Created by Thomas on 02/03/2023.
//

#include <set>
#include "Station.h"
#include "../DesignByContract.h"
#include "../Utils/utils.h"
#include "../Spoor/Spoor.h"

Station::Station() {
    _fInitCheck = this;
}

//Station::Station(const std::string &naam,const std::string& volgende,const std::string& vorige, int spoorNr) : fNaam(naam),
//                                                                                                               fVolgende(volgende),
//                                                                                                               fVorige(vorige),
//                                                                                                               fSpoorNr(spoorNr) {
//    REQUIRE(!(Utils::is_int(naam)), "The parameter naam is a number");
//    REQUIRE(!(Utils::is_int(volgende)), "The parameter volgende is a number");
//    REQUIRE(!(Utils::is_int(vorige)), "The parameter vorige is a number");
//    _fInitCheck = this;
//}

std::string Station::getName() const {
    return fNaam;
}

//std::string Station::getVolgende() const {
//    return fVolgende;
//}
//
//std::string Station::getVorige() const {
//    return fVorige;
//}

std::vector<Spoor*> Station::getSporen() const {
    return sporen;
}

void Station::setName(std::string& n) {
    REQUIRE(!(Utils::is_int(n)), "The parameter naam is a number");
    fNaam = n;
    ENSURE(getName() == n, "The member variable naam has not been properly initialized");
}

bool Station::properlyInitialized() {
    return _fInitCheck == this;
}

void Station::setType(std::string& s) {
    REQUIRE(!(Utils::is_int(s)), "The parameter type is a number");
    fType = s;
    ENSURE(getType() == s, "The member variable type has not been properly initialized");
}

std::string Station::getType() const {
    return fType;
}

bool Station::addSpoor(Spoor *s) {
    if(getType() == "Metrostation")
        sporen.push_back(s);
    else if(getType() == "Halte"){
        if(sporen.size() >= 1)
            return false;
    }
    return true;
}

Spoor *Station::getSpoor(int nr) const {

    for(unsigned int i = 0; i < sporen.size(); i++){

        if(sporen[i]->getSpoorNr() == nr)
            return sporen[i];

    }
    return NULL;
}

bool Station::hasUniqueSporen() const {
    std::vector<int> spoorNrs;


    for (unsigned int i = 0; i < this->getSporen().size(); i++) {

        spoorNrs.push_back(this->getSporen()[i]->getSpoorNr());

    }

    std::set<int> spoorNrs2(spoorNrs.begin(), spoorNrs.end());

    return spoorNrs.size() == spoorNrs2.size();
}

bool Station::hasSpoor(int nr) const {

    for(unsigned int i = 0; i < sporen.size(); i++){

        if(sporen[i]->getSpoorNr() == nr)
            return true;

    }
    return false;
}
