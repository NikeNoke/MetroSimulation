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
//        operation.open("TestOutput/OperationLog.txt");
//        error.open("TestOutput/ErrorLog.txt");
    }

    virtual void TearDown() {

    }
    std::ostream &getOperationStream(){
        return operation;
    }

    std::ostream &getErrorStream(){
        return error;
    }

    void inValid(const std::string& directory){
        ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";
        ASSERT_TRUE(Utils::directoryExists("TestInputXML/" + directory)) << "Directory to test does not exist\n";
        ASSERT_TRUE(Utils::directoryExists("TestOutput")) << "Directory for test output does not exist\n";
        ASSERT_TRUE(Utils::directoryExists("TestOutput/" + directory)) << "Directory for test output does not exist\n";

        int fileCounter = 0;
        std::string fileName = "TestInputXML/" + directory + "/metroNet" + SSTR(fileCounter) + ".xml";
        while (Utils::fileExists(fileName)) {

            std::string outputSimple = "TestOutput/" + directory +"/metroNetTestSpecsSimple" + SSTR(fileCounter) + ".txt";
            std::string outputAdvanced = "TestOutput/" + directory + "/metroNetTestSpecsAdvanced" + SSTR(fileCounter) + ".txt";
            std::string expectedErr = "TestInputXML/" + directory + "/metroNetErr" + SSTR(fileCounter) + ".txt";

            std::string opPath = "TestOutput/" + directory + "/operation" + SSTR(fileCounter) + ".txt";
            std::string errPath = "TestOutput/" + directory + "/error" + SSTR(fileCounter) + ".txt";
            operation.open(opPath.c_str());
            error.open(errPath.c_str());

            MetroNetGenerator generator(fileName, outputSimple, outputAdvanced
                    , getOperationStream(), getErrorStream());

//        generator.generateMetroNet();
            EXPECT_DEATH(generator.generateMetroNet(), "The metroNet is not valid");
            EXPECT_TRUE(Utils::FileCompare(errPath, expectedErr));
            fileCounter = fileCounter + 1;
            fileName = "TestInputXML/" + directory + "/metroNet" + SSTR(fileCounter) + ".xml";
            operation.close();
            error.close();
        }
    }

    std::ofstream operation;
    std::ofstream error;
};

//Preconditie: Stations and Trams are correct!
TEST_F(ValidMetroNet, ValidMetroNet) {
    ASSERT_TRUE(Utils::directoryExists("TestInputXML")) << "Directory to test does not exist\n";
    ASSERT_TRUE(Utils::directoryExists("TestInputXML/ValidMetroNet")) << "Directory to test does not exist\n";
    ASSERT_TRUE(Utils::directoryExists("TestOutput")) << "Directory for test output does not exist\n";

    int fileCounter = 0;
    std::string fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    std::string output = "TestOutput/metroNetTestSpecs.txt";

    while (Utils::fileExists(fileName)) {
        MetroNetGenerator generator(fileName, output, output, getOperationStream(), getErrorStream());

        EXPECT_NO_FATAL_FAILURE(generator.generateMetroNet(true)) << "The metroNet was not Valid!\n";

        fileCounter = fileCounter + 1;
        fileName = "TestInputXML/ValidMetroNet/metroNet" + SSTR(fileCounter) + ".xml";
    }

}

TEST_F(ValidMetroNet, InValidMetroNet) {
    inValid("InValidMetroNet");
}

TEST_F(ValidMetroNet, InValidTrams) {
    inValid("InValidTram");
}

TEST_F(ValidMetroNet, InValidStations){
    inValid("InValidStation");
}

TEST_F(ValidMetroNet, InValidSpoor){
    inValid("InValidSpoor");
}