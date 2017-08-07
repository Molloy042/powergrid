/*
TEAM U - COMP345 - WINTER2016 

Team members: 

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225) 
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016 

*/



#include "PGController.h"
#include <sstream>


using std::stringstream;
using std::cout;


PGController::PGController()
{

}


PGController::~PGController()
{
	this->model->detach(this);
}

void PGController::update()
{

}

void PGController::inGameEventHandler()
{
	//Commands for the user: 
	string userInput;
	vector<string> commandsList = { 
		"DONE",
		"CLEAR", 
		"SHOW AVAILABLE RESOURCES", 
		"HELP",
		"SHOW MAP",
		"SHOW HOUSE AVAILABILITY",
		"SHOW PLAYER INFO"
	};
	bool isExitingGamePlay = false;
	while (isExitingGamePlay == false) {
		view->drawBackGrid();
		string helpMessage;
		for (unint i = 0;i < commandsList.size();++i) {
			helpMessage += commandsList[i];
			helpMessage += " | ";
		}
		PGWindow* helpWindow = view->displayMsgWindow("HELP", helpMessage, 60);
		delete helpWindow;
		unint option = getUserOption(commandsList);
	
		Sleep(3000); 
		
		switch (option) {

		//EXIT GAME
		case 0:
		{
			isExitingGamePlay = true;
		}
		break;
		//CLEAR
		case 1:
		{
			view->clearScreen();
		}
		break;
		//SHOW AVAILABLE RESOURCES
		case 2:
		{
			view->displayResourceMarket();
		}
		break;
		//HELP
		case 3:
		{
			string helpMessage;
			for (unint i = 0;i < commandsList.size();++i) {
				helpMessage += commandsList[i];
				helpMessage += " | ";
			}
			PGWindow* helpWindow = view->displayMsgWindow("HELP", helpMessage, 60);
			delete helpWindow;
		}
		break;
		// SHOW MAP
		case 4:
		{
			view->displayMap();
		}
		break;
		//SHOW HOUSE AVAILABILITY
		case 5:
		{
			view->displayHouseAvailability();
		}
		break;
		//SHOW PLAYER INFO
		case 6:
		{
			showPlayerInfo();
		}
		break;
		default:
		break;
		};
		
	}

}

unint PGController::getUserOption(vector<string>& listCommands)
{

	unint option= listCommands.size();
	while (true) {
		string userChoice = ""; this->getInput(userChoice, true);

		uppercase(userChoice);

		option = findPos(userChoice, listCommands);
		if (option != listCommands.size()) {
			break;
		}
		else {
			view->drawConsole();
			cout << "That just makes no sense!... ";
			Sleep(500);
		}
	}
	return option;
}

void PGController::showPlayerInfo()
{
	vector<Player*> listPlayers = model->getListPlayers();
	vector<string> playersNames;
	for (unint i = 0; i < listPlayers.size();++i) {
		playersNames.push_back(intToString(i+1) + " " + listPlayers[i]->getName());
	}
	PGWindow* displayPlayerNames = view->displayMsgWindow("Choose a player Id", playersNames, 30);
	int playerID;
	while (true) {
		playerID = getInput2();
		if (playerID > 0 && playerID < (int)listPlayers.size()) {
			break;
		}
	}
	view->displayerPlayerInformation(playerID - 1);
}

void PGController::setNumPlayers()
{
	PGWindow* numPlayersWindow = view->displayMsgWindow("Number Of Players", "Please enter the number of players", 40);
	delete numPlayersWindow;
	int numPlayers; 
	while (true) {
		numPlayers = getInput2();

		if (numPlayers > 1 && numPlayers < 6) {
			break;
		}

		view->drawConsole();
		cout << "Number of players must be between 2 and 5";
		Sleep(500);
	}
	model->setNumPlayers(numPlayers);
}

void PGController::createPlayers()
{
	for (unint i = 0; i < (unint)model->getNumPlayers(); ++i) {
		PGWindow* window = view->displayMsgWindow("Player" + intToString(i+1) + " name", "Please enter the name of the player", 50);
		delete window;
		string namePlayer;
		getInput(namePlayer, true);

		view->clearScreen();
		view->drawBackGrid();

		vector<string> colorList = { "Please choose your color from one of the following: ", "1. RED" , "2. YELLOW" , "3. BLUE" , "4. GREEN", "5. BROWN" };
		window = view->displayMsgWindow("Player" + intToString(i + 1)  + " Color Choice", colorList, 50);
		delete window;

		int playerColorInt;
	
		while (true) {
			playerColorInt = getInput2();
			if (playerColorInt > 0 && playerColorInt < 6) {
				break;
			}

			view->drawConsole();
			cout << "Choose from the range above";
			Sleep(500);
		}

		ColorType playerColor = intToColorType(playerColorInt);
		model->addPlayer(namePlayer, playerColor);
	}
		
	
}

void PGController::startGamePlay()
{}

