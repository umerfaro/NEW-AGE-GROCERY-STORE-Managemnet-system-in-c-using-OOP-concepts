#include"Feeback.h"

void Feedback::setFeedback(string n) {
	strcpy_s(feedbackofcustomer, n.length() + 1, n.c_str());
}

void Feedback::setComment(string n) {
	strcpy_s(commentofadmin, n.length() + 1, n.c_str());
}
void Feedback::setRating(string n) {
	strcpy_s(rating, n.length() + 1, n.c_str());
}
char* Feedback::getComment() {
	return commentofadmin;
}
char* Feedback::getFeedback() {
	return feedbackofcustomer;
}
char* Feedback::getrating() {
	return rating;
}

void Feedback::setfeedbackname(string s) 
{
	strcpy_s(namecustomer, s.length() + 1, s.c_str());
}
char* Feedback::getfeedbackname()
{
	return namecustomer;

}