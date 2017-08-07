/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#include "Region.h"
#include <fstream>
#include <iostream>

Region::~Region()
{}


void Region::addCity(CityPtr addedCity)
{
	listCities.push_back(addedCity);
}

void Region::displayCities()
{
	for (CityPtr city : listCities) {
		std::cout << city->getName() << " ";
	}
	std::cout << std::endl;
}

void saveRegion(Region &savedRegion, const string filename)
{
	std::ofstream outputFileStream(filename.c_str(), std::ios::binary);
	boost::archive::binary_oarchive outputArchive(outputFileStream);
	outputArchive << savedRegion;
}

void loadRegion(Region &loadTgtRegion, const string filename)
{
	std::ifstream inputFileStream(filename.c_str(), std::ios::binary);
	boost::archive::binary_iarchive inputArchive(inputFileStream);
	inputArchive >> loadTgtRegion;
}