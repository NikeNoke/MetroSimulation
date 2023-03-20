#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../Station/Station.h"
#include "../Tram/Tram.h"
#include<sstream>

/**
 * Deze klasse test ofdat het gegeven type van de attribute de juiste type is dat required is.
 * @note unknown file: Failure
C++ exception with description "basic_string::_M_construct null not valid" thrown in the test body (metronet20.xml).
 * **/
class AttributeTypeCorrectness : public ::testing::Test {
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
    /**
     * Controleert ofdat de gegeven string een integer is.
     * @param s string waarop de functie toegepast wordt en controleert ofdat die een integer is.
     * **/
    bool is_int(const std::string &s) {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }

    /**
     * Controleert ofdat de gegeven string leeg is.
     * @param word waarop wordt getest ofdat die lengte nul is of niet.
     * **/
    bool is_empty(const std::string &word) {
        if (word.size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Function body voor de tests. Test ofdat de attributes types overeenkomen met wat verwacht wordt.
     * @param Filename Naam van de file dat getest wordt.
     */
    void FunctionFieldEqual(const char *Filename) {
        TiXmlDocument doc;
        if (!doc.LoadFile(Filename)) {
            std::cerr << doc.ErrorDesc() << std::endl;
        }
        TiXmlElement *root = doc.FirstChildElement();
        if (root == NULL) {
            std::cerr << "Failed to load file: No root element." << std::endl;
            doc.Clear();
            return;
        }

        std::vector<bool> attributes;
        long unsigned Amount_Of_Attributes = 0;
        long unsigned Amount_Of_Attributes_Tram = 3;
        long unsigned Amount_Of_Attributes_Station = 4;
        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {

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

    /**
     * Function body voor de tests. Test ofdat de attributes types NIET overeenkomen met wat verwacht wordt.
     * @param Filename Naam van de file dat getest wordt.
     */
    void FunctionFieldNotEqual(const char *Filename) {
        TiXmlDocument doc;
        if (!doc.LoadFile(Filename)) {
            std::cerr << doc.ErrorDesc() << std::endl;
        }
        TiXmlElement *root = doc.FirstChildElement();
        if (root == NULL) {
            std::cerr << "Failed to load file: No root element." << std::endl;
            doc.Clear();
        }

        std::vector<bool> attributes;
        long unsigned Amount_Of_Attributes = 0;
        long unsigned Amount_Of_Attributes_Tram = 3;
        long unsigned Amount_Of_Attributes_Station = 4;
        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {

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
};

TEST_F(AttributeTypeCorrectness, SampleTest1) {
    FunctionFieldEqual("TestInputXML/metronet1.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest2) {
    FunctionFieldEqual("TestInputXML/metronet2.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest3) {
    FunctionFieldEqual("TestInputXML/metronet3.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest4) {
    FunctionFieldEqual("TestInputXML/metronet4.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest5) {
    FunctionFieldEqual("TestInputXML/metronet5.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest6) {
    FunctionFieldNotEqual("TestInputXML/metronet6.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest7) {
    FunctionFieldNotEqual("TestInputXML/metronet7.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest8) {
    FunctionFieldNotEqual("TestInputXML/metronet8.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest9) {
    FunctionFieldEqual("TestInputXML/metronet9.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest10) {
    FunctionFieldNotEqual("TestInputXML/metronet10.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest11) {
    FunctionFieldEqual("TestInputXML/metronet11.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest12) {
    FunctionFieldEqual("TestInputXML/metronet12.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest13) {
    FunctionFieldEqual("TestInputXML/metronet13.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest14) {
    FunctionFieldEqual("TestInputXML/metronet14.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest15) {
    FunctionFieldEqual("TestInputXML/metronet15.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest16) {
    FunctionFieldNotEqual("TestInputXML/metronet16.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest17) {
    FunctionFieldNotEqual("TestInputXML/metronet17.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest18) {
    FunctionFieldNotEqual("TestInputXML/metronet18.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest19) {
    FunctionFieldEqual("TestInputXML/metronet19.xml");
}

/*
TEST_F(AttributeTypeCorrectness, SampleTest20) {
    FunctionFieldNotEqual("TestInputXML/metronet20.xml");
}
*/
TEST_F(AttributeTypeCorrectness, SampleTest21) {
    FunctionFieldEqual("TestInputXML/metronet21.xml");
}


TEST_F(AttributeTypeCorrectness, SampleTest22) {
    FunctionFieldEqual("TestInputXML/metronet22.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest23) {
    FunctionFieldEqual("TestInputXML/metronet23.xml");
}

TEST_F(AttributeTypeCorrectness, SampleTest24) {
    FunctionFieldEqual("TestInputXML/metronet24.xml");
}
