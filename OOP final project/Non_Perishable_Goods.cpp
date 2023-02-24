#include"Non_Perishable_Goods.h"

NonPerishable_Goods::NonPerishable_Goods()
{
	select = 0;

}
void NonPerishable_Goods::select_option_of_NonPerishable_Goods()
{
	cout << "Press 1 to add snacks" << endl;
	cout << "Press 2 to add spices" << endl;
	cout << "Press 3 to add Grains" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
	{
		string s;
		int q;
		cout << "Enter name you want to add in snacks" << endl;
		cin >> s;
		setSnacksname(s);
		cout << "Enter price " << endl;
		cin >> q;
		setSnacksPrice(q);

		break;
	}
	case 2:
	{
		string s;
		int q;
		cout << "Enter name you want to add in spices" << endl;
		cin >> s;
		setSpicesname(s);
		cout << "Enter price " << endl;
		cin >> q;
		setSpicesPrice(q);

		break;
	}
	case 3:
	{
		string s;
		int q;
		cout << "Enter name you want to add in Grains" << endl;
		cin >> s;
		setGrainsname(s);
		cout << "Enter price " << endl;
		cin >> q;
		setGrainsprice(q);

		break;
	}


	default:
		select_option_of_NonPerishable_Goods();

		break;
	}

}