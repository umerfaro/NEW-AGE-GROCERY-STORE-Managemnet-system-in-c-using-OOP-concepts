#pragma once
#ifndef KARACHISTORE_H
#define KARACHISTORE_H
#include"Store.h"

class Karachistore:public Store
{
public:
	Karachistore(Manager& m);
	
	

private:
	Manager& manager;
};





#endif