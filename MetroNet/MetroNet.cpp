#include <iostream>
#include "MetroNet.h"
#include "../Utils/utils.h"
#include "../DesignByContract.h"
#include "../Spoor/Spoor.h"
#include <set>
#include <ctime>
#include <sstream>
#include <map>

#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

bool MetroNet::stationRegistered(const std::string &name) const {
    REQUIRE(!(Utils::is_int(name)), "The parameter name is a number");
    for (long unsigned int i = 0; i < fStations.size(); i++) {
        if (fStations[i]->getName() == name)
            return true;
    }
    return false;
}

void MetroNet::addStation(Station *const station) {
    REQUIRE(station->properlyInitialized(), "The parameter station is not properly initialized");
//    REQUIRE(!stationRegistered(station->getName()), "The station is already in the metroNet");
    REQUIRE(station->getName() != "", "The station needs have a name.");
    REQUIRE(!station->getSporen().empty(), "Station must have sporen.");
    fStations.push_back(station);
    ENSURE(stationRegistered(station->getName()), "The station was not successfully added");
}

void MetroNet::addTram(Tram *const tram) {
    REQUIRE(tram->properlyInitialized(), "The parameter tram is not properly initialized");
//    Require not registered
    fTrams.push_back(tram);
    //Ensure registered
    ENSURE(getTram(tram->getVoertuigNummer()) == tram, "The tram has not been added");
}

Station *MetroNet::getStation(const std::string &name) {
    REQUIRE(!(Utils::is_int(name)), "The parameter name is a number");
//    REQUIRE(stationRegistered(name), "The station is not Registered!");
    for (long unsigned int i = 0; i < fStations.size(); i++) {
        if (fStations[i]->getName() == name)
            return fStations[i];
    }
    return NULL;
}

//Tram *MetroNet::getTram(std::string &name) {
//    for(int i = 0; i < fTrams.size(); i++){
//        if(fTrams[i].naam == name)
//            return &fTrams[i];
//    }
//    return NULL;
//}

std::vector<Station *> MetroNet::getStations() {
    return fStations;
}

std::vector<Tram *> MetroNet::getTrams() {
    return fTrams;
}

MetroNet::~MetroNet() {
    for (unsigned long int i = 0; i < fStations.size(); i++) {
        delete fStations[i];
    }
    for (unsigned long int i = 0; i < fTrams.size(); i++) {
        delete fTrams[i];
    }
}

MetroNet::MetroNet(Exporter& e)
    : exporter(e)
{
    _fInitCheck = this;
    setInitializeStatCalled(false);
    ENSURE(properlyInitialized(), "The metroNet is not properly initialized");
}

bool MetroNet::properlyInitialized() const {
    return _fInitCheck == this;
}

bool MetroNet::isValidMetroNet() {

    REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");

    std::vector<Station *> tempStations = this->getStations();
    std::vector<Tram *> tempTrams = this->getTrams();

    bool result = true;

    if(!uniqueStation()){
        result = false;
        getExporter().writeToError("The stations in this metronet are not unique\n");
    }

    for (long unsigned int i = 0; i < tempStations.size(); i++) {
        REQUIRE(tempStations[i]->properlyInitialized(), "A station of the metroNet is not properly initialized");
        if (!controlStation(tempStations[i])) {
            result = false;
            getExporter().writeToError("The station: " + tempStations[i]->getName() + " is not valid\n");
        }

    }

    if(!uniqueTram()){
        result = false;
        getExporter().writeToError("The trams in this metronet are not unique\n");
    }

    for (long unsigned int i = 0; i < tempTrams.size(); i++) {
        REQUIRE(tempTrams[i]->properlyInitialized(), "A tram of the metroNet is not properly initialized");

        if (!controlTram(tempTrams[i])) {
            result = false;
            getExporter().writeToError("The tram: " + SSTR(tempTrams[i]->getVoertuigNummer()) + " is not valid\n");
        }
    }
    if(!result)
        getExporter().writeToError("THIS METRONET IS INVALID\n");
    return result;
}

void MetroNet::simulateMetroNet(int seconds) {

    REQUIRE(properlyInitialized(), "Metronet must be properly initialized");
    REQUIRE(isValidMetroNet(), "The metronet must be valid");

    struct timespec finish;
    struct timespec start;
    double elapsed;

    clock_gettime(CLOCK_MONOTONIC, &start);

    clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    while (elapsed <= seconds) {

        moveAllTramsOnce();

        clock_gettime(CLOCK_MONOTONIC, &finish);

        elapsed = (finish.tv_sec - start.tv_sec);
        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    }
    ENSURE(isValidMetroNet(), "The metronet must still be valid");
}

