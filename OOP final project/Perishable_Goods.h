#pragma once
#ifndef PERISHABLE_GOODS_H
#define PERISHABLE_GOODS_H
#include"meat.h"
#include"Dairy.h"
#include"Fruit.h"
#include"Vegetable.h"
class Perishable_Goods: public Meat,public Dairy,public Fruit, public vegetable
{
public:
	Perishable_Goods();
	void select_option_of_Perishable_Goods();

private:
	int select;

};






#endif // !PERISHABLE_GOODS_H
