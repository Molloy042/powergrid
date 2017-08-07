/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/


#include"PowerPlantObserverView.h"
#include <iostream>
#include <string>
#include <random>
#include<algorithm>
#include <sstream>



using namespace std;


// NO variables in object class use getters. 

//Default Constructor 
PowerPlantObserverView::PowerPlantObserverView() {
}
//CONSTRUCTOR: 
PowerPlantObserverView::PowerPlantObserverView(vector<PowerPlant*> &mpp) {

	
	this->shuffledDeck = mpp;
	
	//GLOBAL VARIABLE FOR STEP 2: 
	extern bool step2Activated;
	extern bool step3Activated; 

	if (shuffledDeck[7]->getBaseCost() == 9999) {
		step3Activated = true;
		cout << "We are now in Step 3" << endl; 
	}

	bool executeOnce = true;

	//WE ARE STILL IN STEP1:
	if (step2Activated == false) {
		bool executeOnce = false;
	}

	//the step 3 reshuffle method———————————:
	if (step3Activated == true) {

		if (shuffledDeck[7]->getBaseCost() == 9999) {

			shuffledDeck.erase(shuffledDeck.begin() + 8);
		}

		else {

			shuffledDeck.erase(shuffledDeck.begin());
		}
	}


	//IF WE ARE IN STEP2: 
	if (step2Activated == true && executeOnce == true) {
		//remove the first card on the power plant market! 
		cout << "WE HAVE REMOVED THE LOWEST POWER PLANT CARD "
			<< *shuffledDeck[0]
			<<" FROM THE DECK BECAUSE WE ARE IN PHASE 2" << endl;
		shuffledDeck.erase(shuffledDeck.begin());
	}
	
	// shuffles the deck of card after the first 9 cards (in order to respect the game's rules) 
	std::random_shuffle(shuffledDeck.begin() + 9, shuffledDeck.end());

	//2D instance array:
	powerPlantMarket = new PowerPlant*[POWERPLANTMARKET_ROWSIZE];
	//initialize 2D array: 
	for (int i = 0; i < 2; i++) 
	{
		powerPlantMarket[i] = new PowerPlant[POWERPLANTMARKET_COLSIZE];
	}
}

//DESTRUCTOR: 

PowerPlantObserverView::~PowerPlantObserverView() {
	//Kill 2d Array:
	for (int i = 0; i < 2; ++i)
	{
		delete[] this->powerPlantMarket[i];
	}
	
	/* DELETE THAT AT THE VERY END OF THE GAME! 
	for (PowerPlant* item : shuffledDeck)
	{
		delete item;
	}*/

	delete[] this->powerPlantMarket;
	this->powerPlantMarket = NULL;
}

/*
This function compares two object pointers of type PowerPlant.
It is used in order to sort the first 8 cards of the vector shuffledDeck.
Returns false if the first object is greater than the second object.
Returns true otherwise.
*/
bool compare(PowerPlant* card1, PowerPlant* card2)
{
	return card1->getBaseCost() < card2->getBaseCost();
}

/*
The update function which calls the right function for the view and
handles the user's input and thus changes the behavior of the view
accordingly.
*/
void PowerPlantObserverView::Update(int choice, Player* player, vector<PowerPlant*> &mpp) {

	if(choice > 0){
		
		showRemovedCard(choice);

		//add the card to the player's Power Plant deck:
		player->ownedPowerPlants.push_back(shuffledDeck[choice - 1]);



		unsigned findIndex = std::find(mpp.begin(),mpp.end(), shuffledDeck[choice - 1]) - mpp.begin();
		
		if (findIndex >= mpp.size()) {
			cout << "OUPS" << endl; 
		}

		mpp.erase(mpp.begin() + findIndex); 

		//erase the removed card from the shuffled deck at the proper index: 
		shuffledDeck.erase(shuffledDeck.begin() + (choice - 1));
			
		cout << "\nNow, the PowerPlant Market looks like : " << endl;
		//Display PowerPlant Market: 
		displayerPowerPlantMarket();


	}
	/*else if the user's input is lower than 1, just print the powerplant
	market as it is. */
	else {
		//Display PowerPlant Market (display as it is without removing): 
		displayerPowerPlantMarket();
	}
}


vector <PowerPlant*> PowerPlantObserverView:: getShuffledDeck() const {

	return shuffledDeck; 

}



/*If a card shall be removed from the array 2x4 cards, then
show the card into the view*/
void PowerPlantObserverView::showRemovedCard(int choice) {

	cout << "\nYou have removed card " << choice << " : "
		<< *shuffledDeck[choice - 1]; // calls the operator overload (ostream - <<)
									  // function from the powerplant class
}

void PowerPlantObserverView::displayerPowerPlantMarket() {

	//as long that the shuffledDeck's size is greater than 8 then: 
	if (shuffledDeck.size() > 8) {
		//Each time you print, sort and "rebuild" the PowerPlant Market: 
		sort(shuffledDeck.begin(), shuffledDeck.end() - (shuffledDeck.size() - 8), compare);

		int interatorIndexForCard = 0;

		//For-loop which stores the shuffledDeck vector values into the 2x4 array: 
		for (int x = 0; x < POWERPLANTMARKET_ROWSIZE; x++) {

			for (int y = 0; y < POWERPLANTMARKET_COLSIZE; y++) {
				powerPlantMarket[x][y] = *shuffledDeck[interatorIndexForCard];
				interatorIndexForCard++;
			}
		}

		//Print the powerplant market (2x4 array of cards)  
		std::cout << "\n************* ACTUAL MARKET *************\n" << endl;
		for (int displayIndex = 0; displayIndex < POWERPLANTMARKET_ROWSIZE; displayIndex++) {

			for (int z = 0; z < POWERPLANTMARKET_COLSIZE; z++) {

				//operator overloading of << from PowerPlant.h is used to print each cards with all its info:
				std::cout << powerPlantMarket[displayIndex][z];

			}
			if (displayIndex == POWERPLANTMARKET_ROWSIZE - 1) {
				std::cout << "\nEnd of displaying PowerPlant Cards" << endl;
			}
			else {
				std::cout << "\n************* FUTURE MARKET *************\n" << endl;
			}
		}
	}
	//if the shuffled deck is down to only 8 cards, then print it from the shuffled deck: 
	else {

		//Sort the shuffled deck: 		
		sort(shuffledDeck.begin(), shuffledDeck.end(), compare);

		std::cout << "\n************* ACTUAL MARKET *************\n" << endl;

		for (unsigned finalIndices = 0; finalIndices < shuffledDeck.size(); finalIndices++) {

			if (finalIndices == 4) {
				cout << "\n************* FUTURE MARKET *************\n" << endl;
			}

			std::cout << *shuffledDeck[finalIndices];
		}

		std::cout << "\nEnd of displaying PowerPlant Cards" << endl;

		if (shuffledDeck.size() == 0) {
			std::cout << "\nPHASE 3 IS ACTIVATED!" << endl;
		}
	}

}

