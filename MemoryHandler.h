/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#pragma once
#include <vector>
#include "Player.h"
#include "City.h"
#include "Region.h"
#include "Map.h"
#include "ResourceMarket.h"

using std::vector;

class MemoryHandler
{
	typedef Player* PlayerPtr;
	typedef City* CityPtr;
	typedef Region* RegionPtr;
	
	typedef Coal* CoalPtr;
	typedef Oil* OilPtr;
	typedef Garbage* GarbagePtr;
	typedef Uranium* UraniumPtr;
	
public:
	MemoryHandler();
	~MemoryHandler();
	void attachListCities(vector<CityPtr> newListCities);
	void attachListRegions(vector<RegionPtr> newListRegions);
	void attachListPlayers(vector<PlayerPtr> newListPlayers);
	void attachMap(Map *newMap);
	
	void attachCoalList(vector<CoalPtr>);
	void attachOilList(vector<OilPtr>);
	void attachGarbageList(vector<GarbagePtr>);
	void attachUraniumList(vector<UraniumPtr>);

	void deallocateListCities();
	void deallocateListRegions();
	void deallocateListPlayers();
	void deallocateMap();
	void deallocateResources();

private:
	vector<PlayerPtr> listPlayers;
	vector<CityPtr> listCities;
	vector<RegionPtr> listRegions;
	vector<Resource*> listResources;
	Map *map;
};

