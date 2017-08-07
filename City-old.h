#pragma once
#include <string>
#include <vector>

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
	
	City() { 
		initialize();
	}
	City(string givenName) :name(givenName) { initialize(); }
	~City();

	//GETTERS
	string getName() { return name; };
	friend void loadCity(City &loadTgtCity, const string filename);
	friend void saveCity(City &savedCity, const string filename);
	void placeHouse(HousePtr addedHouse);
	vector<House*> getHouses();

private:
	inline void initialize () {
		listHouses.resize(3);
		for (HousePtr currentHouse : listHouses) {
			currentHouse = nullptr;
		}
	}
	vector<House*> listHouses;
	string name;

	friend class boost::serialization::access;
	template<class Archive> 
	void serialize(Archive & boostArchive, const unsigned int version) {
		boostArchive & name;
	}
};

