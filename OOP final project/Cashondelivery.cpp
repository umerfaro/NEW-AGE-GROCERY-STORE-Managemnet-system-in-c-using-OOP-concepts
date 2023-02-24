#include"Cashondelivery.h"

Cashondelivery::Cashondelivery() {

	string s;
	cout << "Enter your Address" << endl;
	cin >> s;
	strcat_s(addresss, s.length() + 1, s.c_str());
	cout << "Enter you city" << endl;
	cin >> s;
	strcat_s(city, s.length() + 1, s.c_str());
}