
#include"USer.h"

bool Userclass::login()
{   //virtual function to use polymorphism
	Userclass a;
	bool b = true;
	ifstream fin("admin.dat", ios::binary);

	while (fin.read((char*)&a, sizeof(a))) {
		if (strcmp(a.username, username) + 1 && strcmp(password, a.password) + 1) {
			cout << "login Successful";
			b = false;
			return true;
			break;

		}

	}
	if (b) {
		cout << "Login unsuccessful";
	}
	fin.close();


}
Userclass::~Userclass() {


}

Userclass::Userclass(Userclass& c) {
	strcpy_s(username, sizeof(c.username), c.username);
	strcpy_s(password, sizeof(c.password), c.password);
	strcpy_s(CNIC, sizeof(c.CNIC), c.CNIC);
	strcpy_s(name, sizeof(c.name), c.name);
	strcpy_s(Gender, sizeof(c.Gender), c.Gender);


}

Userclass::Userclass() {
	username[0] = '\0';
	password[0] = '\0';
	CNIC[0] = '\0';
	name[0] = '\0';
	Gender[0] = '\0';
}
Userclass::Userclass(string u, string  p, string c, string n, string g) {
	strcpy_s(username, u.length() + 1, u.c_str());
	strcpy_s(password, p.length() + 1, p.c_str());
	strcpy_s(CNIC, c.length() + 1, c.c_str());
	strcpy_s(name, n.length() + 1, n.c_str());
	strcpy_s(Gender, n.length() + 1, n.c_str());

}
void Userclass::setUsername(string n) {
	strcpy_s(username, n.length() + 1, n.c_str());
}
void Userclass::setGender(string n)
{
	strcpy_s(Gender, n.length() + 1, n.c_str());
}
void Userclass::setPassword(string n) 
{
	strcpy_s(password, n.length() + 1, n.c_str());
}

void Userclass::setCNIC(string n) {
	strcpy_s(CNIC, n.length() + 1, n.c_str());
}
char* Userclass::getUsername() {
	return username;
}
char* Userclass::getGender() {
	return Gender;
}
char* Userclass::getCNIC() {
	return CNIC;
}
char* Userclass::getPassword() {
	return password;
}
void Userclass::setName(string p) {
	strcpy_s(name, p.length() + 1, p.c_str());
}
char* Userclass::getname() {
	return name;
}
void Userclass::Menu() {

}