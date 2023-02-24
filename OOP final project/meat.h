#pragma once
#ifndef MEAT
#define MEAT
#include<iostream>
using namespace std;


class Meat
{

public:

	Meat() 
	{
		name[0]='\0';
		price =0;
	}
	void setMeatname(string s)
	{
		strcpy_s(name, s.length() + 1, s.c_str());
	}
	char* getMeatname()
	{
		return name;
	}
	void setmeatprice(int n)
	{
		price = n;
	}

	int getmeatprice()
	{
		return price;
	}

	void DisplayMeat()
	{
		if(price!=0)
		cout << name << "             \t" <<price << " Rs";
	}
	
private:
	char name[50];
	int price;


};










#endif // !MEAT
