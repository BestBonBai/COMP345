#include "Orders.h"

using namespace std;

int main()
{
	cout << "test OrderDriver...\n" << endl;
	OrderList anOrderList;

	Deploy aDeploy;
	Advance anadvance;
	Bomb abomb;
	Blockade ablockade;
	Airlift anairlift;
	Negotiate anegotiate;

	anOrderList.set_order_list(&aDeploy);
	anOrderList.set_order_list(&anadvance);
	anOrderList.set_order_list(&abomb);
	anOrderList.set_order_list(&ablockade);
	anOrderList.set_order_list(&anairlift);
	anOrderList.set_order_list(&anegotiate);


	//print orderlist
	cout << "\n the orderlist contains: " << endl;
	for (int i = 0; i < anOrderList.get_order_list()->size(); i++) {
		cout <<"  "<< anOrderList.get_order_list()->at(i)->get_type() << endl;
	}

	//delete an order
	anOrderList.delete_order(&aDeploy);

	//print orderlist
	cout << "\n the orderlist contains: " << endl;
	for (int i = 0; i < anOrderList.get_order_list()->size(); i++) {
		cout << "  " << anOrderList.get_order_list()->at(i)->get_type() << endl;
	}

	//move an order
	anOrderList.move(0,4);
	//anOrderList.move(0, 5);
	anOrderList.move(0, 8);//invalid
	//print orderlist
	cout << "\n the orderlist contains: " << endl;
	for (int i = 0; i < anOrderList.get_order_list()->size(); i++) {
		cout << "  " << anOrderList.get_order_list()->at(i)->get_type() << endl;
	}

}