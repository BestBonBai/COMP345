#include "Map.h"
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string territoryList[10] = 
    { "NorthAmerica1","NorthAmerica2","SouthAmerican1","SouthAmerican2","Europe1","Europe2","Africa1","Africa2","Asia","SouthPacific" };

    cout << "Index" << setw(19) << "Territory" << endl;
                     
    for (int i = 0; i < 10; i++) {
        cout << setw(2) << i << setw(22) << territoryList[i] << endl;
    }
    
    //establish the game Map graph 
    cout << endl;
    Map m(10);
    m.addEdge(0, 1);
    m.addEdge(0, 4);
    m.addEdge(1, 2);
    m.addEdge(1, 5);
    m.addEdge(2, 3);
    m.addEdge(2, 6);
    m.addEdge(3, 7);
    m.addEdge(4, 5);
    m.addEdge(5, 6);
    m.addEdge(5, 8);
    m.addEdge(6, 7);
    m.addEdge(8, 9);
    m.toString();
    //m.~Map();
    if (m.Validate())
        cout << "Map is a connected graph!!\n" << endl;
    else
        cout << "Map is not connected!!\n" << endl;

    cout << "============test model below===============\n" << endl;
    
    //test a connceted graph
    Map continentAmerica(4);
    continentAmerica.addEdge(0, 1);
    continentAmerica.addEdge(1, 2);
    continentAmerica.addEdge(2, 3);
    continentAmerica.toString();
    if (continentAmerica.Validate())
        cout << "continentAmerica is a connected graph!!\n" << endl;
    else
        cout << "continentAmerica is not connected!!\n" << endl;


    //test an unconnected graph
    Map continentSample(4);
    continentSample.addEdge(0, 1);
    continentSample.addEdge(1, 2);
    continentSample.toString();
    if (continentSample.Validate())
        cout << "continentSample is a connected graph!!\n" << endl;
    else
        cout << "continentSample is not connected!!\n" << endl;

}