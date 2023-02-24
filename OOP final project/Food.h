#pragma once
#ifndef FOOD
#define FOOD
#include"Perishable_Goods.h"
#include"Non_Perishable_Goods.h"
#include"ProductCatalog.h"

class Food:public Perishable_Goods ,public NonPerishable_Goods
{
public:
	Food() 
	{
		select2 = 0;
	}

	void selectoptionoffood()
	{
		cout << "Press 1 to add Perishable_goods" << endl;
		cout << "Press 2 to add Non_Perishable_goods" << endl;

		cin >> select2;
		switch (select2)
		{
		case 1:
		{
			select_option_of_Perishable_Goods();
			
			break;
		}
		case 2:
		{
			select_option_of_NonPerishable_Goods();
			break;
		}
		


		default:
			selectoptionoffood();
			break;
		}

	}

	

private:
	int select2;
	
};






#endif // !FOOD
