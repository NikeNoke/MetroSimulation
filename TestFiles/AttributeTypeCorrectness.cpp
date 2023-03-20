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


class AttributeTypeCorrectness : public ::testing::Test {
protected:
    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

    bool is_int(const std::string &s) {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }


};

TEST_F(AttributeTypeCorrectness, SampleTest1) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet1.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement *root = doc.FirstChildElement();
    bool rootNotEmpty = root != NULL;
    ASSERT_EQ(rootNotEmpty, true) << "The root is empty";
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }
    MetroNet metroNet;
    std::vector<bool> attributes;
    long unsigned Amount_Of_Attributes = 0;
    long unsigned Amount_Of_Attributes_Tram = 3;
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);

                    }
                } else if (attribute == "volgende") {
                    
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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

TEST_F(AttributeTypeCorrectness, SampleTest2) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet2.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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

TEST_F(AttributeTypeCorrectness, SampleTest3) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet3.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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

TEST_F(AttributeTypeCorrectness, SampleTest4) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet4.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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

TEST_F(AttributeTypeCorrectness, SampleTest5) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet5.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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

TEST_F(AttributeTypeCorrectness, SampleTest6) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet6.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);
                //}
            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(AttributeTypeCorrectness, SampleTest7) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet7.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);
                //}
            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(AttributeTypeCorrectness, SampleTest8) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet8.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);
                //}
            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}

TEST_F(AttributeTypeCorrectness, SampleTest9) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet9.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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

TEST_F(AttributeTypeCorrectness, SampleTest10) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet10.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);
                //}
            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}
TEST_F(AttributeTypeCorrectness, SampleTest11) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet11.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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
TEST_F(AttributeTypeCorrectness, SampleTest12) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet12.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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
TEST_F(AttributeTypeCorrectness, SampleTest13) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet13.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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
TEST_F(AttributeTypeCorrectness, SampleTest14) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet14.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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
TEST_F(AttributeTypeCorrectness, SampleTest15) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet15.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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
TEST_F(AttributeTypeCorrectness, SampleTest16) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet16.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);
                //}
            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}
TEST_F(AttributeTypeCorrectness, SampleTest17) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet17.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);
                //}
            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}
TEST_F(AttributeTypeCorrectness, SampleTest18) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet18.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);
                //}
            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}
TEST_F(AttributeTypeCorrectness, SampleTest19) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet19.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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
TEST_F(AttributeTypeCorrectness, SampleTest20) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet20.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
                //else if (attribute == "huidigstation"){
                //    attributes.push_back(true);
                //}
            }

        }

    }
    EXPECT_NE(Amount_Of_Attributes, attributes.size());


    doc.Clear();
}
TEST_F(AttributeTypeCorrectness, SampleTest21) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet21.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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
TEST_F(AttributeTypeCorrectness, SampleTest22) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet22.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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
TEST_F(AttributeTypeCorrectness, SampleTest23) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet23.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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
TEST_F(AttributeTypeCorrectness, SampleTest24) {
    TiXmlDocument doc;
    if (!doc.LoadFile("XMLexamples/metronet24.xml")) {
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
    long unsigned Amount_Of_Attributes_Station = 4;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            Amount_Of_Attributes += Amount_Of_Attributes_Station;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "spoorNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                }
            }

        } else if (current == "TRAM") {
            Amount_Of_Attributes += Amount_Of_Attributes_Tram;
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if (!is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if (is_int(inner->GetText())) {
                        attributes.push_back(true);
                    }
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