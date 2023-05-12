//
// Created by Thomas on 04/05/2023.
//
#include <iostream>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../ParseXML/ParseMetroNet.h"
#include "../ParseXML/ParseSpoor.h"
#include "../MetroNetGenerator/MetroNetGenerator.h"
#include "../Stations/HalteStation.h"
#include "../Stations/MetronetStation.h"

//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

/**
 * Deze klasse test de logica van objecten in een MetroNet.
 * **/
class DomainTests : public ::testing::Test {
protected:
    /**
     * "Sets up the text fixture." Klasse overgeërft van gtest.h
     * **/
    virtual void SetUp() {

    }

    /**
     * "Tears down the test fixture." Klasse overgeërft van gtest.h
     * **/
    virtual void TearDown() {

    }

    std::ostream &getOperationStream(){
        return operation;
    }

    std::ostream &getErrorStream(){
        return error;
    }

    std::ofstream operation;
    std::ofstream error;


};


TEST_F(DomainTests, DefaultConstructors) {

    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    std::string fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(0) + ".xml";
    std::string output = "TestOutput/DomainTest/metroNet" +  SSTR(0) + "Simple.txt";
    std::string output2 = "TestOutput/DomainTest/metroNetTest" +  SSTR(0) + "Advanced.txt";
    std::string op = "TestOutput/DomainTest/operation" +  SSTR(0) + ".txt";
    std::string err = "TestOutput/DomainTest/error" +  SSTR(0) + ".txt";

    operation.open(op.c_str());
    error.open(err.c_str());

    MetroNetGenerator generator(fileName, output, output2, getOperationStream(), getErrorStream());

    EXPECT_TRUE(generator.getExporter().properlyInitialized());
    EXPECT_NO_FATAL_FAILURE(generator.generateMetroNet(true)) << "The metroNet was not Valid!\n";


    EXPECT_TRUE(generator.getMetroNet().properlyInitialized()) << "Default constructor for Metronet failed\n";
    std::vector<Station* > tempStations = generator.getMetroNet().getStations();
    for(long unsigned int i = 0; i < tempStations.size(); i++){
        EXPECT_TRUE(tempStations[i]->properlyInitialized());
        std::vector<Spoor* > tempSporen = tempStations[i]->getSporen();
        for(long unsigned int j = 0; j < tempSporen.size(); j++){
            EXPECT_TRUE(tempSporen[j]->properlyInitialized());
        }
    }
    std::vector<Tram* > tempTrams = generator.getMetroNet().getTrams();
    for(long unsigned int i = 0; i < tempTrams.size(); i++){
        EXPECT_TRUE(tempTrams[i]->properlyInitialized());
    }
    operation.close();
    error.close();
}

TEST_F(DomainTests, MoveTrams) {

    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    std::string fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(0) + ".xml";
    std::string output = "TestOutput/DomainTest/metroNet" +  SSTR(0) + "Simple.txt";
    std::string output2 = "TestOutput/DomainTest/metroNetTest" +  SSTR(0) + "Advanced.txt";
    std::string op = "TestOutput/DomainTest/operation" +  SSTR(0) + ".txt";
    std::string err = "TestOutput/DomainTest/error" +  SSTR(0) + ".txt";

    operation.open(op.c_str());
    error.open(err.c_str());

    MetroNetGenerator generator(fileName, output, output2, getOperationStream(), getErrorStream());

    EXPECT_NO_FATAL_FAILURE(generator.generateMetroNet(true)) << "The metroNet was not Valid!\n";

    std::vector<Tram *> tempTrams = generator.getMetroNet().getTrams();

    for (long unsigned int i = 0; i < tempTrams.size(); i++) {

        Station *currentStation = generator.getMetroNet().getStation(tempTrams[i]->getHuidigStation());

        std::string targetStationName = currentStation->nextOfSpoor(tempTrams[i]->getLijnNr());

        EXPECT_TRUE(!targetStationName.empty()) << "TargetStationName cannot be empty to move Tram";

        if (generator.getMetroNet().aTramAtStationSpoor(targetStationName, tempTrams[i]->getLijnNr())) {
            EXPECT_DEATH(generator.getMetroNet().moveTram(tempTrams[i], targetStationName), "There cannot be a tram at targetStation SpoorNr to move Tram!");
            continue;
        }
        Station *targetStation = generator.getMetroNet().getStation(targetStationName);

        if (currentStation->aSpoorConnectedToStation(targetStationName, tempTrams[i]->getLijnNr())) {
            if (tempTrams[i]->stationCanBeServiced(targetStation)) {
                if(tempTrams[i]->tramCanMove()){
                    EXPECT_TRUE(generator.getMetroNet().moveTram(tempTrams[i], targetStationName));
                }else{
                    EXPECT_FALSE(generator.getMetroNet().moveTram(tempTrams[i], targetStationName));
                }
            }else{
                EXPECT_FALSE(generator.getMetroNet().moveTram(tempTrams[i], targetStationName));
            }
        }else{
            EXPECT_FALSE(generator.getMetroNet().moveTram(tempTrams[i], targetStationName));
        }
    }
    EXPECT_TRUE(generator.getMetroNet().isValidMetroNet()) << "The metroNet has become invalid\n";

    operation.close();
    error.close();
}


TEST_F(DomainTests, ContractViolations) {

    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    std::string fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(0) + ".xml";
    std::string output = "TestOutput/DomainTest/metroNet" +  SSTR(0) + "Simple.txt";
    std::string output2 = "TestOutput/DomainTest/metroNetTest" +  SSTR(0) + "Advanced.txt";
    std::string op = "TestOutput/DomainTest/operation" +  SSTR(0) + ".txt";
    std::string err = "TestOutput/DomainTest/error" +  SSTR(0) + ".txt";

    operation.open(op.c_str());
    error.open(err.c_str());

    MetroNetGenerator generator(fileName, output, output2, getOperationStream(), getErrorStream());

    EXPECT_NO_FATAL_FAILURE(generator.generateMetroNet(true)) << "The metroNet was not Valid!\n";

    std::vector<Tram *> tempTrams = generator.getMetroNet().getTrams();

    for (long unsigned int i = 0; i < tempTrams.size(); i++) {

        int reparatieKost = 5;
        Station* halte = new HalteStation;
        Station* metroStation = new MetronetStation;
        if(tempTrams[i]->getType() == TramType::PCC){
            EXPECT_TRUE(tempTrams[i]->getSnelheid() == 40);
            tempTrams[i]->setReparatieKost(reparatieKost);
            EXPECT_TRUE(tempTrams[i]->getReparatieKost() == reparatieKost);
            EXPECT_TRUE(tempTrams[i]->stationCanBeServiced(halte));
            EXPECT_TRUE(tempTrams[i]->stationCanBeServiced(metroStation));
        } else if(tempTrams[i]->getType() == TramType::Albatros || tempTrams[i]->getType() == TramType::StadsLijner){
            EXPECT_TRUE(tempTrams[i]->getSnelheid() == 70);
            tempTrams[i]->setReparatieKost(reparatieKost);
            EXPECT_TRUE(tempTrams[i]->getReparatieKost() == 0);
            EXPECT_FALSE(tempTrams[i]->stationCanBeServiced(halte));
            EXPECT_TRUE(tempTrams[i]->stationCanBeServiced(metroStation));
        }
    }
    EXPECT_TRUE(generator.getMetroNet().isValidMetroNet()) << "The metroNet has become invalid\n";
    operation.close();
    error.close();
}
