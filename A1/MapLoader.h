#pragma once
#include <iostream>
using namespace std;

//declaration of MapLoader class with its members
class MapLoader {
private:
    string inputFileName;               //input file path
        
public:
    MapLoader();                        //default constructor
    MapLoader(const MapLoader*);        //copy constructor
    MapLoader(string , int);            //two parameters constructor
    ~MapLoader();                       //destructor
    string* territoryArray;             //territory name array
    void generateTerritoryArray(int);   //collect territory name from input file
    string getInputFileName();          //accessor
    void setInputFileName(string);            //mutator
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
    string* territoryList;      //string array to store territory name list
    void addEdge(int, int);     //add an edge between two vertices
    void removeEdge(int, int);  //remove an edge between two vertices
    void toString();            //display the Aajancency Matrix
    void traverse(int, bool*);  //traverse the passed graph
    bool Validate();            //verify a graph whether connected or not
};