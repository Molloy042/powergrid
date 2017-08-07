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
#include "City.h"
#include <vector>
#include <algorithm>
#include "Map.h"
#include "Powerplant.h"
#include "SummaryCards.h"
#include "Strategy.h"
#include "Resource.h"

#include<boost\archive\binary_oarchive.hpp>
#include<boost\archive\binary_iarchive.hpp>
#include<boost\serialization\vector.hpp>

class Strategy;


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
	Player(ColorType, string, Strategy* strategy);

	//DESTRUCTOR
	~Player(void);

	//GETTERS
	string getName() const;
	ColorType getColor() const;
	unint getMoney();
	unint getNumHouses();
	void listHouses();
	vector<City*> getOwnedCities();

	void setName(string);
	void setColor(ColorType);
	void increaseMoney(unint amount);
	bool decreaseMoney(unint amount);

	void addHouseToCity(City* city, int i);
	
	SummaryCards* getMySummaryCard() const; 
	void cityHoldsSummaryCardValue();
	void removeCityFromPlayer(int index, Map* map);

	void currentPlayerInformation(); 
	vector<PowerPlant*> getOwnedPowerPlants();
	vector<PowerPlant*> ownedPowerPlants;



	vector<vector<Resource*>> getOwnedResources(); 
	void purchaseResources(char choice, unint amount); 
	void removeResources(char choice, unint amount); 

	//Assignment 3: Strategy methods: 
	void setStrategy(Strategy *newStrategy);
	void thePlayerStrategy();

private:
	Strategy* strategy; 




	string name;
	ColorType color;
	unint playerMoney;
	SummaryCards* mySummaryCard; 

	vector<City*> ownedCities;
	vector<string> ownedCitiesString;

	vector<vector<Resource*>> ownedResources; 

	friend void playerLoad(Player &loadTgtPlayer, const string filename);
	friend void playerSave(Player &savedPlayer, const string filename);



	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & boostArchive, const unsigned int version)
	{
		boostArchive & name & color & ownedCitiesString;
	}


};


