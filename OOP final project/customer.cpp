
#include"Customer.h"
#include<fstream>
#include"MenuHeader.h"
#include"ProductCatalog.h"

int Customer::status2 = 0;

void Customer::setPhonenumber(string n) {
	strcpy_s(phone_number, n.length() + 1, n.c_str());
}

char* Customer::getphoneNumber() {
	return phone_number;
}

void Customer::setaddress(string n) {
	strcpy_s(address, n.length() + 1, n.c_str());
}

char* Customer::getadress() {
	return address;
}

void Customer::setwalletbalance(int n)
{

		Wallet.setbalance(n);

}
int Customer::getwalletbalance() {
	return Wallet.getbalance();
}

void Customer::showmydetails()
{
	cout << getname() << "\t" << getCNIC() << "\t" << getGender() << "\t" << getphoneNumber() << '\t' << getadress() << endl;
}
void Customer::Menu()
{
	int n;
lable3:
	system("cls");
	cout << "************************************NEW AGE GROCERY STORE login*******************************************************#" << endl;
	cout << "#                            Press 1 to login                                                                         #" << endl;
	cout << "#                            Press 2 to Register                                                                      #" << endl;
	cout << "#                            Press 3 to go to back screen                                                             #" << endl;
	cout << "#*********************************************************************************************************************#" << endl;
	cin >> n;
	switch (n) {
	case 1:

		if (login())
		{
		lable4:
			system("pause");
			system("CLS");
			cout << "**********************************************************************************************************************#" << endl;
			cout << "                                         Press 1 to update Password                                                   #" << endl;
			cout << "                                         Press 2 to update username                                                   #" << endl;
			cout << "                                         Press 3 Show Customer Details                                                #" << endl;
			cout << "                                         Press 4 to give Feedback                                                     #" << endl;
			cout << "                                         Press 5 to purchase Product                                                  #" << endl;
			cout << "                                         Press 6 to Add balance to your wallet                                        #" << endl;
			cout << "                                         Press 7 to LogOut                                                            #" << endl;
			cout << "#*********************************************************************************************************************#" << endl;
			cin >> n;
			switch (n) {
			case 1:
				passwordupdate();
				goto lable4;
				break;
			case 2:
				nameuserchnage();
				goto lable4;
				break;
			case 3:
				showmydetails();
				goto lable4;
				break;
			case 4:
				feedbackgive();
				goto lable4;
				break;
			case 5:
			{
				ProductCatalog product;

				cout << "*******************************************Product Catalog*****************************************" << endl;
				cout << "name" << "                  \t" << "Price" << endl;
				cout << endl << endl;;
				product.retrivecatalogdate();
				cout << "*****************************************************************************************************" << endl;
				system("pause");



				int n;
				cout << "Search and buy product from the following stores" << endl;
				cout << "\t\t\t\tWhich store you want to buy" << endl;
				cout << "\t\t\t\tPress 1 for Islamabad store" << endl;
				cout << "\t\t\t\tPress 2 for Lahore store" << endl;
				cout << "\t\t\t\tPress 3 for Islamabad store" << endl;
				cin >> n;
				switch (n)
				{
				case 1:
				{
					inventoryss.cart_of_inventory(n);
					system("pause");
					goto lable4;
					break;
				}
				case 2:
				{
					inventoryss.cart_of_inventory(n);

					system("pause");
					goto lable4;
					break;
				}
				case 3:
				{
					inventoryss.cart_of_inventory(n);
					system("pause");
					goto lable4;
					break;
				}
				default:
					goto lable4;
					break;
				}

				//inventory.


				break;
			}
			case 6:
			{
				int x;
				cout << "Enter you balance to wallet" << endl;
				cin >> x;
				Wallet.setbalance(x);
				goto lable4;
				break;
			}
			case 7:
				status2 = 0;
				goto lable3;
				break;
			default:
				cout << "wrong option plz select again:";

				break;

			}


		}
		break;
	case 2:
	{
		Register();
		break;
	}
	case 3:
	{
		Startingmenu s;
		s.startingmenu1();
         
	break;
	}
	}
	char a;


	cout << "Enter Y to continue: ";
	cin >> a;
	if (a == 'y' || a == 'Y')
		Menu();
	else


		return;

}

