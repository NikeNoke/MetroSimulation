//
// Created by byamba on 19/06/23.
//

#ifndef METROSIMULATION_METRONETLOGGER_H
#define METROSIMULATION_METRONETLOGGER_H
#include <vector>
#include <string>

class Tram;
class Station;

class MetronetLogger {
public:

    virtual void eNonUniqueStations() = 0;

    virtual void eStationNotValid(const std::string& name) = 0;

    virtual void eNonUniqueTrams() = 0;

    virtual void eTramNotValid(const int voertuigNr) = 0;

    virtual void eMetronetInvalid() = 0;

    virtual void eStationHasNonUniqueSporen(const std::string& nameStation) = 0;

    virtual void eSpoorNotValid() = 0;

    virtual void eTramlessSpoor(const int spoorNr) = 0;

    virtual void eBeginOfTramNotRegistered(const int voertuigNr) = 0;

    virtual void eBeginOfTramHasHasDifferentSpoor(const int voertuigNr) = 0;

    virtual void ePreviousOfSpoorNotRegistered(const std::string& vorige, const int spoorNr, const std::string& huidig) = 0;

    virtual void eBeginOfSpoorNotRegistered(const std::string& volgende, const int spoorNr, const std::string& huidig) = 0;

    virtual void ePreviousOfSpoorHasDifferentSpoorNr(const std::string& vorige, const int spoorNr, const std::string& huidig) = 0;

    virtual void eBeginOfSpoorHasDifferentSpoorNr(const std::string& volgende, const int spoorNr, const std::string& huidig) = 0;

    virtual void ePreviousOfSpoorNotNext(const std::string& vorige, const int spoorNr, const std::string& huidig) = 0;

    virtual void eBeginOfSpoorNotPrevious(const std::string& volgende, const int spoorNr, const std::string& huidig) = 0;

    virtual void eTramInvalid(const int voertuigNr) = 0;

    virtual void eTramWithoutStation(const int lijnNr, const int voertuigNr) = 0;

    virtual void oMustWaitToMoveTram(const int occupyingTramVoertuigNr, const std::string& targetStationName, const int voertuigNr) = 0;

    virtual void oStatReport(std::vector<Tram*>& tempTrams, std::vector<Station* >& tempStations) = 0;

    virtual void eNonUniqueStation(const std::string& name, const int amountRegistered) = 0;

};


#endif //METROSIMULATION_METRONETLOGGER_H