bool MetroNet::controlStation(Station *station) {

    REQUIRE(station->properlyInitialized(), "The station must be properly initialized");
    std::vector<Spoor *> tempSporen = station->getSporen();
    bool result = true;
    if (!station->hasUniqueSporen()) {
        getExporter().writeToError("\tSporen in de station " + station->getName() + " is niet uniek\n");
        result = false;
    }

    for (unsigned int i = 0; i < tempSporen.size(); i++) {

        Spoor *current = tempSporen[i];

        if (!validSpoor(current)) {
            getExporter().writeToError("\tSpoor is niet correct\n");
            result = false;
        }

        if (!spoorLineHasTram(current)) {
            getExporter().writeToError("\tSpoor " + SSTR(tempSporen[i]->getSpoorNr()) + " heeft geen tram\n");
            result = false;
        }
    }
    return result;

}

bool MetroNet::aTramAtStation(const std::string stationName) {

    std::vector<Tram *> trams = getTrams();

    for (unsigned int i = 0; i < trams.size(); i++) {

        if (trams[i]->getHuidigStation() == stationName)
            return true;
    }

    return false;
}

bool MetroNet::spoorLineHasTram(Spoor *s) {

    REQUIRE(s->properlyInitialized(), "The spoor must be properly initialized");

    std::vector<Tram *> trams = this->getTrams();

    for (unsigned int i = 0; i < trams.size(); i++) {

        if (trams[i]->getLijnNr() == s->getSpoorNr())
            return true;

    }
    return false;
}

bool MetroNet::tramLineHasSpoor(Tram *t) {

    REQUIRE(t->properlyInitialized(), "The tram must be properly initialized");

    std::vector<Station *> stations = this->getStations();

    for (unsigned int i = 0; i < stations.size(); i++) {

        if (stations[i]->hasSpoor(t->getLijnNr()))
            return true;

    }
    return false;
}

bool MetroNet::beginStationTramCorrect(Tram *t) {

    REQUIRE(t->properlyInitialized(), "The tram must be properly initialized");

    std::string beginStation = t->getBeginStation();

    if (!stationRegistered(beginStation)) {
        getExporter().writeToError("\tThe begin station of tram: " + SSTR(t->getVoertuigNummer()) + " is not registered\n");
        return false;
    }

    Station *bS = this->getStation(beginStation);

    if (!bS->hasSpoor(t->getLijnNr())) {
        getExporter().writeToError("\tThe begin station of tram: " + SSTR(t->getVoertuigNummer()) + " does not have a spoor of the same lijnNr\n");
        return false;
    }

    return true;
}

bool MetroNet::uniqueTram() {

    std::vector<int> tramVoertuigNrs;

    std::vector<Tram *> trams = this->getTrams();

    for (unsigned int i = 0; i < trams.size(); i++) {

        tramVoertuigNrs.push_back(trams[i]->getVoertuigNummer());

    }

    std::set<int> tramVoertuigNrs2(tramVoertuigNrs.begin(), tramVoertuigNrs.end());

    return tramVoertuigNrs.size() == tramVoertuigNrs2.size();
}

bool MetroNet::validSpoor(Spoor *s) {

    REQUIRE(s->properlyInitialized(), "The spoor must be properly initialized");

    Station *huidigStation = getStation(s->getHuiding());
    bool result = true;
    if (!stationRegistered(s->getVorige())) {
        getExporter().writeToError(
                "\t\tDe vorige station " + s->getVorige() + " van spoor " + SSTR(s->getSpoorNr()) + " op station "
                + s->getHuiding()
                + " is niet geregistreerd!\n");
        result = false;
    }

    Station *vorigeStation = getStation(s->getVorige());

    if (!stationRegistered(s->getVolgende())) {
        getExporter().writeToError(
                "\t\tDe volgende station " + s->getVolgende() + " van spoor " + SSTR(s->getSpoorNr()) + " op station "
                + s->getHuiding()
                + " is niet geregistreerd!\n");
        result = false;
    }

    if(!result)
        return result;

    Station *volgendeStation = getStation(s->getVolgende());

    std::vector<Spoor *> sporenVanHuidige = huidigStation->getSporen();
    std::vector<Spoor *> sporenVanVorige = vorigeStation->getSporen();
    std::vector<Spoor *> sporenVanVolgende = volgendeStation->getSporen();

//    for(unsigned int i = 0; i < sporenVanHuidige.size(); i++){

    if (!vorigeStation->hasSpoor(s->getSpoorNr())) {
        getExporter().writeToError(
                "\t\tDe vorige station " + s->getVorige() + " van spoor " + SSTR(s->getSpoorNr()) + " op station "
                + s->getHuiding()
                + " heeft geen dezelfde spoorNr!\n");
        result = false;
    }

    if (!volgendeStation->hasSpoor(s->getSpoorNr())) {
        getExporter().writeToError(
                "\t\tDe volgende station " + s->getVolgende() + " van spoor " + SSTR(s->getSpoorNr()) + " op station "
                + s->getHuiding()
                + " heeft geen dezelfde spoorNr!\n");
        result = false;
    }

    if(!result)
        return result;

    Spoor *spoorVorige = vorigeStation->getSpoor(s->getSpoorNr());

    if (spoorVorige->getVolgende() != s->getHuiding()) {
        getExporter().writeToError(
                "\t\tDe vorige station " + s->getVorige() + " van spoor " + SSTR(s->getSpoorNr()) + " op station "
                + s->getHuiding()
                + ", de volgende ervan is niet de huidige!\n");
        result = false;
    }

    Spoor *spoorVolgende = volgendeStation->getSpoor(s->getSpoorNr());

    if (spoorVolgende->getVorige() != s->getHuiding()) {
        getExporter().writeToError(
                "\t\tDe volgende station " + s->getVolgende() + " van spoor " + SSTR(s->getSpoorNr()) + " op station "
                + s->getHuiding()
                + ", de vorige ervan is niet de huidige!\n");
        result = false;
    }

    return result;
}


