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
#include "City.h"

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>

using std::string;
using std::vector;

class Region
{
public:
	typedef City* CityPtr;
	Region() {}
	~Region();
	Region(string givenName): name(givenName) {}
	string getName() { return name; };
	void addCity(CityPtr addedCity);
	void displayCities();
	vector<CityPtr> getListCities() { return listCities; };
	friend void saveRegion(Region &savedRegion, const string filename);
	friend void loadRegion(Region &loadTgtRegion, const string filename);
private:
	
	friend class boost::serialization::access;
	vector<CityPtr> listCities;
	string name;

	template<class Archive> 
	void serialize(Archive &boostArchive, const unsigned version) {
		boostArchive & name & listCities;
	}
};

