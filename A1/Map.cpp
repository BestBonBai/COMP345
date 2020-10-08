#include "Map.h"

//default constructor
Player::Player() {
    name = "none";
}

//one string parameter constructor
Player::Player(string pname) {
    name = pname;
}

//copy constructor
Player::Player(const Player* player) {

}

//destructor
Player::~Player() {

}

//player name accessor
string Player::getName() {
    return name;
}

//player name mutator
void Player::setName(string pname) {
    name = pname;
}

//default constructor
Territory::Territory() {
    tname = "default territory";
    continent = "default continent";
    territoryOwner = new Player();
    armyAmount = 0;
}

//copy constructor
Territory::Territory(const Territory* territory) {
    tname = territory->tname;
    continent = territory->continent;
    territoryOwner = territory->territoryOwner;
    armyAmount = territory->armyAmount;
}

//four parameters constructor
Territory::Territory(string name, string continent, Player* player, int army) {
    tname = name;
    this->continent = continent;
    territoryOwner = player;
    armyAmount = army;
}

//destructor
Territory::~Territory() {
    territoryOwner = NULL;
}

string Territory::getTname() {
    return tname;
}

string Territory::getContinent() {
    return continent;
}

Player* Territory::getTerritoryOwner() {
    return territoryOwner;
}

int Territory::getArmyAmount() {
    return armyAmount;
}

void Territory::setTname(string s) {
    tname = s;
}

void Territory::setContinent(string s) {
    continent = s;
}

void Territory::setTerritoryOwner(Player* p) {
    territoryOwner = p;
}

void Territory::setArmyAmount(int n) {
    armyAmount = n;
}

//default constructor
Map::Map() {
    this->numVertices = 0;
    this->adjMatrix = NULL;
}

//copy constructor
Map::Map(const Map *map) {
    this->numVertices = map->numVertices;
    this->adjMatrix = map->adjMatrix;
}

//one int parameter constructor
Map::Map(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new bool* [numVertices];
    //initialize the 2d array with false
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = new bool[numVertices];
        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = false;
    }
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
