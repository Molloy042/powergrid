#pragma once
#include "Observer.h"
#include "PGModel.h"

class PGModel;

class PGController : public Observer
{

public:
	
	PGController();
	PGController(PGModel* newPGModel);
	~PGController();

	virtual void update();
	bool getInput();
	string getNewName();
	ColorType getNewColor();
private:
	PGModel* pgModel;
};

