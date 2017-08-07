#pragma once
#include "Player.h"
#include "Map.h"
#include "Subject.h"
#include <vector>
#include "PGController.h"

class PGController;

class PGModel : public Subject
{
public:
	PGModel():
		numPlayers(2)
	{
		listActivePlayers.resize(numPlayers);
		for (unsigned int i = 0; i < listActivePlayers.size();++i) {
			listActivePlayers[i] = nullptr;
		}
	}
	PGModel(int numPlayers):
		numPlayers(numPlayers)
	{
		listActivePlayers.resize(numPlayers);
	}
	~PGModel();

	Player* getPlayer(unsigned int index);
	void attachPlayer(Player* newPlayer, unsigned int index);
	void changePlayerInfo();
	

	//attaches the Player at the first empty position
	//void attachPlayer(Player* newPlayer);
private:
	vector<Player*> listActivePlayers;
	int numPlayers;
	PGController* pgController;
};

