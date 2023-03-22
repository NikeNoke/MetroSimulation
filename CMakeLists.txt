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
set(RELEASE_SOURCE_FILES main.cpp Tram/Tram.cpp Station/Station.cpp TinyXML/tinyxmlparser.cpp
        TinyXML/tinyxmlerror.cpp TinyXML/tinyxml.cpp TinyXML/tinystr.cpp
        MetroNet/MetroNet.cpp
        Utils/utils.cpp
        ParseXML/ParseStation.cpp ParseXML/ParseStation.h ParseXML/ParseTram.cpp ParseXML/ParseTram.h ParseXML/ParseMetroNet.cpp ParseXML/ParseMetroNet.h Exporter/Exporter.cpp Exporter/Exporter.h MetroNetGenerator/MetroNetGenerator.cpp MetroNetGenerator/MetroNetGenerator.h)

# Set source files for DEBUG target
set(DEBUG_SOURCE_FILES tests.cpp TinyXML/tinystr.cpp TinyXML/tinyxml.cpp TinyXML/tinyxmlerror.cpp TinyXML/tinyxmlparser.cpp
        Tram/Tram.cpp Station/Station.cpp TestFiles/ValidAttributesTram.cpp TestFiles/ValidAttributesStation.cpp
        MetroNet/MetroNet.cpp Utils/utils.cpp
        TestFiles/ValidMetroNetTest.cpp ParseXML/ParseStation.cpp ParseXML/ParseTram.cpp ParseXML/ParseMetroNet.cpp ParseXML/ParseMetroNet.h)

# Create RELEASE target
add_executable(Metro ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(testing_tool ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(testing_tool gtest)