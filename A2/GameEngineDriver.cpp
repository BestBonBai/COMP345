#include "GameEngine.h";
#include "Player.h";

int main() 
{
	vector <Territory*> Map1;
	Territory a1("Canada", "NA", 0,1);
	Territory a2("USA", "NA", 0,2);
	Territory a3("Maxico", "NA",0,3);
	Territory a4("Europe", "EU", 0,4);
	Territory a5("Africa", "AF", 0,5);
	Territory a6("SouthAmerica", "SA", 0,6);
	Territory a7("Russia", "AS", 0,7);
	Territory a8("China", "AS", 0,8);
	Territory a9("Japan", "AS", 0,9);
	Territory a10("Australia", "AU", 0,10);
	Map1.push_back(&a1);
	Map1.push_back(&a2);
	Map1.push_back(&a3);
	Map1.push_back(&a4);
	Map1.push_back(&a5);
	Map1.push_back(&a6);
	Map1.push_back(&a7);
	Map1.push_back(&a8);
	Map1.push_back(&a9);
	Map1.push_back(&a10);


	

	return 0;
}