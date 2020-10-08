#include "Player.h"

int main() 
{
	vector<Order*> src;
	vector<string*> rrr;

	vector<string*> tet;
	string c = "asia";
	string d = "Eurpoe";

	tet.push_back(&c);
	tet.push_back(&d);
	rrr = tet;
	vector<string*> card;
	string e = "bomb";
	string f = "spy";

	card.push_back(&e);
	card.push_back(&f);

	string name = "zixuan";
	Player* a1 = new Player(name,tet,card,src);
	(*a1).issueOrder("AAA");
	(*a1).issueOrder("bbb");
	(*a1).printOrder();
	(*a1).toAttack();
	(*a1).toDeffend();
	Player* a2 = new Player(*a1);
	cout << endl;
	(*a2).toAttack();
	


}
