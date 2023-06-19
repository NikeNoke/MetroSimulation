cmake_minimum_required(VERSION 3.6)
project(MetroSimulation)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-std=c++98 -Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(gtest/include)

# Set Library dir
link_directories(gtest/lib)

# Set source files for RELEASE target
set(RELEASE_SOURCE_FILES main.cpp Trams/Tram.cpp Stations/Station.cpp TinyXML/tinyxmlparser.cpp
        TinyXML/tinyxmlerror.cpp TinyXML/tinyxml.cpp TinyXML/tinystr.cpp
        MetroNet/MetroNet.cpp
        Utils/utils.cpp ParseXML/ParseStation.cpp ParseXML/ParseTram.cpp ParseXML/ParseMetroNet.cpp
        Exporter/Exporter.cpp MetroNetGenerator/MetroNetGenerator.cpp Spoor/Spoor.cpp ParseXML/ParseSpoor.cpp
        Trams/PCCTram.cpp Trams/AlbatrosTram.cpp Trams/StadslijnerTram.cpp
        Stations/MetronetStation.cpp Stations/HalteStation.cpp Exporter/SimpleExport.cpp Exporter/AdvancedExport.cpp
        Exporter/InterfaceExport.cpp Exporter/InterfaceExport.h Trams/BigTram.cpp Trams/BigTram.h)

# Set source files for DEBUG target
set(DEBUG_SOURCE_FILES tests.cpp Trams/Tram.cpp Stations/Station.cpp TinyXML/tinyxmlparser.cpp
        TinyXML/tinyxmlerror.cpp TinyXML/tinyxml.cpp TinyXML/tinystr.cpp
        MetroNet/MetroNet.cpp Spoor/Spoor.cpp ParseXML/ParseSpoor.cpp Stations/MetronetStation.cpp Stations/HalteStation.cpp
        Trams/AlbatrosTram.cpp Trams/PCCTram.cpp Trams/StadslijnerTram.cpp Exporter/AdvancedExport.cpp
        Exporter/Exporter.cpp Exporter/InterfaceExport.cpp Exporter/SimpleExport.cpp
        Utils/utils.cpp ParseXML/ParseStation.cpp ParseXML/ParseTram.cpp ParseXML/ParseMetroNet.cpp
        Exporter/Exporter.cpp MetroNetGenerator/MetroNetGenerator.cpp TestFiles/ValidMetroNetTest.cpp
        TestFiles/ValidExport.cpp TestFiles/DomainTestSuite.cpp TestFiles/TagChecker.cpp
        Trams/BigTram.cpp)

# Create RELEASE target
add_executable(Metro ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(testing_tool ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(testing_tool gtest)