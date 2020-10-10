#include "Orders.h"

//Order&Order ::operator = (const Order&O)
//{
//	
//}

Order::Order()
{
}

Order::~Order()
{
}
//Order::Order(const Order& O) 
//{
//	this->vec_type1 = *new vector<string>(O.vec_type1);
//	this->type_id = new string(*(O.type_id));
//}
void Order::validate()
{
	cout << "validate if the order is valid" << endl;
	valid = true;
}

void Order::execute()
{
	if (valid) {
		cout << "executes the action..." << endl;
	}
}

void Order::set_type_id(int num)
{
	type_id = num;
}

string Order::get_type()
{
	return vec_type1.at(type_id);
}





void OrderList::set_order_list(Order* an_order)
{
	vec_order_list.push_back(an_order); //add an order
}

vector<Order*>* OrderList::get_order_list()
{
	return &vec_order_list;
}

void OrderList::delete_order(Order* oneOrder)
{
	for (int i = 0; i < vec_order_list.size(); i++) {
		if (oneOrder->get_type() == vec_order_list.at(i)->get_type()) {
			cout << "  deleting the order: " << oneOrder->get_type() << endl;
			vec_order_list.erase(vec_order_list.begin() + i);
			
			return;
		}
	}
}

void OrderList::move(int position, int new_position)
{
	if (position >= 0 && position < vec_order_list.size() && new_position >= 0 && new_position < vec_order_list.size())
	{
		vec_order_list.insert(vec_order_list.begin() + new_position, vec_order_list.at(position));
		vec_order_list.erase(vec_order_list.begin() + position);
	}
	else if (new_position == vec_order_list.size()  )
	{
		vec_order_list.push_back(vec_order_list.at(position));
		vec_order_list.erase(vec_order_list.begin() + position);
	}
	else {
		cout << "\n not valid position" << endl;
	}
}

Deploy::Deploy()
{
	cout << "deploy is creating..." << endl;
	set_type_id(0);
}

Deploy::~Deploy()
{
}

string* Deploy::get_type()
{
	return &type1;
}

Advance::Advance()
{
	cout << "advance is creating..." << endl;
	set_type_id(1);
}

Advance::~Advance()
{
}

Bomb::Bomb()
{
	cout << "bomb is creating..." << endl;
	set_type_id(2);
}

Bomb::~Bomb()
{
}

Blockade::Blockade()
{
	cout << "blockade is creating..." << endl;
	set_type_id(3);
}

Blockade::~Blockade()
{
}

Airlift::Airlift()
{
	cout << "airlift is creating..." << endl;
	set_type_id(4);
}

Airlift::~Airlift()
{
}

Negotiate::Negotiate()
{
	cout << "negotiate is creating..." << endl;
	set_type_id(5);
}

Negotiate::~Negotiate()
{
}
