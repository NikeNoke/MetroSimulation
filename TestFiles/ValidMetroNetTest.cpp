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
};

TEST_F(ValidMetroNet, HappyDay){

}

TEST_F(ValidMetroNet, IncorrectStation){

}

TEST_F(ValidMetroNet, IncorrectTram){

}

TEST_F(ValidMetroNet, DoubleStation){

}

TEST_F(ValidMetroNet, WrongStationSpoorNr){

}

TEST_F(ValidMetroNet, WrongTramStation){

}