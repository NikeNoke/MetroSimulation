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
 * Deze klasse test ofdat elk Spoor object een correcte hoeveelheid attributen heeft.
 * **/
class ValidAttributesSpoor : public ::testing::Test {
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


TEST_F(ValidAttributesSpoor, ValidSporen) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/ValidSporen/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        TiXmlElement *root = NULL;
        checkFile(doc, root, fileName);

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {

            std::string current = element->Value();
            if (current == "STATION") {
                for (TiXmlElement *innerElement = element->FirstChildElement();
                     innerElement != NULL; innerElement = innerElement->NextSiblingElement()) {
                    std::string innerCurrent = innerElement->Value();
                    if (innerCurrent == "SPOOR") {
                        ParseSpoor parseSpoor(innerElement);

                        EXPECT_TRUE(parseSpoor.checkValidSpoor()) << "Spoor is not valid \n";
                    }
                }
            }

        }

        doc.Clear();

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/ValidSporen/metroNet" + SSTR(fileCounter) + ".xml";
    }
}

TEST_F(ValidAttributesSpoor, InValidSporen) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/InValidSporen/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        TiXmlElement *root = NULL;
        checkFile(doc, root, fileName);

        MetroNet metroNet;

        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {

            std::string current = element->Value();
            if (current == "STATION") {
                for (TiXmlElement *innerElement = element->FirstChildElement();
                     innerElement != NULL; innerElement = innerElement->NextSiblingElement()) {
                    std::string innerCurrent = innerElement->Value();
                    if (innerCurrent == "SPOOR") {
                        ParseSpoor parseSpoor(innerElement);

                        EXPECT_FALSE(parseSpoor.checkValidSpoor()) << "Spoor is valid but was expected not to \n";
                    }
                }
            }

        }

        doc.Clear();

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/InValidSporen/metroNet" + SSTR(fileCounter) + ".xml";
    }
}