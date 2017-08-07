/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#include "Bureaucracy.h"

void Bureaucracy::activatePhase(vector <Player*> activePlayers, vector<PowerPlant*> &mpp, Map* map, ResourceMarket* resourceMarket)
{


	cout << "===== POWER PLANT FOR AUCTION PHASE =====" << endl;

	for (unsigned i = 0; i < activePlayers.size(); i++) {

		bool isDefensive = false;
		bool breakFromLoop = false;
		bool isRandom = true;

		cout << activePlayers[i]->getName() << ", would you like to power your city (y/n)?" << endl;

		string inputBuffer;
		getline(cin, inputBuffer);
		
		// If the user wants to power his or her cities then it enters. Otherwise his or her turn ends here.
		if (inputBuffer == "Y" || inputBuffer == "y") {

			//loop through the current player's cities : 
			for (unint y = 0; y < activePlayers[i]->getOwnedCities().size(); y++)
			{
				//loop through the map's cities : 
				for (unint z = 0; z < map->getListCities().size(); z++)
				{
					//check if there is a link cost between each player's city and the map's cities > 0 : 
					if (map->getLinkCost(activePlayers[i]->getOwnedCities()[y], map->getListCities()[z]) > 0)
					{
						for (unint w = 0; w < map->getListCities()[z]->getHouses().size(); w++) {
							//If so, check if that city on the map has the same color then the player's city : 
							if (map->getListCities()[z]->getHouses()[w]->getColor() == activePlayers[i]->getColor())
							{
								isDefensive = true; // set the defensive strategy of the player to true
								isRandom = false; // set the random strategy of the player to false
								break;
							}

							//If the color is not the same for the city on the map and the player's city then... 
							else
							{
								//check if that city is another opponent's city by checking if it has a color AND check if that city is not powered: 
								if (map->getListCities()[z]->getHouses()[w]->hasAColor() && (map->getListCities()[z]->getHouses()[w]->getNumberOfPoweredComplete() == 0))
								{
									//1) aggressive: always choose a power plant for action if the player own a city that has one adjacent opponent
									// city with no powered houses;

									//If that is the case, then set the set the strategy to aggressive: 
									activePlayers[i]->setStrategy(new Aggressive());

									breakFromLoop = true; // break from the first for loop
									isDefensive = false; // set the defensive strategy to false 
									isRandom = false; // set the random strategy to false
									break; // break from the third for loop 
								}
								break; // break from the second for loop 
							}
							break;
						}
					}
				}

				if (breakFromLoop == true)
				{
					break; // break from the first for loop
				}
			}

			if (isDefensive == true)
			{
				//2) defensive: never power unless the player owned a city for which all adjacent houses are his / hers;
				activePlayers[i]->setStrategy(new Defensive());

			}
			if (isRandom == true)
			{
				//3) random: randomly choose between powering houses or not, then if powering, choose a random valid target house.
				activePlayers[i]->setStrategy(new Random());
			}

			// ACTIVATE THE STRATEGY OF THE PLAYER: 
			activePlayers[i]->thePlayerStrategy();
		}
	}
}