//
// Created by byamba on 20/04/23.
//

#include "StadslijnerTram.h"
#include "../DesignByContract.h"
#include <sstream>
#include "../Exporter/Exporter.h"

#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

void StadslijnerTram::calculateSnelheid() {
    setSnelheid(70);
}

bool StadslijnerTram::stationCanBeServiced(Station *s) {
    REQUIRE(s->properlyInitialized(), "The station must be properly initialized");
    if (s->getTypeEnum() == TypeStation::MetroStation)
        return true;
    return false;
}

int StadslijnerTram::getSnelheid() {
    REQUIRE(properlyInitialized(), "The tram must be properly initialized");
    calculateSnelheid();
    return snelheid;
}

int StadslijnerTram::getAantalDefecten() const {
    return 0;
}

void StadslijnerTram::setAantalDefecten(int aantal) {
    aantalDefecten = 0;
    ENSURE(getAantalDefecten() == 0, "Set not correct");
}

int StadslijnerTram::getReparatieTijd() const {
    return 0;
}

void StadslijnerTram::setReparatieTijd(int aantal) {
    reparatieTijd = aantal;
    ENSURE(getReparatieTijd() == 0, "The set not correct");
}

int StadslijnerTram::getReparatieKost() const {
    return 0;
}

void StadslijnerTram::setReparatieKost(int aantal) {
    reparatieKost = aantal;
    ENSURE(getReparatieKost() == 0, "The set not correct");
}

bool StadslijnerTram::move(Station *targetStation, Exporter &e) {
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
