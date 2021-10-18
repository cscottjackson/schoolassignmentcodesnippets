//Carter Jackson
//Pass 9
//CSCI 2010
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Database.h"
#include <string>
using namespace std;

class Customer : public Database
{
private:
	struct Flds
	{
		int posx;
		int posy;
		int rpos;
		int rlen;
		string* pfld;
	};
	struct CNAInfo
	{
		char customerNumber[10];
		char firstName[40];
		char lastName[40];
		char middleInitial;
		char street[40];
		char city[40];
		char state[20];
		char zipCode[10];
		char country[40];
		char emailAddress[40];
		char phoneNumber[20];
		char comments[100];
		char eor;
	};

	CNAInfo custRec;

	string	customerNumber;
	string	firstName;
	string	lastName;
	string	middleInitial;
	string	street;
	string	city;
	string	state;
	string	zipCode;
	string	country;
	string	emailAddress;
	string	phoneNumber;
	string	comments;
	Flds	*fld;
	string  title;
	string	message;
	
public:
	//Prototypes
	int cnaMenu();
	int cnaScreen(string title, int flag, int x, int y);
	int cnaNewCust();
	int cnaChangeCust();
	int cnaDeleteCust();
	int cnaDisplayCust(string type);
	int cnaDisplayList(string type);
	string cnaIncCno();

	//Default constructor
	Customer()
	{
		customerNumber = "";
		firstName = "";
		lastName = "";
		middleInitial = "";
		street = "";
		city = "";
		state = "";
		zipCode = "";
		country = "";
		emailAddress = "";
		phoneNumber = "";
		comments = "";
		title = "";
		message = "";

		fld = new Flds[12];
		const Flds fldi[] = { { 16, 2, 0, 10, &customerNumber }, { 16, 3, 10, 40, &firstName },
		{ 16, 4, 50, 40, &lastName }, { 16, 5, 90, 1, &middleInitial },
		{ 16, 6, 91, 40, &street }, { 16, 7, 131, 40, &city },
		{ 16, 8, 171, 20, &state }, { 16, 9, 191, 10, &zipCode },
		{ 16, 10, 201, 40, &country }, { 16, 11, 241, 40, &emailAddress },
		{ 16, 12, 281, 20, &phoneNumber }, { 16, 13, 301, 100, &comments } };
	}
	//~Customer();

};

#endif