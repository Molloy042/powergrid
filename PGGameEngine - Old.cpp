#include "PGGameEngine.h"

PGGameEngine::PGGameEngine()
{
	isOver = false;
	initialize();
	
}

PGGameEngine::~PGGameEngine()
{
}

void PGGameEngine::runGame()
{
	Player* player = new Player(ColorType::BLUE, "Charlie");
	player->increaseMoney(50);
	pgModel->attachPlayer(player, 0);
	pgView->update();
	
	while (isOver == false) {
		pgView->drawConsole();
		isOver = pgController->getInput();
	}
	
}

/*
initialize() method
@brief: initializes the GameEngine containing the MVC architecture
@param: no parameters are used

Step 1) Creates an instance of the model, which in turn needs to make all the necessary initializations, controlled from here (FOR NOW)
		PGModel* model = new PGModel;

		IF NEW GAME: 
		feed the model: number of players, colors and names
		feed the model: map
		feed the model: whole PowerPlant list
		ask the model: initializeNewGame()

			INSIDE MODEL: model
				create a PowerPlant market
				find 3,4,5,6 7,8,9,10 and place them in the PowerPlantMarket 
							Idea: for the power plant market we have a vector of powerplant cards with positions 0,1,2,3 and 4,5,6,7. The user can see what is in the whole PPMarket, but can only buy something which is located between 0 and MarketLimit(3 or 7)


We need to make a menu which would be launched by the model in order to properly set the model: nr of players, map, load game, exit game

Step 2) Creates an instance of View, which takes a reference of the Model (from which it will take the data)
		PGView* view = new PGView

Step 3) Attaches the instanced View as an observer to the Model which is a Subject
		model->attach(view);

Step 4) Create an instance of Controller. Pass reference 
*/
void PGGameEngine::initialize()
{
	// STEP 1
	// Instantiate MODEL
	cout << "Create model ... ";
	PGModel* model = new PGModel;
	cout << "Done!\n";
	//TODO: modify the PGModel to self-initialize and check for number of players

	// STEP 2,3
	// Instantiate VIEW, pass MODEL as reference
	// Attach VIEW to MODEL
	cout << "Create view ... \n";
	PGView* view = new PGView(model);

	// STEP4

	
}
