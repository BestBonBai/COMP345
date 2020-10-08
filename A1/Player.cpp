#include "Player.h"

using namespace std;

Player::Player() 
{
	string name;
	vector<string*> terriorty;
	vector<string*> handCard;
	vector<Order*> orderList;
}


Player::Player(string name, vector<string*> t, vector<string*> h,vector<Order*> o) 
{
	this->name = name;
	this->terriorty = t;
	this->handCard = h;
	this->orderList = o;
}



//not deep copy
Player::Player(const Player& p) 
{
	this->name = p.name;
	this->terriorty = p.terriorty;
	this->handCard = p.handCard;
	this->orderList = p.orderList;

}


Player::~Player()
{
	name.clear();
	terriorty.clear();
	handCard.clear();
	for (auto order : orderList)
	{
		delete order;
	}
	orderList.clear();

	
}

void Player::toAttack()
{
	for (int i = 0; i < terriorty.size(); i++) 
	{
		cout << *terriorty[i] << "";
	}
	
}


void Player::toDeffend() 
{
	for (int i = 0; i < terriorty.size(); i++)
	{
		cout << *terriorty[i] << "";
	}
	
}


void Player::issueOrder(string order) 
{
	Order *a = new Order(order);

	orderList.push_back(a);

}

vector<Order*> Player::getOrderList() 
{

	return orderList;
}


void Player::printOrder() 
{

	vector<Order*>::iterator it = orderList.begin();
	for (; it != orderList.end(); it++)
	{
		cout << (*it)->getResult() << " ";
	}
	cout << endl;
}