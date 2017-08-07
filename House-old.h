#pragma once
#include <string>
#include "Utility.h"
using std::string;


class House
{
public:
	House();
	House(ColorType houseColor);
	~House();
	
	ColorType getColor();
	void setColor(ColorType color);

private:
	ColorType color;
};

