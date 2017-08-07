#include"MapEditor.h"


int numberOfRegion;
int numberOfCity;
int cost;
string userInput;
bool loop = false;

vector<vector<MapEditor::MapNode>> MapEditor::getMap() {
	return this->adjacencyMatrix;
}
void MapEditor::setMap(vector<vector<MapNode>> map) {
	this -> adjacencyMatrix = map;
}
string MapEditor::getName() {
	return this->mapName;
}
void MapEditor::setName(string name) {
	this->mapName = name;
}

void MapEditor::startEditing(){
	cout << " !!! welcome to map editing !!! \n"
		<< " How would you like to name your map? " << endl;
	
	cin >> MapEditor::mapName;

	cout << " The new maps name will be:  " << MapEditor::mapName
		<< "\n\n ========================================= \n\n"
		<< " How many regions do you want? " << endl;
	
	while (!(cin >> numberOfRegion)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " ??? Realy ??? Try again: ";
	}

	for (int x = 0; x < numberOfRegion; x++){
		cout <<"\n\n ========================================= \n\n"
			<< " What do you want to name region " << (x + 1) << "? " << endl;
				
		do {
			loop = false;
			cin >> userInput;

			for (int z = 0; z < this->listRegions.size(); z++) {
				if (this->listRegions[z]->getName() == userInput) {
					loop = true;
					cout << "-_- Sorry that name is already taken -_-" << endl;
				}
			}
		} while (loop);

		this->listRegions.push_back(new Region(userInput));

		cout << " The region " << (x + 1) << " is now named " << this->listRegions[x]->getName()
			<< "\n\n ========================================= \n\n"
			<< "how many cities do you want " << this->listRegions[x]->getName() << " to Have? " << endl;

		while (!(cin >> numberOfCity)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << " ??? Are you joking ??? Try again: ";
		}

		for (int y = 0; y < numberOfCity; y++) {
			cout << " What do you want to name city " << (y + 1) << "? " << endl;
			
			do {
				loop = false;
				cin >> userInput;

				for (int z = 0; z <Map->getRegions().size(); z++) {
					if (this->listRegions[x]->getRegions()[z]->getName() == userInput) {
						loop = true;
						cout << "-_- Sorry that name is already taken -_-" << endl;
					}
				}
			} while (loop);
		
			this->listRegions[x]->addCity(new City(userInput));
			this->listCities.push_back(new City(userInput));
		}
	}
	//fixe adjacencyMatrix
	this->adjacencyMatrix.resize(this->listCities.size());
	for (int x = 0; x < this->adjacencyMatrix.size(); x++) {
		this->adjacencyMatrix[x].resize(this->listCities.size());
	}

	cout << "\n\n";

	//make the matrix
	for (int x = 0; x < this->listCities.size(); x++) {
		for (int y = 0; y <= x; y++) {
			if (y == x) {
				this->adjacencyMatrix[x][y].linkCost = 0;
				this->adjacencyMatrix[x][y].isLinked = false;
				break;
			}
			else {
				cout << "Is " << this->listCities[x]->getName() << " connected to " << this->listCities[y]->getName() << "? \n" 
					<< " -true \n"
					<< " -false " << endl;
				
				cin >> userInput;

				if (userInput == "true") {
					this->adjacencyMatrix[x][y].isLinked = true;
					this->adjacencyMatrix[y][x].isLinked = true;
					cout << " What is the cost of the connection?" << endl;
					while (!(cin >> cost)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "??? (-__-) ??? Try again: ";
					}
					this->adjacencyMatrix[x][y].linkCost = cost;
					this->adjacencyMatrix[y][x].linkCost = cost;
					break;
				}
				if (userInput == "false") {
					this->adjacencyMatrix[x][y].isLinked = false;
					this->adjacencyMatrix[y][x].isLinked = false;
					this->adjacencyMatrix[x][y].linkCost = 0;
					this->adjacencyMatrix[y][x].linkCost = 0;
					break;
				}
				else {
					y--;
				}
			}
		}
	}

	cout << " !!! congrats you just finished a new mape !!! " << endl;

}