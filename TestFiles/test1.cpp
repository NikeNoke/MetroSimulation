#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>


class ValidTram : public ::testing::Test {
protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }


};

TEST_F(ValidTram, SampleTest1) {

    TiXmlDocument doc;
    if (!doc.LoadFile("metronet.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return 1;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return 1;
    }
    MetroNet metroNet;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();
        if (current == "STATION") {

            Utils::parseStation(metroNet, element);

        } else if (current == "TRAM") {

            Utils::parseTram(metroNet, element);

        } else {
            std::cerr << "Deze element is ongekend!\n";
        }
    }

    doc.Clear();




}
