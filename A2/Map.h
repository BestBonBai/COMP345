#pragma once
#include <iostream>
#include "Player.h"
using namespace std;

//declaration of Territory class
class Territory {
private:
    string tname, continent;     //the name and continent of a territory
    string territoryOwner;      //the owner of a territory
    int armyAmount;              //the amount of army in a territory

public:
    Territory();                                //default constructor
    Territory(const Territory*);                //copy constructor
    Territory(string);                          //one parameter constructor
    Territory(string, string, int);             //three parameters constructor
    Territory& operator = (const Territory&);   //assignment operator
    ~Territory();                               //destructor

    string getTname();                          //accessor
    string getContinent();                      //accessor
    string getTerritoryOwner();                //accessor
    int getArmyAmount();                        //accessor

    void setTname(string);                      //mutator
    void setContinent(string);                  //mutator
    void setTerritoryOwner(string);            //mutator
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
    string* territoryList;      //string array to store territory name list
    void addEdge(int, int);     //add an edge between two vertices
    void removeEdge(int, int);  //remove an edge between two vertices
    void toString();            //display the Aajancency Matrix
    void traverse(int, bool*);  //traverse the passed graph
    bool Validate();            //verify a graph whether connected or not
    string* getTerritoryList(); //accessor
};




