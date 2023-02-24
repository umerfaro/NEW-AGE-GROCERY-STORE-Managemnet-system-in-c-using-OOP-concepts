#include"ProductCatalog.h"
#include"Admin.h"

ProductCatalog::ProductCatalog()
{
	select3 = 0;
}
void ProductCatalog::selectcatalogoption()
{
	cout << "press 1 to select FOOD" << endl;
	cout << "press 2 to select Personal Hygiene" << endl;
	cout << "press 3 to select Household Cleaning" << endl;
	cout << "Press 4 to go back" << endl;

	cin >> select3;
	switch (select3)
	{
	case 1:
	{
		selectoptionoffood();
		writecatalog();

		break;
	}
	case 2:
	{
		string s;
		int q;
		cout << "Enter HygieneName " << endl;
		cin >> s;
		setPersonal_Hygienename(s);
		cout << "Enter price " << endl;
		cin >> q;
		setPersonal_HygienePrice(q);

		writecatalog();

		break;
	}
	case 3:
	{
		string s;
		int q;
		cout << "Enter HouseHOld cleaning " << endl;
		cin >> s;
		setHousehold_Cleaningname(s);
		cout << "Enter price " << endl;
		cin >> q;
		setHousehold_Cleaningprice(q);

		writecatalog();

		break;
	}
	case 4:
	{
		Admin a;
		a.Menu();
		break;
	}

	default:
		selectcatalogoption();
		break;
	}

}
void ProductCatalog::displayALLPRODUCT()
{


	if (Meat::getmeatprice() != 0)
	{
		Meat::DisplayMeat();
		cout << endl;
	}
	else if (Dairy::getDairyprice() != 0)
	{
		Dairy::DisplayDairy();
		cout << endl;
	}
	else if (Fruit::getFriutprice() != 0)
	{
		Fruit::DisplayFruit();
		cout << endl;
	}
	else if (vegetable::getVegetableprice() != 0)
	{
		vegetable::Displayvegetable();
		cout << endl;
	}
	else if (Snacks::getSnackprice() != 0)
	{
		Snacks::DisplaySnacks();
		cout << endl;
	}
	else if (Spices::getspicesprice() != 0)
	{
		Spices::DisplaySpices();
		cout << endl;
	}
	else if (Grains::getGrainprice() != 0)
	{
		Grains::DisplayGrains();
		cout << endl;
	}
	else if (Personal_Hygiene::getpersonal_hygieneprice() != 0)
	{
		Personal_Hygiene::DisplayPersonal_Hygiene();
		cout << endl;
	}
	else if (Household_Cleaning::getHouseholdprice() != 0)
	{
		Household_Cleaning::DisplayHousehold_Cleaning();
		cout << endl;
	}
	

}

