/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

//#include <string>
#include <fstream>
#include <vector>
#include "ResourceMarket.h"

using namespace std;


ResourceMarket::ResourceMarket() 
{
	coalResourceList.resize(24);
	oilResourceList.resize(24);
	garbageResourceList.resize(24);
	uraniumResourceList.resize(12);
}

ResourceMarket::~ResourceMarket() {

}

bool ResourceMarket::addCoal(CoalPtr newCoal)
{
	for (size_t i = coalResourceList.size() - 1; i >= 0; --i) {
		if (coalResourceList[i] == NULL) {
			coalResourceList[i] = newCoal;
			return true;
		}
	}
	return false;
}

bool ResourceMarket::addOil(OilPtr newOil)
{
	for (size_t i = oilResourceList.size() - 1; i >= 0; --i) {
		if (oilResourceList[i] == NULL) {
			oilResourceList[i] = newOil;
			return true;
		}
	}
	return false;
}

bool ResourceMarket::addGarbage(GarbagePtr newGarbage)
{
	for (size_t i = garbageResourceList.size() - 1; i >= 0; --i) {
		if (garbageResourceList[i] == NULL) {
			garbageResourceList[i] = newGarbage;
			return true;
		}
	}
	return false;
}

bool ResourceMarket::addUranium(UraniumPtr newUranium)
{
	for (size_t i = uraniumResourceList.size() - 1; i >= 0; --i) {
		if (uraniumResourceList[i] == NULL) {
			uraniumResourceList[i] = newUranium;
			return true;
		}
	}
	return false;
}

unint ResourceMarket::getUnitCost(ResourceType resourceType, unint index)
{
	unint cost =0;
	if (resourceType == COAL || resourceType == OIL || resourceType == GARBAGE) {
		cost = index / 3 + 1;
	}
	else if (resourceType == URANIUM) {
		if (index >= 0 && index <= 7) {
			cost = index + 1;
		}
		else if (index >= 8) {
			if (index == 8) cost = 10;
			if (index == 9) cost = 12;
			if (index == 10) cost = 14;
			if (index == 11) cost = 16;
		}
	}
	
	return cost;
}

unint ResourceMarket::getNumCoal()
{	
	unint count=0;
	for (unint i = 0; i < coalResourceList.size();++i) {
		if (coalResourceList[i] != NULL) {
			++count;
		}
	}
	return count;
}

unint ResourceMarket::getNumOil()
{
	unint count=0;
	for (unint i = 0;i < oilResourceList.size();++i) {
		if (oilResourceList[i] != NULL) {
			++count;
		}
	}
	return count;

}

unint ResourceMarket::getNumGarbage()
{
	unint count=0;
	for (unint i = 0; i < garbageResourceList.size();++i) {
		if (garbageResourceList[i] != NULL) {
			++count;
		}
	}
	return count;
}

unint ResourceMarket::getNumUranium()
{
	unint count = 0;
	for (unint i = 0 ;i < uraniumResourceList.size();++i) {
		if (uraniumResourceList[i] != NULL) {
			++count;
		}
	}
	return count;
}

unint ResourceMarket::getCost(ResourceType resourceType, unint amount)
{
	unint totalCost = 0;
	if (resourceType == ResourceType::COAL) {
		unint firstCoal = findFirst(COAL);
		for (unint i = 0;i < amount;++i) {
			totalCost = totalCost + getUnitCost(COAL, firstCoal + i);
		}
	} else if (resourceType == ResourceType::OIL) {
		unint firstOil = findFirst(OIL);
		for (unint i = 0;i < amount;++i) {
			totalCost = totalCost + getUnitCost(OIL, firstOil + i);
		}
	} else if (resourceType == ResourceType::GARBAGE) {
		unint firstGarbage = findFirst(GARBAGE);
		for (unint i = 0;i < amount;++i) {
			totalCost = totalCost + getUnitCost(GARBAGE, firstGarbage + i);
		}
	} else if (resourceType == ResourceType::URANIUM) {
		unint firstUranium = findFirst(URANIUM);
		for (unint i = 0; i < amount;++i) {
			totalCost = totalCost + getUnitCost(URANIUM, firstUranium + i);
		}
	}  
	return totalCost;
}




