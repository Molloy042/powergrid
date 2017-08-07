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
#include "Subject.h"
#include "Player.h"
#include "Map.h"
#include "ResourceMarket.h"
#include "MemoryHandler.h"
#include <vector>
#include "PhasesInterface.h"
#include "Building.h"
#include "Bureaucracy.h"
#include "BuyingResources.h"
#include "GameProcedure.h"
#include "PowerPlantAuction.h"



enum PhaseType {  AUCTION =1, B_RESOURCES =2 , BUILDING =3, BUREAUCRACY =4 };
enum StepType {STEP1 = 1, STEP2 = 2, STEP3 = 3};

const unint MAX_COAL = 24;
const unint MAX_OIL = 24;
const unint MAX_GARBAGE = 24;
const unint MAX_URANIUM = 12;

class PGModel : public Subject
{




public:
	PGModel() { isGameOn = false; }
	~PGModel();

	void startNewGame();

	void step2();

	vector<PowerPlant*> FullPackCard();




	inline ResourceMarket* getResMarket() const { return resMarket; }
	inline Map* getMap() const { return map; }
	inline vector<Player*> getListPlayers() const { return listActivePlayers; }
	void addPlayer(string name, ColorType color);
	inline int getNumPlayers() const{ return numPlayers; }
	inline void setNumPlayers(int newNumPlayers) { numPlayers = newNumPlayers; }
	StepType currentStep;
	PhaseType phasePosition;
	GameProcedure currentPhase;
	bool isFirstTurn;
	bool isGameOn;
	void determinePlayerOrder();
	void rearrangeTurn();
	Coal* removeCoalFromSideList();
	Oil* removeOilFromSideList();
	Garbage* removeGarbageFromSideList();
	Uranium* removeUraniumFromSideList();


	bool checkForWin = false;

	//SIDE LISTS
	vector<CoalPtr> sideCoalList;
	vector<OilPtr> sideOilList;
	vector<GarbagePtr> sideGarbageList;
	vector<UraniumPtr> sideUraniumList;

private:
	//gets called only if the user starts a new game
	//it creates a resMarket, memHandler
	void initializeModel();
	

	bool initResMarket(unint, unint, unint, unint);
	Map* loadMap(MemoryHandler &memoryHandler);
	vector<Player*> listActivePlayers;
	int numPlayers;

	ResourceMarket* resMarket;
	MemoryHandler* memHandler;
	Map* map;
};

