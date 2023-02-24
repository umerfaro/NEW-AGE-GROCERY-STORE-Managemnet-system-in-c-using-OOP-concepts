
#include"Admin.h"
#include"MenuHeader.h"
#include"checkoutsimulation.h"

void Admin::customerFeedbackshow() {
	
	
		Feedback temp;
		ifstream myFile("feedback.dat", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			cout <<temp.getfeedbackname() << "  " << temp.getFeedback() << "  " << temp.getrating() << endl;;
		}
		myFile.close();
	

}
void Admin::deletecustomerfeedback() {
	customerFeedbackshow();

	string s;
	cout << "Enter customer username which feedback you want to delete " << endl;
	cin >> s;
    Feedback temp;
	fstream myFile("feedback.dat", ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.dat", ios::app | ios::binary);

	while (myFile.read((char*)&temp, sizeof(temp))) 
	{
		if (temp.getfeedbackname() != s)
		{
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
	}
	myFile.close();
	myFile_temp.close();
	remove("feedback.dat");
	rename("temp.dat", "feedback.dat");
	cout << endl << endl;


}



void deleteObject(string cnic)
{
	Customer temp;
	fstream myFile("Customer.dat", ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp)))
	{
		if (temp.getCNIC() != cnic) {
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
	}
	myFile.close();
	myFile_temp.close();
	remove("Customer.dat");
	rename("temp.bin", "Customer.dat");
	cout << "Customer deleted successfully" << endl;
}



bool Admin::Searchcustomer() {
	char n[100];
	Customer temp;
	cout << "Enter CNIC of the customer you want to search: ";
	cin >> n;
	ifstream fileopen("Customer.dat", ios::binary);
	fileopen.clear();
	fileopen.seekg(0);
	while (fileopen.read((char*)&temp, sizeof(temp))) {
		if (strcmp(n, temp.getCNIC()) == 0) {
			customer = temp;
			return true;
		}
	}
	return false;
}

void Admin::Showcustomer() {
	cout << customer.getname() << "\t" << customer.getCNIC() << "\t" << customer.getGender() << "\t" << customer.getadress() << endl;;
}

void Admin::Menu()
{
	lable9:
	if (login() == 1)
{ 
		Lable1:
	system("CLS");
	cout << "\t\t\t\t************************************************************************************" << endl;
	cout << "\t\t\t\t\t\tPress 1 to search for customer" << endl;
	cout << "\t\t\t\t\t\tPress 2 to add manager " << endl;
	cout << "\t\t\t\t\t\tPress 3 to add product into catalog" << endl;
	cout << "\t\t\t\t\t\tPress 4 to show all catalog product" << endl;
	cout << "\t\t\t\t\t\tPress 5 to update catalog product" << endl;
	cout << "\t\t\t\t\t\tPress 6 to see customer feedback" << endl;
	cout << "\t\t\t\t\t\tPress 7 to Delete customer feedback" << endl;
	cout << "\t\t\t\t\t\tPress 8 to check how much time takken to customer to checkout " << endl;
	cout << "\t\t\t\t\t\tPress 9 to logout " << endl;
	cout << "\t\t\t\t************************************************************************************" << endl;
	int n;
	cin >> n;
	switch (n) {
	case 1:
		if (Searchcustomer()==1)
		{

			cout << "Press 1 to update password " << endl;
			cout << "Press 2 to update username " << endl;
			cout << "Press 3 to show customer" << endl;
			cout << "Press 4 to delete customer" << endl;

			cin >> n;
			switch (n)
			{
			case 1:
				customer.passwordupdate();
				system("pause");
				goto Lable1;

				break;
			case 2:
				customer.nameuserchnage();
				system("pause");
				goto Lable1;
				break;
			case 3:
				Showcustomer();
				system("pause");
				goto Lable1;
				break;
			case 4:
			{
				cout << "Enter customer cnic to delete it " << endl;
				string n;
				cin >> n;
				deleteObject(n);
				goto Lable1;
				break;
			}



			}
		}
		else {
			cout << "customer Not found";
			goto Lable1;

		}
		break;
	case 2:
	{

		int n;
		cout << "Press 1 to ADD manager to ISlamabad store" << endl;
		cout << "Press 2 to ADD manager to lahore store" << endl;
		cout << "Press 3 to ADD manager to karachi store" << endl;
		cout << "Press 4 to go back" << endl;
		int n1;
		cin >> n1;

		while (n1 > 3 || n1 < 1)
		{
			cout << "Invalid input. \n-->Please Enter valid input: ";
			cin >> n1;
		}
		switch (n1)
		{
		case 1:
		{
			Manager* man;
			man = new Manager1;

			man->Register();


			goto Lable1;
			break;
		}
		case 2:
		{
			Manager* man;
			man = new Manager2;

			man->Register();
			goto Lable1;
			break;
		}
		case 3:
		{
			Manager* man;
			man = new Manager3;

			man->Register();
			goto Lable1;
			break;
		}
		case 4:
		{

			goto Lable1;
			break;
		}

		}

		break;
	}
	case 3:
	{
		product.selectcatalogoption();
		system("pause");
		//Menu();
		goto Lable1;
		break;
	}
	case 4:
	{
		cout << "*******************************************Product Catalog*****************************************" << endl;
		cout << "name" << "                  \t" << "Price" << endl;
		cout << endl << endl;;
		product.retrivecatalogdate();
		cout << "*****************************************************************************************************" << endl;
		system("pause");
		//Menu();
		goto Lable1;
		break;
		//Menu();
	}case 5:
	{
		product.updateCATAlogproduct();
		system("pause");

		//Menu();
		goto Lable1;
		break;
		//Menu();
	}case 6:
	{
		customerFeedbackshow();
		//system("pu")
		system("pause");
		//Menu();
		goto Lable1;
		break;
		//Menu();
	}case 7:
	{
		deletecustomerfeedback();
		system("pause");
		//Menu();
		goto Lable1;
		break;
		//Menu();
	}
	case 8:
	{
	
		Simulation simulae;
		simulae.retrievecustomerdata();
		system("pause");
		cout << endl << endl;
		simulae.simulationMenu();
		simulae.totaltimetakeninmints();
		system("pause");
		goto Lable1;
	}
	case 9:
	{
		Startingmenu s;
		s.startingmenu1();
		break;
		break;
	}


	default:
		Menu();
		break;


	}

}
else
{
goto lable9;
 }

}


bool Admin::login() {
	
	

	ofstream myfile("admin.dat", ios::binary | ios::app);
	myfile.write((char*)this, sizeof(this));
	myfile.close();


	Admin temp;
	string s;
	cout << "Enter Username" << endl;
	cin >> s;
	temp.setUsername(s);
	cout << "Enter Password" << endl;
	cin >> s;
	temp.setPassword(s);
	bool check = true;

		if ((strcmp(temp.getUsername(), this->getUsername()) == 0))
		{
			if ((strcmp(temp.getPassword(), this->getPassword()) == 0))
			{
				cout << "login Successful" << endl;
				check = false;
				*this = temp;
				return true;
			}

			else
			{
				cout << "Password is wrong " << endl;
				check = true;

			}

		}
		else
		{
			cout << "username is wrong " << endl;
			check = true;

		}

	
	if (check==true) 
	{
		cout << "\nLogin unsuccessful\n";
		return false;
	}
	

}

Admin::Admin() {
	setUsername("admin");
	setPassword("admin");

}


