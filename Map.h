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
#include <string>
#include <utility>

#include "Region.h"

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/array.hpp>

using std::string;
using std::vector;

const unsigned int MAX_NUM_CITIES = 10;

class Map
{
	typedef Region* RegionPtr;
	typedef City* CityPtr;
public:



	void displayRegionAndCities();

	class MapNode
	{
	private:
		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &boostArchive, const unsigned version)
		{
			boostArchive & isLinked & linkCost;
		}
	public:
		bool isLinked;
		int linkCost;
	};

	Map() {}
	~Map();
	Map(string givenName): name(givenName) {}
	string getName() { return name; };
	vector<CityPtr> getListCities() { return listCities; }
	vector<RegionPtr> getListRegions() { return listRegions; }
	void addRegion(RegionPtr addedRegion);
	void displayCities();
	void addLink(CityPtr city1, CityPtr city2, int linkCost);
	bool getLink(CityPtr city1, CityPtr city2);
	int getLinkCost(CityPtr city1, CityPtr city2);


	void displayAdjMatrix(); //does not display costs
	void displayAdjMatrixWithCosts(); //displays costs as well
	friend void saveMapToFile(Map &savedMap, const string filename);
	friend void loadMapFromFile(Map &loadTgtMap, const string filename);
	void updateListCities();
	MapNode adjacencyMatrix[MAX_NUM_CITIES][MAX_NUM_CITIES];
	//MapNode** getAM() { return adjacencyMatrix; }
private:
	friend class boost::serialization::access;
	vector<RegionPtr> listRegions;
	string name;
	template<class Archive>
	void serialize(Archive &boostArchive, const unsigned version) {
		boostArchive & name & listRegions & adjacencyMatrix;
	}

	//built, after a Load or similar operation, in order to provide an index
	vector<CityPtr> listCities;
	
	unsigned int getIndex(CityPtr);
};