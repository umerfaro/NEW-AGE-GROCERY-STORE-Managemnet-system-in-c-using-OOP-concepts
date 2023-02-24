#pragma

#ifndef USER_H
#define USER_H

#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;
class Userclass 
{
private:
	char name[100];
	char username[100];   
	char password[100];
	char CNIC[100];
	char Gender[10];
public:
	



	virtual bool login();
	~Userclass();
	Userclass(Userclass& c);
	Userclass();
	Userclass(string u, string  p, string c, string n, string g);
	void setUsername(string n);
	void setGender(string n);
	void setPassword(string n);
	void setCNIC(string n);
	char* getUsername();
	char* getGender();
	char* getCNIC();
	char* getPassword();
	void setName(string p);
	char* getname();
	virtual void Menu();
};





#endif