#pragma
 
#ifndef ADMIN_H
#define ADMIN_H


#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#include<cstring>
#include"USer.h"
#include"Customer.h"
#include"ProductCatalog.h"
#include"Manager1.h"
#include"Manager2.h"
#include"Manager3.h"
using namespace std;

class Admin : public Userclass {
private:
//this are private member of admin class
	//assiciation is used here
	Manager manager;
	Customer customer;
	Feedback admin;
	ProductCatalog product;
	Manager1 islamabadmanager;
	Manager2 lahoremanager;
	Manager3 karachimanager;

public:
	
	bool Searchcustomer();
	void Showcustomer();
	void Menu() override;//this is overriding  as virtual us using in userclass
	bool login() override;
	void customerFeedbackshow();
	void deletecustomerfeedback();
	Admin();

};


#endif 