bool MetroNet::controlTram(Tram *t) {

    REQUIRE(t->properlyInitialized(), "The tram must be properly initialized");

    if (!beginStationTramCorrect(t)) {
        getExporter().writeToError("\tThis tram: " + SSTR(t->getVoertuigNummer()) + " is not correct\n");
        return false;
    }

    if (!tramLineHasSpoor(t)) {
        getExporter().writeToError("\tThere is not a single station with the station number of " + SSTR(t->getLijnNr()) + ", so this tram: "
        + SSTR(t->getVoertuigNummer()) + " is not valid\n");
        return false;
    }
    return true;
}

bool MetroNet::moveTram(Tram *tram, std::string targetStationName) {

    REQUIRE(!aTramAtStationSpoor(targetStationName, tram->getLijnNr()), \
    "There cannot be a tram at targetStation SpoorNr to move Tram!");

    Station *currentStation = getStation(tram->getHuidigStation());
    Station *targetStation = getStation(targetStationName);
    //if possible
    if (currentStation->aSpoorConnectedToStation(targetStationName, tram->getLijnNr())) {
        if (tram->move(targetStation, getExporter())) {
            //if moved targetStation visitedByTrams + 1 TODO
            targetStation->setVisitedByTrams(targetStation->getVisitedByTrams() + 1);
            return true;
        }
        return false;
    }

    return false;
}

void MetroNet::moveAllTramsOnce() {
    REQUIRE(isValidMetroNet(), "Cannot move trams in a invalid metronet");
    std::vector<Tram *> tempTrams = getTrams();

    for (unsigned int i = 0; i < tempTrams.size(); i++) {

        Station *currentStation = getStation(tempTrams[i]->getHuidigStation());

        std::string targetStationName = currentStation->nextOfSpoor(tempTrams[i]->getLijnNr());

        REQUIRE(!targetStationName.empty(), "TargetStationName cannot be empty to move Tram");

        if (aTramAtStationSpoor(targetStationName, tempTrams[i]->getLijnNr())) {
            getExporter().writeToOperation("There is a tram  "
                                                   + SSTR(getTramAtStationSpoor(targetStationName,
                                                                                tempTrams[i]->getLijnNr())->getVoertuigNummer())
                                                   + " at station " + targetStationName +
                                                   " so we must wait till we can move the current "
                                                   + "tram " + SSTR(tempTrams[i]->getVoertuigNummer()) + "\n");
            continue;
        }

        moveTram(tempTrams[i], targetStationName);
//        ENSURE(tempTrams[i]->getHuidigStation() == targetStationName, "The tram has not moved successfully");
    }
    ENSURE(isValidMetroNet(), "The metronet must still be valid");
}

Tram *MetroNet::getTramAtStationSpoor(const std::string &stationName, int lijnNr) {
    REQUIRE(aTramAtStationSpoor(stationName, lijnNr), "There must be a tram at station SpoorNr");

    std::vector<Tram *> tempTrams = getTrams();

    for (unsigned int i = 0; i < tempTrams.size(); i++) {

        if (tempTrams[i]->getHuidigStation() != stationName)
            continue;

        if (tempTrams[i]->getLijnNr() != lijnNr)
            continue;

        return tempTrams[i];
    }
    return NULL;
}

