#pragma once
#ifndef FRUIT
#define FRUIT
#include<iostream>
using namespace std;


class Fruit
{

public:

	Fruit()
	{
		name[0] = '\0';
		price = 0;
	}
	void setFruitname(string s)
	{
		strcpy_s(name, s.length() + 1, s.c_str());
	}
	char* getFruitname()
	{
		return name;
	}
	void setFruitprice(int n)
	{
		price = n;
	}

	int getFriutprice()
	{
		return price;
	}


	void DisplayFruit()
	{
		
		cout << name << "             \t" << price << " Rs";
	}

private:
	char name[50];
	int price;

};










#endif // !Fruit
