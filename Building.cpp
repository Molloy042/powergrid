/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/


#include "Building.h"


void Building::activatePhase(vector <Player*> activePlayers,vector<PowerPlant*> &mpp, Map* map, ResourceMarket* resourceMarket) {

	cout << "===== BUILDING FOR AUCTION PHASE =====" << endl;

	//GLOBAL VARIABLE FOR STEP 2: 
	extern bool step2Activated;
	extern bool step3Activated;

	bool executeOnce = true;
	bool executeOnce2 = true; 

	//WE ARE STILL IN STEP1:
	if (step2Activated == false) {
		bool executeOnce = false;
	}

	//IF WE ARE IN STEP2: 
	if (step2Activated == true && executeOnce == true) {

		for (int i = 0; i < map->getListCities().size(); i++) {

			map->getListCities()[i]->addHouse(15);
		}

		executeOnce = false;
	}

	if (step3Activated == true && executeOnce2 == true)
	{
		for (int i = 0; i < map->getListCities().size(); i++) {

			map->getListCities()[i]->addHouse(20);
		}

		executeOnce2 = false;
	}


	for (unsigned i = 0; i < activePlayers.size(); i++) {

		bool done = false;
		bool Linked = false;
		int index;
		bool first; 
		bool exists = false;
		int houseIndex = 0;
		int cityIndex = 0;
		int costPrice = 0;
		int linkPrice = 0;


		do {
			cout << endl;
			map->displayRegionAndCities(); // the cities

			/* displays the map of the cities with the links ( -> )
			(the numbers in parenthesis represents the link cost of the city. Example: Paris: -> LeMans (6 ).
			The link cost between those two cities is 6 electros.) :
			*/
			map->displayAdjMatrix();

			//map->displayAdjMatrixWithCosts(); 

			//Get the user input: 
			cout << endl;
			string nameCityWant;
			cout << activePlayers[i]->getName() << ", enter the name of the city that you want : ";
			getline(cin, nameCityWant);


			for (int x = 0; x < map->getListCities().size(); x++) {

				first = false; 

				if (map->getListCities()[x]->getName() == nameCityWant)
				{
					for (int y = 0; y < (map->getListCities()[x]->getHouses().size()); y++) {
						if (map->getListCities()[x]->getHouses()[y]->getColor() == activePlayers[i]->getColor()) {
							break;
						}
						if (map->getListCities()[x]->getHouses()[y]->getColor() == DEFAULTCOLOR) {
							exists = true;
							houseIndex = y;
							cityIndex = x;
							costPrice = map->getListCities()[x]->getHouses()[y]->getPrice();
							break;
						}
					}
				}
			}
			if (exists == false) {
				cout << " CANNOT HAVE THAT CITY. Sorry, try again \(-___-\) " << endl;
				
			}

			else if (activePlayers[i]->getOwnedCities().size() > 0)
			{
				for (int index = 0; index < activePlayers[i]->getOwnedCities().size(); index++) {

					if (map->getLinkCost(activePlayers[i]->getOwnedCities()[index], map->getListCities()[cityIndex]) > 0)
					{
						Linked = true;

						if (linkPrice == 0)
						{
							linkPrice = map->getLinkCost(activePlayers[i]->getOwnedCities()[index], map->getListCities()[cityIndex]);
						}
						if (linkPrice > map->getLinkCost(activePlayers[i]->getOwnedCities()[index], map->getListCities()[cityIndex]))
						{
							linkPrice = map->getLinkCost(activePlayers[i]->getOwnedCities()[index], map->getListCities()[cityIndex]);
						}
					}
				}
			}
			else
			{
				cout << "\n" << activePlayers[i]->getName() << " is charged " << (costPrice) << " for his purchase" << endl;

				activePlayers[i]->decreaseMoney(costPrice);
				activePlayers[i]->addHouseToCity(map->getListCities()[cityIndex], houseIndex);
				first = true; 
			}
			
			if (Linked == false && first == false) {
				cout << " Sorry you cant reach that city. " << endl;
			}
			else if (activePlayers[i]->getMoney() > (costPrice + linkPrice) && Linked == true){
				
				cout << "\n"<< activePlayers[i]->getName() << " is charged " << (costPrice + linkPrice) << " for his purchase." << endl;

				activePlayers[i]->decreaseMoney((costPrice + linkPrice));
				activePlayers[i]->addHouseToCity(map->getListCities()[cityIndex], houseIndex);
			}
			else if (activePlayers[i]->getMoney() < (costPrice + linkPrice)){
				cout << " That's too expansive for the likes of you! " << endl;
			}

			activePlayers[i]->currentPlayerInformation();

			//Ask the user if he or she wants to end his or her turn for this phase: 
			done = terminatePhase();

		} while (activePlayers[i]->getMoney() > 0 && done != true); // keep looking until done != true and until the player has money left 

	}

	cout << "Building Phase ENDS here";
}