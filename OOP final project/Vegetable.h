#pragma once
#ifndef VEGETABLE
#define VEGETABLE
#include<iostream>
using namespace std;


class vegetable
{

public:

	vegetable()
	{
		name[0] = '\0';
		Price = 0;
	}
	void setvegetablename(string s)
	{
		strcpy_s(name, s.length() + 1, s.c_str());
	}
	char* getvegetablename()
	{
		return name;
	}
	void setvegetablePrice(int n)
	{
		Price = n;
	}

	int getVegetableprice()
	{
		return Price;
	}


	void Displayvegetable()
	{
		
		cout << name << "             \t" << Price<<" Rs";
	}

private:
	char name[50];
	int Price;

};










#endif // !vegetable
