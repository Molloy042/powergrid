/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#include "Player.h"

#include "Coal.h"
#include "Oil.h"
#include "Garbage.h"
#include "Uranium.h"

#include <iostream>
#include <fstream>
using std::cout;
using std::cerr;
using std::endl;
using std::for_each;
using std::begin;
using std::end;

//Human player (default constructor): 
Player::Player()
	:color(RED), name("unnamed"), mySummaryCard(new SummaryCards()), ownedResources(4)
{
}

//Human player:
Player::Player(ColorType newColor, string newName)
	: color(newColor), name(newName), mySummaryCard(new SummaryCards()), ownedResources(4)
{
}

//Strategy Human Player: 
Player::Player(ColorType newColor, string newName, Strategy* initStrategy)
	: color(newColor), name(newName), mySummaryCard(new SummaryCards()), strategy(initStrategy), ownedResources(4)

{
}


//Assignment 3: Strategy methods: 


//Sets the strategy of the player: 
void Player::setStrategy(Strategy *newStrategy)
{
	strategy = newStrategy;
}

//Activates the player's strategy. The strategy has one parameter which is itself: 
void Player::thePlayerStrategy()
{
	strategy->playerBureaucracyStrategy(this);
}

//returns the vector of owned cities of the player: 
vector<City*> Player::getOwnedCities()
{
	return ownedCities;
}

//returns the vector of ownedResources of the player 

vector<vector<Resource*>> Player::getOwnedResources() 
{
	return ownedResources; 
}
//Whend adding resources to the player's resource bank: 
void Player::purchaseResources(char choice, unint amount) {

	for (int i = 0; i < amount; i++) {
		switch (choice) {
		case 'C':
			ownedResources[0].push_back(new Coal());

			break;
		case 'O':
			ownedResources[1].push_back(new Oil());
			break;
		case 'G':
			ownedResources[2].push_back(new Garbage());
			break;
		case 'U':
			ownedResources[3].push_back(new Uranium());
			break;
		}
	}
}

void Player::removeResources(char choice, unint amount) {
	vector<Resource*> returnedResources;
	for (int i = 0; i < amount; i++) {
		switch (choice) {
		case 'C':
			ownedResources[0].pop_back(); 
			break;
		case 'O':
			ownedResources[1].pop_back(); 
			break;
		case 'G':
			ownedResources[2].pop_back(); 
			break;
		case 'U':
			ownedResources[3].pop_back(); 
			break;
		}
	}
}


//Summary Card: 
SummaryCards* Player::getMySummaryCard() const{
	return mySummaryCard; 
}


//READ NOTE IN DESTRUCTOR TO PREVENT MEM LEAKS
Player::~Player(void)
{

	delete mySummaryCard; 
	delete strategy;


	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < ownedResources[i].size(); j++) {
			delete[] ownedResources[i][j];
		}
	}

	for (int i = 0; i < ownedCities.size(); i++)
	{
		delete ownedCities[i];
	}

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

//returns the color of the player: 
ColorType Player::getColor() const
{
	return color;
}

//returns the name of the player: 
string Player::getName() const
{
	return name;
}

//returns the amount of electros of the player: 
unint Player::getMoney()
{
	return playerMoney;
}

//SETTERS: 
void Player::setName(string newName)
{
	this->name = newName;
}

void Player::setColor(ColorType newColor)
{
	this->color = newColor;
}

//Increase the money of the player: 
void Player::increaseMoney(unint amount)
{
	playerMoney += amount;
}

//Decrease the money of the player: 
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


vector<PowerPlant*> Player::getOwnedPowerPlants() 
{
	return ownedPowerPlants; 
}

//Returns the list of owned cities: 
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

//Adds a city to the player: 
void Player::addHouseToCity(City* city, int i)
{
	ownedCities.push_back(city);
	city->getHouses()[i]->setTaken(true); 
	city->getHouses()[i]->setColor(this->color);

}


//Returns the number of cities that the player owns; 
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


//Removes a city from the player: 
void Player::removeCityFromPlayer(int index, Map* map) {

	for (int i = 0; i < ownedCities.back()->getHouses().size(); i++) {
		if (ownedCities.back()->getHouses()[i]->getColor() == color) {
			ownedCities.back()->getHouses()[i]->setTaken(false);
			map->getListCities()[index]->getHouses()[i]->setTaken(false);
			map->getListCities()[index]->getHouses()[i]->setColor(DEFAULTCOLOR);
			ownedCities.pop_back();
			break;
		}
	}
}

//THIS WILL BE CALLED EACH TIME THERE IS AN UPDATE WITH SUMMARYCARD: 
void Player::cityHoldsSummaryCardValue() {

	//Each player's cities will hold the value of what is the powered cities number: 
		for (unsigned x = 0; x < ownedCities.size(); x++)
		{
			for (int i = 0; i < ownedCities.back()->getHouses().size(); i++) {

				if (ownedCities[x]->getHouses()[i]->getColor() == color) {
					ownedCities[x]->getHouses()[i]->setPower(mySummaryCard->getSumHouse());
					break; 
				}
			}
			
		}

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

//Prints the player's possessions to the console: 
void Player::currentPlayerInformation() {

	cout << endl; 
	printf("%50s\n","==== PLAYER INFORMATION ====" );
	cout << " -----------------------------------------------------------------------" << endl; 

		printf("%-2s%-5s%-5s%-5s%-5s%-23s\n", 
			" | ", "Name", "Money" , " # PowerPlant Cards",
			" # owned cities"," # Powered cities");	



		   cout <<" | " << this->name  << "   " << this->playerMoney  << "            " 
			   << this->ownedPowerPlants.size() 
			<< "               " << this->ownedCities.size() << "                " 
			   << this->mySummaryCard->getSumHouse()   << endl;
		
		   cout << " |                                                                     "<< endl; 
		   cout << " | Power plant cards:                                                  " << endl; 
		   for (unsigned i = 0; i < ownedPowerPlants.size(); i++)
		   {
			   cout << " | " << i+1 << ". "<< *ownedPowerPlants[i];
		   }
		   cout << " |                                                                     " << endl;
		   cout << " | Ressources:                                                         " << endl;
		   cout << " | # Coal -> " << ownedResources[0].size()                               << endl; 
		   cout << " | # Oil -> " << ownedResources[1].size()                                << endl;
		   cout << " | # Garbage -> " << ownedResources[2].size()                            << endl;
		   cout << " | # Uranium -> " << ownedResources[3].size()                            << endl;
		   cout << " | "                                                                     << endl; 
		   cout << " | Owned Cities:                                                        " << endl;
		   cout << " | ";
		   for (unsigned i = 0; i < ownedCities.size(); i++)
		   {
			   cout << ownedCities[i]->getName() << " - ";
		   }


		cout << "\n -----------------------------------------------------------------------" << endl; 
	cout << endl; 

}

