#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../Station/Station.h"
#include "../Tram/Tram.h"
#include<sstream>


class AttributeCorrectness : public ::testing::Test {
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

TEST_F(AttributeCorrectness, SampleTest1) {
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
    const long unsigned Amount_Of_Attributes = 15;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
                else if (attribute == "spoorNr"){
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
            }

        }
        else if (current == "TRAM") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if(is_int(inner->GetText())){
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
TEST_F(AttributeCorrectness, SampleTest2) {
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
    const long unsigned Amount_Of_Attributes = 15;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
                else if (attribute == "spoorNr"){
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
            }

        }
        else if (current == "TRAM") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if(is_int(inner->GetText())){
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
TEST_F(AttributeCorrectness, SampleTest3) {
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
    const long unsigned Amount_Of_Attributes = 15;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
                else if (attribute == "spoorNr"){
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
            }

        }
        else if (current == "TRAM") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if(is_int(inner->GetText())){
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
TEST_F(AttributeCorrectness, SampleTest4) {
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
    const long unsigned Amount_Of_Attributes = 15;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
                else if (attribute == "spoorNr"){
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
            }

        }
        else if (current == "TRAM") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if(is_int(inner->GetText())){
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
TEST_F(AttributeCorrectness, SampleTest5) {
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
    const long unsigned Amount_Of_Attributes = 15;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
                else if (attribute == "spoorNr"){
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
            }

        }
        else if (current == "TRAM") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if(is_int(inner->GetText())){
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
TEST_F(AttributeCorrectness, SampleTest6) {
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
    const long unsigned Amount_Of_Attributes = 15;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
                else if (attribute == "spoorNr"){
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
            }

        }
        else if (current == "TRAM") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if(is_int(inner->GetText())){
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
TEST_F(AttributeCorrectness, SampleTest7) {
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
    const long unsigned Amount_Of_Attributes = 15;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
                else if (attribute == "spoorNr"){
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
            }

        }
        else if (current == "TRAM") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if(is_int(inner->GetText())){
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
TEST_F(AttributeCorrectness, SampleTest8) {
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
    const long unsigned Amount_Of_Attributes = 15;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
                else if (attribute == "spoorNr"){
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
            }

        }
        else if (current == "TRAM") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if(is_int(inner->GetText())){
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
TEST_F(AttributeCorrectness, SampleTest9) {
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
    const long unsigned Amount_Of_Attributes = 15;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
                else if (attribute == "spoorNr"){
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
            }

        }
        else if (current == "TRAM") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if(is_int(inner->GetText())){
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
TEST_F(AttributeCorrectness, SampleTest10) {
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
    const long unsigned Amount_Of_Attributes = 15;
    for (TiXmlElement *element = root->FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {

        std::string current = element->Value();

        if (current == "STATION") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "naam") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "volgende") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "vorige") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
                else if (attribute == "spoorNr"){
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                }
            }

        }
        else if (current == "TRAM") {
            for (TiXmlElement *inner = element->FirstChildElement();
                 inner != NULL; inner = inner->NextSiblingElement()) {
                std::string attribute = inner->Value();
                if (attribute == "lijnNr") {
                    if(is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "beginStation") {
                    if(!is_int(inner->GetText())){
                        attributes.push_back(true);
                    }
                } else if (attribute == "snelheid") {
                    if(is_int(inner->GetText())){
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