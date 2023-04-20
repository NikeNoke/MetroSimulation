//
// Created by Thomas on 02/03/2023.
//

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

std::vector<Spoor*> Station::getSpoorNr() const {
    return sporen;
}

void Station::setName(std::string n) {
    REQUIRE(!(Utils::is_int(n)), "The parameter naam is a number");
    fNaam = n;
    ENSURE(getName() == n, "The member variable naam has not been properly initialized");
}

//void Station::setVolgende(std::string v) {
//    REQUIRE(!(Utils::is_int(v)), "The parameter volgende is a number");
//    fVolgende = v;
//    ENSURE(getVolgende() == v, "The member variable volgende has not been properly initialized");
//}

//void Station::setVorige(std::string v) {
//    REQUIRE(!(Utils::is_int(v)), "The parameter vorige is a number");
//    fVorige = v;
//    ENSURE(getVorige() == v, "The member variable vorige has not been properly initialized");
//}

//void Station::setSpoorNr(int s) {
//    fSpoorNr = s;
//}

bool Station::properlyInitialized() {
    return _fInitCheck == this;
}

void Station::setType(std::string s) {
    REQUIRE(!(Utils::is_int(s)), "The parameter type is a number");
    fType = s;
    ENSURE(getType() == s, "The member variable type has not been properly initialized");
}

std::string Station::getType() const {
    return fType;
}

Station::~Station() {
    for (unsigned long int i = 0; i < sporen.size(); i++) {
        delete sporen[i];
    }
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