int PGController::getInput2()
{
	int userInput;
	string inputBuffer;
	while (true) {
		view->drawConsole();
		getline(cin, inputBuffer);
		stringstream ss(inputBuffer);
		if (ss >> userInput) {
			break;
		}
		view->drawConsole();

		cout << "Bad Input!\n";
		Sleep(500);
	}
	
	
	return userInput;
}


bool PGController::endGameOrNah()
{
	string inputBuffer;
	view->clearScreen();
	view->drawBackGrid();
	view->displayMsgWindow("Quit game?", "Quit game? (y/n)", 20);
	getInput(inputBuffer, false);
	view->clearScreen();
	view->drawBackGrid();
	if (inputBuffer == "Y" || inputBuffer == "y") {
		return true;
	}
	else {
		return false;
	}
}





void PGController::initialize(PGModel * model, PGView * view)
{
	this->view = view;
	this->model = model;
	this->model->attach(this);
}


//This function calculates the winner of the game by rearranging the order: 
string PGController::calculateWinner()
{

	model->rearrangeTurn();

	return model->getListPlayers()[0]->getName() + " is the winner in this game of PowerGrid!";

}



//TO BE REMOVED
void PGController::doTest()
{
	view->drawBackGrid();
	PGWindow* test = new PGWindow(2, 2, 5, 20, "");
	test->centerWindow();
	test->drawSimpleWindow();
	delete test;
	view->drawConsole();
}

void PGController::doMenu()
{
	vector<string> menuOptions = { "NEW GAME", "LOAD GAME","EXIT GAME" };
	bool isExitingGame = false;

	while (isExitingGame == false) {


		view->displayMsgWindow("Main Menu", menuOptions, 12);
		
		unint option = getUserOption(menuOptions);
				
		/*

		returns unint option
		param: menuOptions-vector<string>; 
		localVar: userChoice; 
		*/ 

		/*
		while (true) {
			string userChoice = ""; this->getInput(userChoice, true);

			uppercase(userChoice);

			option = findPos(userChoice, menuOptions);
			if (option != menuOptions.size()) {
				break;
			}
			else {
				view->drawConsole();
				cout << "That just makes no sense!... ";
				Sleep(500);
			}
		}
		*/
		switch (option) {
		//NEW GAME
		case 0:
		{
			startNewGame();
		}
		break;
		
		//LOAD GAME
		case 1: 
		{
		}
		break;
		
		//EXIT GAME
		case 2: 
		{ 
			isExitingGame = true;
		}
		break;
		};
		//RESTART LOOP
	}

}

void PGController::startNewGame()
{

	extern bool step2Activated; 
	extern bool step3Activated; 

	view->clearScreen();
	view->drawBackGrid();
	view->displaySplashScreen(); // THIS WILL ALLOW THE USER TO INPUT COMMANDS! Type "DONE" if want to exit. 
	Sleep(2000);
	model->startNewGame();
	setNumPlayers();
	createPlayers();
	model->isGameOn = true;
	vector<PowerPlant*> mpp = model->FullPackCard();

	vector<PhaseType> position = { AUCTION, B_RESOURCES, BUILDING , BUREAUCRACY };
	int index = 0;

	//GAME BEGIN! 

	while (model->checkForWin == false) {

		model->step2(); 
		model->determinePlayerOrder();
		view->clearScreen();
		view->drawBackGrid();
	//	Sleep(3000);
		inGameEventHandler(); // input DONE (UPPERCASE IMPORTANT) if you want to get out of this event handler. 
		view->clearScreen();
		
		
		//Strategy pattern: Enter each phase and execute them sequentially: 
		switch (position[index]) {
		case PhaseType::AUCTION:
		{
			model->currentPhase.setPhaseStrategy(new PowerPlantAuction());
		}
		break;
		case PhaseType::B_RESOURCES:
		{
			model->currentPhase.setPhaseStrategy(new BuyingResources());
		}
		break;
		case PhaseType::BUILDING:
		{
			model->currentPhase.setPhaseStrategy(new Building());
		}
		break;
		case PhaseType::BUREAUCRACY:
		{
			model->currentPhase.setPhaseStrategy(new Bureaucracy());
		}
		break;
		};
		model->currentPhase.thePhasePlayerStrategy(model->getListPlayers(), mpp, model->getMap(), 
			model->getResMarket());

		Sleep(3000);


		index++;

		//After all phases are done, ask to end the game or not:
		if (index >= 4) {

			model->checkForWin = endGameOrNah(); 

			if (model->checkForWin == false) {

				index = 0;
			}
			else {

				view->clearScreen();
				view->drawBackGrid();
				view->displayMsgWindow("Winner is...", calculateWinner(), 60);
				Sleep(5000);
				model->isGameOn = false;
				view->displayMsgWindow("Game Over!", "Game Over!", 13);
				model->checkForWin = true;
			}
		}
	}
	
	view->clearScreen();
	view->drawBackGrid();
	view->drawConsole();
	cout << "Type HELP if you need a list of commands ...";
	Sleep(600);
	view->drawConsole();
	inGameEventHandler();
	view->clearScreen();
	view->drawBackGrid();
}







