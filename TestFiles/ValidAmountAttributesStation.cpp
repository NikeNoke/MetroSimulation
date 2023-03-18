#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../Station/Station.h"
#include<sstream>

/**
 * Deze klasse test ofdat elk Station object een correcte hoeveelheid attributen heeft
 * **/
class ValidAmountAttributesStation : public ::testing::Test {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
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
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesStation, SampleTest11) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesStation, SampleTest12) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesStation, SampleTest13) {
    TiXmlDocument doc;
    if (!doc.LoadFile("../XMLexamples/metronet13.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesStation, SampleTest14) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesStation, SampleTest15) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesStation, SampleTest16) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesStation, SampleTest17) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesStation, SampleTest18) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesStation, SampleTest19) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesStation, SampleTest20) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesStation, SampleTest21) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesStation, SampleTest22) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesStation, SampleTest23) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(ValidAmountAttributesStation, SampleTest24) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    attributes.push_back(true);

                } else if (attribute == "volgende") {
                    attributes.push_back(true);

                } else if (attribute == "vorige") {
                    attributes.push_back(true);

                } else if (attribute == "spoorNr") {
                    attributes.push_back(true);

                }
            }

        }

    }
    EXPECT_EQ(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}
