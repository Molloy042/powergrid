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
#include"PowerPlantObserverView.h"
#include"PowerPlant.h"
#include "Player.h"
#include<vector>

using namespace std;

class PowerPlantSubject {

private:
	//vector for all observers 
	std::vector<PowerPlantObserverView*> observers;

public:
	//to attach any observers to one subject: 
	void Attach(PowerPlantObserverView* o);
	//to remove any observers to one subject: 
	void Detach(PowerPlantObserverView* o);
	//to notify all observers part of the vector in order to update the view
	void Notify(int choice, Player* player, vector<PowerPlant*> &mpp);

};
