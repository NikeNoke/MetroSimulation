#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../Station/Station.h"
#include "../MetroNet/MetroNet.h"
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

    /**
     * Function body voor de tests. Test ofdat de hoeveelheid attributes overeenkomen met wat verwacht wordt.
     * @param Filename Naam van de file dat getest wordt.
     */
    static void FunctionFieldEqual(const char *Filename){
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

    /**
     * Function body voor de tests. Test ofdat de hoeveelheid attributes NIET overeenkomen met wat verwacht wordt.
     * @param Filename Naam van de file dat getest wordt.
     */
    static void FunctionFieldNotEqual(const char *Filename){
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
};

TEST_F(ValidAmountAttributesStation, SampleTest1) {
    FunctionFieldEqual("XMLexamples/metronet1.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest2) {
    FunctionFieldEqual("XMLexamples/metronet2.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest3) {
    FunctionFieldEqual("XMLexamples/metronet3.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest4) {
    FunctionFieldEqual("XMLexamples/metronet4.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest5) {
    FunctionFieldEqual("XMLexamples/metronet5.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest6) {
    FunctionFieldNotEqual("XMLexamples/metronet6.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest7) {
    FunctionFieldEqual("XMLexamples/metronet7.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest8) {
    FunctionFieldEqual("XMLexamples/metronet8.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest9) {
    FunctionFieldEqual("XMLexamples/metronet9.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest10) {
    FunctionFieldNotEqual("XMLexamples/metronet10.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest11) {
    FunctionFieldEqual("XMLexamples/metronet11.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest12) {
    FunctionFieldEqual("XMLexamples/metronet12.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest13) {
    FunctionFieldEqual("XMLexamples/metronet13.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest14) {
    FunctionFieldEqual("XMLexamples/metronet14.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest15) {
    FunctionFieldEqual("XMLexamples/metronet15.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest16) {
    FunctionFieldEqual("XMLexamples/metronet16.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest17) {
    FunctionFieldEqual("XMLexamples/metronet17.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest18) {
    FunctionFieldNotEqual("XMLexamples/metronet18.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest19) {
    FunctionFieldEqual("XMLexamples/metronet19.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest20) {
    FunctionFieldEqual("XMLexamples/metronet20.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest21) {
    FunctionFieldEqual("XMLexamples/metronet21.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest22) {
    FunctionFieldEqual("XMLexamples/metronet22.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest23) {
    FunctionFieldEqual("XMLexamples/metronet23.xml");
}
TEST_F(ValidAmountAttributesStation, SampleTest24) {
    FunctionFieldEqual("XMLexamples/metronet24.xml");
}