Customer::Customer()
{
	phone_number[0] = '\0';
	address[0] = '\0';
	//status = 0;

}
bool Customer::login()
{
	Customer temp, customer;
	string x;
	bool check = true;
	cout << "Enter username: ";
	cin >> x;
	customer.setUsername(x);
	cout << "Enter password: ";
	cin >> x;
	customer.setPassword(x);
	ifstream fileinput("Customer.dat", ios::binary);
	if (!fileinput) {
		cout << "Please register first ";
		system("pause");
		exit(0);

	}
	else 
	{
		while (fileinput.read((char*)&temp, sizeof(temp))) 
		{
			if ( (strcmp(temp.getUsername(), customer.getUsername()) == 0)   ) 
			{
				if ((strcmp(customer.getPassword(), temp.getPassword()) == 0)) 
				{
					cout << "login Successful" << endl;
					check = false;
					*this = temp;
					return true;
					break;
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

		}
		if (check==1) {
			cout << "Login unsuccessful" << endl;
			return false;
		}
		fileinput.close();
	}

}
void Customer::Register()
{  
	string n;

	cout << "Enter your Gender" << endl;
	cin >> n;
	setGender(n);
	cout << "Enter your phone number" << endl;
	cin >> n;
	setPhonenumber(n);
	cout << "Enter address:" << endl;
	cin >> n;
	setaddress(n);
	Customer customer;
	bool passwordcheck = false;
	bool usernamecheck = true;
	bool CnicValidcheck = true;
	bool checkfileread = true;
	bool largeAlphabet = false;
	bool minoralphabet = false;
	bool number = false;
	bool specific = false;
	cout << "Please enter a valid CNIC ";
	cin >> n;
	if (n.length() != 13) {
		CnicValidcheck = false;
	}
	for (int i = 0; i < n.length(); i++) {
		if (n[i] >= '0' && n[i] <= '9')
		{

		}
		else {
			CnicValidcheck = false;
			break;
		}
	}
	if (CnicValidcheck==0) {
		while (CnicValidcheck==0) 
		{

			CnicValidcheck = true;
			cout << "Please enter 13";
			cout << "digits  valid CNIC";
			cout << "number without - XXXXXXXXXXXXX: ";
			cin >> n;
			if (n.length() != 13) {
				CnicValidcheck = false;
			}
			for (int i = 0; i < n.length(); i++) {
				if (n[i] >= '0' && n[i] <= '9') 
				{

				}
				else {
					CnicValidcheck = false;
					break;
				}
			}
		}
	}
	else {
		ifstream fileinput("Customer.dat", ios::binary);
		if (!fileinput) {
			checkfileread = true;
		}

		else
		{
			while (fileinput.read((char*)&customer, sizeof(customer))) {
				if (customer.getCNIC() == n) {
					checkfileread = false;
					break;
				}
			}
			fileinput.clear();
			fileinput.seekg(0);


			while (!checkfileread) {
				cout << "Please enter 13";
				cout << "digits  valid CNIC";
				cout << "number without - XXXXXXXXXXXXX: ";
				cin >> n;
				if (n.length() != 13) {
					CnicValidcheck = false;
				}
				for (int i = 0; i < n.length(); i++) {
					if (n[i] >= '0' && n[i] <= '9') {

					}
					else {
						CnicValidcheck = false;
						break;
					}
				}
				if (!CnicValidcheck) {
					while (!CnicValidcheck) {
						CnicValidcheck = true;
						cout << "Please enter a valid CNIC without - XXXXXXXXXXXXX:  ";
						cin >> n;
						if (n.length() != 13) {
							CnicValidcheck = false;
						}
						for (int i = 0; i < n.length(); i++) {
							if (n[i] >= '0' && n[i] <= '9') {

							}
							else {
								CnicValidcheck = false;
								break;
							}
						}
					}
				}
				while (fileinput.read((char*)&customer, sizeof(customer))) {
					if (customer.getCNIC() == n) {
						checkfileread = false;
						break;
					}
					else
					{
						checkfileread = true;
					}
				}
				fileinput.clear();
				fileinput.seekg(0);
			}
			fileinput.close();
		}

	}
	setCNIC(n);
	cout << "Please enter username: ";
	cin >> n;

	ifstream fileinput2("Customer.dat", ios::binary);
	if (!fileinput2) {
		usernamecheck = true;
	}
	else
	{
		while (fileinput2.read((char*)&customer, sizeof(customer))) {
			if (customer.getUsername() == n) {
				usernamecheck = false;
				break;
			}
		}
		fileinput2.clear();
		fileinput2.seekg(0);


		while (!usernamecheck) {
			cout << "Please enter again this username already taken: ";
			cin >> n;
			while (fileinput2.read((char*)&customer, sizeof(customer))) {
				if (customer.getUsername() == n) {
					usernamecheck = false;
					break;
				}
				else
				{
					usernamecheck = true;
				}
			}
			fileinput2.clear();
			fileinput2.seekg(0);
		}
		fileinput2.close();
	}

	setUsername(n);
	
	cout << "Please enter password ";
	cin >> n;
	for (int i = 0; i < n.length(); i++)
	{

		if (n[i] >= 65 && n[i] <= 90)//A to Z
			largeAlphabet = true;
		else if (n[i] >= 97 && n[i] <= 122)//a to z
			minoralphabet = true;
		else if (n[i] >= 48 && n[i] <= 57)//0 to 9
			number = true;
		else if ((n[i] >= 33 && n[i] <= 47) || (n[i] >= 58 && n[i] <= 64) || (n[i] >= 91 && n[i] <= 96) || (n[i] >= 123 && n[i] <= 126))//special charachter
		{
			passwordcheck = true;
			specific = true;
		}

	
	}
	if (n.length() < 9) {
		passwordcheck = false;
	}
	while (!(passwordcheck&& largeAlphabet && minoralphabet && number && specific))
	{
		cout << "Plz enter your 9 digit password which contain at least one upper one lower one special characters  ";
		cin >> n;
		for (int i = 0; i < n.length(); i++)
		{
			
			if (n[i] >= 65 && n[i] <= 90)//A to Z
				largeAlphabet = true;
			else if (n[i] >= 97 && n[i] <= 122)//a to z
				minoralphabet = true;
			else if (n[i] >= 48 && n[i] <= 57)//0 to 9
				number = true;
			else if ((n[i] >= 33 && n[i] <= 47) || (n[i] >= 58 && n[i] <= 64) || (n[i] >= 91 && n[i] <= 96) || (n[i] >= 123 && n[i] <= 126))//special charachter
			{
				passwordcheck = true;
				specific = true;
			}


		}
		if (n.length() < 9) {
			passwordcheck = 0;
		}
	}
	setPassword(n);
	cout << "Please enter password again: ";
	cin >> n;

	if (strcmp(getPassword(), n.c_str()) != 0)
	{
		passwordcheck = 0;
	}
	while (passwordcheck==0) {
		cout << "Your passwords do not match: ";
		cin >> n;
		if (strcmp(getPassword(), n.c_str()) == 0)
			passwordcheck = true;

	}
	setPassword(n);
	cin.ignore();
	cout << "Please enter your name: ";
	getline(cin, n);
	setName(n);
	int u;
	cout << "Add balance to waalet" << endl;
	cin >> u;
		setwalletbalance(u);

	ofstream myfile("Customer.dat", ios::binary | ios::app);
	myfile.write((char*)this, sizeof(*this));
	myfile.close();
	cout << "Your account has been created!" << endl;
}

void Customer::feedbackgive()
{
	int rating;
	string input;
	Customer feedback;
	string s;
	if (status2 == 1)
	{


		cout << "Please enter feedback: ";
		cin.ignore();
		getline(cin, input);
		a.setFeedback(input);
		cout << "Enter you name" << endl;
		getline(cin, s);
		a.setfeedbackname(s);
		cout << "Please enter rating: ";
		cin >> rating;
		input = "";
		int i = 0;
		while (i < rating)
		{
			input = input + "*";
			i++;
		}
		a.setRating(input);

		ofstream myfile("feedback.dat", ios::binary | ios::app);
		myfile.write((char*)&a, sizeof(a));
		myfile.close();
	}
	else {
		cout << "Plz buy the product first" << endl;
	}



}

void Customer::nameuserchnage()
{
	Customer temp, customer;
	bool usernamecheck = true;
	fstream fileopen("Customer.dat", ios::binary | ios::in | ios::out);
	string input;

	cout << "Please enter updated username: ";
	cin >> input;
	ifstream fileinput("Customer.dat", ios::binary);

	if (!fileinput) {
		usernamecheck = true;
	}
	else
	{
		while (fileinput.read((char*)&customer, sizeof(customer))) 
		{
			if (customer.getUsername() == input) {
				usernamecheck = false;
				break;
			}
		}
		fileinput.clear();
		fileinput.seekg(0);


		while (!usernamecheck) {
			cout << "Please enter again this username already taken: ";
			cin >> input;
			while (fileinput.read((char*)&customer, sizeof(customer))) {
				if (customer.getUsername() == input) {
					usernamecheck = false;
					break;
				}
				else
				{
					usernamecheck = true;
				}
			}
			fileinput.clear();
			fileinput.seekg(0);
		}
		fileinput.close();
	}

	fileopen.clear();
	fileopen.seekg(0);
	while (fileopen.read((char*)&temp, sizeof(temp))) 
	{
		if (strcmp(getUsername(), temp.getUsername()) == 0) 
		{
			setUsername(input);
			int l = sizeof(temp);
			int a = fileopen.tellg();
			fileopen.seekp(a - l);
			fileopen.write((char*)this, sizeof(temp));
			break;
		}
	}

}
void Customer::passwordupdate()
{  // password change
	string n;
	bool passwordcheck = false;
	bool largeAlphabet = false;
	bool minoralphabet = false;
	bool number = false;
	bool specific = false;
	cout << "Please re enter your password : ";
	cin >> n;
	if (strcmp(n.c_str(), getPassword()) == 0) {
		Customer temp;
		fstream fileopen("Customer.dat", ios::in | ios::out | ios::binary);
		cout << "Please enter updated password which contain 9 digit  with  at least one upper one lower one special characters ";
		cin >> n;
		for (int i = 0; i < n.length(); i++) {

			if (n[i] >= 65 && n[i] <= 90)//A to Z
				largeAlphabet = true;
			else if (n[i] >= 97 && n[i] <= 122)//a to z
				minoralphabet = true;
			else if (n[i] >= 48 && n[i] <= 57)//0 to 9
				number = true;
			else if ((n[i] >= 33 && n[i] <= 47) || (n[i] >= 58 && n[i] <= 64) || (n[i] >= 91 && n[i] <= 96) || (n[i] >= 123 && n[i] <= 126))//special charachter
			{
				passwordcheck = true;
				specific = true;
			}
		}
		if (n.length() < 9) {
			passwordcheck = false;
		}
		while (!(passwordcheck && largeAlphabet && minoralphabet && number && specific)) {
			cout << "Plz enter your 9 digit password which contain at least one upper one lower one special characters  ";
			cin >> n;
			for (int i = 0; i < n.length(); i++) 
			{
				if (n[i] >= 65 && n[i] <= 90)//A to Z
					largeAlphabet = true;
				else if (n[i] >= 97 && n[i] <= 122)//a to z
					minoralphabet = true;
				else if (n[i] >= 48 && n[i] <= 57)//0 to 9
					number = true;
				else if ((n[i] >= 33 && n[i] <= 47) || (n[i] >= 58 && n[i] <= 64) || (n[i] >= 91 && n[i] <= 96) || (n[i] >= 123 && n[i] <= 126))//special charachter
				{
					passwordcheck = true;
					specific = true;
				}
			}
			if (n.length() < 9) {
				passwordcheck = false;
			}
		}
		setPassword(n);
		cout << "Plz enter your 9 digit password which contain at least one upper one lower one special characters  ";
		cin >> n;

		if (strcmp(getPassword(), n.c_str()) != 0)
		{
			passwordcheck = false;
		}
		while (!passwordcheck) 
		{
			cout << "Your passwords do not match Plz enter your 9 digit password which contain at least one upper one lower one special characters  : ";
			cin >> n;
			if (strcmp(getPassword(), n.c_str()) == 0)
				passwordcheck = true;

		}

		while (fileopen.read((char*)&temp, sizeof(temp))) 
		{
			if (strcmp(getUsername(), temp.getUsername()) == 0) {
				setPassword(n);
				int a = fileopen.tellg();
				int l = sizeof(temp);
				fileopen.seekp(a - l);
				fileopen.write((char*)this, sizeof(temp));
				break;
			}
		}
	}
}