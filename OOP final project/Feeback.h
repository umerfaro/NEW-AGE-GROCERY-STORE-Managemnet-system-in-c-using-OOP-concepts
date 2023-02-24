#pragma

#ifndef FEEDBACK_H
#define FEEDBACK_H

#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

class Feedback {
	char feedbackofcustomer[100];
	char rating[10];         
	char commentofadmin[100];
	char namecustomer[100];
public:  
	void setRating(string n);
	char* getComment();
	char* getFeedback();
	char* getrating();
	void setFeedback(string n);
	void setComment(string n);
	void setfeedbackname(string s);
	char* getfeedbackname();
	
};





#endif // !CUSTOMER_H







