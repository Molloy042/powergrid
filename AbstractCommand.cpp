#include "AbstractCommand.h"


AbstractCommand::AbstractCommand(PGController* newController) 
{
	setController(newController);
}

AbstractCommand::~AbstractCommand()
{

}

void AbstractCommand::execute()
{
	controller->startNewGame(); 
}