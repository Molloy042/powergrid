#include "City.h"
#include <fstream>

City::~City()
{}

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
}

void City::placeHouse(HousePtr addedHouse)
{
	listHouses.push_back(addedHouse);
}

vector<House*> City::getHouses()
{

	return listHouses;

}