#pragma once
#ifndef HOUSEHOLD_CLEANING_H
#define HOUSEHOLD_CLEANING_H
#include<iostream>
using namespace std;


class Household_Cleaning
{

public:

	Household_Cleaning()
	{
		name[0] = '\0';
		price = 0;
	}
	void setHousehold_Cleaningname(string s)
	{
		strcpy_s(name, s.length() + 1, s.c_str());
	}
	char* getHousehold_Cleaningname()
	{
		return name;
	}
	void setHousehold_Cleaningprice(int n)
	{
		price = n;
	}

	int getHouseholdprice()
	{
		return price;
	}


	void DisplayHousehold_Cleaning()
	{

		cout << name << "             \t" <<price;
	}

private:
	char name[50];
	int price;

};










#endif // !Household_Cleaning
