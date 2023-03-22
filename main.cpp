#include "MetroNetGenerator//MetroNetGenerator.h"

int main() {

    MetroNetGenerator generator("TestInputXML/ValidMetroNet/metroNet2.xml", "metroNetSpecs.txt");

    generator.generateMetroNet();

    generator.simulate(10);

}
