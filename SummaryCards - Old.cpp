/*
Audrey-Ann Jean-Weisz (ID#: 26980104)
COMP345 - WINTER 2016
Assignment # 1
Due Date : 26/02/16

This .cpp file represent the SummaryCards file which holds the number of houses that were powered up by a power plant card and its electros value;

BOTH COMMON AND DISTINCT PARTS ARE INCLUDED IN THIS FILE.

*/

#include<iostream>
#include"SummaryCards.h"
#include<string>

using namespace std; 


SummaryCards::SummaryCards() {

		sumElectros = "0";
		SumHouse = "0";
}

SummaryCards::SummaryCards(string sh, string se) {

	sumElectros = se; 
	SumHouse = sh;

}

SummaryCards::~SummaryCards() {}

string SummaryCards::getSumHouse() {return this->SumHouse;}

string SummaryCards::getSumElectros() {return this->sumElectros;}

//Used in the player class: this determines the value of the electros to its number of houses: 
string SummaryCards::bureaucracy(int housePoweredsize) {

	switch (housePoweredsize)
	{
	case 0: 
		sumElectros = "10"; 
		SumHouse = "0";
		break;
	case 1:
		sumElectros = "22";
		SumHouse = "1"; 
		break;
	case 2:
		sumElectros = "33";
		SumHouse = "2";
		break;
	case 3:
		sumElectros = "44";
		SumHouse = "3";
		break;
	case 4:
		sumElectros = "54";
		SumHouse = "4";
		break;
	case 5:
		sumElectros = "64";
		SumHouse = "5";
		break;
	case 6:
		sumElectros = "73";
		SumHouse = "6";
		break;
	case 7:
		sumElectros = "82";
		SumHouse = "7";
		break;
	case 8:
		sumElectros = "90";
		SumHouse = "8";
		break;
	case 9:
		sumElectros = "98";
		SumHouse = "9";
		break;
	case 10:
		sumElectros = "105";
		SumHouse = "10";
		break;
	case 11:
		sumElectros = "112";
		SumHouse = "11";
		break;
	case 12:
		sumElectros = "118";
		SumHouse = "12";
		break;
	case 13:
		sumElectros = "124";
		SumHouse = "13";
		break;
	case 14:
		sumElectros = "129";
		SumHouse = "14";
		break;
	case 15:
		sumElectros = "134";
		SumHouse = "15";
		break;
	case 16:
		sumElectros = "138";
		SumHouse = "16";
		break;
	case 17:
		sumElectros = "142";
		SumHouse = "17";
		break;
	case 18:
		sumElectros = "145";
		SumHouse = "18";
		break;
	case 19:
		sumElectros = "148";
		SumHouse = "19";
		break;
	case 20:
	case 21: 
	case 22: 
		sumElectros = "150";
		SumHouse ="20+";
		break;
	}
	return sumElectros + " " + SumHouse;

}