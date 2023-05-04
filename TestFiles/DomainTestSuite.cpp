//
// Created by Thomas on 04/05/2023.
//
#include <iostream>
#include <gtest/gtest.h>
#include "../TinyXML/tinyxml.h"
#include "../Utils/utils.h"
#include "../ParseXML/ParseTram.h"
#include "../ParseXML/ParseMetroNet.h"
#include "../ParseXML/ParseSpoor.h"
#include "../ParseXML/ParseStation.h"
#include "../Trams/AlbatrosTram.h"
#include "../Trams/PCCTram.h"
#include "../Trams/StadslijnerTram.h"
#include "../MetroNet/MetroNet.h"
#include "../Stations/Station.h"
#include "../Stations/MetronetStation.h"
#include "../Stations/HalteStation.h"

//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
#define SSTR(x) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

/**
 * Deze klasse test de logica van objecten in een MetroNet.
 * **/
class DomainTests : public ::testing::Test {
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

    void checkFile(TiXmlDocument &doc, TiXmlElement *&root, const std::string &fileName) {
        ASSERT_TRUE(doc.LoadFile(fileName.c_str())) << "The file cannot be opened\n";
        root = doc.FirstChildElement();
        ASSERT_TRUE(root != NULL) << "The root cannot be NULL\n";
    }

protected:
    friend class MetroNet;

    friend class AlbatrosTram;

    friend class PCCTram;

    friend class StadslijnerTram;

    friend class HalteStation;

    friend class MetronetStation;

    MetroNet testMetronet;
    HalteStation testHalteStation;
    MetronetStation testMetronetStation;
    PCCTram testPCCTram;
    AlbatrosTram testAlbatrosTram;
    StadslijnerTram testStadslijnerTram;
};


TEST_F(DomainTests, DefaultConstructors) {
    EXPECT_TRUE(testMetronet.properlyInitialized()) << "Default constructor for Metronet failed\n";
    EXPECT_TRUE(testHalteStation.properlyInitialized()) << "Default constructor for HalteStation failed\n";
    EXPECT_TRUE(testMetronetStation.properlyInitialized()) << "Default constructor for MetronetStation failed\n";
    EXPECT_TRUE(testPCCTram.properlyInitialized()) << "Default constructor for PCCTram failed\n";
    EXPECT_TRUE(testAlbatrosTram.properlyInitialized()) << "Default constructor for AlbatrosTram failed\n";
    EXPECT_TRUE(testStadslijnerTram.properlyInitialized()) << "Default constructor for StadslijnerTram failed\n";
}

