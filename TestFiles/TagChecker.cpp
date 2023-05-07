//
// Created by Thomas on 04/05/2023.
//
#include <iostream>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../ParseXML/ParseMetroNet.h"
#include "../ParseXML/ParseSpoor.h"


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

    bool checkFile(TiXmlDocument &doc, TiXmlElement *&root, const std::string &fileName) {
        bool success = doc.LoadFile(fileName.c_str());
//        ASSERT_TRUE(success) << "The file cannot be opened\n";
        root = doc.FirstChildElement();
        return success;
//        ASSERT_TRUE(root != NULL) << "The root cannot be NULL\n";
    }
};

TEST_F(TagChecker, InValidFile){
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/InValidFile/metroNet" + SSTR(fileCounter) + ".xml";

    while (Utils::fileExists(fileName)) {
        TiXmlDocument doc;
        TiXmlElement *root = NULL;
        EXPECT_FALSE(checkFile(doc, root, fileName)) << "The file should not be opened\n";
        MetroNet metroNet;
        doc.Clear();
        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/InValidFile/metroNet" + SSTR(fileCounter) + ".xml";
    };
}