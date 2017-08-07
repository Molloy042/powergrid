#pragma once
#include "PGModel.h"
#include "Observer.h"
#include "PGWindow.h"


class PGView : public Observer
{
public:
	
	PGView() { }

	PGView(PGModel *PGModel);
	~PGView();
	
	void displayPlayerInformation();
	virtual void update();
	void drawConsole(); //TO BE REPLACED with the drawConsole from PGWindow
	// void activate();
	// void display();
private:
	PGModel* model;
	PGController* controller;
	void positionCursor(int x, int y);
	void makeController();
};

