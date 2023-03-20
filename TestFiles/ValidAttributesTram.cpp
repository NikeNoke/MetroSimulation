#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../Tram/Tram.h"
#include<sstream>

/**
 * Deze klasse test ofdat elk Tram object een correcte hoeveelheid attributen heeft
 * **/
class ValidAttributesTram : public ::testing::Test {
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
     * Function body voor de tests. Test ofdat de hoeveelheid attributes overeenkomen met wat verwacht wordt.
     * @param Filename Naam van de file dat getest wordt.
     */
    static void FunctionFieldEqual(const char *FileName) {
        TiXmlDocument doc;
        if (!doc.LoadFile(FileName)) {
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
        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {

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

    /**
     * Function body voor de tests. Test ofdat de hoeveelheid attributes NIET overeenkomen met wat verwacht wordt.
     * @param Filename Naam van de file dat getest wordt.
     */
    static void FunctionFieldNotEqual(const char *FileName) {
        TiXmlDocument doc;
        if (!doc.LoadFile(FileName)) {
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
        for (TiXmlElement *element = root->FirstChildElement();
             element != NULL; element = element->NextSiblingElement()) {

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
        EXPECT_NE(Amount_Of_Attributes, attributes.size());


        doc.Clear();
    }
};

TEST_F(ValidAttributesTram, HappyDay) {
    FunctionFieldEqual("TestInputXML/metronet1.xml");
}

TEST_F(ValidAttributesTram, IncorrectBeginStation) {
    FunctionFieldEqual("TestInputXML/metronet2.xml");
}

TEST_F(ValidAttributesTram, IncorrectLijnNr) {
    FunctionFieldEqual("TestInputXML/metronet3.xml");
}

TEST_F(ValidAttributesTram, IncorrectSnelheid) {
    FunctionFieldEqual("TestInputXML/metronet4.xml");
}

TEST_F(ValidAttributesTram, TooMuchAttributes) {
    FunctionFieldEqual("TestInputXML/metronet5.xml");
}

TEST_F(ValidAttributesTram, TooFewAttributes) {
    FunctionFieldEqual("TestInputXML/metronet6.xml");
}

TEST_F(ValidAttributesTram, SampleTest7) {
    FunctionFieldNotEqual("TestInputXML/metronet7.xml");
}

TEST_F(ValidAttributesTram, SampleTest8) {
    FunctionFieldNotEqual("TestInputXML/metronet8.xml");
}

TEST_F(ValidAttributesTram, SampleTest9) {
    FunctionFieldEqual("TestInputXML/metronet9.xml");
}

TEST_F(ValidAttributesTram, SampleTest10) {
    FunctionFieldEqual("TestInputXML/metronet10.xml");
}

TEST_F(ValidAttributesTram, SampleTest11) {
    FunctionFieldEqual("TestInputXML/metronet11.xml");
}

TEST_F(ValidAttributesTram, SampleTest12) {
    FunctionFieldEqual("TestInputXML/metronet12.xml");
}

TEST_F(ValidAttributesTram, SampleTest13) {
    FunctionFieldEqual("TestInputXML/metronet13.xml");
}

TEST_F(ValidAttributesTram, SampleTest14) {
    FunctionFieldEqual("TestInputXML/metronet14.xml");
}

TEST_F(ValidAttributesTram, SampleTest15) {
    FunctionFieldEqual("TestInputXML/metronet15.xml");
}

TEST_F(ValidAttributesTram, SampleTest16) {
    FunctionFieldNotEqual("TestInputXML/metronet16.xml");
}

TEST_F(ValidAttributesTram, SampleTest17) {
    FunctionFieldNotEqual("TestInputXML/metronet17.xml");
}

TEST_F(ValidAttributesTram, SampleTest18) {
    FunctionFieldEqual("TestInputXML/metronet18.xml");
}

TEST_F(ValidAttributesTram, SampleTest19) {
    FunctionFieldEqual("TestInputXML/metronet19.xml");
}

TEST_F(ValidAttributesTram, SampleTest20) {
    FunctionFieldEqual("TestInputXML/metronet20.xml");
}

TEST_F(ValidAttributesTram, SampleTest21) {
    FunctionFieldEqual("TestInputXML/metronet21.xml");
}

TEST_F(ValidAttributesTram, SampleTest22) {
    FunctionFieldEqual("TestInputXML/metronet22.xml");
}

TEST_F(ValidAttributesTram, SampleTest23) {
    FunctionFieldEqual("TestInputXML/metronet23.xml");
}

TEST_F(ValidAttributesTram, SampleTest24) {
    FunctionFieldEqual("TestInputXML/metronet24.xml");
}
