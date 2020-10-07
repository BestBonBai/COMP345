#include "Map.h"
using namespace std;

Map::Map(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new bool* [numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = new bool[numVertices];
        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = false;
    }
}


void Map::addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
}


void Map::removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
}

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

Map::~Map() {
    for (int i = 0; i < numVertices; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

void Map::traverse(int u, bool visited[]) {
    visited[u] = true; //mark v as visited
    for (int v = 0; v < numVertices; v++) {
        if (adjMatrix[u][v]==1) {
            if (!visited[v])
                traverse(v, visited);
        }
    }
}
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
