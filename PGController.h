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
class AbstractCommand;

#include "Observer.h"
#include "PGModel.h"
#include "PGView.h"
//#include <utility>

class PGModel;
class PGView;


using std::string;


class PGController : public Observer
{

public:
	
	PGController();
	~PGController();

	void initialize(PGModel* model, PGView* view);
	void doTest();
	void doMenu();
	void startNewGame();
	template <typename T> void getInput(T& userInput, bool isReturningFullSentence);
	virtual void update();

	//This function calculates the winner of the game by rearranging the order: 
	string calculateWinner(); 

	
private:
	PGView* view;
	PGModel* model;
	void inGameEventHandler();
	unint getUserOption(vector<string>& listCommands);
	void showPlayerInfo();
	void setNumPlayers();
	void createPlayers();



	void startGamePlay();
	bool endGameOrNah();

	inline unint findPos(string input, vector<string> items)
	{
		for (unint i = 0; i < items.size(); ++i) {
			if (items[i] == input) {
				return i;
			}
		}
		return (unint) items.size();
	}
	int getInput2();
};

template<typename T>
inline void PGController::getInput(T & userInput, bool isReturningFullSentence)
{
	
	while (true) {
		string inputBuffer;
		
		view->drawConsole();
		getline(cin, inputBuffer);
		// THERE HAS TO BE A BETTER WAY! THIS IS A BAD SMELL!!!
		if (isReturningFullSentence == true) {
			userInput = inputBuffer;
			break;
		}

		stringstream ss(inputBuffer);
		if (ss >> userInput) {
			break;
		}
		
		view->drawConsole();
		
		cout << "Bad Input!\n";
		Sleep(500);
	}
}
