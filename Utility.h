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
#include <string>
using std::string;

enum ColorType
{
	DEFAULTCOLOR = 0, RED = 1, YELLOW = 2, BLUE = 3, GREEN = 4, BROWN = 5
};

enum ResourceType
{
	COAL = 1, OIL = 2, GARBAGE = 3, URANIUM = 4, DEFAULT = 0
};

ColorType intToColorType(int input);
ResourceType intToResourceType(int input);
string colorTypeToString(ColorType color);
string resourceTypeToString(ResourceType resourceType);
string uppercase(string input);
string lowercase(string input);
string intToString(int input);