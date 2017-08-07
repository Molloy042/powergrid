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
#include "Utility.h"
using std::string;


class House
{
public:
	House();
	House(int price);
	House(ColorType houseColor);
	~House();

	ColorType getColor();
	void setColor(ColorType color);

	void setTaken(bool isTaken);
	bool isTaken();
	bool isPowered();
	void setPower(int n);
	bool hasAColor(); 

	int getNumberOfPoweredComplete() const; 
	int getPrice();


private:

	ColorType color;
	bool taken;
	bool powered; 
	int numOfPoweredComplete;
	int price;



};

