/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#include "PGView.h"
#include "PGModel.h"
#include "PGController.h"
#include "Utility.h"
#include <string>

PGView::~PGView()
{
	delete controller;
	this->model->detach(this);
	delete handler;
}

void PGView::initialize(PGModel* model)
{
	this->model = model;
	this->model->attach(this);
	this->handler = new PGWindow;
	controller = makeController();
	controller->initialize(model, this);
}

void PGView::displayPlayerInformation()
{
	PGWindow window(5, 2, 7, 30, "Display Player Info");
	window.clearScreen();
	window.drawBackGrid();
	window.drawWindow();
	//window.gotoXY(7, 3); cout << model->getPlayer(0)->getName();
	window.gotoXY(26, 3);
	//cout << colorTypeToString(model->getPlayer(0)->getColor());
	window.gotoXY(7, 5);
	//cout << "Electros : " << model->getPlayer(0)->getMoney();
	window.gotoXY(7, 6);
	//cout << "Houses : " << model->getPlayer(0)->getNumHouses();
	window.gotoXY(7, 7);
	//cout << "PPlants : " << model->getPlayer(0)->ownedPowerPlants.size();
	window.gotoXY(1, 10);
}

void PGView::displayResourceMarket()
{
	ResourceMarket* resMarket = model->getResMarket();
	vector<CoalPtr> coalPtrs = resMarket->getCoalPtrList();
	vector<OilPtr> oilPtrs = resMarket->getOilPtrList();
	vector<GarbagePtr> garbPtrs = resMarket->getGarbagePtrList();
	vector<UraniumPtr> uranPtrs = resMarket->getUraniumPtrList();
	
	string row1 = "_C_O_A_L_";
	string row3 = "";
	string row5 = "_O_I_L_";
	string row7= "";
	string row9 = "_G_A_R_B_A_G_E_";
	string row11 = "";
	string row13 = "_U_R_A_N_I_U_M_";
	string row15 = "";

	for (unint i = 0;i < MAX_COAL; ++i) {
		row3 += ((coalPtrs[i] == nullptr) ? "_ " : (intToString(resMarket->getUnitCost(COAL, i))) + " ");
	}
	
	for (unint i = 0;i < MAX_OIL;++i) {
		row7 += ((oilPtrs[i] == nullptr) ? "_ " : (intToString(resMarket->getUnitCost(OIL, i))) + " ");
	}

	for (unint i = 0;i < MAX_GARBAGE;++i) {
		row11 += ((garbPtrs[i] == nullptr) ? "_ " : (intToString(resMarket->getUnitCost(GARBAGE, i))) + " ");
	}

	for (unint i = 0;i < MAX_URANIUM;++i) {
		row15 += ((uranPtrs[i] == nullptr) ? "_ " : (intToString(resMarket->getUnitCost(URANIUM, i))) + " ");
	}


	string title = "Market Content : ";
	vector<string> msgRows = { row1, "", row3, "", row5, "", row7, "", row9, "", row11, "", row13, "", row15 };

	PGWindow* resMktWindow = displayMsgWindow(title, msgRows, 50);
	delete resMktWindow;
}

void PGView::displaySplashScreen()
{
	
	string title = "     Welcome to Concordia 2016 POWER GRID!";
	string row1 = "";
	string row2 = "                        _____";
	string row3 = "                     .-'     '-.";
	string row4 = "                   .'           `.";
	string row5 = "                  /   .      .    \\" ;
	string row6 = "                 :                 :";
	string row7 = "                 |                 |";
	string row8 = "                 :   \\        /    :";
	string row9="                  \\   `.____.'    /";
	string row10="                   `.           .'";
	string row11="                     `-._____.-'";
	string row12="";
	string row13="";
	string row14="   By Audrey-Ann JW, Catalin P, Marco L and Andre M";
	vector<string> msgRows = { row1,row2,row3,row4,row5,row6,row7,row8,row9,row10,row11,row12,row13,row14 };
	PGWindow* handleWindow = displayMsgWindow(title, msgRows, 60);
	delete handleWindow;
}

void PGView::displayMap()
{
	string title = "Map";
	Map* map = model->getMap();
	map->updateListCities();
	vector<string> rows;
	for (unint i = 0; i < map->getListCities().size();++i) {
		string currentRow = map->getListCities()[i]->getName() + ": \t ";
		//rows.push_back(currentRow);
		
		for (unsigned int j = 0; j < map->getListCities().size();++j) {

			if (map->adjacencyMatrix[i][j].isLinked == true) {
				currentRow += map->getListCities()[j]->getName().c_str();
				currentRow += "(";
				currentRow += intToString(map->getLinkCost(map->getListCities()[i], map->getListCities()[j]));
				currentRow += ")\t";
					
			}

		}
		rows.push_back(currentRow);
	}
	PGWindow* mapDisplay = displayMsgWindow(title, rows, 60);
	delete mapDisplay;
}

void PGView::displayHouseAvailability()
{
	string title = "House Availabilities : ";
	Map* map = model->getMap();
	map->updateListCities();
	vector<string> rows;
	for (unint z = 0; z < map->getListCities().size(); z++) {

		for (unint d = 0; d < map->getListCities()[z]->getHouses().size(); d++) {

		string rowA = map->getListCities()[z]->getName() + " houses availability: ";
		string rowB = intToString(d+1) + ". House " + intToString((int)map->getListCities()[z]->getHouses()[d]->isTaken())  + " is owned by " + colorTypeToString(map->getListCities()[z]->getHouses()[d]->getColor());

		rows.push_back(rowA);
		rows.push_back(rowB);

		}
	}

	PGWindow* houseAvailWindow = displayMsgWindow(title, rows, 30);
	delete houseAvailWindow;
}

