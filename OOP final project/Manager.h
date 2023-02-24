#ifndef MANAGER_H
#define MANAGER_H

#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#include<cstring>
#include"USer.h"
#include"Inventory.h"
using namespace std;




class Manager :public Userclass {
private:
	//Inventory inventory;
	

public:
	//All functions;
	int default_id;
	Manager(Manager& a);
	Manager();
	bool login() override;
	virtual  void Register();
	void DisplayManager();
	virtual void managernamechnage();
	virtual void passwordchnage();
	void Menu()override;
	 void Showallcustomer();

};











#endif
