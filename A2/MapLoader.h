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
    MapLoader(string, int);            //two parameters constructor
    MapLoader& operator = (const MapLoader&); //assignment operator
    ~MapLoader();                       //destructor
    string* territoryArray;             //territory name array
    void generateTerritoryArray(int);   //collect territory name from input file
    string getInputFileName();          //accessor
    void setInputFileName(string);            //mutator
};

