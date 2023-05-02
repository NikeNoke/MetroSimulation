//
// Created by byamba on 22/03/23.
//
#include <iostream>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../ParseXML/ParseTram.h"
#include "../MetroNetGenerator/MetroNetGenerator.h"
/*
//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


class ValidExport : public ::testing::Test {

protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

    void checkOutputStations(std::ifstream file, int end) {

    }

    void checkOutputTrams(std::ifstream file, int end) {

    }

    void checkOutputMetroNet(std::string output, MetroNet &metroNet) {

        std::vector<Station *> stations = metroNet.getStations();
        std::vector<Tram *> trams = metroNet.getTrams();

        std::ifstream file;

        file.open(output.c_str());

        int lineCounter = 0;
        std::string start;
        std::getline(file, start);
        EXPECT_TRUE(start == "Stations:") << "The start of the file is wrong!\n";
        lineCounter++;
        int endLineStation = 1 + (stations.size() * 4);
        int stationIndex = 1;
        int stationCounter = 0;
        for (std::string line; lineCounter < endLineStation; lineCounter++) {
            EXPECT_NO_FATAL_FAILURE(getline(file, line));
            EXPECT_FALSE(line == "Trams:") << "Not enough Stations\n";
            if (stationIndex == 1) {
                EXPECT_TRUE(line == "\tstation" + SSTR(stationCounter) + ":")
                                    << "The station is not numbered correctly\n";
                stationCounter++;
                stationIndex++;
            } else if (stationIndex == 2) {
                EXPECT_TRUE(line == "\t\tNaam: " + stations[stationCounter - 1]->getName());
                stationIndex++;
            } else if (stationIndex == 3) {
                EXPECT_TRUE(line == "\t\tVorige Station: " + stations[stationCounter - 1]->getSporen());
                stationIndex++;
            } else {
                EXPECT_TRUE(line == "\t\tVolgende Station: " + stations[stationCounter - 1]->getVolgende());
                stationIndex = 1;
            }
        }

        int endLineTram = endLineStation + 1 + (trams.size() * 5);
        int tramIndex = 1;
        int tramCounter = 0;
        std::string startTrams;
        std::getline(file, startTrams);
        EXPECT_TRUE(startTrams == "Trams:") << "The tramStart of the file is wrong!\n";
        lineCounter++;
        for (std::string line; lineCounter < endLineTram; lineCounter++) {

            EXPECT_NO_FATAL_FAILURE(getline(file, line));
            if (tramIndex == 1) {
                EXPECT_TRUE(line == "\ttram" + SSTR(tramCounter) + ":") << "The Tram is not numbered correctly\n";
                tramCounter++;
                tramIndex++;
            } else if (tramIndex == 2) {
                EXPECT_TRUE(line == "\t\tLijnNr: " + SSTR(trams[tramCounter - 1]->getLijnNr()));
                tramIndex++;
            } else if (tramIndex == 3) {
                EXPECT_TRUE(line == "\t\tSnelheid: " + SSTR(trams[tramCounter - 1]->getSnelheid()));
                tramIndex++;
            } else if (tramIndex == 4) {
                EXPECT_TRUE(line == "\t\tBegin station: " + SSTR(trams[tramCounter - 1]->getBeginStation()));
                tramIndex++;
            } else {
                EXPECT_TRUE(line == "\t\tHuidig station: " + SSTR(trams[tramCounter - 1]->getHuidigStation()));
                tramIndex = 1;
            }
        }
//        std::cout << "end of line: " << std::boolalpha << file.eof() << "\n";
        std::string ok;
        std::getline(file, ok);
//        std::cout << ok << "\n";
//        std::cout << "end of line: " << std::boolalpha << file.eof() << "\n";
    }
};

//Preconditie: MetroNet is Valid!
TEST_F(ValidExport, ValidExport) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    std::string output = "TestOutput/metroNetTestSpecs.txt";

    while (Utils::fileExists(fileName)) {
        MetroNetGenerator generator(fileName, output, output);

        EXPECT_NO_FATAL_FAILURE(generator.generateMetroNet()) << "The metroNet was not Valid!\n";

        EXPECT_TRUE(Utils::fileExists(output)) << "The file was not created\n";
        EXPECT_FALSE(Utils::fileIsEmpty(output)) << "The file was empty\n";

        checkOutputMetroNet(output, generator.getMetroNet());

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    }

}

////Preconditie: Stations and Trams are correct!
//TEST_F(ValidExport, InValidExport) {
//    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";
//
//    int fileCounter = 0;
//    std::string fileName = "TestInputXML/InValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
//
//    while (Utils::fileExists(fileName)) {
//
//        MetroNetGenerator generator(fileName, "metroNetTestSpecs.txt");
//
//        EXPECT_DEATH(generator.generateMetroNet(), "c") << "The metroNet was Valid\n";
//
//        fileCounter = fileCounter + 1;
//        fileName = "TestInputXML/InValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
//    }
//}
*/