/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#include "PGModel.h"
#include <algorithm>


PGModel::~PGModel()
{
	if (resMarket != nullptr) {
		delete resMarket; resMarket = nullptr;
	}
	if (memHandler != nullptr) {
		delete memHandler; memHandler = nullptr;
	}
	for (unint i = 0; i < listActivePlayers.size();++i) {
		if (listActivePlayers[i] != nullptr) {
			delete listActivePlayers[i]; listActivePlayers[i] = nullptr;
		}
	}
}

void PGModel::startNewGame()
{
	initializeModel();
	initResMarket(24, 18, 6, 4);
}

void PGModel::addPlayer(string name, ColorType color)
{
	Player* newPlayer = new Player(color, name);
	newPlayer->increaseMoney(30);
	listActivePlayers.push_back(newPlayer);
}

void PGModel::determinePlayerOrder()
{
	if (isFirstTurn == true) {
		isFirstTurn = false; // it won't be the first turn anymore after this.
		std::random_shuffle(listActivePlayers.begin(), listActivePlayers.end()); // shuffle the vector of players.
		std::cout << endl;
		//Print the order of play: 
		std::cout << "\n ====== THE ORDER OF PLAY IS NOW ======  \n" << endl;
		for (unsigned i = 0; i < listActivePlayers.size(); i++) {
			std::cout << i << "." << listActivePlayers[i]->getName() << "  \n";
		}
		std::cout << endl;
	}
	else if (phasePosition == AUCTION) {
		rearrangeTurn();
	}
	else {
		std::reverse(listActivePlayers.begin(), listActivePlayers.end());
	}
}




void PGModel::step2()
{

	extern bool step2Activated;

	for (int i = 0; i < listActivePlayers.size(); i++) {

		if (listActivePlayers[i]->getOwnedCities().size() >= 7) {
			step2Activated = true;
			break;
		}
	}
}

void PGModel::initializeModel()
{
	memHandler = new MemoryHandler();
	resMarket = new ResourceMarket();
	map = loadMap(*memHandler);
	isFirstTurn = true;
}

void PGModel::rearrangeTurn()
{
	for (unsigned i = 0; i < listActivePlayers.size(); i++) {
		for (unsigned j = 0 + i; j < listActivePlayers.size(); j++) {

			if (j + 1 > listActivePlayers.size() - 1) {
				break;
			}
			/*
			Checks the players' number of houses and compares them together.
			If the sum of the player's cities is smaller than his opponent,
			then swap the two players in the vector
			*/
			if (listActivePlayers[i]->getNumHouses() < listActivePlayers[(j + 1) % listActivePlayers.size()]->getNumHouses()) {

				std::swap(listActivePlayers[i], listActivePlayers[j + 1]);
			}
			//If two or more players are tied for the most cities, 
			//the first player is the player among them with the largest - numbered power plant.
			if (listActivePlayers[i]->getNumHouses() == listActivePlayers[(j + 1) % listActivePlayers.size()]->getNumHouses()) {
				if (listActivePlayers[i]->getOwnedPowerPlants().size() < listActivePlayers[(j + 1) % listActivePlayers.size()]->getOwnedPowerPlants().size()) {
					std::swap(listActivePlayers[i], listActivePlayers[j + 1]);
				}

			}
		}
	}
}

Coal * PGModel::removeCoalFromSideList()
{
	CoalPtr removedCoal = sideCoalList[sideCoalList.size() - 1];
	sideCoalList.pop_back();
	return removedCoal;
}

Oil * PGModel::removeOilFromSideList()
{
	OilPtr removedOil = sideOilList[sideOilList.size() - 1];
	sideOilList.pop_back();
	return removedOil;
}

Garbage * PGModel::removeGarbageFromSideList()
{
	GarbagePtr removedGarbage = sideGarbageList[sideGarbageList.size() - 1];
	sideGarbageList.pop_back();
	return removedGarbage;
}

Uranium * PGModel::removeUraniumFromSideList()
{
	UraniumPtr removedUranium = sideUraniumList[sideUraniumList.size() - 1];
	sideUraniumList.pop_back();
	return removedUranium;
}

bool PGModel::initResMarket(unint numCoal, unint numOil, unint numGarbage, unint numUranium)
{
	//CHECK if resMarket is functional (not null ptr)
	if (resMarket == nullptr) {
		cerr << "resMarket was not initialized. Please report BUG!";
		return false;
	}

	//ADD RESOURCES
	for (unint i = 0;i < numCoal;++i) {
		if (resMarket->addCoal(new Coal) == false) {
			cerr << "impossible to add a created Coal" << endl;
		}
	}

	for (unint i = 0;i < numOil;++i) {
		if (resMarket->addOil(new Oil) == false) {
			cerr << "impossible to add a created Oil" << endl;
		}
	}

	for (unint i = 0;i < numGarbage; ++i) {
		if (resMarket->addGarbage(new Garbage) == false) {
			cerr << "impossible to add a created Garbage" << endl;
		}
	}

	for (unint i = 0; i < numUranium; ++i) {
		if (resMarket->addUranium(new Uranium) == false) {
			cerr << "impossible to add a created Uranium" << endl;
		}
	}

	// COMPUTE RESOURCES THAT ARE REMAINING TO BE ADDED
	unint remainingCoal = MAX_COAL - numCoal;
	unint remainingOil = MAX_OIL - numOil;
	unint remainingGarbage = MAX_GARBAGE - numGarbage;
	unint remainingUranium = MAX_URANIUM - numUranium;

	// CREATING RESOURCES AND PLACING ON THE SIDE
	for (unint i = 0; i < remainingCoal;++i) {
		sideCoalList.push_back(new Coal);
	}

	for (unint i = 0;i < remainingOil; ++i) {
		sideOilList.push_back(new Oil);
	}

	for (unint i = 0; i < remainingGarbage; ++i) {
		sideGarbageList.push_back(new Garbage);
	}

	for (unint i = 0; i < remainingUranium; ++i) {
		sideUraniumList.push_back(new Uranium);
	}
	
	// GIVING RESOURCES TO MEMORY HANDLER
	memHandler->attachCoalList(resMarket->getCoalPtrList());
	memHandler->attachOilList(resMarket->getOilPtrList());
	memHandler->attachGarbageList(resMarket->getGarbagePtrList());
	memHandler->attachUraniumList(resMarket->getUraniumPtrList());

	memHandler->attachCoalList(sideCoalList);
	memHandler->attachOilList(sideOilList);
	memHandler->attachGarbageList(sideGarbageList);
	memHandler->attachUraniumList(sideUraniumList);

	return true;
}

