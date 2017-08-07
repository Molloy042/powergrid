#include "Player.h"
#include <iostream>
#include <fstream>
using std::cout;
using std::cerr;
using std::endl;
using std::for_each;
using std::begin;
using std::end;

Player::Player()
	:color(RED), name("unnamed")
{
}

Player::Player(ColorType newColor, string newName)
	:color(newColor), name(newName)
{

}

vector<City*> Player::getOwnedCities()
{
	return ownedCities;
}


//READ NOTE IN DESTRUCTOR TO PREVENT MEM LEAKS
Player::~Player(void)
{
	/*
	to avoid memory leaks: 
	there will be a house market. Upon destroying Player (end of the game)
	all the houses will be placed back upon the house Market and their 
	references deleted from here by marking them as NULL. 
	It will be the job of the markets (house market and resource market) 
	to clear the memory of the houses that they created upon initialization
	*/
	// DEBUGGING PURPOSES: std::cout << "destructor called" << std::endl;
}

ColorType Player::getColor() const
{
	return color;
}

string Player::getName() const
{
	return name;
}

unint Player::getMoney()
{
	return playerMoney;
}

unint Player::getNumHouses() 
{
	unsigned short int counter = 0;
	for (unsigned int i = 0; i < ownedCities.size(); ++i) {
		if (ownedCities[i] != NULL) {
			++counter;
		}
	}
	return counter;
}


void Player::setName(string newName)
{
	this->name = newName;
}

void Player::setColor(ColorType newColor)
{
	this->color = newColor;
}

void Player::increaseMoney(unint amount)
{
	playerMoney += amount;
}

bool Player::decreaseMoney(unint amount)
{
	bool isTransactionOkay = false;

	//checks if sufficient funds and decreases the amount of money the player owns.
	if (playerMoney >= amount)
	{
		playerMoney -= amount;
		isTransactionOkay = true;
	}
	else
	{
		isTransactionOkay = false;
	}

	return isTransactionOkay;
}

bool Player::addHouse(House* addedHouse)
{
	bool isAdded = false;
	/*
	if (addedHouse != NULL) { //the pointer should point to an actual House object, otherwise this makes no sense
		if (addedHouse->getColor() == this->color) {
			
			for (unsigned int i = 0; (i < MAX_NUM_HOUSES && (isAdded == false)); ++i) {
				if (playerHouses[i] == NULL) { //found an empty spot
					playerHouses[i] = addedHouse;
					isAdded = true;
					break;
				}
			}

			if (isAdded==false) { //we couldn't find room..  THERE CAN ONLY be 22 Houses per player and the vector has 22 spots. This shouldn't happen!
				cerr << "No room in House Vector!" << endl;
			}
		} // else we are trying to add to the list a house that doesn't belong to this player (different color)
		else {
			cout << "why are you trying to add someone else's house?" << endl;
		}
		
	} 
	*/
	return isAdded;
}

//clears the pointer in the playerHouses vector
//NOTE: it's the job of the caller to actually delete the house if-need-be. 
bool Player::removeHouse(City* targetCity)
{
	bool isHouseRemoved = false;
	for (unsigned int i = 0; i < ownedCities.size(); ++i) {
		if (ownedCities[i] == targetCity) {
			ownedCities[i] = NULL; //TODO: change to remove the house
			isHouseRemoved = true;
			break;
		}
	}
	return isHouseRemoved;
}

void Player::listHouses()
{
	cout << "Listing houses ... ";
	for (unsigned int i = 0; i < ownedCities.size(); ++i) {
		if (ownedCities[i] != NULL) {
			cout << "[House] ";
		}
	}
	cout << endl;
}

int Player::addHouseToCity(string nameCity, Map* map)
{
	cout << "Searching for city: " << nameCity << endl;
	vector<City*> listCities = map->getListCities();
	for (unint cityIndexValue = 0; cityIndexValue < listCities.size(); cityIndexValue++) {
		cout << "Does it match? Is " << nameCity << " the same as " << listCities[cityIndexValue]->getName() << "?" << endl;
		if (nameCity == listCities[cityIndexValue]->getName()) {
			cout << "Found a match!" << endl;
			ownedCities.push_back(listCities[cityIndexValue]);
			//listHouses();
			return cityIndexValue;
		}
	}
	return -1;

}


void playerLoad(Player & loadTgtPlayer, const string filename)
{
	std::ifstream inputFileStream(filename.c_str(), std::ios::binary);
	boost::archive::binary_iarchive inputArchive(inputFileStream);
	inputArchive >> loadTgtPlayer;
}

void playerSave(Player & savedPlayer, const string filename)
{
	std::ofstream outputFileStream(filename.c_str(), std::ios::binary);
	boost::archive::binary_oarchive outputArchive(outputFileStream);
	outputArchive << savedPlayer;
}
