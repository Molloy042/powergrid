#pragma once
#include "PGController.h"
#include "PGModel.h"
#include "PGView.h"



class PGGameEngine
{
public:
	PGGameEngine();
	~PGGameEngine();
	void runGame();
private:
	void initialize();
	bool isOver;
	PGController* pgController;
	PGModel* pgModel;
	PGView* pgView;
};

