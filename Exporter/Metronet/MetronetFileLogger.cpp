//
// Created by byamba on 19/06/23.
//

#include "MetronetFileLogger.h"
#include "../../DesignByContract.h"
#include <sstream>
#include "../../Trams/Tram.h"

#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

MetronetFileLogger::MetronetFileLogger(std::ostream &op, std::ostream &err)
    : operationStream(op), errorLog(err), _fInitcheck(this)
{
    ENSURE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
}

void MetronetFileLogger::eNonUniqueStations() {
//    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "The stations in this metronet are not unique\n" << std::flush;
}

void MetronetFileLogger::eStationNotValid(const std::string &name) {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "The station: " + name + " is not valid\n" << std::flush;
}

void MetronetFileLogger::eNonUniqueTrams() {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "The trams in this metronet are not unique\n" << std::flush;
}

void MetronetFileLogger::eTramNotValid(const int voertuigNr) {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "The tram: " + SSTR(voertuigNr) + " is not valid\n" << std::flush;
}

void MetronetFileLogger::eMetronetInvalid() {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "THIS METRONET IS INVALID\n" << std::flush;
}

void MetronetFileLogger::eStationHasNonUniqueSporen(const std::string &nameStation) {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "\tSporen in de station " + nameStation + " is niet uniek\n" << std::flush;
}

void MetronetFileLogger::eSpoorNotValid() {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "\tSpoor is niet correct\n" << std::flush;
}

void MetronetFileLogger::eTramlessSpoor(const int spoorNr) {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "\tSpoor " + SSTR(spoorNr) + " heeft geen tram\n" << std::flush;
}

void MetronetFileLogger::eBeginOfTramNotRegistered(const int voertuigNr) {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "\tThe begin station of tram: " + SSTR(voertuigNr) + " is not registered\n" << std::flush;
}

void MetronetFileLogger::eBeginOfTramHasHasDifferentSpoor(const int voertuigNr) {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "\tThe begin station of tram: " + SSTR(voertuigNr) + " does not have a spoor of the same lijnNr\n" << std::flush;
}

void MetronetFileLogger::ePreviousOfSpoorNotRegistered(const std::string &vorige, const int spoorNr,
                                                       const std::string &huidig) {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "\t\tDe vorige station " + vorige + " van spoor " + SSTR(spoorNr) + " op station "
                        + huidig + " is niet geregistreerd!\n" << std::flush;
}

void MetronetFileLogger::eBeginOfSpoorNotRegistered(const std::string &volgende, const int spoorNr,
                                                    const std::string &huidig) {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "\t\tDe volgende station " + volgende + " van spoor " + SSTR(spoorNr) + " op station "
                        + huidig + " is niet geregistreerd!\n" << std::flush;
}

void MetronetFileLogger::ePreviousOfSpoorHasDifferentSpoorNr(const std::string &vorige, const int spoorNr,
                                                             const std::string &huidig) {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "\t\tDe vorige station " + vorige + " van spoor " + SSTR(spoorNr) + " op station "
                        + huidig + " heeft geen dezelfde spoorNr!\n" << std::flush;
}

void MetronetFileLogger::eBeginOfSpoorHasDifferentSpoorNr(const std::string &volgende, const int spoorNr,
                                                          const std::string &huidig) {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "\t\tDe volgende station " + volgende + " van spoor " + SSTR(spoorNr) + " op station "
                        + huidig + " heeft geen dezelfde spoorNr!\n" << std::flush;
}

void
MetronetFileLogger::ePreviousOfSpoorNotNext(const std::string &vorige, const int spoorNr, const std::string &huidig) {

    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "\t\tDe vorige station " + vorige + " van spoor " + SSTR(spoorNr) + " op station "
                        + huidig + ", de volgende ervan is niet de huidige!\n" << std::flush;
}

void MetronetFileLogger::eBeginOfSpoorNotPrevious(const std::string &volgende, const int spoorNr,
                                                  const std::string &huidig) {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "\t\tDe volgende station " + volgende + " van spoor " + SSTR(spoorNr) + " op station "
                        + huidig + ", de vorige ervan is niet de huidige!\n" << std::flush;
}

void MetronetFileLogger::eTramInvalid(const int voertuigNr) {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "\tThis tram: " + SSTR(voertuigNr) + " is not correct\n" << std::flush;
}

void MetronetFileLogger::eTramWithoutStation(const int lijnNr, const int voertuigNr) {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "\tThere is not a single station with the station number of " + SSTR(lijnNr) + ", so this tram: "
                        + SSTR(voertuigNr) + " is not valid\n" << std::flush;
}

void MetronetFileLogger::oMustWaitToMoveTram(const int occupyingTramVoertuigNr, const std::string &targetStationName,
                                             const int voertuigNr) {
    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "There is a tram  "
                        + SSTR(occupyingTramVoertuigNr) + " at station " + targetStationName +
                        " so we must wait till we can move the current "
                        + "tram " + SSTR(voertuigNr) + "\n" << std::flush;
}

void MetronetFileLogger::oStatReport(std::vector<Tram *> &tempTrams, std::vector<Station *> &tempStations) {

    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    int totReperatieKost = 0;


    getErrorStream() <<  "\n\n ====BEGIN STAT REPORT====\n" << std::flush;

    for (unsigned int i = 0; i < tempTrams.size(); i++) {

        getErrorStream() <<
                "De reparatie kost van tram " + SSTR(tempTrams[i]->getVoertuigNummer()) + " is "
                + SSTR(tempTrams[i]->getTotalReparatieKost())
                + "\n" << std::flush;
        totReperatieKost += tempTrams[i]->getTotalReparatieKost();

    }
    getErrorStream() <<
            "De totale reparatie kost van de metronet is gelijk aan " + SSTR(totReperatieKost) + "\n" << std::flush;


    for (unsigned int i = 0; i < tempStations.size(); i++) {

        getErrorStream() <<  "De station " + SSTR(tempStations[i]->getName()) + " werd bezocht door "
                                       + SSTR(tempStations[i]->getVisitedByTrams())
                                       + " trams\n" << std::flush;

    }

    getErrorStream() <<  "\n\n====END STAT REPORT====\n\n" << std::flush;
}

void MetronetFileLogger::eNonUniqueStation(const std::string &name, const int amountRegistered) {

    REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
    getErrorStream() << "The station: " + name + " is not unique and is registered " + SSTR(amountRegistered) + "times\n" << std::flush;
}

bool MetronetFileLogger::properlyInitialized() const {
    return _fInitcheck == this;
}

std::ostream &MetronetFileLogger::getOperationStream() {
//    REQUIRE(properlyInitialized(), "MetronetFileLogger is not properly initialized");
    return operationStream;
}

std::ostream &MetronetFileLogger::getErrorStream() {
    REQUIRE(properlyInitialized(), "MetronetFileLogger is not properly initialized");
    return errorLog;
}
