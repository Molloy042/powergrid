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
#include <string>
#include <vector>
#include "Utility.h"
#include "House.h"

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>


using std::string;
using std::vector;

typedef House* HousePtr;
class City
{
public:

	City() { initialize(); }
	City(string givenName) :name(givenName) { initialize(); }
	~City();

	//GETTERS
	string getName() { return name; };
	friend void loadCity(City &loadTgtCity, const string filename);
	friend void saveCity(City &savedCity, const string filename);
	void placeHouse(HousePtr addedHouse);

	void addHouse(int i); 
	vector<House*> getHouses(); 


private:

	inline void initialize() {
		
		listHouses.resize(1);
		listHouses = { new House() };
	}

	vector<House*> listHouses;
	string name;


	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & boostArchive, const unsigned int version) {
		boostArchive & name;
	}
};

