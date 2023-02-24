#pragma once
#ifndef PRODUCTCATALOG
#define PRODUCTCATALOG
#include"Food.h"
#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#include<cstring>
#include"Personal_Hygiene.h"
#include"Household_Cleaning.h"




class ProductCatalog :public Food,public Personal_Hygiene,public Household_Cleaning
{
public:
	ProductCatalog();
	void selectcatalogoption();
	void displayALLPRODUCT();
	void updateCATAlogproduct();
	void retrivecatalogdate();
	void writecatalog();
	

private:
	int select3;

};





#endif // !PRODUCTCATALOG
