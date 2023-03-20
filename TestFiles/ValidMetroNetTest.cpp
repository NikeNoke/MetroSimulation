#include <iostream>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../ParseXML/ParseTram.h"
#include "../ParseXML/ParseStation.h"

//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


class ValidMetroNet : public ::testing::Test {

protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

    void checkStation(MetroNet &metroNet, Station *station, ParseStation &parseStation) {
        ASSERT_TRUE(parseStation.checkValidStation()) << "Precondition of valid station is not fulfilled\n";

        ASSERT_TRUE(parseStation.parseAll(metroNet, station))
                                    << "Precondition of valid station is not fulfilled, thus not parsed\n";

        ASSERT_FALSE(parseStation.checkNonValidAttributes()) << "Precondition of valid station is not fulfilled\n";
    }

    void checkTram(MetroNet &metroNet, Tram *tram, ParseTram &parseTram) {

        ASSERT_TRUE(parseTram.checkValidTram()) << "Precondition of valid tram is not fulfilled\n";

        ASSERT_TRUE(parseTram.parseAll(metroNet, tram)) << "Precondition of valid tram is not fulfilled\n";

        ASSERT_FALSE(parseTram.checkNonValidAttributes()) << "Precondition of valid tram is not fulfilled\n";

    }

    void checkFile(TiXmlDocument &doc, TiXmlElement *&root, const std::string &fileName) {
        ASSERT_TRUE(doc.LoadFile(fileName.c_str())) << "The file cannot be opened\n";
        root = doc.FirstChildElement();
        ASSERT_TRUE(root != NULL) << "The root cannot be NULL\n";
    }
};

//Preconditie: Stations and Trams are correct!
TEST_F(ValidMetroNet, ValidMetroNet) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        TiXmlElement *root = NULL;
        checkFile(doc, root, fileName);

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {

            std::string current = element->Value();
            if (current == "STATION") {

                Station *station = new Station();
                ParseStation parseStation(element);

                checkStation(metroNet, station, parseStation);

                metroNet.addStation(station);

            } else if (current == "TRAM") {

                Tram *tram = new Tram();
                ParseTram parseTram(element);

                checkTram(metroNet, tram, parseTram);

                metroNet.addTram(tram);


            } else {
                EXPECT_TRUE(false) << "MetroNet has a non valid attribute besides TRAM and STATION\n";
            }
        }
        doc.Clear();

        EXPECT_TRUE(Utils::validMetroNetSilent(metroNet)) << "The metroNet is not Valid\n";

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    }

}

//Preconditie: Stations and Trams are correct!
TEST_F(ValidMetroNet, InValidMetroNet) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/InValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        TiXmlElement *root = NULL;
        checkFile(doc, root, fileName);

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {

            std::string current = element->Value();
            if (current == "STATION") {

                Station *station = new Station();
                ParseStation parseStation(element);

                checkStation(metroNet, station, parseStation);

                metroNet.addStation(station);

            } else if (current == "TRAM") {

                Tram *tram = new Tram();
                ParseTram parseTram(element);

                checkTram(metroNet, tram, parseTram);

                metroNet.addTram(tram);

            } else {
                EXPECT_TRUE(false) << "MetroNet has a non valid attribute besides TRAM and STATION\n";
            }
        }
        doc.Clear();

        EXPECT_FALSE(Utils::validMetroNetSilent(metroNet)) << "The MetroNet was Valid, expected nonValid\n";

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/InValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    }
}
