#include "Player.h"
#include<time.h>
#include <algorithm>  
#include <assert.h>  
using namespace std;

//Default constructor
Player::Player()
{
	name = "default";
	int reinforcementPool = 0;
	vector<Territory*> territory;
	vector<Card*> handCard;
	vector<Order*> orderList;
}

//added constructor
Player::Player(string s)
{
	this->name = s;

}


//Four parmeter constructor
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

void Player::setTerritory(Territory t)
{

	this->territory.push_back(&t);
}

vector<Territory*> Player::getTerritory() 
{
	return territory;

}
vector<Territory*> Player::get_neighbour_territories(vector<Territory*> Map) 
{
	vector<Territory*> neighbouring_terrritories;
	for (int i = 0; i < territory.size(); i++) 
	{
		for (int j = 0; j < Map.size(); j++) 
		{
			if (!territory[i]->getTerritoryOwner().compare(Map[j]->getTerritoryOwner())) 
			{
				for (int k = 0; k < neighbouring_terrritories.size(); k++) 
				{
					if (!neighbouring_terrritories[k]->getTerritoryOwner().compare(Map[j]->getTerritoryOwner()) || neighbouring_terrritories.empty())
					{
					neighbouring_terrritories.push_back(Map[j]);
					}
				}
				
			}
		}
	
	}

	return neighbouring_terrritories;

}

vector<Territory*> Player::toAttack(vector<Territory*> Map)
{
	vector<Territory*> AttackList;
	AttackList = get_neighbour_territories(Map);

	cout << "The list of territories that are be Attack" << endl;
	for (int i = 0; i < AttackList.size(); i++)
	{
		cout <<"Index "<<i<< " "<<(*AttackList[i]).getTname() << " "<<(*AttackList[i]).getContinent()<< endl;
	}
	return AttackList;
}

vector<Territory*> Player::toDefend()
{
	vector<Territory*> defendList;
	Territory* temp = NULL;
	cout << "The list of territories that are be defended" << endl;
	for (int i = 0; i < territory.size(); i++)
	{
		cout << "Index " << i << " " << (*territory[i]).getTname() << " " << (*territory[i]).getContinent() << endl;
		temp = territory[i];
		defendList.push_back(temp);
	}
	return defendList;
}

bool Player::playerContientBouns()
{ 
	string a = "NA";
	string b = "AS";
	string c = "SA";
	string d = "AU";
	string e = "EU";
	string f = "AF";
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0,c6=0;
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
	if (c1 == 3) { return true; }//NA 
	if (c2 == 3) { return true; }//AS
	if (c3 == 1) { return true; }//SA
	if (c4 == 1) { return true; }//AU
	if (c5 == 1) { return true; }//EU
	if (c6 == 1) { return true; }//EU
	

	
	return false;
}


void Player::issueOrder(vector<Territory*> Map)
{
	vector<Territory*> AttackList;
	AttackList = toAttack(Map);
	vector<Territory*> DefendList;
	DefendList = toDefend();

			//Deploy order until no armies left	
			while (getReinforcementPool() != 0)
			{
				int army = getReinforcementPool();
                
				for (int i = 0; i < DefendList.size(); i++)
				{
					srand(time(NULL));
					int temp = rand() % army + 1;
					temp += DefendList[i]->getArmyAmount();
					DefendList[i]->setArmyAmount(temp);
					army = temp - army;
					setReinforcementPool(army);
					if (army = 1)
					{
						temp = 1;
						temp += DefendList[i]->getArmyAmount();
						DefendList[i]->setArmyAmount(temp);
						setReinforcementPool(0);
					}
				}
			}
			
			//Advance order
			srand(time(NULL));
			int actionNumber = rand()% AttackList.size();
			
			int Enemy = AttackList[actionNumber]->getArmyAmount();


	
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



}



