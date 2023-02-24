#ifndef PAYMENTCONTROLLCLASS_H
#define PAYMENTCONTROLLCLASS_H
#include<string>
#include<iostream>
using namespace std;

class Paymet
{
public:
	Paymet();
	void setbalance(int Balance);
	int getbalance();
	char city[100];

protected:
	char addresss[100];
	
private:
	int Balance;
};




#endif // !PAYMENTCONTROLLCLASS_H
