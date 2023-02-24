#include"PaymentControllClass.h"
Paymet::Paymet()
{
	Balance = 0;
	addresss[0] = '\0';
	city[0] = '\0';;
}

void Paymet::setbalance(int Balance)
{

	this->Balance += Balance;
}
int Paymet::getbalance()
{
	return Balance;
}
