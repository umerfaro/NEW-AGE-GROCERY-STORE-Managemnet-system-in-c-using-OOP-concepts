
#include"Manager.h"
#include"Customer.h"
#include"Manager1.h"
#include"Manager2.h"
#include"Manager3.h"
#include"MenuHeader.h"



Manager::Manager(Manager& a)
{        //Copy constructor;
	setUsername(a.getUsername());
	setPassword(a.getPassword());
	setCNIC(a.getCNIC());
	


}
// setter getter


Manager::Manager() {
	
	default_id=0;

}

void Manager::DisplayManager()
{   //display function

	cout << "Username  " << getUsername() << endl;
	cout << " CNIC " << getCNIC() << endl;
	cout << "Password  " << getPassword() << endl;


	cout << endl << endl;
}
void Manager::managernamechnage()
{  

}


void Manager::passwordchnage()
{  

}

void Manager::Showallcustomer() {

	Customer b;	
	ifstream fin("Customer.dat", ios::binary);
	
	while (fin.read((char*)&b, sizeof(b))) {
		
		b.showmydetails();
		
	}
	fin.close();



}

void Manager::Menu()
{  //menu override used to because polymorphism is used
	int n;
	system("CLS");
	cout << "Press 1 to login as Islamabad store manager:" << endl;
	cout << "Press 2 to login as Lahore store manager:" << endl;
	cout << "Press 3 to login as Karachi store manager:" << endl;
	cout << "Press 4 to go back " << endl;
	//cout << "press 4 for retreat" << endl;
	cin >> n;
	switch (n) 
	{
			case 1:
			{
				Manager* m;
				m = new Manager1;
				m->Menu();
				
		
				break;
			}
			case 2:
			{
				Manager* m;
				m = new Manager2;
				m->Menu();
		
				break;
			}
			case 3:
			{
				Manager* m;
				m = new Manager3;
				m->Menu();

				break;
			}
			case 4:
			{
				Startingmenu s;
				s.startingmenu1();
				break;
			}
			
			default:
			{
				Menu();
				break;
			}

  }
	char a11;
	cout << "Press Y if you want to continue: ";
	cin >> a11;
	if (a11 == 'Y' || a11 == 'y') 
	{
		system("pause");
		Menu();
	}
	else {
		return;
	}
}




void Manager::Register() 
{
	
}



bool Manager::login()
{
	Manager temp, manager;       //login ovverride use because polymorphism is being used
	string input;
	cout << "Enter username: ";
	cin >> input;
	manager.setUsername(input);
	cout << "Enter password: ";
	cin >> input;
	manager.setPassword(input);

	bool check = true;
	ifstream fileinput("Manager.dat", ios::binary);
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