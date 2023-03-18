#ifndef METRONET_XXX
#define METRONET_XXX

#include <vector>
#include "../Station/Station.h"
#include "../Tram/Tram.h"
#include <string>



class MetroNet{
public:

    MetroNet();

    ~MetroNet();

    bool stationRegistered(const std::string& name) const;
    //bool tramRegistered(std::string& name) const;

    void addStation(Station* const station);
    void addTram(Tram* const tram);

    Station* getStation(const std::string& name);
    Tram* getTram(const std::string& name);

    std::vector<Station*> getStations();
    std::vector<Tram*> getTrams();

    bool moveTram(Tram* const tram, const std::string& nameStation);

    bool properlyInitialized();

private:
    std::vector<Station*> stations;
    std::vector<Tram*> trams;
    MetroNet* _initCheck;
};



#endif //METRONET_XXX