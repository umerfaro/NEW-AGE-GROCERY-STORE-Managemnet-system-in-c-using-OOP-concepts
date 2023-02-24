#pragma once
#ifndef CHECKOUTSIMULATION
#define CHECKOUTSIMULATION


class  Simulation
{

public:
	
	Simulation()
	{
		 customername[0]='\0';
		 no_of_items=0;
		 timeTaken = 0.0;
		 total = 0;
	}
	void setcustomername(string s)
	{
		strcpy_s(customername, s.length() + 1, s.c_str());
	}
	char* getcustomername()
	{
		return customername;
	}
	void setnoofitem(int n)
	{
		no_of_items = n;
	}
	int getnoofitem()
	{
		return no_of_items;
	}

	void showcustomeritem()
	{
		cout << getcustomername() << "\t\t\t" << getnoofitem() << endl;
	}

	void settotal(int n)
	{
		total = n;
	}
	int gettotal()
	{
		return total;
	}
	void settimetaken(int s)
	{
		timeTaken = s;

	}
	int gettimetaken()
	{
		return timeTaken;
	}
	void retrievecustomerdata()
	{
		Simulation temp;
		ifstream myFile("simulationcustomer.dat", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			temp.showcustomeritem();
		}
		myFile.close();
   }
	bool checkEXpressLane_9_Items_or_less()
	{
		Simulation temp;
		string s;
		cout << "Enter customer name" << endl;
		cin >> s;
		bool check = false;
		fstream fileopen("simulationcustomer.dat", ios::in);
		while (fileopen.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getcustomername() == s)
			{
				if (temp.getnoofitem() > 1 || temp.getnoofitem() <= 9)
				{
					check = true;
					return true;
				}
				else if(temp.getnoofitem() > 9 || temp.getnoofitem() <= 19)
				{
					return false;
				}
				
			}
			else
			{
				check = false;
			}
			
		}
		fileopen.close();
		if (check == false )
		{
			cout << "customer not found try again" << endl;
			checkEXpressLane_9_Items_or_less();
			//getch();
		}

	}
	void simulationMenu()
	{
		int x;
		cout << "\t\t\t\tSelect which option customer pay" << endl;
		cout << "\t\t\t\t Press 1 Customer had paid the bill through cash " << endl;
		cout << "\t\t\t\t Press 2 Customer had paid the bill through cheque " << endl;
		cout << "\t\t\t\t Press 3 Customer had paid the bill through debit card " << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			settimetaken(60);
			if (checkEXpressLane_9_Items_or_less() == 1)
			{
				
				cout << "Customer is in Express lane which contain item less than or equal to 9" << endl;

				Simulation temp;
				string s;
				cout << "Enter customer name" << endl;
				cin >> s;
				bool check = false;
				fstream fileopen("simulationcustomer.dat", ios::in);
				while (fileopen.read((char*)&temp, sizeof(temp)))
				{
					if (temp.getcustomername() == s)
					{
					  
						settotal(gettimetaken() + (temp.getnoofitem() * 12));
						 
					}
					
				}
				fileopen.close();
			
			}

			else 
			{
				cout << "Customer is in Express lane which contain item Greater than 9 and less than or equal to 19" << endl;

				Simulation temp;
				string s;
				cout << "Enter customer name" << endl;
				cin >> s;
				bool check = false;
				fstream fileopen("simulationcustomer.dat", ios::in);
				while (fileopen.read((char*)&temp, sizeof(temp)))
				{
					if (temp.getcustomername() == s)
					{

						settotal(gettimetaken() + (temp.getnoofitem() * 12));

					}

				}
				fileopen.close();


			}



			break;
		}
		case 2:
		{
		

			settimetaken(150);
			if (checkEXpressLane_9_Items_or_less() == 1)
			{


				Simulation temp;
				string s;
				cout << "Enter customer name" << endl;
				cin >> s;
				bool check = false;
				fstream fileopen("simulationcustomer.dat", ios::in);
				while (fileopen.read((char*)&temp, sizeof(temp)))
				{
					if (temp.getcustomername() == s)
					{

						settotal(gettimetaken() + (temp.getnoofitem() * 12));

					}

				}
				fileopen.close();

			}

			else
			{
				cout << "Customer is in Express lane which contain item Greater than 9 and less than or equal to 19" << endl;

				Simulation temp;
				string s;
				cout << "Enter customer name" << endl;
				cin >> s;
				bool check = false;
				fstream fileopen("simulationcustomer.dat", ios::in);
				while (fileopen.read((char*)&temp, sizeof(temp)))
				{
					if (temp.getcustomername() == s)
					{

						settotal(gettimetaken() + (temp.getnoofitem() * 12));

					}

				}
				fileopen.close();


			}



			break;
		}
		case 3:
		{
			//timeTaken = 2;

			settimetaken(120);
			if (checkEXpressLane_9_Items_or_less() == 1)
			{


				Simulation temp;
				string s;
				cout << "Enter customer name" << endl;
				cin >> s;
				bool check = false;
				fstream fileopen("simulationcustomer.dat", ios::in);
				while (fileopen.read((char*)&temp, sizeof(temp)))
				{
					if (temp.getcustomername() == s)
					{

						settotal(gettimetaken() + (temp.getnoofitem() * 12));

					}

				}
				fileopen.close();

			}

			else
			{
				cout << "Customer is in Express lane which contain item Greater than 9 and less than or equal to 19" << endl;

				Simulation temp;
				string s;
				cout << "Enter customer name" << endl;
				cin >> s;
				bool check = false;
				fstream fileopen("simulationcustomer.dat", ios::in);
				while (fileopen.read((char*)&temp, sizeof(temp)))
				{
					if (temp.getcustomername() == s)
					{

						settotal(gettimetaken() + (temp.getnoofitem() * 12));

					}

				}
				fileopen.close();

			}


			break;
		}
		default:
			break;
		}

		

	}
	void totaltimetakeninmints()
	{

		int hh = (gettotal() / 3600) % 24;
		int ss = gettotal() % 60;
		int mm = (gettotal() / 60) % 60;

		cout << "It will take about "<<hh<<"h"<<":"<< mm <<"m"<<" : "<<ss<<"s for the customer to checkout" << endl;
	}


private:
	char customername[50];
	int no_of_items;
	int timeTaken;
	int total;
	

};





#endif // !CHECKOUTSIMULATION
