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
#include <iostream>
#include <vector>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>

#include "Coal.h"
#include "Oil.h"
#include "Garbage.h"
#include "Uranium.h"

using std::vector;
typedef Coal* CoalPtr;
typedef Oil* OilPtr;
typedef Garbage* GarbagePtr;
typedef Uranium* UraniumPtr;
typedef unsigned int unint;

class ResourceMarket{

public:
	typedef unsigned int unint;

    ResourceMarket();
    ~ResourceMarket();

    vector<Resource*> const &getResourceMarket() const { return market; }
    void setResourceMarket(vector<Resource*> const &m){ market =m;}
	friend void loadResourceMarket(ResourceMarket &loadTgtResMarket, const string filename);
	friend void saveResourceMarket(ResourceMarket &savedResMarket, const string filename);

	void removeResources(char type, int amount);

	// ADD RESOURCES - INDIVIDUALLY
	bool addCoal(CoalPtr newCoal);
	bool addOil(OilPtr newOil);
	bool addGarbage(GarbagePtr newGarbage);
	bool addUranium(UraniumPtr newUranium);

	// GET COST of ONE UNIT
	unint getUnitCost(ResourceType resourceType, unint index);

	unint ResourceMarket::findFirst(ResourceType resourceType)
	{
		unint found = 0;
		switch (resourceType) {
		case ResourceType::COAL:
		{
			for (unint i = 0; i < coalResourceList.size();++i) {
				if (coalResourceList[i] != NULL) {
					return i;
				} //endif

			}
		} //endcase coal
		
		case ResourceType::OIL:
		{
			found = oilResourceList.size();
			for (unint i = 0; i < oilResourceList.size();++i) {
				if (oilResourceList[i] != NULL) {
					return i;
				} //endif

			}
		} //endcase oil

		case ResourceType::GARBAGE:
		{
			found = garbageResourceList.size();
			for (unint i = 0; i < garbageResourceList.size();++i) {
				if (garbageResourceList[i] != NULL) {
					return i;
				} //endif

			}
		} //endcase garbage
		case ResourceType::URANIUM:
		{
			found = uraniumResourceList.size();
			for (unint i = 0; i < uraniumResourceList.size();++i) {
				if (uraniumResourceList[i] != NULL) {
					return i;
				} //endif

			}
		} //endcase garbage
		} //end switch
		if (resourceType == COAL || resourceType == OIL || resourceType == GARBAGE)
			return coalResourceList.size();
		else
			return uraniumResourceList.size();
	}//end function
	 
	 
	 //! Method used to obtain one Coal resource
	 /*!
	 \return Returns a pointer to the obtained Coal unit or nullptr if no coal was available
	 */
	CoalPtr getCoal();

	bool getCoal(unint quantity, vector<CoalPtr> &targetResourceList);

	//! Method used to obtain one Oil resource
	/*!
	\return Returns a pointer to the obtained Oil unit or nullptr if no Oil was available
	*/
	OilPtr getOil();
	bool getOil(unint quantity, vector<OilPtr> &targetResourceList);

	//! Method used to obtain one Garbage resource
	/*!
	\return Returns a pointer to the obtained Garbage unit or nullptr if no Garbage was available
	*/
	GarbagePtr getGarbage();
	bool getGarbage(unint quantity, vector<GarbagePtr> &targetResourceList);

	//! Method used to obtain one Uranium resource
	/*!
	\return Returns a pointer to the obtained Uranium unit or nullptr if no Uranium was available
	*/
	UraniumPtr getUranium();

	bool getUranium(unint quantity, vector<UraniumPtr> &targetResourceList);

	// GetPtr methods for MEMORY HANDLER - return the list of vectors
	vector<CoalPtr> getCoalPtrList() const { return coalResourceList; }
	vector<OilPtr> getOilPtrList() const { return oilResourceList; }
	vector<GarbagePtr> getGarbagePtrList() const { return garbageResourceList;  }
	vector<UraniumPtr> getUraniumPtrList() const { return uraniumResourceList;  }

	unint getNumCoal();
	unint getNumOil();
	unint getNumGarbage();
	unint getNumUranium();
	
	unint getCost(ResourceType resourceType, unint amount);

	void displayResourceMarket();
//  void resupplyResourceToMarket()// step 5 of game
private:
	vector<Resource*> market;
	vector<CoalPtr> coalResourceList;
	vector<OilPtr> oilResourceList;
	vector<GarbagePtr> garbageResourceList;
	vector<UraniumPtr> uraniumResourceList;
	friend class boost::serialization::access;
	
	template<class Archive>
	void serialize(Archive &boostArchive, const unsigned version)
	{
		boostArchive & coalResourceList & oilResourceList & garbageResourceList & uraniumResourceList;
	}

};
/*

template<Resource* T> bool ResourceMarket::getResource(T * resource)
{
	ResourceType resType = T->getResourceType();
	unint pos = findFirst(resType);
	switch (resType) {
	case ResourceType::COAL:
	{
		resource = coalResourceList[pos];
		coalResourceList[pos] = nullptr;
		return true;
	}
	break;
	case ResourceType::OIL:
	{
		resource = oilResourceList[pos];
		oilResourceList[pos] = nullptr;
		return true;
	}
	break;
	case ResourceType::GARBAGE:
	{
		resource = garbageResourceList[pos];
		garbageResourceList[pos] = nullptr;
		return true;
	}
	break;
	case ResourceType::URANIUM:
	{
		resource = uraniumResourceList[pos];
		garbageResourceList[pos] = nullptr;
		return true;
	}
	default:
		return false;
	break;
	};
}
*/