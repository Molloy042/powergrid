/*
Audrey-Ann Jean-Weisz (ID#: 26980104)
COMP345 - WINTER 2016
Assignment # 3
Due Date : 09/04/16

*This assignment represents the 4th part of Assignment 2*

This .cpp file represents the PowerPlant cards which holds:

- base cost of a PowerPlant card (baseCost)
- the number of powered house it can supply (poweredHouses)
- the number of resources needed (resourceNeeded)
- the type of the primary ressource (primaryRessource)
- the type of the secondary resource (secondaryResource)

*/

#include <string>
#include <iostream>
#include <vector>
#include "PowerPlant.h"
#include <sstream>
using namespace std;


//Default constructor
PowerPlant::PowerPlant()
	: baseCost(0), poweredHouses(0), resourcesNeeded(0), primaryResource(""), secondaryResource("")
{

}

//Constructor
PowerPlant::PowerPlant(int bc, int ph, int rNeeded, string pR, string sR)
	: baseCost(bc), poweredHouses(ph), resourcesNeeded(rNeeded), primaryResource(pR), secondaryResource(sR)
{

	baseCost = bc;
	poweredHouses = ph;
	resourcesNeeded = rNeeded;
	primaryResource = pR;
	secondaryResource = sR;

}

//Destructor 
PowerPlant::~PowerPlant() {}

//Copy constructor 
PowerPlant::PowerPlant(const PowerPlant& p) {

	this->baseCost = p.baseCost;
	this->poweredHouses = p.poweredHouses;
	this->resourcesNeeded = p.resourcesNeeded;
	this->primaryResource = p.primaryResource;
	this->secondaryResource = p.secondaryResource;
}

//Getters and Setters for instance variables

int PowerPlant::getBaseCost() const {
	return baseCost;
};

void PowerPlant::setBaseCost(int bs) {
	baseCost = bs;
}

int PowerPlant::getPoweredHouses() const {
	return poweredHouses;
}

void PowerPlant::setPoweredHouses(int pw) {
	poweredHouses = pw;
};

int PowerPlant::getResourcesNeeded() const {
	return resourcesNeeded;
}

void PowerPlant::setResourcesNeeded(int rNeeded) {
	resourcesNeeded = rNeeded;
}

string PowerPlant::getPrimaryResource() const {
	return primaryResource;
}
void PowerPlant::setPrimaryResource(string pR) {
	primaryResource = pR;
}

string PowerPlant::getSecondaryResource() const {
	return secondaryResource;
}
void PowerPlant::setSecondaryResource(string sR) {
	secondaryResource = sR;
}