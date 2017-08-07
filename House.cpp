/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/


#include "House.h"


House::House()
{

	this->taken = false;
	this->powered = false;
	this->numOfPoweredComplete = 0;
	this->color = DEFAULTCOLOR;
	this->price = 10;
}

House::House(int price) {
	this->taken = false;
	this->powered = false;
	this->numOfPoweredComplete = 0;
	this->color = DEFAULTCOLOR;
	this->price = price;
}

House::~House()
{
}

House::House(ColorType housecolor) : color(housecolor)
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

bool House::hasAColor() {

	if (this->color != DEFAULTCOLOR) {
		return true;
	}
	else {
		return  false;
	}
}


void House::setTaken(bool isTaken) {
	this->taken = isTaken;
}


bool House::isTaken() {

	if (taken == true) {
		return true;
	}
	else {
		return false;
	}
}

bool House::isPowered() {
	if (this->powered == true) {
		return true;
	}
	else {
		return false;
	}
}
void House::setPower(int n) {

	this->powered = true;

	this->numOfPoweredComplete = n;
}

int House::getNumberOfPoweredComplete() const {
	return this->numOfPoweredComplete;
}

int House::getPrice() {
	return this->price;
}

