#pragma once

class PGController;

class AbstractCommand
{
protected:
	PGController* controller;
public:
	//AbstractCommand() {}
	AbstractCommand(PGController*);
	~AbstractCommand();
	
	virtual void execute() = 0;
	inline PGController* getController () { return controller; }
	inline void setController(PGController* newController) { controller = newController; }

};