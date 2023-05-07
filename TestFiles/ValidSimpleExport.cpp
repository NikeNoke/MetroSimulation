//
// Created by byamba on 22/03/23.
//
//#include <iostream>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../MetroNetGenerator/MetroNetGenerator.h"
#include "../Spoor/Spoor.h"
#include "../Trams/Tram.h"
#include "../Utils/utils.h"

//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


class ValidSimpleExport : public ::testing::Test {

protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

    void checkOutputStations(std::ifstream& file, std::vector<Station *>& tempStations) {

        std::string line;
        EXPECT_NO_FATAL_FAILURE(getline(file, line));
        EXPECT_TRUE(line == "--== STATIONS ==--") << "The start of the file is wrong!\n";
        for (long unsigned int i = 0; i < tempStations.size(); i++) {
            EXPECT_NO_FATAL_FAILURE(getline(file, line));
            EXPECT_TRUE(line == "= Station " + tempStations[i]->getName() + " =");
            for (unsigned int j = 0; j < tempStations[i]->getSporen().size(); j++) {
                EXPECT_NO_FATAL_FAILURE(getline(file, line));
                EXPECT_TRUE(line == "* Spoor " + SSTR(tempStations[i]->getSporen()[j]->getSpoorNr()) + ":");
                EXPECT_NO_FATAL_FAILURE(getline(file, line));
                EXPECT_TRUE(line == "\t-> Station " + SSTR(tempStations[i]->getSporen()[j]->getVolgende()) + "");
                EXPECT_NO_FATAL_FAILURE(getline(file, line));
                EXPECT_TRUE(line == "\t<- Station  " + SSTR(tempStations[i]->getSporen()[j]->getVorige()) + "");
                EXPECT_NO_FATAL_FAILURE(getline(file, line));
                EXPECT_TRUE(line == "");
            }
        }
    }

    void checkOutputTrams(std::ifstream& file, std::vector<Tram *>& tempTrams) {
        std::string line;
        EXPECT_NO_FATAL_FAILURE(getline(file, line));
        EXPECT_TRUE(line == "--== TRAMS ==--");

        for (long unsigned int i = 0; i < tempTrams.size(); i++) {
            Tram *currentTram = tempTrams[i];
            EXPECT_NO_FATAL_FAILURE(getline(file, line));
            EXPECT_TRUE(line == "Tram " + SSTR(currentTram->getLijnNr()) + " nr " + SSTR(currentTram->getVoertuigNummer()) + "");
            EXPECT_NO_FATAL_FAILURE(getline(file, line));
            EXPECT_TRUE(line == "\ttype: " + SSTR(currentTram->getType()) + "");
            EXPECT_NO_FATAL_FAILURE(getline(file, line));
            EXPECT_TRUE(line == "\tsnelheid: " + SSTR(currentTram->getSnelheid()) + "");
            EXPECT_NO_FATAL_FAILURE(getline(file, line));
            EXPECT_TRUE(line == "\thuidig station: " + SSTR(currentTram->getHuidigStation()) + "");
            EXPECT_NO_FATAL_FAILURE(getline(file, line));
            if(currentTram->getType() == TramType::PCC){
                EXPECT_TRUE(line == "\treparatiekosten: " + SSTR(currentTram->getTotalReparatieKost()) + "");
                EXPECT_NO_FATAL_FAILURE(getline(file, line));
                EXPECT_TRUE(line == "");
            }else{
                EXPECT_TRUE(line == "");
            }
        }
    }

    void checkOutputMetroNet(std::string output, MetroNet &metroNet) {

        std::vector<Station *> stations = metroNet.getStations();
        std::vector<Tram *> trams = metroNet.getTrams();

        std::ifstream file;

        file.open(output.c_str());

        std::vector<Station *> tempStations = metroNet.getStations();
        checkOutputStations(file, tempStations);

        std::vector<Tram *> tempTrams = metroNet.getTrams();
        checkOutputTrams(file, tempTrams);
        EXPECT_TRUE(Utils::fileExists(output)) << "The file was not even created!\n";
    }
};

//Preconditie: MetroNet is Valid!
TEST_F(ValidSimpleExport, ValidSimpleExport) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    std::string output = "TestOutput/metroNetTestSpecs" +  SSTR(fileCounter) + ".txt";
    std::string output2 = "TestOutput/metroNetTestSpecsAdvanced" +  SSTR(fileCounter) + ".txt";

    while (Utils::fileExists(fileName)) {
        MetroNetGenerator generator(fileName, output, output2);

        EXPECT_NO_FATAL_FAILURE(generator.generateMetroNet(true)) << "The metroNet was not Valid!\n";

        EXPECT_TRUE(Utils::fileExists(output)) << "The file was not created\n";
        EXPECT_FALSE(Utils::fileIsEmpty(output)) << "The file was empty\n";

        checkOutputMetroNet(output, generator.getMetroNet());

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
        output = "TestOutput/metroNetTestSpecs" +  SSTR(fileCounter) + ".txt";
    }
}
