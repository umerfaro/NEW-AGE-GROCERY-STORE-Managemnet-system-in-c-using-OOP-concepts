#pragma once
#ifndef MANAGER1_H
#define MANAGER1_H
#include"Manager.h"
#include"Inventory.h"


class Manager1:public Manager 
{
public:


	void passwordchnage()override;
	void managernamechnage()override;
	Manager1();
	bool login2();
	void Menu() override;
	void Register();

private:
	Inventory inventorys;
	Manager1 *man;

};






#endif // 
