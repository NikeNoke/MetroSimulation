#include <iostream>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../ParseXML/ParseTram.h"
#include "../Trams/AlbatrosTram.h"
#include "../Trams/PCCTram.h"
#include "../Trams/StadslijnerTram.h"

//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
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

    void checkFile(TiXmlDocument &doc, TiXmlElement *&root, const std::string &fileName) {
        ASSERT_TRUE(doc.LoadFile(fileName.c_str())) << "The file cannot be opened\n";
        root = doc.FirstChildElement();
        ASSERT_TRUE(root != NULL) << "The root cannot be NULL\n";
    }
};

TEST_F(ValidAttributesTram, ValidTrams) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/ValidTram/metronet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        TiXmlElement *root = NULL;
        checkFile(doc, root, fileName);

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {

            std::string current = element->Value();
            if (current == "TRAM") {
                Tram *tram;
                for (TiXmlElement *inner = element->FirstChildElement();
                     inner != NULL; inner = inner->NextSiblingElement()) {
                    std::string type = inner->Value();
                    std::string typeText = inner->GetText();
                    if (type == "type") {
                        if (typeText == "Albatros") {
                            tram = new AlbatrosTram;
                        }
                        if (typeText == "PCC") {
                            tram = new PCCTram;
                        }
                        if (typeText == "Stadslijner") {
                            tram = new StadslijnerTram;
                        }
                    }
                    ParseTram parseTram(element);

                    EXPECT_TRUE(parseTram.checkValidLijnNr()) << "LijnNr is not Valid\n";
                    EXPECT_TRUE(parseTram.checkValidBeginStation()) << "Begin Station is not Valid\n";
                    //EXPECT_TRUE(parseTram.checkValidSnelheid()) << "Snelheid is not Valid\n";

                    //EXPECT_TRUE(parseTram.parseSnelheid(metroNet, tram)) << "Snelheid has not been correctly parsed\n";
                    //EXPECT_TRUE(parseTram.parseLijnNr(metroNet, tram)) << "LijnNr has not been correctly parsed\n";
                    //EXPECT_TRUE(parseTram.parseBeginStation(metroNet, tram))
                    //                    << "Begin Station has not been correctly parsed\n";

                    EXPECT_FALSE(parseTram.checkNonValidAttributes()) << "There are wrong atrributes present\n";

                }
                delete tram;
            }
            doc.Clear();

            fileCounter = fileCounter + 1;
            fileName = "TestInputXML/ValidTram/metronet" + SSTR(fileCounter) + ".xml";
        }
    }
}

//Death test
TEST_F(ValidAttributesTram, InValidTrams) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/InValidTram/metronet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        TiXmlElement *root = NULL;
        checkFile(doc, root, fileName);

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {

            std::string current = element->Value();
            if (current == "TRAM") {
                Tram *tram;
                for (TiXmlElement *inner = element->FirstChildElement();
                     inner != NULL; inner = inner->NextSiblingElement()) {
                    std::string type = inner->Value();
                    std::string typeText = inner->GetText();
                    if (type == "type") {
                        if (typeText == "Albatros") {
                            tram = new AlbatrosTram;
                        }
                        if (typeText == "PCC") {
                            tram = new PCCTram;
                        }
                        if (typeText == "Stadslijner") {
                            tram = new StadslijnerTram;
                        }
                    }

                    ParseTram parseTram(element);

                    EXPECT_FALSE(parseTram.checkValidTram()) << "Tram should not have been valid\n";

                    //EXPECT_DEATH(parseTram.parseAll(metroNet, tram), "The Tram tag is not correct");


                }
                delete tram;
            }
            doc.Clear();
            fileCounter = fileCounter + 1;
            fileName = "TestInputXML/InValidTram/metronet" + SSTR(fileCounter) + ".xml";
        }
    }
}

TEST_F(ValidAttributesTram, InValidTramAttributes) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/InValidTramAttributes/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        TiXmlElement *root = NULL;
        checkFile(doc, root, fileName);

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {

            std::string current = element->Value();
            if (current == "TRAM") {
                Tram *tram;
                for (TiXmlElement *inner = element->FirstChildElement();
                     inner != NULL; inner = inner->NextSiblingElement()) {
                    std::string type = inner->Value();
                    std::string typeText = inner->GetText();
                    if (type == "type") {
                        if (typeText == "Albatros") {
                            tram = new AlbatrosTram;
                        }
                        if (typeText == "PCC") {
                            tram = new PCCTram;
                        }
                        if (typeText == "Stadslijner") {
                            tram = new StadslijnerTram;
                        }
                    }

                    ParseTram parseTram(element);

                    EXPECT_TRUE(parseTram.checkNonValidAttributes())
                                        << "Wrong attributes are not present (was expected)\n";

                }
                delete tram;
            }
            doc.Clear();

            fileCounter = fileCounter + 1;
            fileName = "TestInputXML/InValidTramAttributes/metroNet" + SSTR(fileCounter) + ".xml";
        }
    }
}