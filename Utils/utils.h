

#ifndef METROSIMULATION_UTILS_H
#define METROSIMULATION_UTILS_H
#include <string>
#include "../TinyXML/tinyxml.h"
#include "../MetroNet/MetroNet.h"
#include "../Stations/Station.h"
#include "../Trams/Tram.h"
#include <fstream>
#include <vector>

/**
 * Functies and utilities dat gebruikt worden doorheen ons project om code duplication waar mogelijk is te vermijden.
 * Deze lijst is nog niet compleet en zou hoogstwaarschijnlijk uigebreid worden in de toekomst.
 * **/
namespace Utils{


    /**
     * Functie dat test ofdat een gegeven string een integer is. Deze functie wordt gebruikt om attribute types te
     * controleren.
     * @param s De string dat gecontroleerd wordt.
     * @return true of false afhankelijk ofdat de string een integer is of niet.
     * @note Source is StackOverFlow.
     * **/
    bool is_int(const std::string &s);

//    /**
//     * Functie dat zal nazien ofdat een metronet correct geïnitialiseerd is en wordt geprint op console.
//     * @param metroNet Het metronet dat gecontroleerd wordt.
//     * @return true of false afhankelijk ofdat het metronet correct geïnitialiseerd is of niet.
//     * **/
//    bool validMetroNet(MetroNet& metroNet);
//
//    /**
//    * Functie dat zal nazien ofdat een metronet correct geïnitialiseerd is en wordt NIET geprint op console.
//     * @param metroNet Het metronet dat gecontroleerd wordt.
//    * @return true of false afhankelijk ofdat het metronet correct geïnitialiseerd is of niet.
//     * **/
//    bool validMetroNetSilent(MetroNet& metroNet);

    /**
     * Simpele functie dat ons toelaat om i.p.v een bool terug te geven een custom message terug te geven.
     * @param b Een boolean.
     * @return Custom message, in dit geval "gevonden" als b true is en "niet gevonden" als b false is.
     * **/
    std::string boolToText(bool b);
//
//    /**
//     * Functie dat ons toelaat om een metronet te laten simuleren voor een bepaald aantal moves.
//     * @param metroNet Het metronet dat we gaan simuleren.
//     * @param amountOfMove De hoevelheid stappen dat we gaan simuleren.
//     * @note Deze functie moeten we aanpassen zodat het i.p.v. werkt met een hoeveelheid moves, dat het werkt met gebruik
//     * van een tijdstip. Hierbij moeten we echter zorgen dat we meerdere attributes hebben die toelaten om een
//     * realistische simulatie te doen lopen over een MetroNet. Hierbij moeten we Tram en Station zodanig aanpassen
//     * zodat trammen over een bepaalde afstand rijden in een bepaalde tijd met een bepaalde snelheid.
//     * **/
//    void simulateMetroNet(MetroNet& metroNet, int amountOfMove);

    /**
     * Simpele functie dat een vrij gerandomiseerde integer terug geeft.
     * @param max Limiter om een niet te hoge random getal te krijgen.
     * @return Een random integer.
     * **/
    int getRandomInt(int max);

    /**
     * Functie dat controleerd ofdat een directory bestaat of niet.
     * @param dirname Naam van de directory.
     * @return true of false
     */
    bool directoryExists(const std::string dirname);

    /**
     * Functie dat controleerd ofdat een file bestaat.
     * @param filename Naam van de file.
     * @return true of false
     */
    bool fileExists(const std::string filename);

    /**
     * Functie dat controleerd ofdat een file leeg is.
     * @param filename Naam van de file.
     * @return true of false
     */
    bool fileIsEmpty(const std::string filename);

}

#endif //METROSIMULATION_UTILS_H