void ResourceMarket::displayResourceMarket()
{

 cout << "\n\n====================== RESOURCE MARKET ======================\n" << endl; 
 printf("%-10s%-10s%-10s%-10s\n", "Coal", "Oil", "Garbage", "Uranium");
 cout << "---------------------------------------------------------------" << endl; 
 printf("%-10d%-12d%-12d%-12d\n", getNumCoal(), getNumOil(), getNumGarbage(), getNumUranium());
 cout << "---------------------------------------------------------------" << endl;
 cout << " Coal: \t\t";
 for (int x = 0; x < coalResourceList.size(); x++) {
	 if (coalResourceList[x] != nullptr) {
		 cout << getUnitCost(COAL, x) << "_";
	 }
	 
 }
 cout << endl; 
 cout << " Oil: \t\t";
 for (int x = 0; x < oilResourceList.size(); x++) {
	 if (oilResourceList[x] != nullptr) {
		 cout << getUnitCost(OIL, x) << "_";
	 }
 }
 cout << endl; 
 cout << " Garbage \t";
 for (int x = 0; x < garbageResourceList.size(); x++) {
	 if (garbageResourceList[x] != nullptr) {
		 cout << getUnitCost(GARBAGE, x) << "_";
	 }
 }
 cout << endl; 
 cout << " Uranium: \t";
 for (int x = 0; x < uraniumResourceList.size(); x++) {
	 if (uraniumResourceList[x] != nullptr) {
		 cout << getUnitCost(URANIUM, x) << "_";
	 }
	 
 }
 cout << endl; 
 cout << "=============================================================\n" << endl;
 cout << endl; 


}


void ResourceMarket::removeResources(char type, int amount)
{

	for (int i = 0; i < amount; i++) {

		switch (type) {
		case 'C':
			this->coalResourceList.pop_back();
			break;
		case 'O':
			this->oilResourceList.pop_back();

			break;
		case 'G':
			this->garbageResourceList.pop_back();
			break;
		case 'U':
			this->uraniumResourceList.pop_back();
			break;
		}
	}
}

void loadResourceMarket(ResourceMarket & loadTgtResMarket, const string filename)
{
	std::ifstream inputFileStream(filename.c_str(), std::ios::binary);
	boost::archive::binary_iarchive inputArchive(inputFileStream);
	inputArchive >> loadTgtResMarket;
}

void saveResourceMarket(ResourceMarket & savedResMarket, const string filename)
{
	std::ofstream outputFileStream(filename.c_str(), std::ios::binary);
	boost::archive::binary_oarchive outputArchive(outputFileStream);
	outputArchive << savedResMarket;
}

CoalPtr ResourceMarket::getCoal()
{
	CoalPtr obtainedCoal = nullptr;
	unint pos = findFirst(COAL);
	if (findFirst(COAL) != coalResourceList.size()) {
		obtainedCoal = coalResourceList[pos];
		coalResourceList[pos] = nullptr;
	}
	return obtainedCoal;
}

bool ResourceMarket::getCoal(unint quantity, vector<CoalPtr> &targetResourceList)
{
	if (getNumCoal() < quantity)
		return false;
	else {
		for (unint i = 0; i < quantity;++i) {
			targetResourceList.push_back(getCoal());
		}
		return true;
	}
}

OilPtr ResourceMarket::getOil()
{
	OilPtr obtainedOil = nullptr;
	unint pos = findFirst(OIL);
	if (findFirst(OIL) != oilResourceList.size()) {
		obtainedOil = oilResourceList[pos];
		oilResourceList[pos] = nullptr;
	}
	return obtainedOil;
}

bool ResourceMarket::getOil(unint quantity, vector<OilPtr>& targetResourceList)
{
	if (getNumOil() < quantity)
		return false;
	else {
		for (unint i = 0; i < quantity;++i) {
			targetResourceList.push_back(getOil());
		}
		return true;
	}
}

GarbagePtr ResourceMarket::getGarbage()
{
	GarbagePtr obtainedGarbage = nullptr;
	unint pos = findFirst(GARBAGE);
	if (findFirst(GARBAGE) != garbageResourceList.size()) {
		obtainedGarbage = garbageResourceList[pos];
		garbageResourceList[pos] = nullptr;
	}
	return obtainedGarbage;
}

bool ResourceMarket::getGarbage(unint quantity, vector<GarbagePtr>& targetResourceList)
{
	if (getNumGarbage() < quantity)
		return false;
	else {
		for (unint i = 0; i < quantity;++i) {
			targetResourceList.push_back(getGarbage());
		}
		return true;
	}
}

UraniumPtr ResourceMarket::getUranium()
{
	UraniumPtr obtainedUranium = nullptr;
	unint pos = findFirst(URANIUM);
	if (findFirst(URANIUM) != uraniumResourceList.size()) {
		obtainedUranium = uraniumResourceList[pos];
		uraniumResourceList[pos] = nullptr;
	}
	return obtainedUranium;
}

bool ResourceMarket::getUranium(unint quantity, vector<UraniumPtr>& targetResourceList)
{
	if (getNumUranium() < quantity)
		return false;
	else {
		for (unint i = 0; i < quantity;++i) {
			targetResourceList.push_back(getUranium());
		}
		return true;
	}
}
