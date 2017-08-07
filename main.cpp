/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#include <iostream>
#include "PGGameEngine.h"
#include "ResourceMarket.h"
#include "PGWindow.h"

typedef unsigned int unint;

//Global variable for the different steps of the game. Initially set to false:
bool step2Activated = false;
bool step3Activated = false;


int main()

{
	PGGameEngine game;
	game.run();
	return EXIT_SUCCESS;
}



