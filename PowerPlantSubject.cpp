/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/


#include<iostream>
#include "PowerPlantSubject.h"

void PowerPlantSubject::Attach(PowerPlantObserverView *o) {
	//add any observer of type PowerPlantObserverView into the vector: 
	observers.push_back(o);
}

void PowerPlantSubject::Detach(PowerPlantObserverView *o) {
	//remove any observers of type PowerPlantObserverView into the vector: 
	observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
}

void PowerPlantSubject::Notify(int choice, Player* player, vector<PowerPlant*> &mpp) {

	//Notifies all observers calls the updates function of each one by iterating through the vector: 
	for (vector<PowerPlantObserverView*>::const_iterator
		loop = observers.begin(); loop != observers.end(); ++loop) {

		// if the vector is not empty then send the update to all observers: 
		if (*loop != 0)
		{
			(*loop)->Update(choice, player,mpp);
		}
	}
}