TEST_F(DomainTests, MoveTramsAndSetterTest) {
    MetroNet *Metro = new MetroNet();
    MetronetStation *MetronetStation1 = new MetronetStation();
    MetronetStation1->setType("Metrostation");
    MetronetStation1->setName("A");
    MetronetStation *MetronetStation2 = new MetronetStation();
    MetronetStation2->setType("Metrostation");
    MetronetStation2->setName("B");
    MetronetStation *MetronetStation3 = new MetronetStation();
    MetronetStation3->setType("Metrostation");
    MetronetStation3->setName("C");
    Spoor *MetroSpoora1 = new Spoor("C", "B", 12);
    Spoor *MetroSpoorb1 = new Spoor("A", "C", 12);
    Spoor *MetroSpoorc1 = new Spoor("B", "A", 12);
    Spoor *MetroSpoora2 = new Spoor("B", "C", 21);
    Spoor *MetroSpoorb2 = new Spoor("C", "A", 21);
    Spoor *MetroSpoorc2 = new Spoor("A", "B", 21);
    MetronetStation1->addSpoor(MetroSpoora1);
    MetronetStation1->addSpoor(MetroSpoora2);
    MetronetStation2->addSpoor(MetroSpoorb1);
    MetronetStation2->addSpoor(MetroSpoorb2);
    MetronetStation3->addSpoor(MetroSpoorc1);
    MetronetStation3->addSpoor(MetroSpoorc2);
    HalteStation *HalteStation1 = new HalteStation();
    HalteStation1->setType("Halte");
    HalteStation1->setName("X");
    HalteStation *HalteStation2 = new HalteStation();
    HalteStation2->setType("Halte");
    HalteStation2->setName("Y");
    HalteStation *HalteStation3 = new HalteStation();
    HalteStation3->setType("Halte");
    HalteStation3->setName("Z");
    Spoor *HalteSpoorx1 = new Spoor("Z", "Y", 23);
    Spoor *HalteSpoory1 = new Spoor("X", "Z", 23);
    Spoor *HalteSpoorz1 = new Spoor("Y", "X", 23);
    Spoor *HalteSpoorx2 = new Spoor("Y", "Z", 32);
    Spoor *HalteSpoory2 = new Spoor("Z", "X", 32);
    Spoor *HalteSpoorz2 = new Spoor("X", "Y", 32);
    HalteStation1->addSpoor(HalteSpoorx1);
    HalteStation1->addSpoor(HalteSpoorx2);
    HalteStation2->addSpoor(HalteSpoory1);
    HalteStation2->addSpoor(HalteSpoory2);
    HalteStation3->addSpoor(HalteSpoorz1);
    HalteStation3->addSpoor(HalteSpoorz2);
    PCCTram *PCCTram = new class PCCTram();
    PCCTram->setLijnNr(23);
    PCCTram->setType("PCC");
    PCCTram->setVoertuigNummer(1);
    PCCTram->setBeginStation("X");
    PCCTram->setHuidigStation("X");
    PCCTram->setAantalDefecten(0);
    PCCTram->setReparatieTijd(0);
    PCCTram->setReparatieKost(0);
    AlbatrosTram *AlbatrosTram = new class AlbatrosTram();
    AlbatrosTram->setLijnNr(12);
    AlbatrosTram->setType("Albatros");
    AlbatrosTram->setVoertuigNummer(5);
    AlbatrosTram->setBeginStation("A");
    AlbatrosTram->setHuidigStation("A");
    StadslijnerTram *stadslijnerTram = new class StadslijnerTram();
    stadslijnerTram->setLijnNr(21);
    stadslijnerTram->setType("Stadslijner");
    stadslijnerTram->setVoertuigNummer(6);
    stadslijnerTram->setBeginStation("A");
    stadslijnerTram->setHuidigStation("A");
    Metro->addStation(MetronetStation1);
    Metro->addStation(MetronetStation2);
    Metro->addStation(MetronetStation3);
    Metro->addStation(HalteStation1);
    Metro->addStation(HalteStation2);
    Metro->addStation(HalteStation3);
    Metro->addTram(PCCTram);
    Metro->addTram(AlbatrosTram);
    Metro->addTram(stadslijnerTram);
    EXPECT_TRUE(Metro->getTrams().size() == 3);
    EXPECT_TRUE(Metro->getStations().size() == 6);
    EXPECT_TRUE(Metro->stationRegistered(MetronetStation1->getName()));
    EXPECT_TRUE(Metro->stationRegistered(MetronetStation2->getName()));
    EXPECT_TRUE(Metro->stationRegistered(MetronetStation3->getName()));
    EXPECT_TRUE(Metro->stationRegistered(HalteStation1->getName()));
    EXPECT_TRUE(Metro->stationRegistered(HalteStation2->getName()));
    EXPECT_TRUE(Metro->stationRegistered(HalteStation3->getName()));
    EXPECT_NO_FATAL_FAILURE(Metro->_moveTest(PCCTram, HalteStation2->getName()));
    EXPECT_NO_FATAL_FAILURE(Metro->_moveTest(AlbatrosTram, MetronetStation2->getName()));
    EXPECT_NO_FATAL_FAILURE(Metro->_moveTest(stadslijnerTram, MetronetStation3->getName()));
    EXPECT_TRUE(PCCTram->getHuidigStation() == "Y");
    EXPECT_TRUE(AlbatrosTram->getHuidigStation() == "B");
    EXPECT_TRUE(stadslijnerTram->getHuidigStation() == "C");
}


