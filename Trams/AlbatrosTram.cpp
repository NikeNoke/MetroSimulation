//
// Created by byamba on 20/04/23.
//

#include "AlbatrosTram.h"
#include <sstream>
#include "../Exporter/Exporter.h"
#include "../DesignByContract.h"

#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

void AlbatrosTram::test() const {
    this->getType();
}

void AlbatrosTram::calculateSnelheid() {
    setSnelheid(70);
}

bool AlbatrosTram::stationCanBeServiced(Station *s) {
    if (s->getTypeEnum() == TypeStation::MetroStation)
        return true;
    return false;
}

int AlbatrosTram::getSnelheid() {
    calculateSnelheid();
    return snelheid;
}

int AlbatrosTram::getAantalDefecten() const {
    return 0;
}

void AlbatrosTram::setAantalDefecten(int aantal) {
    aantalDefecten = 0;
}

int AlbatrosTram::getReparatieTijd() const {
    return 0;
}

void AlbatrosTram::setReparatieTijd(int aantal) {
    reparatieTijd = 0;
}

int AlbatrosTram::getReparatieKost() const {
    return 0;
}

void AlbatrosTram::setReparatieKost(int aantal) {
    reparatieKost = 0;
}

bool AlbatrosTram::move(Station *targetStation, Exporter &e) {
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
