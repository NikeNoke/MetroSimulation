#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../Tram/Tram.h"
#include "../MetroNet/MetroNet.h"
#include<sstream>

/**
 * Deze klasse test ofdat elk Tram object een correcte hoeveelheid attributen heeft
 * **/
class ValidAmountAttributesTram : public ::testing::Test {
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


};

TEST_F(ValidAmountAttributesTram, SampleTest1) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet1.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    bool rootNotEmpty = false;
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        EXPECT_EQ(rootNotEmpty, true);
    }
    rootNotEmpty = true;
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);
                //}
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest2) {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);
                //}
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest3) {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);
                //}
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest4) {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);
                //}
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest5) {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);
                //}
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest6) {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest7) {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest8) {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest9) {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest10) {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest11) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet11.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest12) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet12.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest13) {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest14) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet14.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest15) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet15.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest16) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet16.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest17) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet17.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest18) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet18.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest19) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet19.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest20) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet20.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest21) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet21.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest22) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet22.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest23) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet23.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesTram, SampleTest24) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet24.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    attributes.push_back(true);

                } else if (attribute == "beginStation") {
                    attributes.push_back(true);

                } else if (attribute == "snelheid") {
                    attributes.push_back(true);

                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);

            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

