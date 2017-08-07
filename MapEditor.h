#pragma once
#include <iostream>
#include "Map.h"
#include "Region.h"

using namespace std;

class MapEditor:public Map {
public:
	class MapNode
	{
		
	public:
		bool isLinked;
		int linkCost;
	};

	MapEditor() {} ;
	//MapEditor(file location); // to save at location 

	vector<vector<MapNode>> getMap();
	void setMap(vector<vector<MapNode>> map);
	string getName();
	void setName(string name);
	void startEditing();

private:
	
	string mapName; // to name the save file with
	vector<vector<MapNode>> adjacencyMatrix;
	vector<Region*> listRegions;
	vector<City*> listCities;
};