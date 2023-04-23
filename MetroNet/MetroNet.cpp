#include <iostream>
#include "MetroNet.h"
#include "../Utils/utils.h"
#include "../DesignByContract.h"
#include "../Spoor/Spoor.h"
#include <set>
#include <ctime>

bool MetroNet::stationRegistered(const std::string &name) const {
    REQUIRE(!(Utils::is_int(name)), "The parameter name is a number");
    for (long unsigned int i = 0; i < fStations.size(); i++) {
        if (fStations[i]->getName() == name)
            return true;
    }
    return false;
}

//bool MetroNet::tramRegistered(std::string &name) const { //
//    for(int i = 0; i < fTrams.size(); i++){
//        if(fTrams[i].lijnNr == name)
//            return true;
//    }
//    return false;
//}

void MetroNet::addStation(Station *const station) {
    REQUIRE(station->properlyInitialized(), "The parameter station is not properly initialized");
    REQUIRE(!stationRegistered(station->getName()), "The station is already in the metroNet");
    fStations.push_back(station);
    ENSURE(stationRegistered(station->getName()), "The station was not successfully added");
}

void MetroNet::addTram(Tram *const tram) {
    REQUIRE(tram->properlyInitialized(), "The parameter tram is not properly initialized");
//    Require not registered
    fTrams.push_back(tram);
    //Ensure registered
}

