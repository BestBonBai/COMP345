#include "Player.h"


using namespace std;

//Default constructor
Player::Player()
{
	name = "default";
	reinforcementPool = 0;
	
}

//added constructor
Player::Player(string s)
{
	this->name = s;

}

Player::Player(int reinforcementPool,string name, vector<Territory*> t, vector<Card*> h, vector<Order*> o)
{
	this->reinforcementPool = reinforcementPool;
	this->name = name;
	this->territory = t;
	this->handCard = h;
	this->orderList = o;
}



//Copy constructor (Deep copy)
Player::Player(const Player& p)
{
	this->reinforcementPool = p.reinforcementPool;
	this->name = p.name;
	this->territory = p.territory;
	this->handCard = p.handCard;
	this->orderList = p.orderList;

}

//added assignment operator
Player& Player::operator=(const Player& player)
{
	this->name = player.name;
	this->reinforcementPool = player.reinforcementPool;
	this->territory = player.territory;
	this->handCard = player.handCard;
	this->orderList = player.orderList;
	return *this;
}

//Destructor
Player::~Player()
{
	name = "";
	reinforcementPool = 0;
	territory.clear();
	handCard.clear();
	for (auto order : orderList)
	{
		delete order;
	}
	orderList.clear();
	//release memory
	vector<Territory*>().swap(territory);
	vector<Card*>().swap(handCard);
	vector<Order*>().swap(orderList);
}

//added
string Player::getName() {
	return this->name;
}

void Player::setName(string s) {
	this->name = s;
}

int Player::getReinforcementPool() {
	return this->reinforcementPool;
}

void Player::setReinforcementPool(int i) {
	this->reinforcementPool = i;
}


void Player::toAttack() 
{

}

vector<Territory*> Player::toDefend()
{
	vector<Territory*> defendList;
	Territory* temp = NULL;
	cout << "The list of territories that are be defended" << endl;
	for (int i = 0; i < territory.size(); i++)
	{
		cout << (*territory[i]).getTname() << endl;
		temp = territory[i];
		defendList.push_back(temp);
	}
	return defendList;
}

bool Player::playerContientBouns()
{ 
	string a = "Artic";
	string b = "Canada";
	string c = "Russia";
	string d = "Norway";
	string e = "United_States";
	string f = "Denmark";
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0,c6 = 0;
	for (int i = 0; i < territory.size(); i++)
	{
		if ((*territory[i]).getContinent().compare(a))
		{
			c1++;
		}
		if ((*territory[i]).getContinent().compare(b))
		{
			c2++;
		}
		if ((*territory[i]).getContinent().compare(c))
		{
			c3++;
		}
		if ((*territory[i]).getContinent().compare(d))
		{
			c4++;
		}
		if ((*territory[i]).getContinent().compare(e))
		{
			c5++;
		}
		if ((*territory[i]).getContinent().compare(f))
		{
			c6++;
		}	
		
	}
	if (c1 == 5) { return true; } 
	if (c2 == 5) { return true; }
	if (c3 == 8) { return true; }
	if (c4 == 2) { return true; }
	if (c5 == 4) { return true; }
	if (c6 == 5) { return true; }

	
	return false;
}


void Player::issueOrder()
{
	int actionNumber = rand() % 6;
	
		int countAction = 5;
		switch (actionNumber)
		{
			//Choose which neighbor to attack
		case 0:
			toAttack();
			//Choose which neighbor to Deffend
		case 1:
			toDefend();

		case 2:
			//Deploy order until no armies left	
			while (getReinforcementPool() != 0)
			{
				int army = getReinforcementPool();
				int j = 0;
				toDefend();
				string temp1 = NULL;

				cout << "Chose which territories you want to defend. " << endl;
				cin >> temp1;
				bool check = true;
				while (check)
					for (int i = 0; i <territory.size(); i++)
					{
						if (temp1.compare(territory[i]->getTname()))
						{
							j = i;
							check = false;
						}
						else
						{
							cout << "Please enter correct terrioty name. " << endl;
							cin >> temp1;
						}
					}

				int temp2 = 0;

				{
					cout << "How many arrmies you want to add?" << endl;
					cin >> temp2;
					while (temp2 > army || army < 0)
					{
						cout << "Please enter correct number" << endl;
						cin >> temp2;
					}
					army = army - temp2;
					territory[j]->setArmyAmount(temp2);
					setReinforcementPool(army);

				}
				check = true;
				j = 0;


			}
		
	case 3:
		toAttack();
	case 4:
		toDefend();
	case 5:
	   //using card;

	}
	
}

vector<Order*> Player::getOrderList()
{

	return orderList;
}


void Player::printOrder()
{

	for (int i = 0; i < orderList.size(); i++) {
		cout << "<" << orderList.at(i)->getResult() << "> ";
	}
	cout << endl;
}

void Player::printHandcard()
{
	cout << "The list of Player's handcard" << endl;
	for (int i = 0; i < handCard.size(); i++)
	{
		cout << *handCard[i] << endl;
	}
	cout << endl;


}



