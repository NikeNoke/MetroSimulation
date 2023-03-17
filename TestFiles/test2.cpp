#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../Station/Station.h"
#include<sstream>


class ValidAmountAttributesStation : public ::testing::Test {
protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }


};

TEST_F(ValidAmountAttributesStation, SampleTest1) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet1.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    const long unsigned Amount_Of_Attributes = 12;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);
                } else if (attribute == "volgende") {
                    attributes.push_back(true);
                } else if (attribute == "vorige") {
                    attributes.push_back(true);
                }
                else if (attribute == "spoorNr"){
                    attributes.push_back(true);
                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());



    doc.Clear();
}
TEST_F(ValidAmountAttributesStation, SampleTest2) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet2.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    const long unsigned Amount_Of_Attributes = 12;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);
                } else if (attribute == "volgende") {
                    attributes.push_back(true);
                } else if (attribute == "vorige") {
                    attributes.push_back(true);
                }
                else if (attribute == "spoorNr"){
                    attributes.push_back(true);
                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());



    doc.Clear();
}
TEST_F(ValidAmountAttributesStation, SampleTest3) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet3.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    const long unsigned Amount_Of_Attributes = 12;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);
                } else if (attribute == "volgende") {
                    attributes.push_back(true);
                } else if (attribute == "vorige") {
                    attributes.push_back(true);
                }
                else if (attribute == "spoorNr"){
                    attributes.push_back(true);
                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());



    doc.Clear();
}
TEST_F(ValidAmountAttributesStation, SampleTest4) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet4.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    const long unsigned Amount_Of_Attributes = 12;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);
                } else if (attribute == "volgende") {
                    attributes.push_back(true);
                } else if (attribute == "vorige") {
                    attributes.push_back(true);
                }
                else if (attribute == "spoorNr"){
                    attributes.push_back(true);
                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());



    doc.Clear();
}
TEST_F(ValidAmountAttributesStation, SampleTest5) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet5.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    const long unsigned Amount_Of_Attributes = 12;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);
                } else if (attribute == "volgende") {
                    attributes.push_back(true);
                } else if (attribute == "vorige") {
                    attributes.push_back(true);
                }
                else if (attribute == "spoorNr"){
                    attributes.push_back(true);
                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());



    doc.Clear();
}
TEST_F(ValidAmountAttributesStation, SampleTest6) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet6.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    const long unsigned Amount_Of_Attributes = 12;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);
                } else if (attribute == "volgende") {
                    attributes.push_back(true);
                } else if (attribute == "vorige") {
                    attributes.push_back(true);
                }
                else if (attribute == "spoorNr"){
                    attributes.push_back(true);
                }
            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());



    doc.Clear();
}
TEST_F(ValidAmountAttributesStation, SampleTest7) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet7.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    const long unsigned Amount_Of_Attributes = 12;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);
                } else if (attribute == "volgende") {
                    attributes.push_back(true);
                } else if (attribute == "vorige") {
                    attributes.push_back(true);
                }
                else if (attribute == "spoorNr"){
                    attributes.push_back(true);
                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());



    doc.Clear();
}
TEST_F(ValidAmountAttributesStation, SampleTest8) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet8.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    const long unsigned Amount_Of_Attributes = 12;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);
                } else if (attribute == "volgende") {
                    attributes.push_back(true);
                } else if (attribute == "vorige") {
                    attributes.push_back(true);
                }
                else if (attribute == "spoorNr"){
                    attributes.push_back(true);
                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());



    doc.Clear();
}
TEST_F(ValidAmountAttributesStation, SampleTest9) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet9.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    const long unsigned Amount_Of_Attributes = 12;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);
                } else if (attribute == "volgende") {
                    attributes.push_back(true);
                } else if (attribute == "vorige") {
                    attributes.push_back(true);
                }
                else if (attribute == "spoorNr"){
                    attributes.push_back(true);
                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());



    doc.Clear();
}
TEST_F(ValidAmountAttributesStation, SampleTest10) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet10.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    const long unsigned Amount_Of_Attributes = 12;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);
                } else if (attribute == "volgende") {
                    attributes.push_back(true);
                } else if (attribute == "vorige") {
                    attributes.push_back(true);
                }
                else if (attribute == "spoorNr"){
                    attributes.push_back(true);
                }
            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());



    doc.Clear();
}