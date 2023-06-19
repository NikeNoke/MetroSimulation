//
// Created by byamba on 19/06/23.
//

#ifndef METROSIMULATION_METRONETFILELOGGER_H
#define METROSIMULATION_METRONETFILELOGGER_H
#include "MetronetLogger.h"
#include <fstream>

class MetronetFileLogger{
public:

    /**
     * ENSURE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
     */
    MetronetFileLogger(std::ostream& op, std::ostream& err);

    /**
     * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
     */
    void eNonUniqueStations();

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eStationNotValid(const std::string& name);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eNonUniqueTrams();

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eTramNotValid(const int voertuigNr);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eMetronetInvalid();

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eStationHasNonUniqueSporen(const std::string& nameStation);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eSpoorNotValid();

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eTramlessSpoor(const int spoorNr);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eBeginOfTramNotRegistered(const int voertuigNr);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eBeginOfTramHasHasDifferentSpoor(const int voertuigNr);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void ePreviousOfSpoorNotRegistered(const std::string& vorige, const int spoorNr, const std::string& huidig);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eBeginOfSpoorNotRegistered(const std::string& volgende, const int spoorNr, const std::string& huidig);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void ePreviousOfSpoorHasDifferentSpoorNr(const std::string& vorige, const int spoorNr, const std::string& huidig);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eBeginOfSpoorHasDifferentSpoorNr(const std::string& volgende, const int spoorNr, const std::string& huidig);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void ePreviousOfSpoorNotNext(const std::string& vorige, const int spoorNr, const std::string& huidig);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eBeginOfSpoorNotPrevious(const std::string& volgende, const int spoorNr, const std::string& huidig);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eTramInvalid(const int voertuigNr);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eTramWithoutStation(const int lijnNr, const int voertuigNr);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void oMustWaitToMoveTram(const int occupyingTramVoertuigNr, const std::string& targetStationName, const int voertuigNr);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void oStatReport(std::vector<Tram*>& tempTrams, std::vector<Station* >& tempStations);

    /**
 * REQUIRE(properlyInitialized(), "MetroNetFileLogger is not properly initialized");
 */
    void eNonUniqueStation(const std::string& name, const int amountRegistered);

    bool properlyInitialized() const;

    /**
     * REQUIRE(properlyInitialized(), "MetronetFileLogger is not properly initialized");
     */
    std::ostream& getOperationStream();

    /**
     * REQUIRE(properlyInitialized(), "MetronetFileLogger is not properly initialized");
     */
    std::ostream& getErrorStream();

private:
    std::ostream& operationStream;
    std::ostream& errorLog;
    MetronetFileLogger* _fInitcheck;
};


#endif //METROSIMULATION_METRONETFILELOGGER_H
