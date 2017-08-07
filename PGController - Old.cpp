#include "PGController.h"
#include <sstream>
using std::stringstream;

// changes what the controller can do
void PGController::update()
{

}

PGController::PGController()
{}

PGController::PGController(PGModel* newPGModel)
{
	pgModel = newPGModel;
}


PGController::~PGController()
{}

bool PGController::getInput()
{
	string userInput;
	getline(cin, userInput);
	userInput = uppercase(userInput);
	if (userInput == "MODIFY PLAYER INFO") {
		pgModel->changePlayerInfo();
		return false; // game not over
	}
	if (userInput == "EXIT")
		return true; // game over
}

string PGController::getNewName()
{
	string userInput;
	getline(cin, userInput);
	return userInput;
}

ColorType PGController::getNewColor()
{
	int userInput;
	while (true) {
		string inputBuffer;
		getline(cin, inputBuffer);
		std::stringstream ss(inputBuffer);
		if (ss >> userInput) {
			if (userInput > 0 && userInput < 5) {
				break;
			}
		}
		cout << "Invalid input!" << endl;
	}
	return intToColorType(userInput);
}




