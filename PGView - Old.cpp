#include "PGView.h"
#include "PGModel.h"
#include <Windows.h>
#include "Utility.h"

PGView::PGView(PGModel * PGModel)
{
	cout << "Attaching model ...";
	model = PGModel;
	model->attach(this);
	cout << "Done!\n";

	cout << "Create Controller...";
	makeController();
	cout << "Done!\n";
}

PGView::~PGView()
{
	model->detach(this);
	if (model != nullptr) {
		delete model;
		model = nullptr;
	}
	model->detach(controller);
	if (controller != nullptr) {
		delete controller;
		controller = nullptr;
	}
}

void PGView::displayPlayerInformation()
{
	PGWindow window(5, 2, 7, 30, "Display Player Info");
	window.clearScreen();
	window.drawBackGrid();
	window.drawWindow();
	window.gotoXY(7, 3); cout << model->getPlayer(0)->getName();
	window.gotoXY(26, 3);
	cout << colorTypeToString(model->getPlayer(0)->getColor());
	window.gotoXY(7, 5);
	cout << "Electros : " << model->getPlayer(0)->getMoney();
	window.gotoXY(7, 6);
	cout << "Houses : " << model->getPlayer(0)->getNumHouses();
	window.gotoXY(7, 7);
	cout << "PPlants : " << model->getPlayer(0)->ownedPowerPlants.size();
	window.gotoXY(1, 10);
}

void PGView::update()
{
	displayPlayerInformation();
}

void PGView::drawConsole()
{
	positionCursor(1, 20);
	cout << " Command > ";
}

void PGView::makeController()
{
	controller = new PGController();
}

void PGView::positionCursor(int x, int y)
{
	HANDLE handleStandardOutput;
	CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
	handleStandardOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handleStandardOutput, &consoleScreenBufferInfo);
	consoleScreenBufferInfo.dwCursorPosition.X = x;
	consoleScreenBufferInfo.dwCursorPosition.Y = y;
	SetConsoleCursorPosition(handleStandardOutput, consoleScreenBufferInfo.dwCursorPosition);
}

