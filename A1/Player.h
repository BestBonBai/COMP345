#include <string>
#include <vector>
#include <iostream>
#include "OrderPTest.h"
//#include "Map.h"
//#include "Cards.h"
using namespace std;

class Player {

public:
    Player();       // default constructor
    Player(string name, vector<string*> t, vector<string*> h,vector<Order*>); //constructor
    Player(const Player&); //copy constructor
    ~Player(); //disturctor
    void toAttack();
    void toDeffend();
    void issueOrder(string);
    vector<Order*> getOrderList();
    void printOrder();

private:
    string name;
    vector<string*> terriorty;
    vector<string*> handCard;
    vector<Order*> orderList;
};