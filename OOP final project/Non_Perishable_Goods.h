#pragma once
#ifndef NON_PERISHABLE_GOODS_H
#define NON_PERISHABLE_GOODS_H
#include<iostream>
#include"Snacks.h"
#include"Spices.h"
#include"Grains.h"
using namespace std;




class NonPerishable_Goods :public Snacks,public Spices,public Grains
{
public:
	NonPerishable_Goods();
	void select_option_of_NonPerishable_Goods();




private:
	int select;

};






#endif // !NonPerishable_Goods_H
