#include"Perishable_Goods.h"

Perishable_Goods::Perishable_Goods()
{
	select = 0;

}
void Perishable_Goods::select_option_of_Perishable_Goods()
{
	cout << "Press 1 to add Meat" << endl;
	cout << "Press 2 to add Dairy" << endl;
	cout << "Press 3 to add fruit" << endl;
	cout << "Press 4 to add vegitable" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
	{
		string s;
		int q;
		cout << "Enter name you want to add in meat" << endl;
		cin >> s;
		setMeatname(s);
		cout << "Enter price " << endl;
		cin >> q;
		setmeatprice(q);

		break;
	}
	case 2:
	{
		string s;
		int q;
		cout << "Enter name you want to add in Dairy" << endl;
		cin >> s;
		setDairyname(s);
		cout << "Enter price " << endl;
		cin >> q;
		setDairyprice(q);

		break;
	}
	case 3:
	{
		string s;
		int q;
		cout << "Enter name you want to add in Fruit" << endl;
		cin >> s;
		setFruitname(s);
		cout << "Enter price " << endl;
		cin >> q;
		setFruitprice(q);

		break;
	}
	case 4:
	{
		string s;
		int q;
		cout << "Enter name you want to add in vegitable" << endl;
		cin >> s;
		setvegetablename(s);
		cout << "Enter price " << endl;
		cin >> q;
		setvegetablePrice(q);

		break;
	}

	default:
		select_option_of_Perishable_Goods();

		break;
	}

}