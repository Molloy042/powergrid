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
#include "Aggressive.h"
#include "Defensive.h"
#include "Random.h"
#include "ResourceMarket.h"

#include<algorithm> // for std::rotate

#include <iostream>
using namespace std;



class PhasesInterface {

public: 


	//change the parameters: Player* activePlayer with the vector of players itself: 

	virtual void activatePhase(vector <Player*> activePlayers, vector<PowerPlant*> &mpp, Map* map, ResourceMarket* resourceMarket) = 0;

	bool terminatePhase() {
		
		string decision; 
		bool returnDecision = false; 

		while (true) {
			cout << "Are you done buying Power Plant cards? Enter \"done\" or \"not done\" " << endl;
			getline(cin, decision);

			//changes the input into uppercase
			transform(decision.begin(), decision.end(), decision.begin(), toupper);

			if (decision == "DONE" || decision == "NOT DONE")
				break;
			cout << "Bad Input!" << endl;
		}



		if (decision == "DONE") {
			returnDecision = true;
		}
		else if (decision == "NOT DONE") {
			returnDecision = false;
		}
		else {
			std::cerr << "Runtime Error: the input was not read correctly." << std::endl;
		}
		

		return returnDecision; 

	}




};

