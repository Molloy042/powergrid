/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#include "Utility.h"
#include <locale>
#include <algorithm>
#include <sstream>

using std::string;
using std::stringstream;
typedef unsigned int unint;

string colorTypeToString(ColorType color)
{
	string outputString;
	switch (color) {
	case ColorType::DEFAULTCOLOR:
	{
		outputString = "None";
	}
	break;
	case ColorType::BLUE:
	{
		outputString = "Blue";
		break;
	}
	case ColorType::GREEN:
	{
		outputString = "Green";
		break;
	}
	case ColorType::RED:
	{
		outputString = "Red";
		break;
	}
	case ColorType::YELLOW:
	{
		outputString = "Yellow";
		break;
	}
	case ColorType::BROWN:
	{
		outputString = "Brown";
		break;
	}

	default:
		break;
	}
	return outputString;
}

ColorType intToColorType(int input)
{
	ColorType color;
	if (input > 0 && input < 5) {
		switch (input) {
		case 0:
		{
			color = ColorType::DEFAULTCOLOR;
			break;
		}
		case 1:
		{
			color = ColorType::RED;
			break;
		}
		case 2:
		{
			color = ColorType::YELLOW;
			break;
		}
		case 3:
		{
			color = ColorType::BLUE;
			break;
		}
		case 4:
		{
			color = ColorType::GREEN;
			break;
		}
		case 5:
		{
			color = ColorType::BROWN;
			break;
		}
		} // end switch

	}
	return color;
}

string resourceTypeToString(ResourceType resourceType)
{
	string convertedResourceType;
	switch (resourceType) {
	case COAL:
		convertedResourceType = "Coal";
		break;
	case OIL:
		convertedResourceType = "Oil";
		break;
	case GARBAGE:
		convertedResourceType = "Garbage";
		break;
	case URANIUM:
		convertedResourceType = "Uranium";
		break;
	default:
		convertedResourceType = "...";
		break;

	};
	return convertedResourceType;
}

string uppercase(string input)
{
	for (unint i = 0; i < input.length();++i) {
		input[i] = toupper(input[i]);
	}
	return input;
}

string lowercase(string input)
{
	transform(input.begin(), input.end(), input.begin(), tolower);
	return input;
}

string intToString(int input)
{
	stringstream converter;
	converter << input;
	return converter.str();
}

ResourceType intToResourceType(int input)
{
	ResourceType resourceType = DEFAULT;
	switch (input) {
	case 1:
		resourceType = COAL;
		break;
	case 2:
		resourceType = OIL;
		break;
	case 3:
		resourceType = GARBAGE;
		break;
	case 4:
		resourceType = URANIUM;
		break;
	default:
		break;
	}
	return resourceType;
}


