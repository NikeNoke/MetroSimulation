#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../Tram/Tram.h"
#include "../ParseXML/ParseTram.h"
#include<sstream>

//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

/**
 * Deze klasse test ofdat elk Tram object een correcte hoeveelheid attributen heeft
 * **/
class ValidAttributesTram : public ::testing::Test {
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
};

TEST_F(ValidAttributesTram, ValidTrams) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    std::ofstream myfile;
    int fileCounter = 0;
    std::string fileName = "TestInputXML/ValidTram/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        ASSERT_TRUE(doc.LoadFile(fileName.c_str())) << "The file cannot be opened\n";

        TiXmlElement *root = doc.FirstChildElement();
        ASSERT_TRUE(root != NULL) << "The root cannot be NULL\n";

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

            std::string current = element->Value();
            if (current == "TRAM") {

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
            }
        }
        doc.Clear();

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/ValidTram/metroNet" + SSTR(fileCounter) + ".xml";
    }
}

TEST_F(ValidAttributesTram, InValidTrams) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    std::ofstream myfile;
    int fileCounter = 0;
    std::string fileName = "TestInputXML/InValidTram/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        ASSERT_TRUE(doc.LoadFile(fileName.c_str())) << "The file cannot be opened\n";

        TiXmlElement *root = doc.FirstChildElement();
        ASSERT_TRUE(root != NULL) << "The root cannot be NULL\n";

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

            std::string current = element->Value();
            if (current == "TRAM") {

                Tram* tram = new Tram();
                ParseTram parseTram(element);

                try{
                    EXPECT_FALSE(parseTram.checkValidTram()) << "Tram should not have been valid\n";
                }catch (const std::exception& e){

                }

//                EXPECT_FALSE(parseTram.checkValidTram()) << "Tram should not have been valid\n";
//                EXPECT_THROW(parseTram.checkValidTram(), );

                try{
                    EXPECT_FALSE(parseTram.parseAll(metroNet, tram)) << "Tram should not have been parsed\n";
                }catch (const std::exception& e){

                }


                try{
                    EXPECT_TRUE(parseTram.checkNonValidAttributes()) << "Wrong attributes are not present (was expected)\n";
                }catch (const std::exception& e){

                }

                if(!parseTram.parseAll(metroNet,tram))
                    delete tram;
            }
        }
        doc.Clear();

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/InValidTram/metroNet" + SSTR(fileCounter) + ".xml";
    }
}