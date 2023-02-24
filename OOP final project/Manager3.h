#pragma once
#ifndef MANAGER3_H
#define MANAGER3_H
#include"Manager.h"
#include"Inventory.h"

class Manager3 :public Manager
{
public:

	Manager3();
	void passwordchnage()override;
	bool login2();
	void managernamechnage()override;
	void Menu() override;
	void Register() override;




private:
	Inventory inventory3;

};






#endif // !MANAGER1
