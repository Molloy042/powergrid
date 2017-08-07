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
#include"PowerPlant.h"
#include<vector>
#include<iostream>
#include "PowerPlantObserver.h"

using namespace std;

//class PGGameController :public Subject {
class PowerPlantObserverView : public PowerPlantObserver
{

public:

	PowerPlantObserverView(); 
	//constructor: 
	PowerPlantObserverView(vector<PowerPlant*> &mpp);
	//destructor: 
	~PowerPlantObserverView();

	//ASSIGNMENT2: 
	void Update(int choice, Player* player,vector<PowerPlant*> &mpp); //Updates the observer object by printing the view to the console 
	void displayerPowerPlantMarket(); // the view of the 2x4 cards sorted and updated. 
	void showRemovedCard(int choice); // the view of the card that is removed by the input user 
	
	vector <PowerPlant*> getShuffledDeck() const;


private:

	//Deck of card: instance variable of all the powerplant cards shuffled  
	vector<PowerPlant*> shuffledDeck;

	//2d array which will hold the 8 displayed cards
	PowerPlant** powerPlantMarket;
	//2D array size: 
	int const POWERPLANTMARKET_ROWSIZE = 2;
	int const POWERPLANTMARKET_COLSIZE = 4;



};