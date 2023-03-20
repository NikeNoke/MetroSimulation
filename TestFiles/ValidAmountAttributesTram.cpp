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

TEST_F(ValidAmountAttributesTram, SampleTest1) {
    FunctionFieldEqual("XMLexamples/metronet1.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest2) {
    FunctionFieldEqual("XMLexamples/metronet2.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest3) {
    FunctionFieldEqual("XMLexamples/metronet3.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest4) {
    FunctionFieldEqual("XMLexamples/metronet4.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest5) {
    FunctionFieldEqual("XMLexamples/metronet5.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest6) {
    FunctionFieldEqual("XMLexamples/metronet6.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest7) {
    FunctionFieldNotEqual("XMLexamples/metronet7.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest8) {
    FunctionFieldNotEqual("XMLexamples/metronet8.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest9) {
    FunctionFieldEqual("XMLexamples/metronet9.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest10) {
    FunctionFieldEqual("XMLexamples/metronet10.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest11) {
    FunctionFieldEqual("XMLexamples/metronet11.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest12) {
    FunctionFieldEqual("XMLexamples/metronet12.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest13) {
    FunctionFieldEqual("XMLexamples/metronet13.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest14) {
    FunctionFieldEqual("XMLexamples/metronet14.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest15) {
    FunctionFieldEqual("XMLexamples/metronet15.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest16) {
    FunctionFieldNotEqual("XMLexamples/metronet16.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest17) {
    FunctionFieldNotEqual("XMLexamples/metronet17.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest18) {
    FunctionFieldEqual("XMLexamples/metronet18.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest19) {
    FunctionFieldEqual("XMLexamples/metronet19.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest20) {
    FunctionFieldEqual("XMLexamples/metronet20.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest21) {
    FunctionFieldEqual("XMLexamples/metronet21.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest22) {
    FunctionFieldEqual("XMLexamples/metronet22.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest23) {
    FunctionFieldEqual("XMLexamples/metronet23.xml");
}

TEST_F(ValidAmountAttributesTram, SampleTest24) {
    FunctionFieldEqual("XMLexamples/metronet24.xml");
}
