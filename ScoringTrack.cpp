/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#include "ScoringTrack.h"
#include <fstream>


ScoringTrack::ScoringTrack()
{
	activePlayers.resize(2);
}


ScoringTrack::~ScoringTrack()
{}

void ScoringTrack::attachPlayer(unint playerNumber, PlayerPtr attachedPlayer)
{
	activePlayers[playerNumber] = attachedPlayer;
}

void ScoringTrack::refresh()
{
	for (unint i = 0; i <= activePlayers.size(); ++i) {
		playerScore[i] = activePlayers[i]->getNumHouses();
	}
}

void ScoringTrackLoad(ScoringTrack & loadTgtScoringTrack, const string filename)
{
	std::ifstream inputFileStream(filename.c_str(), std::ios::binary);
	boost::archive::binary_iarchive inputArchive(inputFileStream);
	inputArchive >> loadTgtScoringTrack;
}

void ScoringTrackSave(ScoringTrack & savedScoringTrack, const string filename)
{
	std::ofstream outputFileStream(filename.c_str(), std::ios::binary);
	boost::archive::binary_oarchive outputArchive(outputFileStream);
	outputArchive << savedScoringTrack;
}
