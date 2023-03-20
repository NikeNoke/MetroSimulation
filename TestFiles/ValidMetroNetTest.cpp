#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../Station/Station.h"
#include "../Tram/Tram.h"
#include "../MetroNet/MetroNet.h"
#include<sstream>


class ValidMetroNet : public ::testing::Test {

protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }
    static int amountOfTests;
};

TEST_F(ValidMetroNet, hmm){

}