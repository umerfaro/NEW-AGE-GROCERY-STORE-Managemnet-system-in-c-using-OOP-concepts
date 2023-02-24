#pragma once
#ifndef ISLAMABADSTORE_H 
#define ISLAMABADSTORE_H
#include"Store.h"

class Islamabadstore:public Store
{

public:
	
	Islamabadstore(Manager& m);

private:
	Manager& manager;
};








#endif