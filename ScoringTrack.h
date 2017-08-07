/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#pragma once
#include "Player.h"
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>

// must load in the future from PlayerList from GameController. Forcing 2 player mode, now!
// IMPORTANT NOTE: the activePlayers vector isn't loaded. IN ALL CASES, before calling this function the players must be loaded, beforehand

class ScoringTrack
{
	typedef Player* PlayerPtr;
	typedef unsigned int unint;
public:
	ScoringTrack();
	~ScoringTrack();
	void attachPlayer(unint playerNumber, PlayerPtr attachedPlayer);
	void refresh();
	void displayScore() { 
		for (unint i = 0; i < activePlayers.size(); ++i) {
			cout << "Player " << i+1 << " = " << activePlayers[i]->getNumHouses() << endl;
		}
	};
	friend void ScoringTrackLoad(ScoringTrack &loadTgtScoringTrack, const string filename);
	friend void ScoringTrackSave(ScoringTrack &savedScoringTrack, const string filename);

private:
	
	vector<PlayerPtr> activePlayers;
	vector<unint> playerScore;
	friend class boost::serialization::access;
	
	//BOOST SERIALIZATION
	template<class Archive>
	void serialize(Archive & boostArchive, const unsigned int version)
	{
		boostArchive & playerScore;
	}
};

