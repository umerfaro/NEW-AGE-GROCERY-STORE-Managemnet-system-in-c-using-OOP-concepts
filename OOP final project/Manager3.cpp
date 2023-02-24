#include"Manager3.h"

Manager3::Manager3()
{
	default_id = 3;
}




void Manager3::passwordchnage()
{  //update password
	string n;
	bool passwordcheck = false;
	bool largeAlphabet = false;
	bool minoralphabet = false;
	bool number = false;
	bool specific = false;
	cout << "Please re enter your password: ";
	cin >> n;
	if (strcmp(n.c_str(), getPassword()) == 0) {
		Manager d;
		fstream obj("KarachiManager.dat", ios::in | ios::out | ios::binary);
		cout << "Please enter updated password ";
		cin >> n;
		for (int i = 0; i < n.length(); i++)
		{

			if (n[i] >= 65 && n[i] <= 90)
				largeAlphabet = true;
			else if (n[i] >= 97 && n[i] <= 122)
				minoralphabet = true;
			else if (n[i] >= 48 && n[i] <= 57)
				number = true;
			else if ((n[i] >= 33 && n[i] <= 47) || (n[i] >= 58 && n[i] <= 64) || (n[i] >= 91 && n[i] <= 96) || (n[i] >= 123 && n[i] <= 126))
			{
				passwordcheck = true;
				specific = true;
			}

		}
		if (n.length() < 9) {
			passwordcheck = false;
		}
		while (!(passwordcheck && largeAlphabet && minoralphabet && number && specific)) {
			cout << "Please enter password atleast 9 characters with one special character: ";
			cin >> n;
			for (int i = 0; i < n.length(); i++)
			{

				if (n[i] >= 65 && n[i] <= 90)
					largeAlphabet = true;
				else if (n[i] >= 97 && n[i] <= 122)
					minoralphabet = true;
				else if (n[i] >= 48 && n[i] <= 57)
					number = true;
				else if ((n[i] >= 33 && n[i] <= 47) || (n[i] >= 58 && n[i] <= 64) || (n[i] >= 91 && n[i] <= 96) || (n[i] >= 123 && n[i] <= 126))
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
		cout << "Please enter password again: ";
		cin >> n;

		if (strcmp(getPassword(), n.c_str()) != 0)
		{
			passwordcheck = false;
		}
		while (passwordcheck == 0)
		{
			cout << "Your passwords do not match: ";
			cin >> n;
			if (strcmp(getPassword(), n.c_str()) == 0)
				passwordcheck = true;

		}
		while (obj.read((char*)&d, sizeof(d))) {
			if (strcmp(getUsername(), d.getUsername()) == 0) {
				setPassword(n);
				int a = obj.tellg();
				int l = sizeof(d);
				obj.seekp(a - l);
				obj.write((char*)this, sizeof(d));
				break;
			}
		}
	}
}

bool Manager3::login2()
{
	Manager3 temp, manager;       //login ovverride use because polymorphism is being used
	string input;
	cout << "Enter username: ";
	cin >> input;
	manager.setUsername(input);
	cout << "Enter password: ";
	cin >> input;
	manager.setPassword(input);

	bool check = true;
	ifstream fileinput("KarachiManager.dat", ios::binary);
	if (!fileinput) {
		cout << "Please register first ";
	}

	else {
		while (fileinput.read((char*)&temp, sizeof(temp)))
		{
			if ((strcmp(temp.getUsername(), manager.getUsername()) == 0))
			{
				if ((strcmp(manager.getPassword(), temp.getPassword()) == 0))
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

		if (check == 1) {
			cout << "Login unsuccessful" << endl;
			return false;
		}
		fileinput.close();
	}

}

void Manager3::managernamechnage() {
	//update username
	Manager temp, manager;
	bool usernamecheck = true;
	fstream obj("KarachiManager.dat", ios::binary | ios::in | ios::out);
	string n;

	cout << "Please enter updated username: ";
	cin >> n;
	ifstream fin("KarachiManager.dat", ios::binary);
	if (!fin) {
		usernamecheck = true;
	}
	else
	{
		while (fin.read((char*)&manager, sizeof(manager))) {
			if (manager.getUsername() == n)
			{
				usernamecheck = false;
				break;
			}
		}
		fin.clear();
		fin.seekg(0);


		while (!usernamecheck) {
			cout << "This username already taken please enter again : ";
			cin >> n;
			while (fin.read((char*)&manager, sizeof(manager))) {
				if (manager.getUsername() == n) {
					usernamecheck = false;
					break;
				}
				else
				{
					usernamecheck = true;
				}
			}
			fin.clear();
			fin.seekg(0);
		}
		fin.close();
	}
	obj.clear();
	obj.seekg(0);
	while (obj.read((char*)&temp, sizeof(temp))) {
		if (strcmp(getUsername(), temp.getUsername()) == 0) {
			setUsername(n);
			int a = obj.tellg();
			int l = sizeof(temp);
			obj.seekp((long long int)(a - l));
			obj.write((char*)this, sizeof(temp));
			break;


		}
	}
}

void Manager3::Menu()
{  //menu override used to because polymorphism is used
	int n;

	system("CLS");
	cout << "Karacchi manager" << endl << endl;
	if (login2() == 1)
	{
	lable5:
		cout << "Karacchi manager" << endl << endl;
		system("CLS");
		cout << "Karacchi manager" << endl << endl;
		cout << "#***************************************************************************************************#" << endl;
		cout << "#                                      Press 1 to update Username                                   #" << endl;
		cout << "#                                      Press 2 to Update Password                                   #" << endl;
		cout << "#                                      Press 3 to show details                                      #" << endl;
		cout << "#                                      Press 4 to Customer details                                  #" << endl;
		cout << "#                                      Press 5 to ADD inventory                                     #" << endl;
		cout << "#                                      Press 6 to Show ALL available inventory                      #" << endl;
		cout << "#                                      Press 7 To refill product quatity                            #" << endl;
		cout << "#                                      Press 8 To Update the Product                                #" << endl;
		cout << "#                                      Press 9 To Delete the Product                                #" << endl;
		cout << "#                                      Press 10 show different store inventory                      #" << endl;
		cout << "#                                      Press 11 to logout                                           #" << endl;
		cout << "#***************************************************************************************************#" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			managernamechnage();
			system("pause");
			goto lable5;
			break;
		case 2:
			passwordchnage();
			system("pause");
			goto lable5;
			break;
		case 3:
			DisplayManager();
			system("pause");
			goto lable5;
			break;
		case 4:

			Showallcustomer();
			system("pause");
			goto lable5;
			break;
		case 5:
		{
			inventory3.Write_THE_PRoduct(3);
			system("pause");
			goto lable5;
			break;
		}
		case 6:
		{
			inventory3.Menu2(3);
			system("pause");
			goto lable5;
			break;
		}
		case 7:
		{
			inventory3.refillquantityofproduct(3);
			system("pause");
			goto lable5;
			break;
		}
		case 8:
		{
			inventory3.modify_given_product_in_inventory(3);
			system("pause");
			goto lable5;
			break;
		}
		case 9:
		{
			inventory3.Delete_product(3);
			system("pause");
			goto lable5;
			break;
		}
		case 10:
		{
			int x;
			cout << "\t\t\t\twhich store inventry you want to show" << endl;
			cout << "\t\t\t\t\tPress 1 for Lahore store" << endl;
			cout << "\t\t\t\t\tPress 2 for Islamabad store" << endl;
			cin >> x;
			switch (x)
			{
			case 1:
			{
				inventory3.Menu2(2);
				string s;
				cout << "Enter product name to search" << endl;
				cin >> s;
				inventory3.search_seperate_product(s, 2);
				system("pause");
				goto lable5;
				break;

			}
			case 2:
			{
				inventory3.Menu2(1);
				string s;
				cout << "Enter product name to search" << endl;
				cin >> s;
				inventory3.search_seperate_product(s, 1);
				system("pause");
				goto lable5;
				break;

			}
			default:
				break;
			}


		}
		case 11:
		{
			Manager mmm;
			mmm.Menu();
			break;
		}
		default:
			cout << "Plz select correct option" << endl;
			system("pause");
			goto lable5;
			break;


		}




	}
	
}


void Manager3::Register()
{
	string n;

	Manager  manager;
	bool passwordcheck = false;
	bool usernamecheck = true;
	bool CnicValidcheck = true;
	bool checkfileread = true;
	bool check4 = true;
	bool largeAlphabet = false;
	bool minoralphabet = false;
	bool number = false;
	bool specific = false;
	int q;
	cout << "Press 1 to register to register manager";
	cin >> q;
	switch (q)
	{
	case 1:
	{

		cout << "Please enter Manager name: ";
		cin >> n;
		getline(cin, n);
		setName(n);

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
		if (!CnicValidcheck) {
			while (!CnicValidcheck) {
				CnicValidcheck = true;
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
			}
		}
		else {
			ifstream fileinput("KarachiManager.dat", ios::binary);
			if (!fileinput) {
				checkfileread = true;
			}
			else
			{
				while (fileinput.read((char*)&manager, sizeof(manager))) {
					if (manager.getCNIC() == n) {
						checkfileread = false;
						break;
					}
				}
				fileinput.clear();
				fileinput.seekg(0);


				while (!checkfileread) {
					cout << "This is CNIC is already registered please enter different CNIC: ";
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
					if (!CnicValidcheck) {
						while (!CnicValidcheck) {
							CnicValidcheck = true;
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
						}
					}
					while (fileinput.read((char*)&manager, sizeof(manager))) {
						if (manager.getCNIC() == n) {
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
		break;

	}

	}

	cout << "Please enter username: ";
	cin >> n;

	ifstream fileinput2("KarachiManager.dat", ios::binary);
	if (!fileinput2) {
		usernamecheck = true;
	}
	else
	{
		while (fileinput2.read((char*)&manager, sizeof(manager))) {
			if (manager.getUsername() == n) {
				usernamecheck = false;
				break;
			}
		}
		fileinput2.clear();
		fileinput2.seekg(0);


		while (!usernamecheck) {
			cout << "Please enter again this username already taken: ";
			cin >> n;
			while (fileinput2.read((char*)&manager, sizeof(manager)))
			{
				if (manager.getUsername() == n) {
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
	while (!(passwordcheck && largeAlphabet && minoralphabet && number && specific))
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
			passwordcheck = false;
		}
	}
	setPassword(n);
	cout << "Please enter password again: ";
	cin >> n;

	if (strcmp(getPassword(), n.c_str()) != 0)
	{
		passwordcheck = false;
	}
	while (!passwordcheck) {
		cout << "Your passwords do not match: ";
		cin >> n;
		if (strcmp(getPassword(), n.c_str()) == 0)
			passwordcheck = true;

	}
	setPassword(n);


	ofstream myfile("KarachiManager.dat", ios::binary | ios::app);
	myfile.write((char*)this, sizeof(*this));
	myfile.close();
	cout << "Manager Account has been created!" << endl;
}