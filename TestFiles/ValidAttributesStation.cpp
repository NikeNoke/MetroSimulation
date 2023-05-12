//#include <gtest/gtest.h>
//#include "../TinyXML/tinyxml.h"
//#include "../Utils/utils.h"
//#include<sstream>
//#include "../ParseXML/ParseStation.h"
//#include "../Stations/HalteStation.h"
//#include "../Stations/MetronetStation.h"
//
////https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
//
//
///**
// * Deze klasse test ofdat elk Station object een correcte hoeveelheid attributen heeft
// * **/
//class ValidAttributesStation : public ::testing::Test {
//protected:
//    /**
//     * Klasse overgeërft van gtest.h
//     * **/
//    virtual void SetUp() {
//
//    }
//
//    /**
//     * Klasse overgeërft van gtest.h
//     * **/
//    virtual void TearDown() {
//
//    }
//
//    void checkFile(TiXmlDocument &doc, TiXmlElement *&root, const std::string &fileName) {
//        ASSERT_TRUE(doc.LoadFile(fileName.c_str())) << "The file cannot be opened\n";
//        root = doc.FirstChildElement();
//        ASSERT_TRUE(root != NULL) << "The root cannot be NULL\n";
//    }
//};
//
//
//
////HappyDay
//TEST_F(ValidAttributesStation, ValidStations) {
//    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";
//    ASSERT_TRUE(Utils::directoryExists("TestInputXML/ValidStation")) << "Directory to test does not exist\n";
//
//    int fileCounter = 0;
//    std::string fileName = "TestInputXML/ValidStation/metroNet" + SSTR(fileCounter) + ".xml";
//
//    while (Utils::fileExists(fileName)) {
//        TiXmlDocument doc;
//        TiXmlElement *root = NULL;
//        checkFile(doc, root, fileName);
//
//        MetroNet metroNet;
//
//        for (TiXmlElement *element = root->FirstChildElement();
//             element != NULL; element = element->NextSiblingElement()) {
//
//            std::string current = element->Value();
//            if (current == "STATION") {
//
//
//                ParseStation parseStation(element);
//
//                EXPECT_TRUE(parseStation.checkValidStation()) << "The station was not seen as valid\n";
//                EXPECT_TRUE(parseStation.parseSuccessful()) << "Parse unsuccessful\n";
//
//
//            }
//
//        }
//
//        doc.Clear();
//
//        fileCounter = fileCounter + 1;
//        fileName = "TestInputXML/ValidStation/metroNet" + SSTR(fileCounter) + ".xml";
//    }
//}
//
//
//
////Death Test
//TEST_F(ValidAttributesStation, InValidStation) {
//
//    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";
//    ASSERT_TRUE(Utils::directoryExists("TestInputXML/InValidStation")) << "Directory to test does not exist\n";
//
//    int fileCounter = 0;
//    std::string fileName = "TestInputXML/InValidStation/metroNet" + SSTR(fileCounter) + ".xml";
//
//    while (Utils::fileExists(fileName)) {
//        TiXmlDocument doc;
//        TiXmlElement *root = NULL;
//        checkFile(doc, root, fileName);
//
//        MetroNet metroNet;
//
//        for (TiXmlElement *element = root->FirstChildElement();
//             element != NULL; element = element->NextSiblingElement()) {
//
//            std::string current = element->Value();
//            if (current == "STATION") {
//
//                    ParseStation parseStation(element);
//
//                    EXPECT_FALSE(parseStation.checkValidStation()) << "checkValidStation returned true\n";
//
//                    EXPECT_DEATH(parseStation.parseAll(), "The Station tag is not correct");
//
//                }
//
////                if(!station->getName().empty()){
////                    if(!metroNet.stationRegistered(station->getName()))
//
////                }
//
//
//        }
//        doc.Clear();
//
//        fileCounter = fileCounter + 1;
//        fileName = "TestInputXML/InValidStation/metroNet" + SSTR(fileCounter) + ".xml";
//    };
//}
//
//TEST_F(ValidAttributesStation, InValidStationAttributes) {
//
//    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";
//
//    int fileCounter = 0;
//    std::string fileName = "TestInputXML/InValidStationAttributes/metroNet" + SSTR(fileCounter) + ".xml";
//
//    while (Utils::fileExists(fileName)) {
//        TiXmlDocument doc;
//        TiXmlElement *root = NULL;
//        checkFile(doc, root, fileName);
//
//        MetroNet metroNet;
//
//        for (TiXmlElement *element = root->FirstChildElement();
//             element != NULL; element = element->NextSiblingElement()) {
//
//            std::string current = element->Value();
//            if (current == "STATION") {
//
//                ParseStation parseStation(element);
//
//                EXPECT_TRUE(parseStation.checkNonValidAttributes())
//                                    << "Wrong attributes were not detected\n";
//
//            }
//        }
//        doc.Clear();
//
//        fileCounter = fileCounter + 1;
//        fileName = "TestInputXML/InValidStationAttributes/metroNet" + SSTR(fileCounter) + ".xml";
//    };
//}
