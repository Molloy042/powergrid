#include "House.h"


House::House()
{
}


House::~House()
{
}

House::House(ColorType housecolor): color(housecolor)
{
}

ColorType House::getColor()
{
	return color;
}

void House::setColor(ColorType color)
{
	this->color = color;
}