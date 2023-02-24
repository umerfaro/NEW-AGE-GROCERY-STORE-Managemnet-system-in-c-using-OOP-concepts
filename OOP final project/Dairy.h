#pragma once
#ifndef DAIRY
#define DAIRY
#include<iostream>
using namespace std;


class Dairy
{

public:

	Dairy()
	{
		name[0] = '\0';
		price = 0;
	}
	void setDairyname(string s)
	{
		strcpy_s(name, s.length() + 1, s.c_str());
	}
	char* getDairyname()
	{
		return name;
	}
	void setDairyprice(int n)
	{
		price = n;
	}

	int getDairyprice()
	{
		return price;
	}

	void DisplayDairy()
	{
		if(price!=0)
		cout << name << "             \t"<<price << " Rs";
	}

private:
	char name[50];
	int price;

};










#endif // !Dairy
