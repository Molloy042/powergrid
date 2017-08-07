/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/


#include "PowerPlantObserverView.h"
#include "PowerPlantAuction.h"

using namespace std; 

int totalMoney = 0; 

//This function is not used for this assignment but the logic is there... 
Player* bid(vector<Player*> &copyplayerList, PowerPlant* card) 
{

	int counter = 1;
	string input;
	int input2;
	int increaseMinBid; 
	int bid = 0;

	std::cout << copyplayerList[0]->getName() << " have selected the power plant card: " 
			  << *card << endl;

	if (copyplayerList.size() > 1) 
	{
		cout << "Add extra amount to the minimum bid: " << card->getBaseCost() << endl;

		getline(cin, input);
		increaseMinBid = atoi(input.c_str());

		bid = card->getBaseCost() + increaseMinBid;

		cout << "\nWHO WINS IT GETS ITS!" << endl;
	}
	else 
	{
		bid = card->getBaseCost();

	}

	vector<Player*> copy = copyplayerList; 


	while (copy.size() > 1)
	{ 
		std::cout << "\nThe current amount of the card is " << bid << endl;
		cout << endl; 
		std::cout << copy[counter % copy.size()]->getName() << ", do you want to bid or skip? " << endl;
		
		cout << "---------------------------------\n" << endl;

		std::cout << "Enter: bid or skip: ";

		getline(cin, input);
		cout << endl; 

		if (uppercase(input) == "SKIP" || copy[counter % copy.size()]->getMoney() < bid)
			{
				if (copy[counter % copy.size()]->getMoney() < bid) 
				{
					std::cout << "... Player " << copy[counter % copy.size()]->getName() 
						<< " you can't keep up with the bidding of this round. Sorry your turn is now skipped." << endl;
				}
				else
				{
					std::cout << "Player " << copy[counter % copy.size()]->getName() << " skipped" << endl;
				}
				copy.erase(copy.begin() + (counter % copy.size()));

			}
		
		else if(uppercase(input) == "BID")
			{
				std::cout << "->" << copy[counter % copy.size()]->getName() << " bids: ";
				getline(cin, input);
				input2 = atoi(input.c_str());
				bid = bid + input2; 
				counter++; 
			}
		else 
			{

				std::cout << "Wrong input. Please try again." << endl;
			}
		}

		cout << "---------------------------------" << endl;

		totalMoney = bid;

		return copy[0];
				
		for (Player* item : copy)
		{
		delete item;
		}
	}	
	
void PowerPlantAuction::activatePhase(vector <Player*> activePlayers, vector<PowerPlant*> &mpp, Map* map, ResourceMarket* resourceMarket) {
	
	std::cout << "\n===== POWER PLANT FOR AUCTION PHASE =====" << endl;

	vector<Player*> copyListPlayer = activePlayers; 


		//child of Subject class:  
		PowerPlantMarket market;

		//Observer: 
		PowerPlantObserverView test = PowerPlantObserverView(mpp);

		//Attach the Observer object test to the market subject: 
		market.Attach(&test);

		Player* aPlayer; 

		test.displayerPowerPlantMarket();

		while(copyListPlayer.size() > 0 ) {
			/*
			Input represent the card's number that the user wants to remove.
			If input = 0, it means that the view stay unchanged.
			*/
				std::cout << "\nPlease " << copyListPlayer[0]->getName()
					<< " input the card you'd like to remove from the PowerPlant Market."
					<< "\n(0 means: you are skipping this turn)" << endl;


				string input;
				int input2;
				getline(cin, input);
				input2 = atoi(input.c_str());


				/*if user's input is between the range of the current market,
				then show the card that shall be removed and print the powerplant market.*/

				if (input2 > 0 && input2 < 5)
				{
					cout << "\n BE READY TO PLACE YOUR BID!" << endl;
					cout << "---------------------------------" << endl;

					aPlayer = bid(copyListPlayer, test.getShuffledDeck()[input2 - 1]);

					for (int z = 0; z < activePlayers.size(); z++) {

						if (activePlayers[z]->getName() == aPlayer->getName()) {
							
							market.deletePowerCardFromMarket(input2, activePlayers[z], mpp);
							activePlayers[z]->decreaseMoney(totalMoney);

							//Print the player's information to the console: 
							activePlayers[z]->currentPlayerInformation();

							copyListPlayer.erase(copyListPlayer.begin() + (z % copyListPlayer.size())); 

							//break;
						
						}
					}
				}
				/*else if the user's input is between the range of the future market,
				then send an error message. */
				else if (input2 >= 5 && input2 < 9) {
				std::	cout << "\nYou can't select cards from the FUTURE MARKET."
						<< "\nPlease select from the ACTUAL MARKET (during the two phases of this game).\n" << endl;
				}
				else if (input2 == 0)
				{
					std::cout << copyListPlayer[0]->getName() << " skipped this turn. " << endl;
					copyListPlayer[0]->currentPlayerInformation(); 
					copyListPlayer.erase(copyListPlayer.begin());
				}
				else 
				{
					std::	cout << "Wrong input" << endl;
				}
			}

		std::cout << "Power Plant for Auction Phase ENDS. ";

		//delete aPlayer; 
		
		for (Player* item : copyListPlayer) 
		{
			delete item;
		}
	} 
