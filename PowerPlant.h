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
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;


class PowerPlant {

private:

	int baseCost;
	int poweredHouses;
	int resourcesNeeded; //needed to power the plant (Type match is checked in bool canBeTurnedOn)
	string primaryResource;
	string secondaryResource;

public:

	//Default constructor:
	PowerPlant();
	//Constructor: 
	PowerPlant(int bc, int ph, int rNeeded, string pR, string sR); //resources needed x 2 will essentially set the size of the powerplant's vector
																   //Destructor: 
	~PowerPlant();
	//Copy constructor: 
	PowerPlant(const PowerPlant& p);


	//Getters and Setters: 
	int getBaseCost() const;
	void setBaseCost(int bs);

	int getPoweredHouses() const;
	void setPoweredHouses(int pw);

	int getResourcesNeeded() const;
	void setResourcesNeeded(int rNeeded);

	string getPrimaryResource() const;
	void setPrimaryResource(string pR);

	string getSecondaryResource() const;
	void setSecondaryResource(string pR);

	//NOT A MEMBER function, but a free function that displays each powerplant cards' information:
	friend ostream& operator<<(ostream &output, PowerPlant& card) {

		output << "[" << card.baseCost
			<< ", PH: " << card.poweredHouses
			<< ", RN: " << card.resourcesNeeded
			<< ", PR & SR: " << card.primaryResource;
		if (card.secondaryResource != "") {
			output << ", " << card.secondaryResource << "]" << endl;
		}
		else {
			output << ", ****]" << endl;
		}
		return output;
	}

};

