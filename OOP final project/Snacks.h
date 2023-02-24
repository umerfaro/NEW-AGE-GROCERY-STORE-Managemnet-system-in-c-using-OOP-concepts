#pragma once
#ifndef SNACKS_H
#define SNACKS_H
#include<iostream>
using namespace std;


class Snacks
{

public:

	Snacks()
	{
		name[0] = '\0';
		Price = 0;
	}
	void setSnacksname(string s)
	{
		strcpy_s(name, s.length() + 1, s.c_str());
	}
	char* getSnacksname()
	{
		return name;
	}
	void setSnacksPrice(int n)
	{
		Price = n;
	}

	int getSnackprice()
	{
		return Price;
	}


	void DisplaySnacks()
	{

		cout << name << "             \t" <<Price << " Rs";
	}

private:
	char name[50];
	int Price;

};










#endif // !Snacks
