#include "MapLoader.h"
#include <fstream>
#include <string>

//default constructor
MapLoader::MapLoader() {
    inputFileName = "none";
}

//copy constructor
MapLoader::MapLoader(const MapLoader* ml) {
    inputFileName = ml->inputFileName;
}

//two parameters constructor
MapLoader::MapLoader(string fileName, int arraySize) {
    this->inputFileName = fileName;
    territoryArray = new string[arraySize];
    generateTerritoryArray(arraySize);
}

//destructor
MapLoader::~MapLoader() {
    inputFileName = "null";
}

//accessor
string MapLoader::getInputFileName() {
    return inputFileName;
}

//mutator
void MapLoader::setInputFileName(string s) {
    inputFileName = s;
}

//collect territory names from valid input file, exit(0) if invalid input file
void MapLoader::generateTerritoryArray(int size) {
    int a, b, c, d;
    bool valid = false;
    string s;
    ifstream input(inputFileName);
    getline(input, s);
    while (!input.eof()) {
        if ((a = s.find("countries") != string::npos)) {
            valid = true;
            for (int i = 0; i < size; i++) {
                input >> a >> territoryArray[i] >> b >> c >> d;
            }
            cout << "Index     Territory" << endl;
            for (int i = 0; i < size; i++) {
                cout << "  " << i << "   :   " << territoryArray[i] << endl;
            }
        }
        if (input.eof()) {}

        else
            getline(input, s);

    }
    
    if (!valid) {
        cout << "Invalid input file!!" << endl;
        exit(0);
    }
    
    input.close();

}


//default constructor
Map::Map() {
    this->numVertices = 0;
    this->adjMatrix = NULL;
}

//copy constructor
Map::Map(const Map* map) {
    this->numVertices = map->numVertices;
    this->adjMatrix = map->adjMatrix;
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
