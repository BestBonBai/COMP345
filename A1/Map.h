#pragma once
#include <iostream>
using namespace std;

//declaration of Player class
class Player {
private:
    string name;

public:
    Player();
    Player(string);
    Player(const Player*);
    ~Player();

    string getName();
    void setName(string);
};

//declaration of Territory class
class Territory {
private:
    string tname, continent;     //the name and continent of a territory
    Player* territoryOwner;      //the owner of a territory
    int armyAmount;              //the amount of army in a territory

public:
    Territory();
    Territory(const Territory*);
    Territory(string, string, Player*, int);
    ~Territory();

    string getTname();
    string getContinent();
    Player* getTerritoryOwner();
    int getArmyAmount();

    void setTname(string);
    void setContinent(string);
    void setTerritoryOwner(Player*);
    void setArmyAmount(int);

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
    ~Map();                     //destructor  

    void addEdge(int, int);     //add an edge between two vertices
    void removeEdge(int, int);  //remove an edge between two vertices
    void toString();            //display the Aajancency Matrix
    void traverse(int, bool*);  //traverse the passed graph
    bool Validate();            //verify a graph whether connected or not
};


