//
// Created by byamba on 22/03/23.
//
//#include <iostream>
#include <gtest/gtest.h>
#include <map>
#include "../TinyXML/tinyxml.h"
#include "../MetroNetGenerator/MetroNetGenerator.h"
#include "../Spoor/Spoor.h"
#include "../Trams/Tram.h"
#include "../Utils/utils.h"

//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


class ValidAdvancedExport : public ::testing::Test {

protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

    int indexVolgende(std::vector<Spoor *> &container, const std::string &naam) const {

        for (unsigned int i = 0; i < container.size(); i++) {
            if (container[i]->getHuiding() == naam)
                return i;
        }

        return -1;
    }

    void checkOutputMetroNet(std::string output, MetroNet &metroNet) {

        std::vector<Station *> stations = metroNet.getStations();
        std::vector<Tram *> trams = metroNet.getTrams();

        std::ifstream file;

        file.open(output.c_str());

        std::vector<Station *> tempStations = metroNet.getStations();
        std::vector<Tram *> tempTrams = metroNet.getTrams();

        std::map<int, std::vector<Spoor *> > spoorMap;

        for (long unsigned int i = 0; i < tempStations.size(); i++) {
//        Station* currentStation = tempStations[i];
            for (unsigned int j = 0; j < tempStations[i]->getSporen().size(); j++) {
                Spoor *currentSpoor = tempStations[i]->getSporen()[j];
                const int nr = currentSpoor->getSpoorNr();

                spoorMap[nr].push_back(currentSpoor);
            }
        }

        std::map<int, std::vector<Spoor *> >::iterator it;

        for (it = spoorMap.begin(); it != spoorMap.end(); it++) {

            std::vector<std::string> correctOrder;

            correctOrder.push_back(it->second[0]->getVorige());
            correctOrder.push_back(it->second[0]->getHuiding());
            correctOrder.push_back(it->second[0]->getVolgende());

            std::string toSearch = it->second[0]->getVolgende();

            while (correctOrder.size() < it->second.size()) {

                int index = indexVolgende(it->second, toSearch);

                toSearch = it->second[index]->getVolgende();

                correctOrder.push_back(toSearch);

            }

            std::string line;
            std::string tempLine;
            EXPECT_NO_FATAL_FAILURE(getline(file, line));
            for (unsigned int j = 0; j < correctOrder.size(); j++) {

                tempLine += "=" + correctOrder[j] + "=";
            }
            EXPECT_TRUE(line == tempLine);

            tempLine = "";
            EXPECT_NO_FATAL_FAILURE(getline(file, line));
            for (unsigned int j = 0; j < correctOrder.size(); j++) {

                if (metroNet.aTramAtStation(correctOrder[j])){
                    tempLine += " T ";
                }
                else{
                    tempLine += "   ";
                }
            }
            EXPECT_TRUE(line == tempLine);
            EXPECT_NO_FATAL_FAILURE(getline(file, line));
            EXPECT_TRUE(line == "");
        }

        EXPECT_TRUE(Utils::fileExists(output)) << "The file was not even created!\n";
    }
};

//Preconditie: MetroNet is Valid!
TEST_F(ValidAdvancedExport, ValidAdvancedExport) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    std::string output = "TestOutput/metroNetTestSpecs" +  SSTR(fileCounter) + ".txt";
    std::string output2 = "TestOutput/metroNetTestSpecsAdvanced" +  SSTR(fileCounter) + ".txt";

    while (Utils::fileExists(fileName)) {
        MetroNetGenerator generator(fileName, output, output2);

        EXPECT_NO_FATAL_FAILURE(generator.generateMetroNet(true)) << "The metroNet was not Valid!\n";

        EXPECT_TRUE(Utils::fileExists(output2)) << "The file was not created\n";
        EXPECT_FALSE(Utils::fileIsEmpty(output2)) << "The file was empty\n";

        checkOutputMetroNet(output2, generator.getMetroNet());

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
        output = "TestOutput/metroNetTestSpecs" +  SSTR(fileCounter) + ".txt";
    }
}
