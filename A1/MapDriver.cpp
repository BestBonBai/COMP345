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

    //Map mm(10);
    //mm.addEdge(0, 1);
    //mm.addEdge(0, 4);
    //mm.toString();

    cout << endl;
    if (m.Validate())
        cout << "connected graph!!" << endl;
    else
        cout << "graph is not connected!!" << endl;

}