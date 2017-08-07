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

class PowerPlantObserver
{

public:

	virtual void Update(int choice, Player* player, vector<PowerPlant*> &mpp) = 0;

};