void PGView::displayerPlayerInformation(int index)
{
	Player* player = model->getListPlayers()[index];
	
	
	string topRow = "  Name  Money  # PowerPlant Cards  # Owned Cities  # Powered Cities\n";

	

	string currentRow = "   " + player->getName() + " " + intToString(player->getMoney()) + "               " + intToString(player->getOwnedPowerPlants().size()) + "               " + intToString(player->getOwnedCities().size()) + "                "
		+ intToString(player->getMySummaryCard()->getSumHouse());



	string currentRow2 = "                                                                      ";
	currentRow2 += "  Power plant cards:                                                  ";

	for (unsigned i = 0; i < player->getOwnedPowerPlants().size(); i++) {
		currentRow2 += "  " + intToString(i + 1) + ". " + "\nYou are using ["
			+ intToString(player->getOwnedPowerPlants()[i]->getBaseCost())
			+ ", PH: " + intToString(player->getOwnedPowerPlants()[i]->getPoweredHouses())
			+ ", RN: " + intToString(player->getOwnedPowerPlants()[i]->getResourcesNeeded())
			+ ", PR & SR: " + player->getOwnedPowerPlants()[i]->getPrimaryResource();
		if (player->getOwnedPowerPlants()[i]->getSecondaryResource() != "") {
			currentRow2 += ", " + player->getOwnedPowerPlants()[i]->getSecondaryResource() + "] ";
		}
		else {
			currentRow2 += ", ****] ";
		}
	}
	

	string currentRow5 = "  Resources:                                                         ";
	string currentRow6 = "  # Coal -> " + intToString (player->getOwnedResources()[0].size());
	string currentRow7 = "  # Oil -> " + intToString(player->getOwnedResources()[1].size()) ;
	string currentRow8 = "  # Garbage -> " + intToString(player->getOwnedResources()[2].size());
	string currentRow9 = "  # Uranium -> " + intToString(player->getOwnedResources()[3].size());
	string currentRow10 = "  ";
	string currentRow11 = "  Owned Cities:                                                        ";
	string currentRow12 = "  ";
	for (unsigned i = 0; i < player->getOwnedCities().size(); i++) {
		currentRow12 += player->getOwnedCities()[i]->getName() + " - ";
	}

	vector<string> rows = { topRow, currentRow, currentRow2, "" ,currentRow5, currentRow6, currentRow7, currentRow8, currentRow9, currentRow10, currentRow11, currentRow12 };
	string title = "Player Information for player " + intToString(index + 1);
	
	PGWindow* newWindow = displayMsgWindow(title, rows, 50);
	delete newWindow;
}



void PGView::update()
{
	// needs a flag-check system
	displayPlayerInformation();
}

void PGView::drawConsole()
{
	handler->drawConsole();
}

void PGView::drawBackGrid()
{

	extern bool step2Activated;
	extern bool step3Activated;
		

	handler->drawBackGrid();

	if (model->isGameOn == true) {
		vector<Player*> listPlayers = model->getListPlayers();
		handler->gotoXY(30, 15); cout << "Current Player Order : |";
		for (unint i = 0;i < listPlayers.size();++i) {
			cout << listPlayers[i]->getName() << " | ";
		}
		handler->gotoXY(30, 16); cout << "Current Step : " << (step2Activated == true) ? "2" : "1";
		handler->gotoXY(17, 2); cout << (step3Activated == true) ? "3" : "2";
	}
	handler->drawConsole();
}

PGWindow* PGView::displayMsgWindow(string title, string message, unint cols)
{
	unint rows = (unint) message.size() / cols + 1;
	vector<string> tokenizedMessage = processMessageIntoRows(message,cols, rows);

	return displayMsgWindow(title, tokenizedMessage, cols);
}

PGWindow* PGView::displayMsgWindow(string title, vector<string> tokenizedMessage, unint cols)
{
	unint rows = (unint) tokenizedMessage.size();

	PGWindow* msgWindow = new PGWindow(1, 1, rows + 3, cols + 2, title);
	msgWindow->centerWindow();
	

	msgWindow->drawWindow();
	unint topX = msgWindow->getPosX();
	unint topY = msgWindow->getPosY();

	unint currentRow = 0;
	for (unint i = topY + 3;i < topY + 3 + rows; ++i) {
		msgWindow->gotoXY(topX + 1, i);
		cout << tokenizedMessage[currentRow];
		++currentRow;
	}

	return msgWindow;
}

PGController* PGView::getController()
{
	return controller;
}

PGController* PGView::makeController()
{
	return new PGController;
}

vector<string> PGView::processMessageIntoRows(string message, unint cols, unint rows)
{
	vector<string> tokenizedMessage;
	unint currentPos = 0;
	for (unint i = 0;i < rows;++i) {
		string buffer = message.substr(currentPos, cols);
		tokenizedMessage.push_back(buffer);
		currentPos = currentPos + cols;
	}
	return tokenizedMessage;
}

