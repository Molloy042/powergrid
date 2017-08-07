/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/


#include "Aggressive.h"

void Aggressive::playerPowerPlantAuctionStrategy(Player* player) {
	//Will be implemented for the last build of this project 
}
void Aggressive::playerBuyingRessourcesStrategy(Player* player) {
	//Will be implemented for the last build of this project 

}
void Aggressive:: playerBuildingStrategy(Player* player) {
	//Will be implemented for the last build of this project 

}
void Aggressive:: playerBureaucracyStrategy(Player* player) {

	bool isGood = false;

	//Notifies the strategy of the user on the console (in this case: AGGRESSIVE) :
	cout << "\n" << player->getName() << " strategy is at AGGRESSIVE" << endl;
	
	//Of course, checks if the player has any Power Plant cards in order to power his or her houses: 
	if (player->getOwnedPowerPlants().size() == 0) {

		cout << "BUY SOME POWERPLANT CARDS AT LEAST! You don't have any right now..." << endl;

	}
	//If the player has power plant cards: 
	else
	{
		cout << "You can power your cities now. Here are your information" << endl;

		player->currentPlayerInformation(); // prints the informatin of the user

		string input;
		unsigned input2;

		cout << "\nWhich card would you like to update your Summary card and power your cities?"
			<< "\n-- The cost you'll input must be equal to at least one of your card --" << endl;
		cout << "-- If you input 0 then you are done powering your houses --" << endl;

		int accumulation = 0; // the player should be able to add as many power plant cards in order to power his or her cities.

		while (true) {

			//the user input to decide which powerplant card should be used: 
			getline(cin, input);
			input2 = atoi(input.c_str());

			//If the input is greater then the size of the player's power plant cards, or if the input is negatif 
			// then notify the user for bad input: 
			if (input2 > player->getOwnedPowerPlants().size() || input2 < 0) {
				cerr << "input was not good. Please try again." << endl;
			}
			//If the input is 0, then no card is selected: 
			else if (input2 == 0) {
				break;
			}
			//Else, if the input is > 0 
			else
			{
				if (player->getOwnedPowerPlants()[input2 - 1]->getPrimaryResource() == "Coal") {

					if (player->getOwnedResources()[0].size() >= player->getOwnedPowerPlants()[input2 - 1]->getResourcesNeeded()) {
					 player->removeResources('C', player->getOwnedPowerPlants()[input2 - 1]->getResourcesNeeded());
						isGood = true;
					}
				}
				else if (player->getOwnedPowerPlants()[input2 - 1]->getPrimaryResource() == "Oil") {

					if (player->getOwnedResources()[1].size() >= player->getOwnedPowerPlants()[input2 - 1]->getResourcesNeeded()) {

						player->removeResources('O', player->getOwnedPowerPlants()[input2 - 1]->getResourcesNeeded());
						isGood = true;
					}

					if (isGood == true) {
						if (player->getOwnedPowerPlants()[input2 - 1]->getSecondaryResource() == "Coal") {

							if (player->getOwnedResources()[0].size() >= player->getOwnedPowerPlants()[input2 - 1]->getResourcesNeeded()) {
								isGood = true;
							}
							else {
								isGood = false;
							}
						}
					}

				}
				else if (player->getOwnedPowerPlants()[input2 - 1]->getPrimaryResource() == "Garbage") {

					if (player->getOwnedResources()[2].size() >= player->getOwnedPowerPlants()[input2 - 1]->getResourcesNeeded()) {
						 player->removeResources('G', player->getOwnedPowerPlants()[input2 - 1]->getResourcesNeeded());
						isGood = true;
					}

				}
				else if (player->getOwnedPowerPlants()[input2 - 1]->getPrimaryResource() == "Uranium") {

					if (player->getOwnedResources()[3].size() >= player->getOwnedPowerPlants()[input2 - 1]->getResourcesNeeded()) {

						 player->removeResources('U', player->getOwnedPowerPlants()[input2 - 1]->getResourcesNeeded());
						isGood = true;
					}

				}
				else {

					cout << "You don't Have the necessary resources to power up your houses.";
					isGood = false;

				}
				
				if (isGood == true) {
					// Print the card that will be used to power the city to the console: 
					cout << "\nYou are using "
						<< "[" << player->getOwnedPowerPlants()[input2 - 1]->getBaseCost()
						<< ", PH: " << player->getOwnedPowerPlants()[input2 - 1]->getPoweredHouses()
						<< ", RN: " << player->getOwnedPowerPlants()[input2 - 1]->getResourcesNeeded()
						<< ", PR & SR: " << player->getOwnedPowerPlants()[input2 - 1]->getPrimaryResource();
					if (player->getOwnedPowerPlants()[input2 - 1]->getSecondaryResource() != "") {
						cout << ", " << player->getOwnedPowerPlants()[input2 - 1]->getSecondaryResource() << "] ";
					}
					else {
						cout << ", ****] ";
					}

					//Increment the number of cities that will be powered: 
					accumulation = accumulation + player->getOwnedPowerPlants()[input2 - 1]->getPoweredHouses();
				}

				//repeat the while loop until the user is done powering his or her cities: 
				cout << "\nUse another powered card? (0 means you are done powering your cities)." << endl;

			}
		}
		
		//If the number of powered cities by the power plant card is > then the number of cities on the map 
		// then update the summary card with the number of cities on the map only: 
		if (accumulation > player->getOwnedPowerPlants().size())
		{
			player->getMySummaryCard()->bureaucracy(player->getOwnedPowerPlants().size());
		}
		// Otherwise update the summary card with the accumulation variable: 
		else
		{
			player->getMySummaryCard()->bureaucracy(accumulation);
		}

		//Notify the user with the amount of money he gain: 
		cout << player->getName() << " earned " << player->getMySummaryCard()->getSumElectros() << "$" << endl;
		//Increase his or her money: 
		 
		
			player->increaseMoney(player->getMySummaryCard()->getSumElectros());
		

		//Print the user informaiton to the console: 
		player->currentPlayerInformation();
	}
}