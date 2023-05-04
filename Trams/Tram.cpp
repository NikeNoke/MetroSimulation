//
// Created by Thomas on 02/03/2023.
//

#include <iostream>
#include "Tram.h"
#include "../DesignByContract.h"
#include "../Utils/utils.h"

Tram::Tram() {
    _initCheck = this;
    ENSURE(properlyInitialized(), "Tram has not been properly initialized");
}

Tram::Tram(const std::string &beginStation, int snelheid, int lijnNr) : snelheid(snelheid), beginStation(beginStation),
                                                                        lijnNr(lijnNr), huidigStation(beginStation) {
    REQUIRE(!(Utils::is_int(beginStation)), "The parameter beginStation is a number");
    _initCheck = this;
    ENSURE(properlyInitialized(), "Tram has not been properly initialized");
}

std::string Tram::getBeginStation() const {
    return beginStation;
}

int Tram::getSnelheid() {
    return -1;
}

int Tram::getLijnNr() const {
    return lijnNr;
}

std::string Tram::getHuidigStation() const {
    return huidigStation;
}

void Tram::setBeginStation(std::string bs) {
    REQUIRE(!(Utils::is_int(bs)), "The parameter beginStation is a number");
    beginStation = bs;
    ENSURE(getBeginStation() == bs, "The member beginStation type has not been set properly");
}

void Tram::setSnelheid(int s) {
    snelheid = s;
//    ENSURE(getSnelheid() == s, "The member snelheid type has not been set properly");
}

void Tram::setLijnNr(int l) {
    lijnNr = l;
    ENSURE(getLijnNr() == l, "The member lijnNr type has not been set properly");
}

void Tram::setHuidigStation(std::string h) {
    REQUIRE(!(Utils::is_int(h)), "The parameter huidigStation is a number");
    huidigStation = h;
    ENSURE(getHuidigStation() == h, "The member huidigStation type has not been set properly");
}

bool Tram::properlyInitialized() {
    return _initCheck == this;
}

bool Tram::move(Station *targetStation) {
    REQUIRE(targetStation->aSpoorConnectedToStation(getHuidigStation(), getLijnNr()),
            "Station to move to has no Spoor connected to the current Station of the tram!");
    REQUIRE(targetStation->hasSpoor(getLijnNr()), "The target station does not have the same lijnNr as this tram");
    //targetStation at lijnNr has no Tram at the moment
    std::string temp = getHuidigStation();
    std::string target = targetStation->getName();
    if (stationCanBeServiced(targetStation)) {
        if (!tramCanMove()) {
            std::cout << "De huidige tram " << getVoertuigNummer() << " kan niet bewegen, want het is defect voor nog "
                      << getTotalReparatieKost() - getReparatieTijdWatcher() << " 'stappen'\n";
            ENSURE(getHuidigStation() == temp, "The member huidigStation has changed");
            return false;
        }
        setHuidigStation(target);
        std::cout << "The tram " << getVoertuigNummer() << " reed van station " << temp << " naar station " << target
                  << " op spoor " << getLijnNr() << "\n";
        ENSURE(getHuidigStation() == target, "The member huidigStation has not been changed properly");
        return true;
    } else {
        std::cout << "The tram " << getVoertuigNummer() << " kan niet rijden van station " << temp << " naar station "
                  << target
                  << " op spoor " << getLijnNr() << "\n";
        ENSURE(getHuidigStation() == temp, "The member huidigStation has changed");
        return false;
    }
}

bool Tram::_moveTest(Station *targetStation) {
    REQUIRE(targetStation->aSpoorConnectedToStation(getHuidigStation(), getLijnNr()),
            "Station to move to has no Spoor connected to the current Station of the tram!");
    REQUIRE(targetStation->hasSpoor(getLijnNr()), "The target station does not have the same lijnNr as this tram");
    //targetStation at lijnNr has no Tram at the moment
    std::string temp = getHuidigStation();
    std::string target = targetStation->getName();
    if (stationCanBeServiced(targetStation)) {
        if (!tramCanMove()) {

            ENSURE(getHuidigStation() == temp, "The member huidigStation has changed");
            return false;
        }
        setHuidigStation(target);
        ENSURE(getHuidigStation() == target, "The member huidigStation has not been changed properly");
        return true;
    } else {
        ENSURE(getHuidigStation() == temp, "The member huidigStation has changed");
        return false;
    }
}

void Tram::setType(std::string t) {
    REQUIRE(!(Utils::is_int(t)), "The parameter type is a number");
    REQUIRE(t == "Albatros" || t == "PCC" || t == "Stadslijner", "Type given for tram is an invalid type");
    type = t;
    ENSURE(getType() == t, "The member variable type has not been set properly");
}

std::string Tram::getType() const {
    return type;
}

void Tram::setVoertuigNummer(int n) {
    voertuigNummer = n;
    ENSURE(getVoertuigNummer() == n, "The member variable voertuigNummer has not been set properly");
}

int Tram::getVoertuigNummer() const {
    return voertuigNummer;
}

int Tram::getDefectWatcher() const {
    return defectWatcher;
}

void Tram::setDefectWatcher(int d) {
    Tram::defectWatcher = d;
}

int Tram::getReparatieTijdWatcher() const {
    return reparatieTijdWatcher;
}

void Tram::setReparatieTijdWatcher(int r) {
    Tram::reparatieTijdWatcher = r;
}

bool Tram::tramDefect() const {
    if (getAantalDefecten() == 0)
        return false;
    return getDefectWatcher() == getAantalDefecten();
}

int Tram::getTotalReparatieKost() const {
    if (getReparatieTijd() == 0)
        return 0;
    return getReparatieTijd() + getReparatieKost();
}

bool Tram::tramCanMove() {
    if (tramDefect()) {
        if (getReparatieTijdWatcher() == getTotalReparatieKost()) {
            setDefectWatcher(0);
            setReparatieTijdWatcher(0);
            ENSURE(!tramDefect(), "Tram must now be able to move");
            return true;
        }
        setReparatieTijdWatcher(getReparatieTijdWatcher() + 1);
        return false;
    }
    setDefectWatcher(getDefectWatcher() + 1);
    setReparatieTijdWatcher(0);
    return true;
}
