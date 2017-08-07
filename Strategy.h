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
#include "Player.h"
#include <vector> 

class Player;


class  Strategy {

public: 
	/*
	Method whose implementation varies 
	depending on the strategy adopded
	*/

	virtual void playerPowerPlantAuctionStrategy(Player* player) = 0; 
	virtual void playerBuyingRessourcesStrategy(Player* player) = 0; 
	virtual void playerBuildingStrategy(Player* player) = 0; 
	virtual void playerBureaucracyStrategy(Player* player) = 0;


};