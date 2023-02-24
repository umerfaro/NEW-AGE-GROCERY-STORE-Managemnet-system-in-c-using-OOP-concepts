#include"Inventory.h"
#include"Customer.h"
#include"checkoutsimulation.h"
#include<iostream>

using namespace std;

// here i used templates in inventory buz through this i don't have to make more class for differents inventory of different stores

Inventory::Inventory()
{
	productnumber = 0;
	nameofproduct[0] = '\0';
	price = 0;
	quantity = 0;
	discount = 0;
}

void Inventory::setproductnumber(int n)
{
	productnumber = n;
}
void Inventory::setNameOfproduct(string s)
{
	strcat_s(nameofproduct, s.length() + 1, s.c_str());
}
void Inventory::setPriceOFproduct(float n)
{
	price = n;
}
void Inventory::setquantityofproduct(float n)
{
	quantity = n;
}
void Inventory::setDiscount(float n)
{
	discount = 0;
}


int Inventory::Getproductnumber()
{
	return productnumber;
}
char* Inventory::GetNameOfproduct()
{
	return nameofproduct;
}
float Inventory::GetPriceOFproduct()
{
	return price;
}
float Inventory::Getquantityofproduct()
{
	return quantity;
}
float Inventory::GetDiscount()
{
	return discount;
}

void Inventory::Create_New_product()
{
	cout << "Enter product no." << endl;
	cin >> productnumber;
	cin.ignore();
	cout << "Enter name of product" << endl;
	cin.getline(nameofproduct, 100);
	cout << "Enter Price ofproduct" << endl;
	cin >> price;
	cout << "Enter Quantity of product" << endl;
	cin >> quantity;
}

void Inventory::Remove_the_QUantity_after_purchase(int qty)
{
	if (quantity >= qty)
	{
		quantity -= qty;
		cout << "\n\nStock updated.\n";
	}
	else
		cout << "\n\nInsufficient stock";
	//getch();


}
void Inventory::Refill_the_QUantity(int qty)
{
	quantity += qty;
	cout << "\n\nStock updated.";
	//getch();
}
void Inventory::Show_Products()
{
	cout << "The product no. of the product :  " << Getproductnumber() << endl;
	cout << "The name of the product :  " << GetNameOfproduct() << endl;
	cout << "Total quantity Avialable of product " << Getquantityofproduct() << endl;
	cout << "Pric of product is " << GetPriceOFproduct() << endl;
}



template<typename p>void writep(p x)
{
	Inventory inventory;
	fstream fileopen(x, ios::out | ios::app);
	inventory.Create_New_product();
	fileopen.write((char*)&inventory, sizeof(inventory));
	fileopen.close();
	cout << "New product has been created" << endl;

}

void Inventory::Write_THE_PRoduct(int default_id)
{

	switch (default_id)
	{
	case 1:
	{

		writep<string>("InventoryIslamabad.dat");
		break;
	}
	case 2:
	{
		writep<string>("InventoryLahore.dat");
		break;
	}
	case 3:
	{
		writep<string>("InventoryKarachi.dat");
		break;
	}
	default:
		break;
	}
	
}

template<typename p>void displayall(p x)
{
	cout << "\t\t\tALL Available Inventory are" << endl << endl;
	Inventory inventory;
	fstream fileopen(x, ios::in);
	while (fileopen.read((char*)&inventory, sizeof(inventory)))
	{
		inventory.Show_Products();
		cout << "\n\n====================================\n";
		//getch();

	}
	fileopen.close();
}

void Inventory::DisplayALLRecord(int default_id)
{
	
	switch (default_id)
	{
	case 1:
	{

		displayall<string>("InventoryIslamabad.dat");
		break;
	}
	case 2:
	{
		displayall<string>("InventoryLahore.dat");
		break;
	}
	case 3:
	{
		displayall<string>("InventoryKarachi.dat");
		break;
	}
	default:
		break;
	}


}


template<typename p>void search(p x,p n)
{
	Inventory inventory;
	bool check = true;
	fstream fileopen(x, ios::in);
	while (fileopen.read((char*)&inventory, sizeof(inventory)))
	{
		if (inventory.GetNameOfproduct() == n)
		{
			inventory.Show_Products();
			check = false;
			//break;
		}
	}
	fileopen.close();
	if (check == 1)
	{
		cout << "Given product not found" << endl;
		//getch();
	}

}


void Inventory::search_seperate_product(string n, int default_id)
{
	
	switch (default_id)
	{
	case 1:
	{

		search<string>("InventoryIslamabad.dat",n);
		break;
	}
	case 2:
	{
		search<string>("InventoryLahore.dat",n);
		break;
	}
	case 3:
	{
		search<string>("InventoryKarachi.dat",n);
		break;
	}
	default:
		break;
	}

}


