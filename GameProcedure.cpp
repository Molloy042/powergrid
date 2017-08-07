/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/


#include "GameProcedure.h"
#include "Player.h"
#include "Map.h"
#include "PowerPlant.h"
#include <iostream>
using namespace std; 


//Assignment 3: Strategy methods (Optional): 

//Default constructor: 
GameProcedure::GameProcedure(){}

//Destructor: 
GameProcedure::~GameProcedure() { delete phase; }

//Function to set the strategy of the phase (which phase we are at?) : 
void GameProcedure::setPhaseStrategy(PhasesInterface *phaseStrategy)
{
	phase = phaseStrategy;
}

//Activates the current phase by executing the method : activatePhase(list of players, the pack of Power Plant cards, the map)
void GameProcedure::thePhasePlayerStrategy(vector <Player*> activePlayers, vector<PowerPlant*> &mpp, Map* map, ResourceMarket* resourceMarket)
{
	phase->activatePhase(activePlayers, mpp, map, resourceMarket);
}

