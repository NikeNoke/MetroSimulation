//
// Created by Thomas on 04/05/2023.
//
#include <iostream>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../ParseXML/ParseTram.h"
#include "../ParseXML/ParseMetroNet.h"
#include "../ParseXML/ParseSpoor.h"
#include "../ParseXML/ParseStation.h"
#include "../Trams/AlbatrosTram.h"
#include "../Trams/PCCTram.h"
#include "../Trams/StadslijnerTram.h"
#include "../MetroNet/MetroNet.h"
#include "../Stations/Station.h"
#include "../Stations/MetronetStation.h"
#include "../Stations/HalteStation.h"

//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

/**
 * Deze klasse test ofdat XML files correcte tags hebben of niet.
 * **/
class TagChecker : public ::testing::Test {
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

protected:
    friend class MetroNet;

    friend class AlbatrosTram;

    friend class PCCTram;

    friend class StadslijnerTram;

    friend class HalteStation;

    friend class MetronetStation;

    MetroNet testMetronet;
    HalteStation testHalteStation;
    MetronetStation testMetronetStation;
    PCCTram testPCCTram;
    AlbatrosTram testAlbatrosTram;
    StadslijnerTram testStadslijnerTram;
};


TEST_F(TagChecker, ValidXmlTags) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/ValidXmlTags/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        TiXmlElement *root = NULL;
        checkFile(doc, root, fileName);

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {
            std::string current = element->Value();
            if (current == "STATION") {
                EXPECT_NO_FATAL_FAILURE(ParseStation parseStation(element));
            }
            if (current == "TRAM") {
                EXPECT_NO_FATAL_FAILURE(ParseStation parseStation(element));
            }
        }
        doc.Clear();

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/ValidXmlTags/metroNet" + SSTR(fileCounter) + ".xml";
    };
}

TEST_F(TagChecker, InValidXmlTags) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/InValidXmlTags/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        TiXmlElement *root = NULL;
        checkFile(doc, root, fileName);

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {
            std::string current = element->Value();
            if (current == "STATION") {
                EXPECT_NO_FATAL_FAILURE(ParseStation parseStation(element));
            }
            if (current == "TRAM") {
                EXPECT_NO_FATAL_FAILURE(ParseStation parseStation(element));
            } else {
                EXPECT_TRUE(current != "STATION" || current != "TRAM");
            }
        }
        doc.Clear();

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/InValidXmlTags/metroNet" + SSTR(fileCounter) + ".xml";
    };
}

TEST_F(TagChecker, InValidFile){
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/InValidXmlFile/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        TiXmlElement *root = NULL;
        EXPECT_DEATH(checkFile(doc, root, fileName),"Assertion.*failed");
        MetroNet metroNet;
        doc.Clear();
        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/InValidFile/metroNet" + SSTR(fileCounter) + ".xml";
    };
}