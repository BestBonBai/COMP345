#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Orders.h"
#include "Map.h"
#include "Card.h"
using namespace std;

class Player {

public:
    Player();       // Default constructor
    Player(string); //added
    Player(int reinforcementPool,string name, vector<Territory*> territories, vector<string*> handCard, vector<Order*> order); //Constructor
    Player(const Player &p); //Copy constructor
    Player& operator = (const Player ); //added
    ~Player(); //Destructor

    //Methods
    void toAttack();
    vector<Territory*> toDefend();
    void issueOrder();
    vector<Order*> getOrderList();
    void printOrder();
    void printHandcard();
    string getName();
    void setName(string);
    int getReinforcementPool();
    void setReinforcementPool(int);
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


