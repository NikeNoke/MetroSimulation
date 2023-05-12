//
// Created by Thomas on 02/03/2023.
//

#include <iostream>
#include "Tram.h"
#include "../DesignByContract.h"
#include "../Utils/utils.h"
#include <sstream>

#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

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

bool Tram::move(Station *targetStation, Exporter& e) { //TODO refactor and virtualize
    REQUIRE(properlyInitialized(), "The tram must be properly initialized");
    REQUIRE(targetStation->aSpoorConnectedToStation(getHuidigStation(), getLijnNr()),
            "Station to move to has no Spoor connected to the current Station of the tram!");
    REQUIRE(targetStation->hasSpoor(getLijnNr()), "The target station does not have the same lijnNr as this tram");
    //targetStation at lijnNr has no Tram at the moment
    std::string temp = getHuidigStation();
    std::string target = targetStation->getName();
    if (stationCanBeServiced(targetStation)) {
        if (!tramCanMove()) {
            e.writeToOperation("De huidige tram " + SSTR(getVoertuigNummer()) + " kan niet bewegen, want het is defect voor nog "
                      + SSTR(getTotalReparatieKost() - getReparatieTijdWatcher()) + " 'stappen'\n");
            ENSURE(getHuidigStation() == temp, "The member huidigStation has changed");
            return false;
        }
        setHuidigStation(target);
        e.writeToOperation("The tram " + SSTR(getVoertuigNummer()) + " reed van station " + temp + " naar station " + target
                  + " op spoor " + SSTR(getLijnNr()) + "\n");
        ENSURE(getHuidigStation() == target, "The member huidigStation has not been changed properly");
        return true;
    } else {
        e.writeToOperation("The tram " + SSTR(getVoertuigNummer()) + " kan niet rijden van station " + temp + " naar station "
                  + target
                  + " op spoor " + SSTR(getLijnNr()) + "\n");
        ENSURE(getHuidigStation() == temp, "The member huidigStation has changed");
        return false;
    }
}

void Tram::setType(std::string t) {
    REQUIRE(!(Utils::is_int(t)), "The parameter type is a number");
    REQUIRE(t == "Albatros" || t == "PCC" || t == "Stadslijner", "Type given for tram is an invalid type");
    if (t == "PCC")
        type = TramType::PCC;
    else if(t == "Stadslijner")
        type = TramType::StadsLijner;
    else if (t == "Albatros")
        type = TramType::Albatros;
    else
        type = TramType::InvalidTram;
    ENSURE(getType() == type, "The member variable type has not been set properly");
}

TramType::TypeTram Tram::getType() const {
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
    ENSURE(getDefectWatcher() == d, "The setting was not successful");
}

int Tram::getReparatieTijdWatcher() const {
    return reparatieTijdWatcher;
}

void Tram::setReparatieTijdWatcher(int r) {
    Tram::reparatieTijdWatcher = r;
    ENSURE(getReparatieTijdWatcher() == r, "The setting was not succesful");
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
