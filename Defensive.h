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
#include"Strategy.h"

/*

A concrete strategy that implements the defensive operation

*/
class Defensive : public Strategy {

public:
	//Not yet implemented:
	void playerPowerPlantAuctionStrategy(Player* player);

	//Not yet implemented:
	void playerBuyingRessourcesStrategy(Player* player);

	//Not yet implemented:
	void playerBuildingStrategy(Player* player);

	//Implemented for assignment 3: 
	void playerBureaucracyStrategy(Player* player);
};