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
#include "Observer.h"
#include "PGModel.h"
#include "PGController.h"
#include "PGWindow.h"

#include <sstream>
#include <stdlib.h>

class PGModel;
class PGController;

class PGView : public Observer
{
public:
	
	PGView() { }
	~PGView();
	
	void initialize(PGModel* model);

	//id=0
	void displayPlayerInformation();
	void displayerPlayerInformation(int index);
	//id=1
	void displayResourceMarket();
	void displaySplashScreen();
	void displayMap();
	void displayHouseAvailability();


	virtual void update();
	void drawConsole();
	void drawBackGrid();
	PGWindow* displayMsgWindow(string title, string message, unint cols);
	PGWindow* displayMsgWindow(string title, vector<string> tokenizedMessage, unint cols);
	template<typename T>
	void inputWindow(string title, string question, T& userInput, bool isReturningFullSentence);

	PGController* getController();

	inline void clearScreen() const { handler->clearScreen(); }

private:
	PGController* controller;
	PGModel* model;
	PGWindow* handler;

	PGController* makeController();
	vector<string> processMessageIntoRows(string message, unint numCols, unint numRows);
};

template<typename T>
void PGView::inputWindow(string title, string question, T& userInput, bool isReturningFullSentence)
{
	PGWindow* inputBox = this->displayMsgWindow(title, question, 40);

	unint rows = inputBox->getRows();
	unint cols = inputBox->getCols();

	unint topX = inputBox->getPosX();
	unint topY = inputBox->getPosY() + rows + 1;

	while (true) {
		string inputBuffer;

		//clear the input line(in case of previous input
		inputBox->gotoXY(topX, topY);
		for (unint i = 0;i < cols;++i) {
			cout << " ";
		}

		//draw input line
		inputBox->gotoXY(topX, topY);
		cout << "|";
		inputBox->gotoXY(topX + cols, topY);
		cout << "|";

		//draw bottom
		inputBox->gotoXY(topX, topY + 1);
		cout << "+";
		for (unint i = 0;i < cols;++i) {
			cout << "-";
		}
		cout << "+";

		//reposition and ask for input
		inputBox->gotoXY(topX + 2, topY);
		getline(cin, inputBuffer);

		// THERE HAS TO BE A BETTER WAY! THIS IS A BAD SMELL!!!
		if (isReturningFullSentence == true) {
			userInput = inputBuffer;
			break;
		}

		std::stringstream ss(inputBuffer);
		if (ss >> userInput) {
			break;
		}
		
		//clear the input line(in case of previous input
		inputBox->gotoXY(topX, topY);
		for (unint i = 0;i < cols;++i) {
			cout << " ";
		}

		//draw input line
		inputBox->gotoXY(topX, topY);
		cout << "|";
		inputBox->gotoXY(topX + cols, topY);
		cout << "|";

		//inform user about bad input
		inputBox->gotoXY(topX + 2, topY);
		cout << "Invalid input !";
		Sleep(500);
	}
	delete inputBox;
}
