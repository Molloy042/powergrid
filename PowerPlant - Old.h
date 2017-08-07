#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "PowerPlant.h"
#include "Resource.h"
#include "Utility.h"
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

using namespace std;

typedef unsigned int unint;
class PowerPlant{
public:

	PowerPlant();
	PowerPlant(unint bc, unint ph, unint rNeeded, ResourceType primaryResourceType, ResourceType secondarResourceType); //resources needed x 2 will essentially set the size of the powerplant's vector
	~PowerPlant();

	unint getBaseCost();
	void setBaseCost(unint bs);

	unint getPoweredHouses();
	void setPoweredHouses(unint pw);

	unint getResourcesNeeded();
	void setResourcesNeeded(unint rNeeded);

	ResourceType getPrimaryResource();
	void setPrimaryResource(ResourceType primaryResourceType);

	ResourceType getSecondaryResource();
	void setSecondaryResource(ResourceType secondaryResourceType);

	void displayPowerPlantInfo();
	
	// string toString(); 

	// bool canBeTurnedOn(int c, int rNeeded, string pR, string sR, vector<Resource> myCurrentResources);//{

private:

	unint baseCost;
	unint poweredHouses;
	unint resourcesNeeded; //needed to power the plant (Type match is checked in bool canBeTurnedOn)
	ResourceType primaryResource;
	ResourceType secondaryResource;
	vector<Resource*> storedResources;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & boostArchive, const unsigned int version)
	{
		boostArchive & baseCost & poweredHouses & resourcesNeeded & primaryResource & secondaryResource;
	}

};




