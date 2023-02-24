#pragma
#ifndef STORE_H
#define STORE_H

#include <iostream>
#include"Manager.h"
using namespace std;

class Store
{
private:
	 /// aggregasion
	char store_name[100];
	int store_id;

public:

	Store();
	void setstorename(string s);
	void setstoreID(int n);
	char* getstorename();
	int getstoreid();



protected:


};






#endif // !STORE_H
