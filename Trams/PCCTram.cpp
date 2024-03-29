//
// Created by byamba on 20/04/23.
//

#include "PCCTram.h"
#include "../DesignByContract.h"
#include <sstream>
#include "../Exporter/Exporter.h"

#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

void PCCTram::calculateSnelheid() {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    setSnelheid(40);
}

bool PCCTram::stationCanBeServiced(Station *s) {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    REQUIRE(s->properlyInitialized(), "The station must be properly initialized");
    if (s->getTypeEnum() == TypeStation::MetroStation)
        return true;
    if (s->getTypeEnum() == TypeStation::Halte)
        return true;
    return false;
}

int PCCTram::getSnelheid() {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    calculateSnelheid();
    return snelheid;
}

int PCCTram::getAantalDefecten() const {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    return aantalDefecten;
}

void PCCTram::setAantalDefecten(int aantal) {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    aantalDefecten = aantal;
    ENSURE(getAantalDefecten() == aantal, "The set not correct");
}

int PCCTram::getReparatieTijd() const {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    return reparatieTijd;
}

void PCCTram::setReparatieTijd(int aantal) {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    reparatieTijd = aantal;
    ENSURE(getReparatieTijd() == aantal, "The set not corerct");
}

int PCCTram::getReparatieKost() const {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    return reparatieKost;
}

void PCCTram::setReparatieKost(int aantal) {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    reparatieKost = aantal;
    ENSURE(getReparatieKost() == aantal, "The set not correct");
}

bool PCCTram::move(Station *targetStation, Exporter &e) {
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

TramType::TypeTram PCCTram::getType() const {
    REQUIRE(properlyInitialized(), "The tram is not properly initialized");
    return TramType::PCC;
}
