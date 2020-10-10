#pragma once
#include <iostream>
using namespace std;

//declaration of Player class (temporary)
class Player {
private:
    string name;                         //player name

public:
    Player();                            //default constructor
    Player(string);                      //one parameter constructor
    Player(const Player*);               //copy constructor
    Player& operator = (const Player&);  //assignment operator
    ~Player();                           //destructor

    string getName();                    //accessor
    void setName(string);                //mutator
};

//declaration of Territory class
class Territory {
private:
    string tname, continent;     //the name and continent of a territory
    Player* territoryOwner;      //the owner of a territory
    int armyAmount;              //the amount of army in a territory

public:
    Territory();                                //default constructor
    Territory(const Territory*);                //copy constructor
    Territory(string, string, Player*, int);    //four parameters constructor
    Territory& operator = (const Territory&);   //assignment operator
    ~Territory();                               //destructor

    string getTname();                          //accessor
    string getContinent();                      //accessor
    Player* getTerritoryOwner();                //accessor
    int getArmyAmount();                        //accessor

    void setTname(string);                      //mutator
    void setContinent(string);                  //mutator
    void setTerritoryOwner(Player*);            //mutator
    void setArmyAmount(int);                    //mutator

};

//declaration of Map class with its members
class Map {
private:
    bool** adjMatrix;           //2D boolean matrix to represent Adjancency Matrix
    int numVertices;            //int to store number of vertices (territories)
        
public:
    Map();                      //default constructor
    Map(int);                   //one int parameter constructor
    Map(const Map*);            //copy constructor
    Map& operator = (const Map&);//assignment operator
    ~Map();                     //destructor  

    void addEdge(int, int);     //add an edge between two vertices
    void removeEdge(int, int);  //remove an edge between two vertices
    void toString();            //display the Aajancency Matrix
    void traverse(int, bool*);  //traverse the passed graph
    bool Validate();            //verify a graph whether connected or not
};


