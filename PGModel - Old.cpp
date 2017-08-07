#include "PGModel.h"



PGModel::~PGModel()
{}

Player * PGModel::getPlayer(unsigned int index)
{
	if (index >= 0 && index < listActivePlayers.size() && listActivePlayers[index] != nullptr) {
		return listActivePlayers[index];
	}
	else {
		return nullptr;
	}
}

void PGModel::attachPlayer(Player * newPlayer, unsigned int index)
{
	if (newPlayer != nullptr && listActivePlayers[index] == nullptr) {
		listActivePlayers[index] = newPlayer;
	}
}

void PGModel::changePlayerInfo()
{
	
	cout << "Enter new name: "; 
	string newName = pgController->getNewName();
	cout << "Choose color: ";
	ColorType newColor = pgController->getNewColor();
	listActivePlayers[0]->setName(newName);
	listActivePlayers[0]->setColor(newColor);
	this->notify();
}