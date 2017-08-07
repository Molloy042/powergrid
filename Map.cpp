/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#include <iostream>
#include "Map.h"
#include <fstream>
#include <iomanip>

Map::~Map()
{}

void Map::addRegion(RegionPtr addedRegion)
{
	listRegions.push_back(addedRegion);
}

void Map::displayCities()
{
	std::cout << "Listing cities : " << std::endl;
	for (RegionPtr region : listRegions) {
		std::cout << "Region " << region->getName() << ": ";
		region->displayCities();
	}
	//std::cout << std::endl;
}

void Map::displayRegionAndCities()
{
	std::cout << "Listing cities : " << std::endl;
	for (RegionPtr region : listRegions) {
		std::cout << "Region " << region->getName() << ": ";
		region->displayCities();
	}
	//std::cout << std::endl;
}



void saveMapToFile(Map &savedMap, const string filename)
{
	std::ofstream outputFileStream(filename.c_str(), std::ios::binary);
	boost::archive::binary_oarchive outputArchive(outputFileStream);
	outputArchive << savedMap;
}

void loadMapFromFile(Map &loadTgtMap, const string filename)
{
	std::ifstream inputFileStream(filename.c_str(), std::ios::binary);
	boost::archive::binary_iarchive inputArchive(inputFileStream);
	inputArchive >> loadTgtMap;
	loadTgtMap.updateListCities();
}

void Map::addLink(CityPtr city1, CityPtr city2, int linkCost)
{
	//updateListCities();
	unsigned int index1 = getIndex(city1);
	unsigned int index2 = getIndex(city2);
	
	if (index1 != listCities.size() &&
		index2 != listCities.size()) {
		
		adjacencyMatrix[index1][index2].isLinked = true;
		adjacencyMatrix[index1][index2].linkCost = linkCost;

		adjacencyMatrix[index2][index1].isLinked = true;
		adjacencyMatrix[index2][index1].linkCost = linkCost;
	}
}

bool Map::getLink(CityPtr city1, CityPtr city2)
{
	//updateListCities();
	unsigned int index1 = getIndex(city1);
	unsigned int index2 = getIndex(city2);
	return adjacencyMatrix[index1][index2].isLinked = true;
}

int Map::getLinkCost(CityPtr city1, CityPtr city2)
{
	//updateListCities();
	unsigned int index1 = getIndex(city1);
	unsigned int index2 = getIndex(city2);
	return adjacencyMatrix[index1][index2].linkCost;
}

void Map::updateListCities()
{
	listCities.clear();
	vector<CityPtr> obtainedListCities;
	for (RegionPtr region : listRegions) {
		obtainedListCities = region->getListCities();
		for (CityPtr city : obtainedListCities) {
			listCities.push_back(city);
		}
	}
}

// Returns index based on listCities. updateListCities() must always be called prior to calling this . If it was unable to find the city in the list, it will return the size of the list.
unsigned int Map::getIndex(CityPtr tgtCity)
{	
	unsigned int tgtIndex = (unsigned int) listCities.size();
	for (unsigned int i = 0; i < listCities.size(); ++i) {
		if (listCities[i] == tgtCity) {
			tgtIndex = i;
			break;
		}
	}
	return tgtIndex;
}

void Map::displayAdjMatrix()
{
	std::cout << std::endl;

	updateListCities();
	std::cout << "------------------------------------------------------------" << std::endl;
	for (unsigned int i = 0; i < listCities.size();++i) {
		std::cout << listCities[i]->getName() << ":" << std::endl;

		for (unsigned int j = 0; j < listCities.size();++j) {


			if (adjacencyMatrix[i][j].isLinked == true) {
				//	std::cout << "1" << " ";

				if ((j % 4) != 0) {
					printf("%-0s%-9s%-0s%-2.0f%-1s%-0s", " -> ", listCities[j]->getName().c_str(), "(",
						(float)this->getLinkCost(listCities[i], listCities[j]), ")", " | ");
				}
				else {
					printf("%-0s%-9s%-0s%-2.0f%-1s%-0s\n", " -> ", listCities[j]->getName().c_str(), "(",
						(float)this->getLinkCost(listCities[i], listCities[j]), ")", " | ");

				}

			}
			else {
				//std::cout << "0" << " ";
			}
		}
		std::cout << "\n------------------------------------------------------------" << std::endl;

	}
	std::cout << std::endl;

	for (int z = 0; z < this->listCities.size(); z++) {

		for (int d = 0; d < listCities[z]->getHouses().size(); d++) {

			std::cout << listCities[z]->getName() << " houses availability: \n " << d << ". "
				<< listCities[z]->getHouses()[d]->isTaken() << " with color " << listCities[z]->getHouses()[d]->getColor() << "\n";
		}
		std::cout << std::endl;
	}
		
}

void Map::displayAdjMatrixWithCosts()
{
	updateListCities();
	
	for (unsigned int i = 0; i < listCities.size();++i) {
		for (unsigned int j = 0; j < listCities.size();++j) {
			if (adjacencyMatrix[i][j].isLinked == true) {
				std::cout << std::setw(2) << adjacencyMatrix[i][j].linkCost << " ";
			}
			else {
				std::cout << "na" << " ";
			}
		}
		std::cout << std::endl;
	}

}