void ProductCatalog::updateCATAlogproduct()
{
	string s, s2;
	int n;
	cout << "which Product you want to update" << endl;
	cout << "Press 1 for Meat" << endl;
	cout << "Press 2 for Dairy" << endl;
	cout << "Press 3 for Fruit" << endl;
	cout << "Press 4 for Vegetable" << endl;
	cout << "Press 5 for Snacks" << endl;
	cout << "Press 6 for Grains" << endl;
	cout << "Press 7 for Personal_Hygiene" << endl;
	cout << "Press 8 for Household_Cleaning" << endl;
	cout << "Press 9 for Spices" << endl;
	cout << "Press 10 to go back" << endl;
	cin >> n;

	switch (n)
	{
	case 1:
	{
		retrivecatalogdate();

		cout << endl;

		cout << "Enter old name" << endl;
		cin >> s;
		cout << "Enter updated name" << endl;
		cin >> s2;

		ProductCatalog temp;
		fstream myFile("ProductCatalog.dat", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getMeatname() == s)
			{
				temp.setMeatname(s2);
				int current = myFile.tellg();
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
			}
		}
		updateCATAlogproduct();
		break;
	}


	case 2:
	{
		retrivecatalogdate();

		cout << endl;

		cout << "Enter old name" << endl;
		cin >> s;
		cout << "Enter updated name" << endl;
		cin >> s2;

		ProductCatalog temp;
		fstream myFile("ProductCatalog.dat", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getDairyname() == s)
			{
				temp.setDairyname(s2);
				int current = myFile.tellg();
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
			}
		}
		updateCATAlogproduct();
		break;
	}


	case 3:
	{
		retrivecatalogdate();

		cout << endl;

		cout << "Enter old name" << endl;
		cin >> s;
		cout << "Enter updated name" << endl;
		cin >> s2;

		ProductCatalog temp;
		fstream myFile("ProductCatalog.dat", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getFruitname() == s)
			{
				temp.setFruitname(s2);
				int current = myFile.tellg();
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
			}
		}
		updateCATAlogproduct();
		break;
	}
	case 4:

	{
		retrivecatalogdate();

		cout << endl;

		cout << "Enter old name" << endl;
		cin >> s;
		cout << "Enter updated name" << endl;
		cin >> s2;

		ProductCatalog temp;
		fstream myFile("ProductCatalog.dat", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getvegetablename() == s)
			{
				temp.setvegetablename(s2);
				int current = myFile.tellg();
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
			}
		}
		updateCATAlogproduct();
		break;
	}
	case 5:

	{
		retrivecatalogdate();

		cout << endl;

		cout << "Enter old name" << endl;
		cin >> s;
		cout << "Enter updated name" << endl;
		cin >> s2;

		ProductCatalog temp;
		fstream myFile("ProductCatalog.dat", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getSnacksname() == s)
			{
				temp.setSnacksname(s2);
				int current = myFile.tellg();
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
			}
		}
		updateCATAlogproduct();
		break;
	}
	case 6:

	{
		retrivecatalogdate();

		cout << endl;

		cout << "Enter old name" << endl;
		cin >> s;
		cout << "Enter updated name" << endl;
		cin >> s2;

		ProductCatalog temp;
		fstream myFile("ProductCatalog.dat", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getGrainsname() == s)
			{
				temp.setGrainsname(s2);
				int current = myFile.tellg();
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
			}
		}
		updateCATAlogproduct();
		break;
	}
	case 7:

	{
		retrivecatalogdate();

		cout << endl;

		cout << "Enter old name" << endl;
		cin >> s;
		cout << "Enter updated name" << endl;
		cin >> s2;

		ProductCatalog temp;
		fstream myFile("ProductCatalog.dat", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getPersonal_Hygienename() == s)
			{
				temp.setPersonal_Hygienename(s2);
				int current = myFile.tellg();
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
			}
		}
		updateCATAlogproduct();
		break;
	}
	case 8:

	{
		retrivecatalogdate();

		cout << endl;

		cout << "Enter old name" << endl;
		cin >> s;
		cout << "Enter updated name" << endl;
		cin >> s2;

		ProductCatalog temp;
		fstream myFile("ProductCatalog.dat", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getHousehold_Cleaningname() == s)
			{
				temp.setHousehold_Cleaningname(s2);
				int current = myFile.tellg();
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
			}
		}
		updateCATAlogproduct();
		break;
	}
	case 9:

	{
		retrivecatalogdate();

		cout << endl;

		cout << "Enter old name" << endl;
		cin >> s;
		cout << "Enter updated name" << endl;
		cin >> s2;

		ProductCatalog temp;
		fstream myFile("ProductCatalog.dat", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getSpicesname() == s)
			{
				temp.setSpicesname(s2);
				int current = myFile.tellg();
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock);
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
			}
		}
		updateCATAlogproduct();
		break;
	}
	case 10:
	{
		Admin a;
		a.Menu();
		break;
	}

	default:
		updateCATAlogproduct();
		break;
	}






}

void ProductCatalog::retrivecatalogdate()
{


	ProductCatalog temp;
	ifstream myFile("ProductCatalog.dat", ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp)))
	{
		temp.displayALLPRODUCT();
	}
	myFile.close();


}

void ProductCatalog::writecatalog()
{
	ofstream myFile("ProductCatalog.dat", ios::binary | ios::app);
	if (myFile.write((char*)this, sizeof(*this)))
		cout << "Object Successfully Inserted!" << endl;
	else
		cout << " Object Insertion Failed" << endl;
	myFile.close();
}