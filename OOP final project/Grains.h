#pragma once
#ifndef GRAINS_H
#define GRAINS_H
#include<iostream>
using namespace std;


class Grains
{

public:

	Grains()
	{
		name[0] = '\0';
		price = 0;
	}
	void setGrainsname(string s)
	{
		strcpy_s(name, s.length() + 1, s.c_str());
	}
	char* getGrainsname()
	{
		return name;
	}
	void setGrainsprice(int n)
	{
		price = n;
	}
	int getGrainprice()
	{
		return price;
	}

	void DisplayGrains()
	{

		cout << name <<"             \t" << price << " Rs";
	}

private:
	char name[50];
	int price;

};










#endif // !Grains
