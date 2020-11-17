#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Orders.h"
#include "Map.h"
#include "Card.h"
#include "GameEngine.h"
using namespace std;


class Player {

public:
    Player();       // Default constructor
    Player(string); //added
    Player(int,string, vector<Territory*> territories, vector<Card*> handCard, vector<Order*> order); //Constructor
    Player(const Player &p); //Copy constructor
    Player& operator = (const Player& ); //added
    ~Player(); //Destructor

    //Methods
    vector<Territory*> getTerritory();
    vector<Territory*> toAttack(vector<Territory*>);
    vector<Territory*> toDefend();  
    vector<Territory*> get_neighbour_territories(vector<Territory*>);
    vector<Order*> getOrderList();    
    string getName();
    int getReinforcementPool();
    void setReinforcementPool(int);
    void setTerritory(Territory);
    void setName(string);
    void issueOrder(vector<Territory*>);
    void printOrder();
    void printHandcard();
    bool playerContientBouns();

private:
    string name;
    int reinforcementPool;

    vector<Territory*> territory;
    vector<Card*> handCard;
    vector<Order*> orderList;

    //friend classes
    friend class Card;
    friend class GameEngine;
    friend class Map;
};