template<typename p>void modify(p x)
{

	
	cout << endl << endl;
	int n;
	bool flag = false;
	cout << "\n\n\n\To Modify product" << endl;
	cout << "\n\n\nPlease Enter the Product no. to modified" << endl;
	cin >> n;
	Inventory inventory;
	fstream fileopen(x, ios::in | ios::out);
	while (fileopen.read((char*)&inventory, sizeof(inventory)) && flag == 0)
	{
		if (inventory.Getproductnumber() == n)
		{
			inventory.Show_Products();
			cout << "Plz Enter new details of product" << endl;
			cin.ignore();
			inventory.Create_New_product();
			int pos = -1 * sizeof(inventory);
			fileopen.seekp(pos, ios::cur);
			fileopen.write((char*)&inventory, sizeof(inventory));
			cout << "\n\n\t Record Updated";
			flag = 1;

		}

	}
	fileopen.close();
	if (flag == 0)
	{
		cout << "Product Record not Found ";
		//getch();
	}
	
}



void Inventory::modify_given_product_in_inventory(int default_id)
{
	switch (default_id)
	{
	case 1:
		{
		Menu2(default_id);
		modify<string>("InventoryIslamabad.dat");
		Menu2(default_id);
			break;
		}
	case 2:
		{
		Menu2(default_id);
		modify<string>("InventoryLahore.dat");
		Menu2(default_id);
			break;
		}
	case 3:
		{
		Menu2(default_id);
		modify<string>("InventoryKarachi.dat");
		Menu2(default_id);
			break;
		}
	default:
		break;
	}
	


}

template<typename p>void deletep(p x)
{

	
	cout << endl << endl;
	int n;
	cout << "\t\t\t\tDelete Record of product" << endl;
	cout << "\t\t\t\tEnter the Product no. to Delete the record" << endl;
	cin >> n;
	Inventory inventory;
	fstream fileopen(x, ios::in | ios::out);

	fstream fileopen2("Temp.dat", ios::out);
	fileopen.seekg(0, ios::beg);
	while (fileopen.read((char*)&inventory, sizeof(inventory)))
	{
		if (inventory.Getproductnumber() != n)
		{
			fileopen2.write((char*)&inventory, sizeof(inventory));
		}

	}
	fileopen2.close();
	fileopen.close();
	
	cout << "Given product recoard has been Deleted" << endl;
	//getch();

}



void Inventory::Delete_product(int default_id)
{
	
	switch (default_id)
	{
	case 1:
	{
		Menu2(default_id);
		deletep<string>("InventoryIslamabad.dat");
		remove("InventoryIslamabad.dat");
		rename("Temp.dat", "InventoryIslamabad.dat");
		Menu2(default_id);
		break;
	}
	case 2:
	{
		Menu2(default_id);
		deletep<string>("InventoryLahore.dat");
		remove("InventoryLahore.dat");
		rename("Temp.dat", "InventoryLahore.dat");
		Menu2(default_id);
		break;
	}
	case 3:
	{
		Menu2(default_id);
		deletep<string>("InventoryKarachi.dat");
		remove("InventoryKarachi.dat");
		rename("Temp.dat", "InventoryKarachi.dat");
		Menu2(default_id);
		break;
	}
	default:
		break;
	}

}


template<typename p>void Meneeeeeu(p x)
{
	Inventory inventory;
	fstream fileopen(x, ios::in);
	if (!fileopen)
	{
		cout << "Error!!!!! File if not Found" << endl;
		//getch();
		exit(0);
	}


	cout << "\n\n\t\tProduct MENU\n\n";
	cout << "====================================================\n";
	cout << "P.NO.\t\tNAME\t\tPRICE\t\tQuantity\n";
	cout << "====================================================\n";

	while (fileopen.read((char*)&inventory, sizeof(inventory)))
	{
		cout << inventory.Getproductnumber() << "\t\t" << inventory.GetNameOfproduct() << "\t\t" << inventory.GetPriceOFproduct()<<" Rs" << "\t\t" << inventory.Getquantityofproduct() << endl;
	}
	fileopen.close();
}



void Inventory::Menu2(int default_id)
{
	switch (default_id)
	{
	case 1:
	{

		Meneeeeeu<string>("InventoryIslamabad.dat");
		break;
	}
	case 2:
	{
		Meneeeeeu<string>("InventoryLahore.dat");
		break;
	}
	case 3:
	{
		Meneeeeeu<string>("InventoryKarachi.dat");
		break;
	}
	default:
		break;
	}

}




