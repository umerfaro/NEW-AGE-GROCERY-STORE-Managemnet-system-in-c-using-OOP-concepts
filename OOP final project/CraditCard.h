#pragma once
#ifndef CRADITCARD_H
#define CRADITCARD_H
#include"PaymentControllClass.h"

class CraditCard:public Paymet
{
public:
	CraditCard();
	

private:

	int cardnumber;
	int ccv;


};




#endif // !PAYMENTCONTROLLCLASS_H