TEST_F(DomainTests, ContractViolations) {
    MetroNet *Metro = new MetroNet();
    MetronetStation *MetronetStation1 = new MetronetStation();
    MetronetStation1->setType("Metrostation");
    MetronetStation1->setName("A");
    MetronetStation *MetronetStation2 = new MetronetStation();
    MetronetStation2->setType("Metrostation");
    MetronetStation2->setName("B");
    MetronetStation *MetronetStation3 = new MetronetStation();
    MetronetStation3->setType("Metrostation");
    MetronetStation3->setName("C");
    Spoor *MetroSpoora1 = new Spoor("C", "B", 12);
    Spoor *MetroSpoorb1 = new Spoor("A", "C", 12);
    Spoor *MetroSpoorc1 = new Spoor("B", "A", 12);
    Spoor *MetroSpoora2 = new Spoor("B", "C", 21);
    Spoor *MetroSpoorb2 = new Spoor("C", "A", 21);
    Spoor *MetroSpoorc2 = new Spoor("A", "B", 21);
    MetronetStation1->addSpoor(MetroSpoora1);
    MetronetStation1->addSpoor(MetroSpoora2);
    MetronetStation2->addSpoor(MetroSpoorb1);
    MetronetStation2->addSpoor(MetroSpoorb2);
    MetronetStation3->addSpoor(MetroSpoorc1);
    MetronetStation3->addSpoor(MetroSpoorc2);
    HalteStation *HalteStation1 = new HalteStation();
    HalteStation1->setType("Halte");
    HalteStation1->setName("X");
    HalteStation *HalteStation2 = new HalteStation();
    HalteStation2->setType("Halte");
    HalteStation2->setName("Y");
    HalteStation *HalteStation3 = new HalteStation();
    HalteStation3->setType("Halte");
    HalteStation3->setName("Z");
    Spoor *HalteSpoorx1 = new Spoor("Z", "Y", 23);
    Spoor *HalteSpoory1 = new Spoor("X", "Z", 23);
    Spoor *HalteSpoorz1 = new Spoor("Y", "X", 23);
    Spoor *HalteSpoorx2 = new Spoor("Y", "Z", 32);
    Spoor *HalteSpoory2 = new Spoor("Z", "X", 32);
    Spoor *HalteSpoorz2 = new Spoor("X", "Y", 32);
    HalteStation1->addSpoor(HalteSpoorx1);
    HalteStation1->addSpoor(HalteSpoorx2);
    HalteStation2->addSpoor(HalteSpoory1);
    HalteStation2->addSpoor(HalteSpoory2);
    HalteStation3->addSpoor(HalteSpoorz1);
    HalteStation3->addSpoor(HalteSpoorz2);
    PCCTram *PCCTram = new class PCCTram();
    PCCTram->setLijnNr(23);
    PCCTram->setType("PCC");
    PCCTram->setVoertuigNummer(1);
    PCCTram->setBeginStation("X");
    PCCTram->setHuidigStation("X");
    PCCTram->setAantalDefecten(0);
    PCCTram->setReparatieTijd(0);
    PCCTram->setReparatieKost(0);
    AlbatrosTram *AlbatrosTram = new class AlbatrosTram();
    AlbatrosTram->setLijnNr(12);
    AlbatrosTram->setType("Albatros");
    AlbatrosTram->setVoertuigNummer(5);
    AlbatrosTram->setBeginStation("A");
    AlbatrosTram->setHuidigStation("A");
    StadslijnerTram *stadslijnerTram = new class StadslijnerTram();
    stadslijnerTram->setLijnNr(21);
    stadslijnerTram->setType("Stadslijner");
    stadslijnerTram->setVoertuigNummer(6);
    stadslijnerTram->setBeginStation("A");
    stadslijnerTram->setHuidigStation("A");
    Metro->addStation(MetronetStation1);
    Metro->addStation(MetronetStation2);
    Metro->addStation(MetronetStation3);
    Metro->addStation(HalteStation1);
    Metro->addStation(HalteStation2);
    Metro->addStation(HalteStation3);
    Metro->addTram(PCCTram);
    Metro->addTram(AlbatrosTram);
    Metro->addTram(stadslijnerTram);
    EXPECT_DEATH(Metro->moveTram(AlbatrosTram, HalteStation3->getName()), "Assertion.*failed")
                        << "Tram van type Albatros kan niet op een halte rijden";
    EXPECT_DEATH(Metro->moveTram(PCCTram, MetronetStation3->getName()), "Assertion.*failed")
                        << "Tram kan niet op een station rijden van een andere spoor";
    EXPECT_DEATH(Metro->moveTram(stadslijnerTram, HalteStation3->getName()), "Assertion.*failed");
    EXPECT_DEATH(Metro->addStation(HalteStation1), "Assertion.*failed") << "Station already in MetroNet";
    EXPECT_DEATH(Metro->addStation(MetronetStation1), "Assertion.*failed") << "Station already in MetroNet";
    MetronetStation *falseMetronetStation = new MetronetStation;
    falseMetronetStation->setType("Metrostation");
    falseMetronetStation->setName("Alfa");
    EXPECT_DEATH(Metro->addStation(falseMetronetStation), "Assertion.*failed");
    MetronetStation *falseMetronetStation2 = new MetronetStation;
    EXPECT_DEATH(falseMetronetStation2->setName("20"), "Assertion.*failed");
    EXPECT_DEATH(falseMetronetStation2->setType("Falsetype"), "Assertion.*failed");
    Tram *falsePCCTram;
    falsePCCTram = new class PCCTram();
    EXPECT_DEATH(falsePCCTram->setType("Falsetype"), "Assertion.*failed");
    EXPECT_DEATH(falsePCCTram->setType("595"), "Assertion.*failed");
    Tram *falseAlbatrosTram;
    falseAlbatrosTram = new class AlbatrosTram();
    EXPECT_DEATH(falseAlbatrosTram->setType("Falsetype"), "Assertion.*failed");
    EXPECT_DEATH(falseAlbatrosTram->setType(""), "Assertion.*failed");
    EXPECT_DEATH(falseAlbatrosTram->setType("665"), "Assertion.*failed");
    Tram *falseStadslijnerTram;
    falseStadslijnerTram = new class StadslijnerTram();
    EXPECT_DEATH(falseStadslijnerTram->setType("Falsetype"), "Assertion.*failed");
    EXPECT_DEATH(falseStadslijnerTram->setType("545954"), "Assertion.*failed");
    EXPECT_DEATH(falsePCCTram->_moveTest(HalteStation3), "Assertion.*failed");
    EXPECT_DEATH(PCCTram->_moveTest(falseMetronetStation), "Assertion.*failed");
    EXPECT_DEATH(PCCTram->setBeginStation("26516"), "Assertion.*failed");
    EXPECT_DEATH(PCCTram->setHuidigStation("20"), "Assertion.*failed");
}
