#pragma once
#ifndef MANAGER2_H
#define MANAGER2_H
#include"Manager.h"
#include"Inventory.h"

class Manager2 :public Manager
{
public:
	Manager2();
	void passwordchnage()override;
	void managernamechnage()override;
	bool login2();
	void Menu() override;
	void Register() override;




private:
	Inventory inventoryss;

};






#endif // !Manager2
