/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#include "MemoryHandler.h"
#include <iostream>
using std::cout;
using std::endl;



MemoryHandler::MemoryHandler()
{}


MemoryHandler::~MemoryHandler()
{
	deallocateListCities();
	deallocateListRegions();
	deallocateListRegions();
	deallocateMap();
	deallocateResources();
}

void MemoryHandler::attachListCities(vector<CityPtr> newListCities)
{
	this->listCities.resize(newListCities.size());
	for (unsigned int i = 0; i < listCities.size(); ++i) {
		listCities[i] = newListCities[i];
	}
}

void MemoryHandler::attachListRegions(vector<RegionPtr> newListRegions)
{
	this->listRegions.resize(newListRegions.size());
	for (unsigned int i = 0; i < listRegions.size(); ++i) {
		listRegions[i] = newListRegions[i];
	}
}

void MemoryHandler::attachListPlayers(vector<PlayerPtr> newListPlayers)
{
	this->listPlayers.resize(newListPlayers.size());
	for (unsigned int i = 0;i < listPlayers.size();++i) {
		listPlayers[i] = newListPlayers[i];
	}
}

void MemoryHandler::attachMap(Map *newMap)
{
	map = newMap;
}

void MemoryHandler::attachCoalList(vector<CoalPtr> givenCoalList)
{
	for (unint i = 0; i < givenCoalList.size(); ++i) {
		listResources.push_back(givenCoalList[i]);
	}
}

void MemoryHandler::attachOilList(vector<OilPtr> givenOilList)
{
	for (unint i = 0; i < givenOilList.size(); ++i) {
		listResources.push_back(givenOilList[i]);
	}
}


void MemoryHandler::attachGarbageList(vector<GarbagePtr> givenGarbageList)
{
	for (unint i = 0; i < givenGarbageList.size(); ++i) {
		listResources.push_back(givenGarbageList[i]);
	}
}


void MemoryHandler::attachUraniumList(vector<UraniumPtr> givenUraniumList)
{
	for (unint i = 0; i < givenUraniumList.size(); ++i) {
		listResources.push_back(givenUraniumList[i]);
	}
}

void MemoryHandler::deallocateListCities()
{
	for (unsigned int i = 0; i < listCities.size(); ++i) {
		if (listCities[i] != NULL) {
			delete listCities[i];
			//cout << "deleting listCities[" << i << "] ... " << endl;
			listCities[i] = NULL;
		}
	}
}

void MemoryHandler::deallocateListRegions()
{
	for (unsigned int i = 0; i < listRegions.size(); ++i) {
		if (listRegions[i] != NULL) {
			delete listRegions[i];
			//cout << "deleting listRegions[" << i << "] ... " << endl;
			listRegions[i] = NULL;
		}
	}
}

void MemoryHandler::deallocateListPlayers()
{
	for (unsigned int i = 0;i < listPlayers.size();++i) {
		if (listPlayers[i] != NULL) {
			delete listPlayers[i];
			listPlayers[i] = NULL;
		}
	}
}

void MemoryHandler::deallocateMap()
{
	delete map;
}

void MemoryHandler::deallocateResources()
{
	for (unint i = 0; i < listResources.size(); ++i) {
		if (listResources[i] != nullptr) {
			delete listResources[i];
			listResources[i] = nullptr;
		}
	}
}
