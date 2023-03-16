#ifndef METRONET_XXX
#define METRONET_XXX

#include <vector>
#include "../Station/Station.h"
#include "../Tram/Tram.h"
#include <string>



class MetroNet{
public:

    bool stationRegistered(std::string& name) const;
    //bool tramRegistered(std::string& name) const;

    void addStation(Station& station);
    void addTram(Tram& tram);

    Station* getStation(std::string& name);
    Tram* getTram(std::string& name);

    std::vector<Station>* getStations(); //returns a reference thus no const promise
    std::vector<Tram>* getTrams();

    bool moveTram(Tram& tram, std::string& nameStation);


//private:
    std::vector<Station> stations;
    std::vector<Tram> trams;
};



#endif //METRONET_XXX