bool MetroNet::aTramAtStationSpoor(const std::string &stationName, int lijnNr) {

    REQUIRE(stationRegistered(stationName), "stationName must be valid");
    REQUIRE(getStation(stationName)->hasSpoor(lijnNr), "Station must have lijnNr");

    std::vector<Tram *> trams = getTrams();

    for (unsigned int i = 0; i < trams.size(); i++) {

        if (trams[i]->getHuidigStation() != stationName)
            continue;

        if (trams[i]->getLijnNr() == lijnNr)
            return true;
    }

    return false;
}

int MetroNet::getTotaalMetroNetReparatieKost() {

    std::vector<Tram *> tempTrams = getTrams();

    int ans = 0;

    for (unsigned int i = 0; i < tempTrams.size(); i++) {

        ans += tempTrams[i]->getTotalReparatieKost();

    }
    return ans;
}

void MetroNet::initializeStat() {
    REQUIRE(isValidMetroNet(), "The metronet must be valid");
    REQUIRE(getInitializeStatCalled() == false, "This function must only be called once");
    if (getInitializeStatCalled())
        return;

    std::vector<Tram *> tempTrams;

    for (unsigned int i = 0; i < tempTrams.size(); i++) {

        Station *visitedStation = getStation(tempTrams[i]->getHuidigStation());

        visitedStation->setVisitedByTrams(visitedStation->getVisitedByTrams() + 1);

    }
    setInitializeStatCalled(true);
    ENSURE(isValidMetroNet(), "The metronet must still be valid");
}

bool MetroNet::getInitializeStatCalled() const {
    return initializeStatCalled;
}

void MetroNet::setInitializeStatCalled(bool b) {
    initializeStatCalled = b;
    ENSURE(getInitializeStatCalled() == b, "The setting was not successful");
}

void MetroNet::getStatReport() {

    int totReperatieKost = 0;

    std::vector<Tram *> tempTrams = getTrams();

    getExporter().writeToOperation("\n\n ====BEGIN STAT REPORT====\n");

    for (unsigned int i = 0; i < tempTrams.size(); i++) {

        getExporter().writeToOperation(
                "De reparatie kost van tram " + SSTR(tempTrams[i]->getVoertuigNummer()) + " is "
                + SSTR(tempTrams[i]->getTotalReparatieKost())
                + "\n");
        totReperatieKost += tempTrams[i]->getTotalReparatieKost();

    }
    getExporter().writeToOperation(
            "De totale reparatie kost van de metronet is gelijk aan " + SSTR(totReperatieKost) + "\n");

    std::vector<Station *> tempStations = getStations();

    for (unsigned int i = 0; i < tempStations.size(); i++) {

        getExporter().writeToOperation("De station " + SSTR(tempStations[i]->getName()) + " werd bezocht door "
                                               + SSTR(tempStations[i]->getVisitedByTrams())
                                               + " trams\n");

    }

    getExporter().writeToOperation("\n\n====END STAT REPORT====\n\n");
}

Tram *MetroNet::getTram(int voertuigNr) {

    REQUIRE(tramExists(voertuigNr), "The tram with this nummer must exist");

    std::vector<Tram* > tempTrams = getTrams();

    for(unsigned int i = 0; i < tempTrams.size(); i++){

        if(tempTrams[i]->getVoertuigNummer() == voertuigNr)
            return tempTrams[i];
    }
    return NULL;
}

bool MetroNet::tramExists(int voertuigNr) {

    std::vector<Tram* > tempTrams = getTrams();

    for(unsigned int i = 0; i < tempTrams.size(); i++){

        if(tempTrams[i]->getVoertuigNummer() == voertuigNr)
            return true;
    }
    return false;
}

Exporter &MetroNet::getExporter() {
    return exporter;
}

bool MetroNet::uniqueStation() {

    std::vector<std::string> stationNames;

    std::vector<Station *> stations = this->getStations();

    for (unsigned int i = 0; i < stations.size(); i++) {

        stationNames.push_back(stations[i]->getName());

    }

    std::set<std::string> stationNames2(stationNames.begin(), stationNames.end());

    bool result = stationNames.size() == stationNames2.size();

    std::map<std::string, int> counter;

    if(!result){

        for (unsigned int i = 0; i < stations.size(); i++) {

            if(counter.find(stations[i]->getName()) == counter.end()){
                counter[stations[i]->getName()] = 1;
            }else{
                counter[stations[i]->getName()] += 1;
            }
        }
    }

    std::map<std::string, int>::iterator it;

    for(it = counter.begin(); it != counter.end(); it++){
        if(it->second > 1){
            getExporter().writeToError("The station: " + it->first + " is not unique and is registered " + SSTR(it->second) + "times\n");
        }
    }

    return result;
}

