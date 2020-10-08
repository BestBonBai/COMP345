#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Order 
{
private:
	string orderName;


public:
	Order();
	Order(string);
	~Order();
	string getResult();


};
