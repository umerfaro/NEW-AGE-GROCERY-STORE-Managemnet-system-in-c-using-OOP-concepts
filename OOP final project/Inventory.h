#ifndef INVENTORY
#define INVENTORY
#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
#include"PaymentControllClass.h"
#include"Cashondelivery.h"
#include"EasyPaisa.h"
#include"JazzCash.h"
#include"CraditCard.h"
//#include"Customer.h"
using namespace std;


class Inventory
{
public:
	Inventory();

	void setproductnumber(int n);
	void setNameOfproduct(string s);
	void setPriceOFproduct(float n);
	void setquantityofproduct(float n);
	void setDiscount(float n);
	int Getproductnumber();
	char* GetNameOfproduct();
	float GetPriceOFproduct();
	float Getquantityofproduct();
	float GetDiscount();
	void Create_New_product();
    void Remove_the_QUantity_after_purchase(int qty);
	void Refill_the_QUantity(int qty);
	void Show_Products();
    void Write_THE_PRoduct(int default_id);
	void DisplayALLRecord(int default_id);
	void search_seperate_product(string n, int default_id);
	void modify_given_product_in_inventory(int default_id);
	void Delete_product(int default_id);
	void Menu2(int default_id);
	void refillquantityofproduct(int default_id);
	void cart_of_inventory(int default_id);
	

private:
	int productnumber;
	char nameofproduct[100];
	float price;
	float quantity;
	float discount;
	

};















#endif // !INVENTORY
