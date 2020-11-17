#pragma once
#include "Map.h"
#include "MapLoader.h"
#include "Card.h"
#include "Player.h"
#include "Orders.h"

class GameEngine {
public:
	GameEngine();								//default constructor
	GameEngine(string, int);					//two parameter constructor
	~GameEngine();								//destructor
	GameEngine& operator = (const GameEngine&); //assignment operator
	string getUserInputMap();					//accessor
	int getUserInputPlayerQuantity();			//accessor
	void setUserInputMap(string);				//mutator
	void setUserInputPlayerQuantity(int);		//mutator
	void gameStart();							//methord to initialize a game
	int getTerritoryQuantity();					//accessor
	Map* getMap();								//accessor
	Player* getPlayerList();					//accessor
	void startupPhase(int, int, int);


	void reinforcmentPhase(vector<Player*>);
	void issueOrdersPhase(vector<Player*>);
	void excuteOrderPhase();

private:
	string userInputMap;						//user inputed map index
	int userInputPlayerQuantity;				//user inputed player quantity
	Map* map;									//initialized Map for the game
	MapLoader* map_loader;						//initialized MapLoader for the game
	Player* player_list;						//initialized Player Array for the gamePlayer array
	Deck* deck;									//initialized Deck for the game
	const int TerritoryQuantity = 10;			//initialize with ten territories
	const string playerNameArr[5] = { "Player1","Player2","Player3","Player4","Player5" }; // fixed five player names
	Territory* territory_array[10];				//Territory array
};

