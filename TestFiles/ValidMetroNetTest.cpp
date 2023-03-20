#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../Station/Station.h"
#include "../Tram/Tram.h"
#include "../MetroNet/MetroNet.h"
#include<sstream>
#include "../ParseXML/ParseTram.h"
#include "../ParseXML/ParseStation.h"

//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


class ValidMetroNet : public ::testing::Test {

protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }
};

TEST_F(ValidMetroNet, ValidMetroNet){
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    std::ofstream myfile;
    int fileCounter = 0;
    std::string fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        ASSERT_TRUE(doc.LoadFile(fileName.c_str())) << "The file cannot be opened\n";

        TiXmlElement *root = doc.FirstChildElement();
        ASSERT_TRUE(root != NULL) << "The root cannot be NULL\n";

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

            std::string current = element->Value();
            if (current == "STATION") {

                Station *station = new Station();
                ParseStation parseStation(element);

                EXPECT_TRUE(parseStation.checkValidSpoorNr()) << "SpoorNr is not Valid\n";
                EXPECT_TRUE(parseStation.checkValidVolgende()) << "Volgende is not Valid\n";
                EXPECT_TRUE(parseStation.checkValidVorige()) << "Vorige is not Valid\n";
                EXPECT_TRUE(parseStation.checkValidNaam()) << "Naam is not Valid\n";

                EXPECT_TRUE(parseStation.parseVorige(metroNet, station)) << "Vorige has not been correctly parsed\n";
                EXPECT_TRUE(parseStation.parseVolgende(metroNet, station)) << "Volgende has not been correctly parsed\n";
                EXPECT_TRUE(parseStation.parseSpoorNr(metroNet, station)) << "SpoorNr has not been correctly parsed\n";
                EXPECT_TRUE(parseStation.parseNaam(metroNet, station)) << "Naam has not been correctly parsed\n";

                EXPECT_FALSE(parseStation.checkNonValidAttributes()) << "There are wrong atrributes present\n";

                if(!parseStation.parseAll(metroNet,station))
                    delete station;
            }else if(current == "TRAM"){

                Tram* tram = new Tram();
                ParseTram parseTram(element);

                EXPECT_TRUE(parseTram.checkValidLijnNr()) << "LijnNr is not Valid\n";
                EXPECT_TRUE(parseTram.checkValidBeginStation()) << "Begin Station is not Valid\n";
                EXPECT_TRUE(parseTram.checkValidSnelheid()) << "Snelheid is not Valid\n";

                EXPECT_TRUE(parseTram.parseSnelheid(metroNet, tram)) << "Snelheid has not been correctly parsed\n";
                EXPECT_TRUE(parseTram.parseLijnNr(metroNet, tram)) << "LijnNr has not been correctly parsed\n";
                EXPECT_TRUE(parseTram.parseBeginStation(metroNet, tram)) << "Begin Station has not been correctly parsed\n";

                EXPECT_FALSE(parseTram.checkNonValidAttributes()) << "There are wrong atrributes present\n";

                if(!parseTram.parseAll(metroNet,tram))
                    delete tram;

            }else{
                EXPECT_TRUE(false) << "MetroNet has a non valid attribute besides TRAM and STATION\n";
            }
        }
        doc.Clear();

        EXPECT_TRUE(Utils::validMetroNetSilent(metroNet)) << "The metroNet is not Valid\n";

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    }

}

//Death Test
TEST_F(ValidMetroNet, InValidMetroNet){
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    std::ofstream myfile;
    int fileCounter = 0;
    std::string fileName = "TestInputXML/InValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        ASSERT_TRUE(doc.LoadFile(fileName.c_str())) << "The file cannot be opened\n";

        TiXmlElement *root = doc.FirstChildElement();
        ASSERT_TRUE(root != NULL) << "The root cannot be NULL\n";

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

            std::string current = element->Value();
            if (current == "STATION") {

                Station *station = new Station();
                ParseStation parseStation(element);

                EXPECT_FALSE(parseStation.checkValidStation()) << "checkValidStation returned true\n";

                EXPECT_FALSE(parseStation.parseAll(metroNet, station)) << "Parsing should not have succeeded\n";

                EXPECT_TRUE(parseStation.checkNonValidAttributes()) << "Wrong attributes are not present (was expected)\n";

                if(!parseStation.parseAll(metroNet,station))
                    delete station;

            }else if(current == "TRAM"){

                Tram* tram = new Tram();
                ParseTram parseTram(element);

                EXPECT_FALSE(parseTram.checkValidTram()) << "Tram should not have been valid\n";

                EXPECT_FALSE(parseTram.parseAll(metroNet, tram)) << "Tram should not have been parsed\n";

                EXPECT_TRUE(parseTram.checkNonValidAttributes()) << "Wrong attributes are not present (was expected)\n";

                if(!parseTram.parseAll(metroNet,tram))
                    delete tram;

            }else{
                EXPECT_TRUE(false) << "MetroNet has a non valid attribute besides TRAM and STATION\n";
            }
        }
        doc.Clear();

        EXPECT_FALSE(Utils::validMetroNetSilent(metroNet)) << "The MetroNet was Valid, expected nonValid\n";

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/InValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    }
}
