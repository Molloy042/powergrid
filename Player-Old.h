#pragma once
#include <string>
#include "Coal.h"
#include "Oil.h"
#include "Garbage.h"
#include "Uranium.h"
#include "Resource.h"
#include "City.h"
#include <vector>
#include <algorithm>
#include "SummaryCards.h"
#include "PowerPlant.h"
#include "Map.h"

#include<boost/archive/binary_iarchive.hpp>
#include<boost/archive/binary_oarchive.hpp>
#include<boost/serialization/vector.hpp>


using std::string;
using std::vector;
typedef unsigned short ushort;
typedef unsigned int unint;

const unint MAX_NUM_HOUSES = 22;

class Player
{
public:
	
	//CONSTRUCTORS
	Player(void);
	Player(ColorType, string);

	//DESTRUCTOR
	~Player(void);

	//GETTERS
	string getName() const;
	ColorType getColor() const;
	unint getMoney();
	unint getNumHouses();
	void listHouses();
	vector<City*> getOwnedCities();

	//SETTERS
	void setName(string);
	void setColor(ColorType);
	void increaseMoney(unint amount);
	bool decreaseMoney(unint amount);
	bool addHouse(House* addedHouse);
	bool removeHouse(City* targetCity);
	int addHouseToCity(string nameCity, Map* map);
	vector<PowerPlant> ownedPowerPlants;

private:
	string name;
	ColorType color;
	unint playerMoney;

	SummaryCards* summaryCard; // NOT SERIALIZED. MUST BE ATTACHED, there will be only 1 summarycard for all the players. a player does not OWN a summary card.

	vector<City*> ownedCities;
	vector<string> ownedCitiesString;
	

	friend void playerLoad(Player &loadTgtPlayer, const string filename);
	friend void playerSave(Player &savedPlayer, const string filename);
	


	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & boostArchive, const unsigned int version)
	{
		boostArchive & name & color & ownedCitiesString & ownedPowerPlants;
	}

};

