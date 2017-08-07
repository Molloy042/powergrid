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
#include<iostream>
#include"City.h"
#include<string> 
using namespace std;

class SummaryCards {

public:

	SummaryCards(); //default constructor
	SummaryCards(int sh, int se); //constructor
	~SummaryCards(); //destructor

	void bureaucracy(int houseCurrentsize); // method used to update the number of electros for a powered up house (Done in the Buraucracy phase) 
	int getSumHouse () const;  // returns the number of powered up houses 
	int getSumElectros () const; // returns the sum of electros

private:
	int SumHouse;
	int sumElectros;
};
