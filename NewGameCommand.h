#pragma once
#include "AbstractCommand.h"

class NewGameCommand :public AbstractCommand
{
public:
	NewGameCommand(PGController* newController);
	~NewGameCommand() {}
	virtual void execute();
		
};