Station *MetroNet::getStation(const std::string &name) {
    REQUIRE(!(Utils::is_int(name)), "The parameter name is a number");
    REQUIRE(stationRegistered(name), "The station is not Registered!");
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

//
//bool MetroNet::moveTram(Tram *const tram, const std::string &nameStation) {
//
//    REQUIRE(tram->properlyInitialized(), "The parameter tram is not properly initialized");
//    REQUIRE(!(Utils::is_int(nameStation)), "The parameter nameStation is a number");
//    Station *current = getStation(tram->getHuidigStation());
//
//    if (nameStation != current->getVorige() && nameStation != current->getVolgende()) {
//        std::cerr << "De tram kan niet verplaatst worden naar " << nameStation << "\n";
//        return false;
//    }
//
//    if (nameStation == current->getVorige()) {
//        std::cout << "De tram " << tram->getLijnNr() << " reed van station " << tram->getHuidigStation()
//                  << " naar station " << current->getVorige() << "\n";
//        tram->setHuidigStation(current->getVorige());
//        return true;
//    } else {
//        std::cout << "De tram " << tram->getLijnNr() << " reed van station " << tram->getHuidigStation()
//                  << " naar station " << current->getVolgende() << "\n";
//        tram->setHuidigStation(current->getVolgende());
//        return true;
//    }
//}

MetroNet::~MetroNet() {
    for (unsigned long int i = 0; i < fStations.size(); i++) {
        delete fStations[i];
    }
    for (unsigned long int i = 0; i < fTrams.size(); i++) {
        delete fTrams[i];
    }
}

MetroNet::MetroNet() {
    _fInitCheck = this;
    setInitializeStatCalled(false);
}

bool MetroNet::properlyInitialized() const {
    return _fInitCheck == this;
}

bool MetroNet::isValidMetroNet() {

    REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");

    std::vector<Station *> tempStations = this->getStations();
    std::vector<Tram *> tempTrams = this->getTrams();

    for (long unsigned int i = 0; i < tempStations.size(); i++) {
        REQUIRE(tempStations[i]->properlyInitialized(), "A station of the metroNet is not properly initialized");

        if (!controlStation(tempStations[i])) {
            return false;
        };

    }

    for (long unsigned int i = 0; i < tempTrams.size(); i++) {
        REQUIRE(tempTrams[i]->properlyInitialized(), "A tram of the metroNet is not properly initialized");

        if (!controlTram(tempTrams[i])) {
            return false;
        }

    }

    return true;
}

//bool MetroNet::isValidMetroNetSilent() {
//
//    REQUIRE(this->properlyInitialized(), "The metroNet is not properly initialized");
//
//    std::vector<Station *> tempStations = this->getStations();
//    std::vector<Tram *> tempTrams = this->getTrams();
//
//    for (long unsigned int i = 0; i < tempStations.size(); i++) {
//        REQUIRE(tempStations[i]->properlyInitialized(), "A station of the metroNet is not properly initialized");
//        if (!this->stationRegistered(tempStations[i]->getVorige())) {
//            return false;
//        }
//
//        if (!this->stationRegistered(tempStations[i]->getVolgende())) {
//            return false;
//        }
//
//        Station *vorige = this->getStation(tempStations[i]->getVorige());
//        Station *volgende = this->getStation(tempStations[i]->getVolgende());
//
//        if (vorige->getVolgende() != tempStations[i]->getName())
//            return false;
//        if (volgende->getVorige() != tempStations[i]->getName())
//            return false;
//
//        if (tempStations[i]->getSporen() != vorige->getSporen()) {
//            return false;
//        }
//
//        if (tempStations[i]->getSporen() != volgende->getSporen()) {
//            return false;
//        }
//
//        bool spoorHeeftTram = false;
//        for (long unsigned int j = 0; j < tempTrams.size(); j++) {
//            REQUIRE(tempTrams[j]->properlyInitialized(), "A tram of the metroNet is not properly initialized");
//            if (tempStations[i]->getSporen() == tempTrams[j]->getLijnNr()) {
//                spoorHeeftTram = true;
//                break;
//            }
//        }
//
//        if (!spoorHeeftTram) {
//            return false;
//        }
//
//    }
//
//    for (long unsigned int i = 0; i < tempTrams.size(); i++) {
//        REQUIRE(tempTrams[i]->properlyInitialized(), "A tram of the metroNet is not properly initialized");
//        if (!this->stationRegistered(tempTrams[i]->getBeginStation())) {
//            return false;
//        }
//        Station *beginStation = this->getStation(tempTrams[i]->getBeginStation());
//
//        if (beginStation->getSporen() != tempTrams[i]->getLijnNr()) {
//            return false;
//        }
//
//    }
//
//    return true;
//}

void MetroNet::simulateMetroNet(int seconds) {

    struct timespec start, finish;
    double elapsed;

    clock_gettime(CLOCK_MONOTONIC, &start);

    clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    while(elapsed <= seconds){

        moveAllTramsOnce();

        clock_gettime(CLOCK_MONOTONIC, &finish);

        elapsed = (finish.tv_sec - start.tv_sec);
        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    }
//
//    for(int i = 0; i < seconds; i++){
//
//        moveAllTramsOnce();
//
//    }
}

bool MetroNet::controlStation(Station *station){

    std::vector<Spoor *> tempSporen = station->getSporen();

    if (!station->hasUniqueSporen()) {
        std::cerr << "Sporen in de station " << station->getName() << " is niet uniek\n";
        return false;
    }

    for (unsigned int i = 0; i < tempSporen.size(); i++) {

        Spoor *current = tempSporen[i];

        if (!validSpoor(current)) {
//            std::cerr << "Spoor is niet correct\n";
            return false;
        }

        if (!spoorLineHasTram(current)) {
            std::cerr << "Spoor " << tempSporen[i]->getSpoorNr() << " heeft geen tram\n";
            return false;
        }
    }

    return true;

}

bool MetroNet::aTramAtStation(const std::string &stationName){

    std::vector<Tram *> trams = getTrams();

    for (unsigned int i = 0; i < trams.size(); i++) {

        if (trams[i]->getHuidigStation() == stationName)
            return true;
    }

    return false;
}

bool MetroNet::spoorLineHasTram(Spoor *s) {

    std::vector<Tram *> trams = this->getTrams();

    for (unsigned int i = 0; i < trams.size(); i++) {

        if (trams[i]->getLijnNr() == s->getSpoorNr())
            return true;

    }
    return false;
}

bool MetroNet::tramLineHasSpoor(Tram *t) {

    std::vector<Station*> stations = this->getStations();

    for(unsigned int i = 0; i < stations.size(); i++){

        if(stations[i]->hasSpoor(t->getLijnNr()))
            return true;

    }
    return false;
}

bool MetroNet::beginStationTramCorrect(Tram *t) {

    std::string beginStation = t->getBeginStation();

    if(!stationRegistered(beginStation)){
        return false;
    }

    Station* bS = this->getStation(beginStation);

    if(!bS->hasSpoor(t->getLijnNr())){
        return false;
    }

    return true;
}

bool MetroNet::uniqueTram(Tram *t) {

    std::vector<int> tramVoertuigNrs;

    std::vector<Tram* > trams = this->getTrams();

    for (unsigned int i = 0; i < trams.size(); i++) {

        tramVoertuigNrs.push_back(trams[i]->getVoertuigNummer());

    }

    std::set<int> tramVoertuigNrs2(tramVoertuigNrs.begin(), tramVoertuigNrs.end());

    return tramVoertuigNrs.size() == tramVoertuigNrs2.size();
}

bool MetroNet::validSpoor(Spoor *s) {

    Station* huidigStation = getStation(s->getHuiding());

    if(!stationRegistered(s->getVorige())){
        std::cerr << "De vorige station " << s->getVorige() << " van spoor " << s->getSpoorNr() << " op station " << s->getHuiding()
        << " is niet geregistreerd!\n";
        return false;
    }

    Station* vorigeStation = getStation(s->getVorige());

    if(!stationRegistered(s->getVolgende())){
        std::cerr << "De volgende station " << s->getVolgende() << " van spoor " << s->getSpoorNr() << " op station " << s->getHuiding()
                  << " is niet geregistreerd!\n";
        return false;
    }

    Station* volgendeStation = getStation(s->getVolgende());

    std::vector<Spoor* > sporenVanHuidige = huidigStation->getSporen();
    std::vector<Spoor* > sporenVanVorige = vorigeStation->getSporen();
    std::vector<Spoor* > sporenVanVolgende = volgendeStation->getSporen();

//    for(unsigned int i = 0; i < sporenVanHuidige.size(); i++){

    if(!vorigeStation->hasSpoor(s->getSpoorNr())){
        std::cerr << "De vorige station " << s->getVolgende() << " van spoor " << s->getSpoorNr() << " op station " << s->getHuiding()
                  << " heeft geen dezelfde spoorNr!\n";
        return false;
    }

    if(!volgendeStation->hasSpoor(s->getSpoorNr())){
        std::cerr << "De volgende station " << s->getVolgende() << " van spoor " << s->getSpoorNr() << " op station " << s->getHuiding()
                  << " heeft geen dezelfde spoorNr!\n";
        return false;
    }

    Spoor* spoorVorige = vorigeStation->getSpoor(s->getSpoorNr());

    if(spoorVorige->getVolgende() != s->getHuiding()){
        std::cerr << "De vorige station " << s->getVolgende() << " van spoor " << s->getSpoorNr() << " op station " << s->getHuiding()
                  << ", de volgende ervan is niet de huidige!\n";
        return false;
    }

    Spoor* spoorVolgende = volgendeStation->getSpoor(s->getSpoorNr());

    if(spoorVolgende->getVorige() != s->getHuiding()){
        std::cerr << "De volgende station " << s->getVolgende() << " van spoor " << s->getSpoorNr() << " op station " << s->getHuiding()
                  << ", de vorige ervan is niet de huidige!\n";
        return false;
    }

//    }

    return true;
}


bool MetroNet::controlTram(Tram *t) {

    if (!uniqueTram(t)) {
        return false;
    }

    if (!beginStationTramCorrect(t)) {
        return false;
    }

    if (!tramLineHasSpoor(t)) {
        return false;
    }
    return true;
}

bool MetroNet::moveTram(Tram* tram, std::string &targetStationName) {

    REQUIRE(!aTramAtStationSpoor(targetStationName, tram->getLijnNr()), "There cannot be a tram at targetStation SpoorNr to move Tram!");

    Station* currentStation = getStation(tram->getHuidigStation());
    Station* targetStation = getStation(targetStationName);
    //if possible
    if(currentStation->aSpoorConnectedToStation(targetStationName, tram->getLijnNr())){
        if(tram->move(targetStation)){
            //if moved targetStation visitedByTrams + 1 TODO
            targetStation->setVisitedByTrams(targetStation->getVisitedByTrams()+1);
            return true;
        }
        return false;
    }

    return false;
}

void MetroNet::moveAllTramsOnce() {
    //preconditie, is valid metronet -> i.e. all spore has tram etc.
    REQUIRE(isValidMetroNet(), "Cannot move trams in a invalid metronet");
    std::vector<Tram* > tempTrams = getTrams();

    for(unsigned int i = 0; i < tempTrams.size(); i++){

        Station* currentStation = getStation(tempTrams[i]->getHuidigStation());

        std::string targetStationName = currentStation->nextOfSpoor(tempTrams[i]->getLijnNr());

        REQUIRE(!targetStationName.empty(), "TargetStationName cannot be empty to move Tram");

        if(aTramAtStationSpoor(targetStationName, tempTrams[i]->getLijnNr())){
            std::cout << "There is a tram  " << getTramAtStationSpoor(targetStationName, tempTrams[i]->getLijnNr())->getVoertuigNummer()
            << " at station " << targetStationName << " so we must wait till we can move the current "
            << "tram " << tempTrams[i]->getVoertuigNummer() << "\n";
            continue;
        }

        moveTram(tempTrams[i], targetStationName);
//        ENSURE(tempTrams[i]->getHuidigStation() == targetStationName, "The tram has not moved successfully");
    }

}

Tram *MetroNet::getTramAtStationSpoor(const std::string &stationName, int lijnNr) {
    REQUIRE(aTramAtStationSpoor(stationName, lijnNr), "There must be a tram at station SpoorNr");

    std::vector<Tram* > tempTrams = getTrams();

    for(unsigned int i = 0; i < tempTrams.size(); i++){

        if(tempTrams[i]->getHuidigStation() != stationName)
            continue;

        if(tempTrams[i]->getLijnNr() != lijnNr)
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

        if(trams[i]->getLijnNr() == lijnNr)
            return true;
    }

    return false;
}

int MetroNet::getTotaalMetroNetReparatieKost() {

    std::vector<Tram* > tempTrams = getTrams();

    int ans = 0;

    for(unsigned int i = 0; i < tempTrams.size(); i++){

        ans += tempTrams[i]->getTotalReparatieKost();

    }
    return ans;
}

void MetroNet::initializeStat() {
    REQUIRE(isValidMetroNet(), "The metronet must be valid");
    if(getInitializeStatCalled())
        return;

    std::vector<Tram* > tempTrams;

    for(unsigned int i = 0; i < tempTrams.size(); i++){

        Station* visitedStation = getStation(tempTrams[i]->getHuidigStation());

        visitedStation->setVisitedByTrams(visitedStation->getVisitedByTrams()+1);

    }
    setInitializeStatCalled(true);
}

bool MetroNet::getInitializeStatCalled() const {
    return initializeStatCalled;
}

void MetroNet::setInitializeStatCalled(bool b) {
    initializeStatCalled = b;
}

void MetroNet::getStatReport() {

    int totReperatieKost = 0;

    std::vector<Tram* > tempTrams = getTrams();

    std::cout << "\n\n ====BEGIN STAT REPORT====\n";

    for(unsigned int i = 0; i < tempTrams.size(); i++){

        std::cout << "De reparatie kost van tram " << tempTrams[i]->getVoertuigNummer() << " is " << tempTrams[i]->getTotalReparatieKost()
        << "\n";
        totReperatieKost += tempTrams[i]->getTotalReparatieKost();

    }
    std::cout << "De totale reparatie kost van de metronet is gelijk aan " << totReperatieKost << "\n";

    std::vector<Station* > tempStations = getStations();

    for(unsigned int i = 0; i < tempStations.size(); i++){

        std::cout << "De station " << tempStations[i]->getName() << " werd bezocht door " << tempStations[i]->getVisitedByTrams()
        << " trams\n";

    }

    std::cout << "\n\n====END STAT REPORT====\n\n";
}

