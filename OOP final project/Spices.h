#pragma once
#ifndef SPICES_H
#define SPICES_H
#include<iostream>
using namespace std;


class Spices
{

public:

	Spices()
	{
		name[0] = '\0';
		Price = 0;
	}
	void setSpicesname(string s)
	{
		strcpy_s(name, s.length() + 1, s.c_str());
	}
	char* getSpicesname()
	{
		return name;
	}
	void setSpicesPrice(int n)
	{
		Price = n;
	}

	int getspicesprice()
	{
		return Price;
	}


	void DisplaySpices()
	{

		cout << name << "             \t" << Price << " Rs";
	}

private:
	char name[50];
	int Price;

};










#endif // !Spices
