//#include <iostream>
//#include <gtest/gtest.h>
//#include "../TinyXML/tinyxml.h"
//#include "../Utils/utils.h"
//#include "../ParseXML/ParseTram.h"
//#include "../Trams/AlbatrosTram.h"
//#include "../Trams/PCCTram.h"
//#include "../Trams/StadslijnerTram.h"
//
////https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
//
///**
// * Deze klasse test ofdat elk Tram object een correcte hoeveelheid attributen heeft
// * **/
//class ValidAttributesTram : public ::testing::Test {
//protected:
//    /**
//     * "Sets up the text fixture." Klasse overgeërft van gtest.h
//     * **/
//    virtual void SetUp() {
//        operation.open("TestOutput/OperationLog.txt");
//        error.open("TestOutput/ErrorLog.txt");
//    }
//
//    /**
//     * "Tears down the test fixture." Klasse overgeërft van gtest.h
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
//    std::ostream &getOperationStream(){
//        return operation;
//    }
//
//    std::ostream &getErrorStream(){
//        return error;
//    }
//
//    std::ofstream operation;
//    std::ofstream error;
//};
//
//TEST_F(ValidAttributesTram, ValidTrams) {
//    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";
//    ASSERT_TRUE(Utils::directoryExists("TestInputXML/ValidTram")) << "Directory to test does not exist\n";
//
//    int fileCounter = 0;
//    std::string fileName = "TestInputXML/ValidTram/metronet" + SSTR(fileCounter) + ".xml";
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
//            if (current == "TRAM") {
//
//                ParseTram parseTram(element);
//
//                EXPECT_TRUE(parseTram.checkTramTypeExists()) << "Tram does not have a type is not Valid\n";
//                EXPECT_TRUE(parseTram.checkValidTypeTram()) << "Type of Tram is not Valid\n";
//
//                if(parseTram.getTramType() != TramType::PCC){
//                    EXPECT_TRUE(parseTram.checkValidLijnNr()) << "LijnNr is not Valid\n";
//                    EXPECT_TRUE(parseTram.checkValidBeginStation()) << "Begin Station is not Valid\n";
//                    EXPECT_TRUE(parseTram.checkValidVoertuigNummer()) << "The Tram identification is not Valid\n";
//                    EXPECT_FALSE(parseTram.checkNonValidAttributes()) << "There are nonValidAttributes in the Tram\n";
//                }else{
//                    EXPECT_TRUE(parseTram.checkValidLijnNr()) << "LijnNr is not Valid\n";
//                    EXPECT_TRUE(parseTram.checkValidBeginStation()) << "Begin Station is not Valid\n";
//                    EXPECT_TRUE(parseTram.checkValidVoertuigNummer()) << "The Tram identification is not Valid\n";
//                    EXPECT_TRUE(parseTram.checkValidReparatieTijd()) << "The reparation Time is not Valid\n";
//                    EXPECT_TRUE(parseTram.checkValidReparatieKosten()) << "The reparation Cost is not Valid\n";
//                    EXPECT_TRUE(parseTram.checkValidAantalDefecten()) << "The amount of defects are not Valid\n";
//                    EXPECT_FALSE(parseTram.checkNonValidAttributes()) << "There are wrong atrributes present\n";
//                }
//                EXPECT_TRUE(parseTram.parseSuccessful()) << "The parsing was not successful\n";
//            }
//
//        }
//        doc.Clear();
//
//        fileCounter = fileCounter + 1;
//        fileName = "TestInputXML/ValidTram/metronet" + SSTR(fileCounter) + ".xml";
//    }
//}
//
//
////Death test
//TEST_F(ValidAttributesTram, InValidTrams) {
//    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";
//    ASSERT_TRUE(Utils::directoryExists("TestInputXML/InValidTram")) << "Directory to test does not exist\n";
//
//    int fileCounter = 0;
//    std::string fileName = "TestInputXML/InValidTram/metronet" + SSTR(fileCounter) + ".xml";
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
//            if (current == "TRAM") {
//
//
//                ParseTram parseTram(element);
//
//                EXPECT_FALSE(parseTram.checkValidTram()) << "Tram should not have been valid\n";
//                EXPECT_FALSE(parseTram.parseSuccessful()) << "Tram should not have been parsed\n";
//
//            }
//
//        }
//        doc.Clear();
//        fileCounter = fileCounter + 1;
//        fileName = "TestInputXML/InValidTram/metronet" + SSTR(fileCounter) + ".xml";
//    }
//}
//
//
//TEST_F(ValidAttributesTram, InValidTramAttributes) {
//    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";
//
//    int fileCounter = 0;
//    std::string fileName = "TestInputXML/InValidTramAttributes/metroNet" + SSTR(fileCounter) + ".xml";
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
//            if (current == "TRAM") {
//
//
//                ParseTram parseTram(element);
//
//                EXPECT_TRUE(parseTram.checkNonValidAttributes())
//                                    << "Wrong attributes were no detected\n";
//
//            }
//
//        }
//        doc.Clear();
//
//        fileCounter = fileCounter + 1;
//        fileName = "TestInputXML/InValidTramAttributes/metroNet" + SSTR(fileCounter) + ".xml";
//    }
//}
