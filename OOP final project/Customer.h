#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#include<cstring>
#include"USer.h"
#include"Feeback.h"
#include"Inventory.h"
#include"PaymentControllClass.h"

using namespace std;

class Customer :public Userclass {
private:

	char phone_number[15];
	char address[50];
	Paymet Wallet;

public:
	Feedback a;
	Inventory inventoryss;
	static int status2;
	Customer();
	void setwalletbalance(int n);
	int getwalletbalance();
	void setPhonenumber(string n);
	char* getphoneNumber();
	void setaddress(string n);
	char* getadress();
	void feedbackgive();
	void showmydetails();
	void Menu() override;
	bool login() override;
	void Register();
	void nameuserchnage();
	void passwordupdate();


};







#endif // !CUSTOMER_H
