#pragma once
#ifndef LAHORESTORE_H 
#define LAHORESTORE_H
#include"Store.h"
class Lahorestore :public Store
{
public:
	Lahorestore(Manager& m);


private:
	Manager& manager;
};







#endif