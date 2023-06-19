//
// Created by byamba on 22/03/23.
//
//#include <iostream>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../MetroNetGenerator/MetroNetGenerator.h"
#include "../Spoor/Spoor.h"

//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


class ValidSimpleExport : public ::testing::Test {

protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {

    }

    std::ostream &getOperationStream(){
        return operation;
    }

    std::ostream &getErrorStream(){
        return error;
    }

    std::ofstream operation;
    std::ofstream error;
};

//Preconditie: MetroNet is Valid!
TEST_F(ValidSimpleExport, ValidExport) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";
    ASSERT_TRUE(Utils::directoryExists("TestInputXML/ValidMetroNet")) << "Directory to test does not exist\n";
    ASSERT_TRUE(Utils::directoryExists("TestOutput")) << "Directory for test output does not exist\n";
    ASSERT_TRUE(Utils::directoryExists("TestOutput/SimpleExport")) << "Directory for test output does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    while (Utils::fileExists(fileName)) {

        std::string outputSimple = "TestOutput/SimpleExport/metroNetTestSpecsSimple" + SSTR(fileCounter) + ".txt";
        std::string outputAdvanced = "TestOutput/SimpleExport/metroNetTestSpecsAdvanced" + SSTR(fileCounter) + ".txt";
        std::string expectedSimple = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + "Simple.txt";
        std::string expectedAdvanced = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + "Advanced.txt";

        std::string opPath = "TestOutput/SimpleExport/operation" + SSTR(fileCounter) + ".txt";
        std::string errPath = "TestOutput/SimpleExport/error" + SSTR(fileCounter) + ".txt";
        operation.open(opPath.c_str());
        error.open(errPath.c_str());

        MetroNetGenerator generator(fileName, outputSimple, outputAdvanced
                , getOperationStream(), getErrorStream());

//        generator.generateMetroNet();
        EXPECT_NO_FATAL_FAILURE(generator.generateMetroNet());
        EXPECT_TRUE(Utils::compareFiles(outputSimple, expectedSimple));
        EXPECT_TRUE(Utils::compareFiles(outputAdvanced, expectedAdvanced));
        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
        operation.close();
        error.close();
    }
}
