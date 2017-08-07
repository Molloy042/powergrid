/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/



#include "BuyingResources.h"
#include <sstream> 
#include <iostream>
#include <string>
using namespace std; 


void BuyingResources::activatePhase(vector <Player*> activePlayers, vector<PowerPlant*> &mpp, Map* map, ResourceMarket* resourceMarket)
{

	std::cout << "\n===== BUYING RESOURCES FOR AUCTION PHASE =====" << endl;

	char selection;

	int units;

	int totalCost;
	bool done = false;

	//I comment it out because it was giving inconsistent results and the cin was messing with the rest... lol 
	int i = 0; 
	while(i < activePlayers.size())
	{

		activePlayers[i]->currentPlayerInformation();

		//	resourceMarket->displayResourceMarket2();
			resourceMarket->displayResourceMarket();

		    cout << "CURRENT PLAYER: " << activePlayers[i]->getName() << " has " << activePlayers[i]->getMoney() << " Elecktrons. " << endl;


			cout << " Which type of resource do you want to buy: \n"

				<< "----------------------------------------------------\n"

				<< "C = Coal \n"

				<< "O = Oil \n"

				<< "G = Garbage \n"

				<< "U = Uranium\n"

				<< "S = Skip\n"

				<< "----------------------------------------------------\n";


				while (true) {
					string input;
					getline(cin, input);
					stringstream ss(input);
					if (ss >> selection)
						break;
					cout << "Bad call!";
				}

				if (selection != 'S') {
				
					cout << "How many units of choice " << selection << "?: " << endl;

					while (true) {
						string input;
						getline(cin, input);
						stringstream ss(input);
						if (ss >> units)
							break;
						cout << "Bad call!";
					}
				}

				switch (selection)

				{
				case 'S':

					//cout << endl; 
					i++;

					break;

				case 'C':

					totalCost = resourceMarket->getCost(COAL, units);

					if (totalCost < activePlayers[i]->getMoney() && units <= resourceMarket->getNumCoal())
					{

						cout << "-> The total cost is " << totalCost << " for " << units << " Coals." << endl;

						activePlayers[i]->purchaseResources(selection, units);
						activePlayers[i]->decreaseMoney(totalCost);
						activePlayers[i]->currentPlayerInformation();
						resourceMarket->removeResources(selection, units); 		
					}

					else { cout << "-> The total cost is " << totalCost << "You don't have enough money: " << activePlayers[i]->getMoney(); }

					break;

				case 'O':

					totalCost = resourceMarket->getCost(OIL, units);

					if (totalCost < activePlayers[i]->getMoney() && units <= resourceMarket->getNumOil()) {


						cout << "-> The total cost is " << totalCost << " for " << units << " Oil." << endl;

						activePlayers[i]->purchaseResources(selection, units);
						activePlayers[i]->decreaseMoney(totalCost);
						activePlayers[i]->currentPlayerInformation();
						resourceMarket->removeResources(selection, units);

					}

					else { cout << "-> The total cost is " << totalCost << "You don't have enough money: " << activePlayers[i]->getMoney(); }

					break;

				case 'G':

					totalCost = resourceMarket->getCost(GARBAGE, units);

					if (totalCost < activePlayers[i]->getMoney() && units <= resourceMarket->getNumGarbage()) {


						cout << "-> The total cost is " << totalCost << " for " << units << " Garbage." << endl;

						activePlayers[i]->purchaseResources(selection, units);
						activePlayers[i]->decreaseMoney(totalCost);
						activePlayers[i]->currentPlayerInformation();
						resourceMarket->removeResources(selection, units);

					}

					else { cout << "-> The total cost is " << totalCost << "You don't have enough money: " << activePlayers[i]->getMoney(); }


					break;

				case 'U':

					totalCost = resourceMarket->getCost(URANIUM, units);

					if (totalCost < activePlayers[i]->getMoney() && units <= resourceMarket->getNumUranium()) {


						cout << "-> The total cost is " << totalCost << " for " << units << " Garbage." << endl;

						activePlayers[i]->purchaseResources(selection, units);
						activePlayers[i]->decreaseMoney(totalCost);
						activePlayers[i]->currentPlayerInformation();
						resourceMarket->removeResources(selection, units);

					}

					else { cout << "-> The total cost is " << totalCost << "You don't have enough money: " << activePlayers[i]->getMoney(); }

					break;

				default:

					cout << "Error. No such type";
				}
				
			//	system("cls"); 
	}
}