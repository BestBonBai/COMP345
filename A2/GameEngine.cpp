#include "GameEngine.h";
#include <iomanip>

//default constructor
GameEngine::GameEngine() {
    this->userInputMap = "";
    this->userInputPlayerQuantity = 0;
}

//two parameter constructor(optional,for gameStartNew() only)
GameEngine::GameEngine(string s, int i) {
    this->userInputMap = s;
    this->userInputPlayerQuantity = i;
    gameStart();
}

//assignment operator
GameEngine& GameEngine::operator=(const GameEngine& game_engine)
{
    userInputMap = game_engine.userInputMap;
    userInputPlayerQuantity = game_engine.userInputPlayerQuantity;
    map = game_engine.map;
    map_loader = game_engine.map_loader;
    player_list = game_engine.player_list;
    deck = game_engine.deck;
    return *this;
}

//destructor
GameEngine::~GameEngine() {
    delete map; map = nullptr;
    delete map_loader; map_loader = nullptr;
    delete[] player_list; player_list = nullptr;
    delete deck; deck = nullptr;
    for (int i = 0; i < TerritoryQuantity; i++) {
        delete territory_array[i];
    }
}

//accessor
string GameEngine::getUserInputMap() {
    return this->userInputMap;
}

//accessor
int GameEngine::getUserInputPlayerQuantity() {
    return this->userInputPlayerQuantity;
}

//mutator
void GameEngine::setUserInputMap(string s) {
    this->userInputMap = s;
}

//mutator
void GameEngine::setUserInputPlayerQuantity(int i) {
    this->userInputPlayerQuantity = i;
}

//methord to initialize a game
void GameEngine::gameStart() {
    //call MapLoader and Map object to generate a map graph
    cout << "\n<Generated Index of Territories>" << endl;
    string mapLoaded = "map" + userInputMap + ".txt";
    map_loader = new MapLoader(mapLoaded, TerritoryQuantity);
    map = new Map(TerritoryQuantity);
    for (int i = 0; i < TerritoryQuantity; i++) {
        map->territoryList[i] = map_loader->territoryArray[i];
    }

    //initialize empty attributes for each player
    vector<Territory*> territory;
    vector<string*> card;
    vector<Order*> order;

    //create and display players according to user inputed quantity
    cout << "\n<Participating Player List>" << endl;
    player_list = new Player[userInputPlayerQuantity];
    for (int i = 0; i < userInputPlayerQuantity; i++) {
        player_list[i] = Player(0,playerNameArr[i], territory, card, order);
        cout << player_list[i].getName() << endl;
    }

    //create edges for the game map
    cout << "\n<Generated Map Structure>" << endl;
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
    if (map->Validate())
        cout << "Generated Map is a connected graph!!\n" << endl;
    else
        cout << "Caution! Generated Map is not connected graph!!\n" << endl;

    //initialize a card deck
    cout << "<Initial Card Deck Status>" << endl;
    deck = new Deck;
    deck->initial_vec_deck();
    deck->print_vec_deck();

}

//accessor
Map* GameEngine::getMap() {
    return map;
}

//accessor
Player* GameEngine::getPlayerList() {
    return player_list;
}

//accessor
int GameEngine::getTerritoryQuantity() {
    return this->TerritoryQuantity;
}

//method to start the game and initialize players
void GameEngine::startupPhase(int playerQuantity, int orderQuantity, int reinforcement) {
    //assign territory to players in round-robin fashion
    cout << "\n     Territory   " << "         Owner" << endl;
    for (int i = 0; i < TerritoryQuantity; i++) {
        territory_array[i] = new Territory();
        territory_array[i]->setTerritoryOwner((player_list + (i % playerQuantity))->getName());
        territory_array[i]->setTname(*((map->getTerritoryList()) + i));
        cout << setw(12) << territory_array[i]->getTname() << setw(20) << territory_array[i]->getTerritoryOwner() << endl;
    }

    //initialize army(amount of reinforcement) to each player 
    for (int k = 0; k < playerQuantity; k++) {
        (player_list + k)->setReinforcementPool(reinforcement);
        //cout << (p_list + i)->getArmy() << endl;
    }

    //assign random orders to each player
    const int o_range = 6;
    srand(time(NULL));
    //int o_index = (rand() % o_range);
    for (int j = 0; j < orderQuantity; j++) {
        for (int i = 0; i < playerQuantity; i++) {
            (player_list + i)->issueOrder(orderPool[(rand() % o_range)]);
        }
    }

    //display each player's initial status
    cout << "\n\n<Initialized status for each player>" << endl;
    for (int m = 0; m < playerQuantity; m++) {
        cout << "\n[player" << (m + 1) << "]" << endl;
        cout << "orders: ";
        (player_list + m)->printOrder();
        cout << "armies:";
        cout << (player_list + m)->getReinforcementPool();
        cout << endl;
    }

}
    void GameEngine::reinforcmentPhase(vector<Player*> playerList)
    {
        bool check = false;
        int temp = 0;
        double count = 0;

        for (int i = 0; i < playerList.size(); i++)
        {   //check the player's terriotries
            temp = playerList[i]->getReinforcementPool();

            for (int j = 0; j < playerList[i]->territory.size(); i++)
            {//count the terriorties number
                count++;
            }
            //calcuate the contient bouns
             check = (*playerList[i]).playerContientBouns();
            
            if(round(count / 3)>3)
            {
                if (check == true) 
                {
                 temp += 2*(int)round(count/3);
                }
                else 
                {
                    temp +=(int)round(count / 3);
                }
            }
            else 
            {
                temp += 3;
            }
            playerList[i]->setReinforcementPool(temp);
            check = false;
            temp = 0;
            count = 0;
               
        }
    }
    void  GameEngine::issueOrdersPhase(vector<Player*> playerList)
    {

       
        for (int i = 0; i < playerList.size(); i++) 
        {
            playerList[i]->issueOrder();

        }

    }

    void GameEngine::excuteOrderPhase() 
    {
    
    }

