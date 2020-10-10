#include "MapLoader.h"
#include <iostream>
#include <fstream>

int main() {
    //initialization
    int territoryQuantity = 10;
    MapLoader* maploader = new MapLoader("map1.txt", territoryQuantity);
    Map* map = new Map(territoryQuantity);

    //copy the territory list from MapLoader to Map via string array
    for (int i = 0; i < territoryQuantity; i++) {
        map->territoryList[i] = maploader->territoryArray[i];
    }
    
    //add ajancent edges
    cout << endl;
    map->addEdge(0, 1);
    map->addEdge(0, 4);
    map->addEdge(1, 2);
    map->addEdge(1, 5);
    map->addEdge(2, 3);
    map->addEdge(2, 6);
    map->addEdge(3, 7);
    map->addEdge(4, 5);
    map->addEdge(5, 6);
    map->addEdge(5, 8);
    map->addEdge(6, 7);
    map->addEdge(8, 9);
    map->toString();

    //verify the graph whether connected or not
    if (map->Validate())
        cout << "Map is a connected graph!!\n" << endl;
    else
        cout << "Map is not connected!!\n" << endl;

}