//
// Created by byamba on 22/05/23.
//

#include "BigTram.h"
#include "../DesignByContract.h"
#include <sstream>

#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

void BigTram::calculateSnelheid() {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    setSnelheid(70);
}

bool BigTram::stationCanBeServiced(Station *s) {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    REQUIRE(s->properlyInitialized(), "The station must be properly initialized");
    if (s->getTypeEnum() == TypeStation::MetroStation)
        return true;
    return false;
}

int BigTram::getSnelheid() {
    REQUIRE(properlyInitialized(), "The tram must be properly initialized");
    calculateSnelheid();
    return snelheid;
}

int BigTram::getAantalDefecten() const {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    return 0;
}

void BigTram::setAantalDefecten(int aantal) {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    reparatieTijd = aantal;
    ENSURE(getReparatieTijd() == 0, "The set not correct");
}

int BigTram::getReparatieTijd() const {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    return 0;
}

void BigTram::setReparatieTijd(int aantal) {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    reparatieKost = aantal;
    ENSURE(getReparatieKost() == 0, "The set not correct");
}

int BigTram::getReparatieKost() const {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    return 0;
}

void BigTram::setReparatieKost(int aantal) {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    reparatieKost = aantal;
    ENSURE(getReparatieKost() == 0, "The set not correct");
}

bool BigTram::move(Station *targetStation, Exporter &e) {
    REQUIRE(properlyInitialized(), "The tram must be properly initialized");
    REQUIRE(targetStation->aSpoorConnectedToStation(getHuidigStation(), getLijnNr()),
            "Station to move to has no Spoor connected to the current Station of the tram!");
    REQUIRE(targetStation->hasSpoor(getLijnNr()), "The target station does not have the same lijnNr as this tram");
    //targetStation at lijnNr has no Tram at the moment
    std::string temp = getHuidigStation();
    std::string target = targetStation->getName();
    if (stationCanBeServiced(targetStation)) {
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
