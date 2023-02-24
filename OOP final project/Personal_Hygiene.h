#pragma once
#ifndef PERSONAL_HYGIENE_H
#define PERSONAL_HYGIENE_H
#include<iostream>
using namespace std;


class Personal_Hygiene
{

public:

	Personal_Hygiene()
	{
		name[0] = '\0';
		Price = 0;
	}
	void setPersonal_Hygienename(string s)
	{
		strcpy_s(name, s.length() + 1, s.c_str());
	}
	char* getPersonal_Hygienename()
	{
		return name;
	}
	void setPersonal_HygienePrice(int n)
	{
		Price = n;
	}
	int getpersonal_hygieneprice()
	{
		return Price;
	}


	void DisplayPersonal_Hygiene()
	{

		cout << name << "             \t" << Price << " Rs";
	}

private:
	char name[50];
	int Price;

};










#endif // !Personal_Hygiene