template<typename p>void refilllll(p x)
{
	int quntity2;
	int n;
	bool flag = false;
	
	cout << "Enter product id" << endl;
	cin >> n;
	cout << "Enter quantity to add" << endl;
	cin >> quntity2;
	Inventory inventory;
	long pos = 0;
	fstream fileopen(x, ios::in | ios::out);
	while (fileopen)
	{
		pos = fileopen.tellg();
		fileopen.read((char*)&inventory, sizeof(inventory));
		{
			if (inventory.Getproductnumber() == n)
			{
				inventory.Refill_the_QUantity(quntity2);
				fileopen.seekp(pos);
				fileopen.write((char*)&inventory, sizeof(inventory));
				flag = 1;
				break;
			}
		}
	}
	if (flag != 1)
	{
		cout << "\t\t\t<<Record not found!!" << endl;

	}
	fileopen.close();

}

void Inventory::refillquantityofproduct(int default_id)
{
	switch (default_id)
	{
	case 1:
	{
		Menu2(default_id);
		refilllll<string>("InventoryIslamabad.dat");
		Menu2(default_id);
		break;
	}
	case 2:
	{
		Menu2(default_id);
		refilllll<string>("InventoryLahore.dat");
		Menu2(default_id);
		break;
	}
	case 3:
	{
		Menu2(default_id);
		refilllll<string>("InventoryKarachi.dat");
		Menu2(default_id);
		break;
	}
	default:
		break;
	}

}


void displayproduct(int *id, int i, Inventory  inventory2, int amount, int *quntity2)
{

cout << "\t\t\t\t" << *(id +i) << "\t" << inventory2.GetNameOfproduct() << "\t" << *(quntity2 +i) << "\t\t" << inventory2.GetPriceOFproduct()<<" Rs" << '\t' << amount << endl;

}


