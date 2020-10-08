#include "OrderPTest.h"

Order::Order() 
{
	string orderName;

}

Order::Order(string n) 
{
	this->orderName = n;

}

Order::~Order() 
{
	orderName.clear();
}

string Order::getResult() 
{
	return orderName;
}