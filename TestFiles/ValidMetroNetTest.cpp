#include <iostream>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../ParseXML/ParseTram.h"
#include "../MetroNetGenerator/MetroNetGenerator.h"

//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


class ValidMetroNet : public ::testing::Test {

protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }
};

//Preconditie: Stations and Trams are correct!
TEST_F(ValidMetroNet, ValidMetroNet) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    std::string output = "TestOutput/metroNetTestSpecs.txt";

    while (Utils::fileExists(fileName)) {
        MetroNetGenerator generator(fileName, output);

        EXPECT_NO_FATAL_FAILURE(generator.generateMetroNet()) << "The metroNet was not Valid!\n";

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    }

}

//Preconditie: Stations and Trams are correct!
TEST_F(ValidMetroNet, InValidMetroNet) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/InValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    std::string output = "TestOutput/metroNetTestSpecs.txt";

    while (Utils::fileExists(fileName)) {

        MetroNetGenerator generator(fileName, output);

        EXPECT_DEATH(generator.generateMetroNet(), "c") << "The metroNet was Valid\n";

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/InValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    }
}