Map * PGModel::loadMap(MemoryHandler & memoryHandler)
{
	Map *map2 = new Map();

	loadMapFromFile(*map2, "PGMap.dat");

	//memory handler loads 
	memoryHandler.attachListCities(map2->getListCities());
	memoryHandler.attachListRegions(map2->getListRegions());
	memoryHandler.attachMap(map2);
	//need to implement for build 1 a GetAHouse() inside Player which will remove the house automatically and return a pointer to the house which can be used by placeHouse as such: city1.placeHouse(player1.getAHouse());
	return map2;
}


// DECK OF POWER PLANT CARDS: 
vector<PowerPlant*> PGModel::FullPackCard()
{

	vector<PowerPlant*> mpp;

	mpp.push_back(new PowerPlant(3, 1, 2, "Oil", ""));
	mpp.push_back(new PowerPlant(4, 1, 2, "Coal", ""));
	mpp.push_back(new PowerPlant(5, 1, 2, "Oil", "Coal"));
	mpp.push_back(new PowerPlant(6, 1, 1, "Garbage", ""));
	mpp.push_back(new PowerPlant(7, 2, 3, "Oil", ""));
	mpp.push_back(new PowerPlant(8, 2, 3, "Coal", ""));
	mpp.push_back(new PowerPlant(9, 1, 1, "Oil", ""));
	mpp.push_back(new PowerPlant(10, 2, 2, "Coal", ""));
	mpp.push_back(new PowerPlant(13, 1, 0, "", ""));
	mpp.push_back(new PowerPlant(11, 2, 1, "Uranium", ""));
	mpp.push_back(new PowerPlant(12, 2, 2, "Oil", "Coal"));
	mpp.push_back(new PowerPlant(14, 2, 2, "Garbage", ""));
	mpp.push_back(new PowerPlant(15, 3, 2, "Coal", ""));
	mpp.push_back(new PowerPlant(16, 3, 2, "Oil", ""));
	mpp.push_back(new PowerPlant(17, 2, 1, "Uranium", ""));
	mpp.push_back(new PowerPlant(18, 2, 0, "", ""));
	mpp.push_back(new PowerPlant(19, 3, 2, "Garbage", ""));
	mpp.push_back(new PowerPlant(20, 5, 3, "Coal", ""));
	mpp.push_back(new PowerPlant(21, 4, 2, "Oil", "Coal"));
	mpp.push_back(new PowerPlant(22, 2, 0, "", ""));
	mpp.push_back(new PowerPlant(23, 3, 1, "Uranium", ""));
	mpp.push_back(new PowerPlant(24, 4, 2, "Garbage", ""));
	mpp.push_back(new PowerPlant(25, 5, 2, "Coal", ""));
	mpp.push_back(new PowerPlant(26, 5, 2, "Oil", ""));
	mpp.push_back(new PowerPlant(27, 3, 0, "", ""));
	mpp.push_back(new PowerPlant(28, 4, 1, "Uranium", ""));
	mpp.push_back(new PowerPlant(29, 4, 1, "Oil", "Coal"));
	mpp.push_back(new PowerPlant(30, 6, 3, "Garbage", ""));
	mpp.push_back(new PowerPlant(31, 6, 3, "Coal", ""));
	mpp.push_back(new PowerPlant(32, 6, 3, "Oil", ""));
	mpp.push_back(new PowerPlant(33, 4, 0, "", ""));
	mpp.push_back(new PowerPlant(34, 5, 1, "Uranium", ""));
	mpp.push_back(new PowerPlant(35, 5, 1, "Oil", ""));
	mpp.push_back(new PowerPlant(36, 7, 3, "Coal", ""));
	mpp.push_back(new PowerPlant(37, 4, 0, "", ""));
	mpp.push_back(new PowerPlant(38, 7, 3, "Garbage", ""));
	mpp.push_back(new PowerPlant(39, 6, 1, "Uranium", ""));
	mpp.push_back(new PowerPlant(40, 6, 2, "Oil", ""));
	mpp.push_back(new PowerPlant(42, 6, 2, "Coal", ""));
	mpp.push_back(new PowerPlant(44, 5, 0, "", ""));
	mpp.push_back(new PowerPlant(46, 7, 3, "Oil", "Coal"));
	mpp.push_back(new PowerPlant(50, 6, 0, "", ""));
	mpp.push_back(new PowerPlant(9999, 0, 0, "", ""));


	return mpp;

}
