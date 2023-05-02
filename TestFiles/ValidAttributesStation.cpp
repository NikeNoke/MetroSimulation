#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include<sstream>
#include "../ParseXML/ParseStation.h"
#include "../Stations/HalteStation.h"
#include "../Stations/MetronetStation.h"

//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


/**
 * Deze klasse test ofdat elk Station object een correcte hoeveelheid attributen heeft
 * **/
class ValidAttributesStation : public ::testing::Test {
protected:
    /**
     * Klasse overgeërft van gtest.h
     * **/
    virtual void SetUp() {

    }

    /**
     * Klasse overgeërft van gtest.h
     * **/
    virtual void TearDown() {

    }

    void checkFile(TiXmlDocument &doc, TiXmlElement *&root, const std::string &fileName) {
        ASSERT_TRUE(doc.LoadFile(fileName.c_str())) << "The file cannot be opened\n";
        root = doc.FirstChildElement();
        ASSERT_TRUE(root != NULL) << "The root cannot be NULL\n";
    }
};



//HappyDay
TEST_F(ValidAttributesStation, ValidStations) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/ValidStation/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        TiXmlElement *root = NULL;
        checkFile(doc, root, fileName);

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {

            std::string current = element->Value();
            if (current == "STATION") {
                Station *station;
                for (TiXmlElement *attribute = element->FirstChildElement();
                     attribute != NULL; attribute = attribute->NextSiblingElement()) {
                    std::string type = attribute->Value();
                    std::string typeText = attribute->GetText();
                    if (type == "type") {
                        if (typeText == "Metrostation") {
                            station = new MetronetStation;
                        }
                        if (typeText == "Halte") {
                            station = new HalteStation;
                        }
                    }
                    ParseStation parseStation(element);

                    EXPECT_TRUE(parseStation.parseSuccessful()) << "Parse unsuccessful\n";
                    //EXPECT_TRUE(parseStation.checkValidSpoorNr()) << "SpoorNr is not Valid\n";
                    //EXPECT_TRUE(parseStation.checkValidVolgende()) << "Volgende is not Valid\n";
                    //EXPECT_TRUE(parseStation.checkValidVorige()) << "Vorige is not Valid\n";
                    EXPECT_TRUE(parseStation.checkValidNaam()) << "Naam is not Valid\n";
                    EXPECT_TRUE(parseStation.checkValidTypeStation()) << "Type is not valid\n";
                    EXPECT_TRUE(parseStation.checkValidStation()) << "Station is not valid\n";
                    //EXPECT_TRUE(parseStation.parseVorige(metroNet, station)) << "Vorige has not been correctly parsed\n";
                    //EXPECT_TRUE(parseStation.parseVolgende(metroNet, station)) << "Volgende has not been correctly parsed\n";
                    //EXPECT_TRUE(parseStation.parseSpoorNr(metroNet, station)) << "SpoorNr has not been correctly parsed\n";
                    //EXPECT_TRUE(parseStation.parseNaam(metroNet, station)) << "Naam has not been correctly parsed\n";

                    EXPECT_FALSE(parseStation.checkNonValidAttributes()) << "There are wrong atrributes present\n";
                }
                delete station;
            }
        }
        doc.Clear();

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/ValidStation/metroNet" + SSTR(fileCounter) + ".xml";
    }

}

//Death Test
TEST_F(ValidAttributesStation, InValidStation) {

    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/InValidStation/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        TiXmlElement *root = NULL;
        checkFile(doc, root, fileName);

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {

            std::string current = element->Value();
            if (current == "STATION") {
                Station *station;
                for (TiXmlElement *inner = element->FirstChildElement();
                     inner != NULL; inner = inner->NextSiblingElement()) {
                    std::string type = inner->Value();
                    std::string typeText = inner->GetText();
                    if (type == "type") {
                        if (typeText == "Metrostation") {
                            station = new MetronetStation;
                        }
                        if (typeText == "Halte") {
                            station = new HalteStation;
                        }
                    }
                    ParseStation parseStation(element);

                    EXPECT_FALSE(parseStation.checkValidStation()) << "checkValidStation returned true\n";

                    EXPECT_DEATH(parseStation.parseAll(), "The Station tag is not correct");

                }

//                if(!station->getName().empty()){
//                    if(!metroNet.stationRegistered(station->getName()))
                delete station;
//                }

            }
        }
        doc.Clear();

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/InValidStation/metroNet" + SSTR(fileCounter) + ".xml";
    };
}

TEST_F(ValidAttributesStation, InValidStationAttributes) {

    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/InValidStationAttributes/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        TiXmlElement *root = NULL;
        checkFile(doc, root, fileName);

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {

            std::string current = element->Value();
            if (current == "STATION") {

                ParseStation parseStation(element);

                EXPECT_TRUE(parseStation.checkNonValidAttributes())
                                    << "Wrong attributes are not present (was expected)\n";

            }
        }
        doc.Clear();

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/InValidStationAttributes/metroNet" + SSTR(fileCounter) + ".xml";
    };
}
