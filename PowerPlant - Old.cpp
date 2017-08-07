
#include <string>
#include <iostream>
#include <vector>
#include "PowerPlant.h"
#include <sstream>
using std::cout;
using std::endl;


PowerPlant::PowerPlant() 
	: baseCost(0), poweredHouses(0), resourcesNeeded(0), primaryResource(ResourceType::DEFAULT), secondaryResource(ResourceType::DEFAULT)
{

}

PowerPlant::PowerPlant(unint bc, unint ph, unint rNeeded, ResourceType primaryResourceType, ResourceType secondarResourceType)
	: baseCost(bc), poweredHouses(ph), resourcesNeeded(rNeeded), primaryResource(primaryResourceType), secondaryResource(secondarResourceType)
{
	storedResources.resize(resourcesNeeded * 2);
}

PowerPlant::~PowerPlant() {

}

unint PowerPlant::getBaseCost(){
    return baseCost;
};

void PowerPlant::setBaseCost(unint bs){
    baseCost = bs;
}

unint PowerPlant::getPoweredHouses(){
    return poweredHouses;
}

void PowerPlant::setPoweredHouses(unint pw){
    poweredHouses = pw;
};

unint PowerPlant::getResourcesNeeded() {
    return resourcesNeeded;
}

void PowerPlant::setResourcesNeeded(unint rNeeded) {
    resourcesNeeded = rNeeded;
}

ResourceType PowerPlant::getPrimaryResource() {
    return primaryResource;
     }
void PowerPlant::setPrimaryResource(ResourceType primaryResourceType) {
    primaryResource = primaryResourceType;
}

ResourceType PowerPlant::getSecondaryResource() {
    return secondaryResource;
}
void PowerPlant::setSecondaryResource(ResourceType secondaryResourceType){
    secondaryResource = secondaryResourceType;
}
void PowerPlant::displayPowerPlantInfo()
{
	cout << "Power Plant Nr. " << baseCost << (secondaryResource == ResourceType::DEFAULT) ? " Regular" : " Hybrid";
	cout << endl;
	cout << "Starting Bid Cost : " << baseCost << endl;
	cout << "Primary Resource Used : " << resourceTypeToString(primaryResource) << endl;
	cout << "Secondary Resource Used : " << (secondaryResource == ResourceType::DEFAULT) ? "None" : resourceTypeToString(secondaryResource);
	cout << endl;
}
/*
string PowerPlant::toString() {
    stringstream os;
    string aux = "";

    if (secondaryResource != ""){
        aux = " or " + secondaryResource + ".";
    }

    os << "\tPowerPlant costs " << baseCost  << " elecktros , powers " << poweredHouses << " house(s) and need(s) " << resourcesNeeded  << " resources from " <<  primaryResource  << aux << endl;
   
    cout << os.str() << endl;
	return os.str();
}

*/