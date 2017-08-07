/*
Audrey-Ann Jean-Weisz (ID#: 26980104)
COMP345 - WINTER 2016
Assignment # 1
Due Date : 26/02/16

This header file represent the SummaryCards file which holds the number of houses that were powered up by a power plant card and its electros value; 

BOTH COMMON AND DISTINCT PARTS ARE INCLUDED IN THIS FILE.

*/

#pragma once
#include<iostream>
#include"City.h"
#include<string> 
using namespace std;

class SummaryCards{

public: 

	SummaryCards(); //default constructor
	SummaryCards(string sh, string se); //constructor
	~SummaryCards(); //destructor
	
	string bureaucracy(int houseCurrentsize); // method used to update the number of electros for a powered up house (Done in the Buraucracy phase) 
	string getSumHouse();  // returns the number of powered up houses 
	string getSumElectros(); // returns the sum of electros

private: 
	string SumHouse;
	string sumElectros; 
};

