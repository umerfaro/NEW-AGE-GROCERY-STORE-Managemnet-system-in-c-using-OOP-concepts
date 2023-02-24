#include<iostream>
#include<fstream>
#include"MenuHeader.h"
#include"USer.h"
#include"Customer.h"
#include"Admin.h"



using namespace std;


void Startingmenu::startingmenu1() {

    system("cls");
    Userclass* a;
    cout << "************************************NEW AGE GROCERY STORE*******************************************************#" << endl;
    cout << "#                            Press 1 to enter as customer                                                       #" << endl;
    cout << "#                            Press 2 to enter as Manager                                                        #" << endl;
    cout << "#                            Press 3 to enter as admin                                                          #" << endl;
    cout << "#                            Press 4 to Exit Program                                                            #" << endl;
    cout << "#***************************************************************************************************************#" << endl;
    int n;
    cin >> n;

    if (n == 1)
    {
        a = new Customer;
        a->Menu();
    }
    else if (n == 2)
    {
        a = new Manager;
        a->Menu();
    }
    else if (n == 3) {
        a = new Admin;
        a->Menu();
    }
    else if (n == 4) {
        exit(0);
    }
    else
    {
        startingmenu1();
    }

}
   
   







