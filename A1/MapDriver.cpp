#include "Map.h"
#include <iomanip>

int main() {
    //create Player and Territory objects
    Player* p1 = new Player("Jack");
    Player* p2 = new Player("Amy");
    Territory* t0 = new Territory("NorthAmerica1", "NA", p1, 15);
    Territory* t1 = new Territory("NorthAmerica2", "NA", p2, 20);
    Territory* t2 = new Territory("SouthAmerica1", "SA", new Player(), 0);
    Territory* t3 = new Territory("SouthAmerica2", "SA", new Player(), 0);
    Territory* t4 = new Territory("Europe1", "EU", new Player(), 0);
    Territory* t5 = new Territory("Europe2", "EU", new Player(), 0);
    Territory* t6 = new Territory("Africa1", "AF", new Player(), 0);
    Territory* t7 = new Territory("Africa2", "AF", new Player(), 0);
    Territory* t8 = new Territory("Asia", "AS", new Player(), 0);
    Territory* t9 = new Territory("SouthPacific", "SP", new Player(), 0);

    //collect territory objects into an array
    Territory tArray[10];
    tArray[0] = *t0;
    tArray[1] = *t1;
    tArray[2] = *t2;
    tArray[3] = *t3;
    tArray[4] = *t4;
    tArray[5] = *t5;
    tArray[6] = *t6;
    tArray[7] = *t7;
    tArray[8] = *t8;
    tArray[9] = *t9;
    
    //display territory information
    cout << "Index" << setw(19) << "Territory" 
        << "   " << "Continent"
        << "       " << "Owner"
        << "        " << "Army" << endl;
    for (int i = 0; i < 10; i++) {
        cout << setw(2) << i 
            << setw(22) << tArray[i].getTname() 
            << setw(12) << tArray[i].getContinent() 
            << setw(12) << tArray[i].getTerritoryOwner()->getName()
            << setw(12) << tArray[i].getArmyAmount() << endl;
    }

    //create a Map object
    cout << endl;
    Map* map = new Map(10);
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
    
    //test Map object
    if (map->Validate())
        cout << "Map is a connected graph!!\n" << endl;
    else
        cout << "Map is not connected!!\n" << endl;

    cout << "============test model below===============\n" << endl;
    
    //test a connceted graph
    Map continentNA(4);
    continentNA.addEdge(0, 1);
    continentNA.addEdge(1, 2);
    continentNA.addEdge(2, 3);
    continentNA.toString();
    if (continentNA.Validate())
        cout << "continent NA is a connected graph!!\n" << endl;
    else
        cout << "continent NA is not connected!!\n" << endl;

    //test an unconnected graph
    Map continentSample(4);
    continentSample.addEdge(0, 1);
    continentSample.addEdge(1, 2);
    continentSample.toString();
    if (continentSample.Validate())
        cout << "continent Sample is a connected graph!!\n" << endl;
    else
        cout << "continent Sample is not connected!!\n" << endl;
    
    //call destructors to avoid memory leak
    delete map;
    delete p1;
    delete p2;
    delete t0;
    delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete t5;
    delete t6;
    delete t7;
    delete t8;
    delete t9;
    
}