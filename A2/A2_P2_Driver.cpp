#include "GameEngine.h";

//driver to initialize a game with two user inputs(mapIndex & playerQuanatity)
int main() {

    cout << "\n===========================Part1===========================\n" << endl;
    //variables to store corresponding game initializing values
    string inputMapIndex;
    int inputPlayerQuantity;
    const int TerritoryQuantity = 10;
    int reinforcement;
    int orderQuantity = 3;

    //promt user to choose map1 or map2 as valid input, otherwise terminate the program
    cout << "Availabe Game Map List: Map1(Valid), Map2(Valid), Map3(Invalid)\n";
    cout << "Please enter the Map Index(1/2/3) for your game:\n";
    cin >> inputMapIndex;
    switch (inputMapIndex.at(0)) {
    case '1':
        cout << "Map1 successfully loaded!\n" << endl;
        break;
    case '2':
        cout << "Map2 successfully loaded!\n" << endl;
        break;
    case '3':
        cout << "Map3 successfully loaded!\n" << endl;
        break;
    default:
        cout << "Invalid map file, program terminated!!" << endl;
        exit(0);
    }

    //promt user to enter valid player number, otherwise terminate the program
    cout << "Please enter the number of players(2/3/4/5):\n";
    cin >> inputPlayerQuantity;
    switch (inputPlayerQuantity) {
    case 2:
        cout << "2 Players created!Reinforcement is 40 armies per round!\n" << endl;
        reinforcement = 40;
        break;
    case 3:
        cout << "3 Players created!Reinforcement is 35 armies per round!\n" << endl;
        reinforcement = 35;
        break;
    case 4:
        cout << "4 Players created!Reinforcement is 30 armies per round!\n" << endl;
        reinforcement = 30;
        break;
    case 5:
        cout << "5 Players created!Reinforcement is 25 armies per round!\n" << endl;
        reinforcement = 25;
        break;
    default:
        cout << "Invalid Player number, program terminated!!" << endl;
        exit(0);
    }


    //pass the user inputed arguments to game initialization method
    GameEngine* game_engine = new GameEngine(inputMapIndex, inputPlayerQuantity);


    cout << "\n\n===================Part2===================" << endl;

    //pass corresponding arguments to start the game and initialize players
    game_engine->startupPhase(inputPlayerQuantity, orderQuantity, reinforcement);

    //call destructors to avoid memory leak
    delete game_engine; game_engine = nullptr;

}