template<typename p>void cart(p x,p y,int default_id)
{
	cout << "\t\t\tAdd product to Cart" << endl;

	int quntity2[100];
	int id[100];
	int count = 0;
	char choose = ' ';
	bool flag = false;
	int amount = 0;
	int totalAmountafter_discount=0;
	Inventory inventory;
	Simulation s;

	int uuuu;
	lable92:
	cout << "Press 1 to search product if available " << endl;
	cout << "Press 2 to buy product" << endl;
	cin >> uuuu;

	switch (uuuu)
	{
	case 1:
	{

		string n;
		cout << "Enter product name to find : " << endl;
		cin >> n;
		inventory.search_seperate_product( n,  default_id);
		system("pause");
		goto lable92;
		break;
	}
	case 2:
	{
		lable89:
		do {
			cout << count << endl<<endl;
			cout << "Enter product id" << endl;
			cin >> id[count];
			cout << "Enter quantity to add" << endl;
			cin >> quntity2[count];
			count++;
			cout << "Do you want to buy another product" << endl;
			cin >> choose;


		} while (choose == 'y' || choose == 'Y');



		//Inventory inventory;
		int index = 0;

		bool check2 = true;
		
		for (int i = 0; i < count; i++)
		{
			fstream fileopen3(x, ios::in);
			fileopen3.read((char*)&inventory, sizeof(inventory));
			while (!fileopen3.eof())
			{
				
				if (inventory.Getproductnumber() == id[i] )
				{
					if (inventory.Getquantityofproduct() == 0)
					{
						
						index = i;
						check2 = false;
						break;
					}
					
				}
				fileopen3.read((char*)&inventory, sizeof(inventory));
			}
			fileopen3.close();
		}

		
		if (check2 == false)
		{
			cout << "you Can't add following product because it out of stock" << endl;
			count = 0;

			
			fstream fileopen4(x, ios::in);
			while (fileopen4.read((char*)&inventory, sizeof(inventory)))
			{
				if (inventory.Getproductnumber() == id[index])
				{
					inventory.Show_Products();
					
				}
			}
			fileopen4.close();
			 
			system("pause");
			goto lable89;
		}
		else
		{
		


			system("cls");
			cout << "\t\t\t\t*******************************************************" << endl;
			cout << "\t\t\t\tTotal Item in the cart" << endl;
			cout << "\t\t\t\tPr No.\tPr Name\tQuantity \tPrice \tAmount " << endl;

			Inventory inventory2;
			for (int i = 0; i < count; i++)
			{
				fstream fileopen2(x, ios::in);
				fileopen2.read((char*)&inventory2, sizeof(inventory2));
				while (!fileopen2.eof())
				{
					if (inventory2.Getproductnumber() == id[i])
					{
						amount = inventory2.GetPriceOFproduct() * quntity2[i];
						displayproduct(id, i, inventory2, amount, quntity2);
						totalAmountafter_discount += amount;
					}
					fileopen2.read((char*)&inventory2, sizeof(inventory2));


				}
				fileopen2.close();

			}
			cout << "\t\t\t\t*******************************************************" << endl;

			string ssss;
			cout << "Enter your name" << endl;
			cin >> ssss;

			int q;
			Paymet* payment;
			cout << "\t\t\t\tSelect your paymnet option" << endl;
			cout << "\t\t\t\tPress 1 for Cash on delivery" << endl;
			cout << "\t\t\t\tPress 2 for Cradit card payment" << endl;
			cout << "\t\t\t\tPress 3 for Easy paisa option" << endl;
			cout << "\t\t\t\tPress 4 for Jazz Cash option" << endl;
			cin >> q;

			switch (q)
			{
			case 1:
			{
				payment = new Cashondelivery;
				if (payment->city == y)
				{
					totalAmountafter_discount += 30;
				}
				else
				{
					totalAmountafter_discount += 50;
				}

				break;
			}case 2:
			{
				payment = new CraditCard;


				break;
			}case 3:
			{
				payment = new EasyPaisa;

				break;
			}case 4:
			{
				payment = new Jazzcash;
				break;
			}

			default:
				break;
			}

			system("cls");
			cout << "\t\t\t\t*******************************************************" << endl;
			cout << "\t\t\t\tTotal Item in the cart" << endl;
			cout << "\t\t\t\tPr No.\tPr Name\tQuantity \tPrice \tAmount " << endl;


			for (int i = 0; i < count; i++)
			{
				fstream fileopen2(x, ios::in);
				fileopen2.read((char*)&inventory2, sizeof(inventory2));
				while (!fileopen2.eof())
				{
					if (inventory2.Getproductnumber() == id[i])
					{
						amount = inventory2.GetPriceOFproduct() * quntity2[i];
						cout << "\t\t\t\t" << id[i] << "\t" << inventory2.GetNameOfproduct() << "\t" << quntity2[i] << "\t\t" << inventory2.GetPriceOFproduct()<<" Rs" << '\t' << amount << endl;

					}
					fileopen2.read((char*)&inventory2, sizeof(inventory2));


				}
				fileopen2.close();

			}
			cout << "\t\t\t\t*******************************************************" << endl;

			cout << "Your Total Account you have to pay is = " << totalAmountafter_discount << endl;

			int yyyy;
		lable6:
			cout << "Press 1 to continue paymnet" << endl;
			cout << "Press 2 to exist the store" << endl;
			cin >> yyyy;

			switch (yyyy)
			{
			case 1:
			{
				bool check = true;
				Customer c;
				ifstream fileinput("Customer.dat", ios::binary);

				while (fileinput.read((char*)&c, sizeof(c)))
				{
					if (c.getwalletbalance() < totalAmountafter_discount)
					{

						//cout << "login Successful" << endl;
						check = false;
						break;

					}
				}
				fileinput.close();

				if (check == false)
				{
					cout << "Balance is insufficient Plz refill your card" << endl;
				}
				else
				{
					long pos = 0;
					fstream fileopen(x, ios::in | ios::out);
					for (int i = 0; i < count; i++)
					{

						while (fileopen)
						{
							pos = fileopen.tellg();
							fileopen.read((char*)&inventory, sizeof(inventory));
							if (inventory.Getproductnumber() == id[i])
							{
								inventory.Remove_the_QUantity_after_purchase(quntity2[i]);
								fileopen.seekp(pos);
								fileopen.write((char*)&inventory, sizeof(inventory));
								flag = 1;
								break;
							}
							fileopen.read((char*)&inventory, sizeof(inventory));

						}

					}
					if (flag != 1)
					{
						cout << "\t\t\t<<Record not found!!" << endl;

					}

					fileopen.close();


					s.setnoofitem(count);
					s.setcustomername(ssss);
					ofstream myfile("simulationcustomer.dat", ios::binary | ios::app);
					myfile.write((char*)&s, sizeof(s));
					myfile.close();
				




					cout << "\t\t\t\t\t\Thanks for Shopping Hope you see us again (:" << endl;
					c.status2 = 1;
				}
				break;
			}
			case 2:
			{
				Customer m;
				m.Menu();
				break;
			}
			default:
				goto lable6;
				break;
			}
			break;

		}

		

	}

	default:
		goto lable92;
		break;
	}

}


void Inventory::cart_of_inventory(int default_id)
{

	switch (default_id)
	{
	case 1:
	{
		Menu2(default_id);
		cart<string>("InventoryIslamabad.dat","Islamabad", default_id);
		//Menu2(default_id);
		break;
	}
	case 2:
	{
		Menu2(default_id);
		cart<string>("InventoryLahore.dat","Lahore", default_id);
		//Menu2(default_id);
		break;
	}
	case 3:
	{
		Menu2(default_id);
		cart<string>("InventoryKarachi.dat","Karachi", default_id);
		//Menu2(default_id);
		break;
	}
	default:
		break;
	}

}