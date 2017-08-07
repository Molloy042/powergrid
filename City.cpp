/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#include "City.h"
#include <fstream>

City::~City()
{
	for (unsigned int i = 0; i < listHouses.size(); i++) {
		delete listHouses[i];
		listHouses[i] = NULL;
	}
}


void loadCity(City &loadTgtCity, const string filename)
{
	std::ifstream inputFileStream(filename.c_str(), std::ios::binary);

	boost::archive::binary_iarchive inputArchive(inputFileStream);
	inputArchive >> loadTgtCity;
}

void saveCity(City &savedCity, const string filename)
{
	std::ofstream outputFileStream(filename.c_str(), std::ios::binary);
	boost::archive::binary_oarchive outputArchive(outputFileStream);
	outputArchive << savedCity;
	//how come we don't need to close the stream?!?
}

void City::placeHouse(HousePtr addedHouse)
{
	listHouses.push_back(addedHouse);
}


vector<House*> City::getHouses() {

	return listHouses; 

}

void City::addHouse(int i) {

	listHouses.push_back(new House(i));
}

