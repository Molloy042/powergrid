/*
TEAM U - COMP345 - WINTER2016

Team members:

- Audrey-Ann Jean-Weisz (ID # 26980104)
- Andre Marques Manata (ID # 27148225)
- Marco Lyi (ID# 29815341)
- Catalin Popescu ID# 29678999)

Final Build Project - 13/04/2016

*/

#include "PGGameEngine.h"

PGGameEngine::PGGameEngine()
{
	model = new PGModel();
	view = new PGView();
	view->initialize(model);
	controller = view->getController();
}

PGGameEngine::~PGGameEngine()
{
	delete view;
	delete model;
}

void PGGameEngine::run()
{
	// ... DO MAIN MENU, ETC... start controller and event handling
	controller->doMenu();
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

