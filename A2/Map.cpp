#include "Map.h"
#include "Player.h";

//default constructor
Territory::Territory() {
    tname = "default territory";
    continent = "default continent";
    territoryOwner = "default player";
    armyAmount = 0;
    index = 0;
}

//copy constructor
Territory::Territory(const Territory* territory) {
    tname = territory->tname;
    continent = territory->continent;
    territoryOwner = territory->territoryOwner;
    armyAmount = territory->armyAmount;
    index = territory->index;
}

//one parameter constructor
Territory::Territory(string s) {
    tname = s;

}
Territory::Territory(string name, string continent, int army,int index) {
    tname = name;
    this->continent = continent;
    armyAmount = army;
    index = index;
}

//four parameters constructor
Territory::Territory(string name, string continent,string territoryOwner, int army,int index) {
    tname = name;
    this->continent = continent;
    this->territoryOwner = territoryOwner;
    armyAmount = army;
    int index;
}

//assignment operator
Territory& Territory::operator=(const Territory& territory)
{
    this->tname = territory.tname;
    this->continent = territory.continent;
    this->territoryOwner = territory.territoryOwner;
    this->armyAmount = territory.armyAmount;
    return *this;
}

//destructor
Territory::~Territory() {
    tname = "";
    continent = "";
    territoryOwner = "";
    armyAmount = 0;
}

//accessor
string Territory::getTname() {
    return tname;
}

//accessor
string Territory::getContinent() {
    return continent;
}

//accessor
string Territory::getTerritoryOwner() {
    return territoryOwner;
}


int Territory::getIndex() 
{
    return index;
}
//accessor
int Territory::getArmyAmount() {
    return armyAmount;
}


void Territory::setIndex(int i) 
{
    index = i;
}
//mutator
void Territory::setTname(string s) {
    tname = s;
}

//mutator
void Territory::setContinent(string s) {
    continent = s;
}

//mutator
void Territory::setTerritoryOwner(string s) {
    territoryOwner = s;
}

//mutator
void Territory::setArmyAmount(int n) {
    armyAmount = n;
}

//default constructor
Map::Map() {
    this->numVertices = 0;
    this->adjMatrix = NULL;
    this->territoryList = NULL;
}

//copy constructor
Map::Map(const Map* map) {
    this->numVertices = map->numVertices;
    this->adjMatrix = map->adjMatrix;
    this->territoryList = map->territoryList;
}

//one int parameter constructor
Map::Map(int numVertices) {
    territoryList = new string[numVertices];
    this->numVertices = numVertices;
    adjMatrix = new bool* [numVertices];
    //initialize the 2d array with false
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = new bool[numVertices];
        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = false;
    }
}

//assignment operator
Map& Map::operator=(const Map& map)
{
    this->adjMatrix = map.adjMatrix;
    this->numVertices = map.numVertices;
    return *this;
}

//add an edge between two vertices
void Map::addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
}

//remove an edge between two vertices
void Map::removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
}

//display the Adjancency Matrix
void Map::toString() {
    cout << "    Adjancency Matrix" << endl;
    cout << "    ";
    for (int m = 0; m < numVertices; m++) {
        cout << m << " ";
    }
    cout << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << i << " : ";
        for (int j = 0; j < numVertices; j++)
            cout << adjMatrix[i][j] << " ";
        cout << "\n";
    }
}

//destructor
Map::~Map() {
    for (int i = 0; i < this->numVertices; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

//traverse a graph
void Map::traverse(int u, bool visited[]) {
    visited[u] = true;
    for (int v = 0; v < numVertices; v++) {
        if (adjMatrix[u][v]) {
            if (!visited[v])
                traverse(v, visited);
        }
    }
}

//verify whether a graph is connected or not
bool Map::Validate() {
    bool* vis = new bool[numVertices];
    //for all vertex u as start point, check whether all nodes are visible or not
    for (int u = 0; u < numVertices; u++) {
        for (int i = 0; i < numVertices; i++)
            vis[i] = false; //initialize as no node is visited
        traverse(u, vis);
        for (int i = 0; i < numVertices; i++) {
            if (!vis[i]) //if there is a node, not visited by traversal, graph is not connected
                return false;
        }
    }
    return true;
}

//accessor
string* Map::getTerritoryList() {
    return this->territoryList;
}




