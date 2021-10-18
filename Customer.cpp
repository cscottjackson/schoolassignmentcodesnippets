//Carter Jackson
//Pass 9
//CSCI 2010
#include "Customer.h"
#include "consoleFunctions.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//int rc = 0;
string *record;
string key;
string inpt;
int Customer::cnaMenu()
{
	int rc;
	string opt;
	message = "";
	do
	{ 
		cout << string(50, '\n');
		gotoxy(0, 0);
		cout << "CSCI Customer Name and Address" << endl;
		cout << " " << endl;
		cout << "1. New Customer" << endl;
		cout << "2. Change Customer" << endl;
		cout << "3. Delete Customer" << endl;
		cout << "4. Display Customer" << endl;
		cout << "5. Display Customer List" << endl;
		cout << "6. Exit" << endl;
		cout << " " << endl;
		cout << "Enter Option: " << endl;
		cin >> opt;
		rc = atoi(opt.c_str());
		//cin.ignore();

		if (rc < 1 || rc > 7)
		{
			cout << "Invalid option - reenter" << endl;
			cin >> opt;
			rc = atoi(opt.c_str());
		}
		else
			break;
	} while (true);
	return rc;
}

int Customer::cnaScreen(string title, int flag, int posx, int posy)
{
	cout << string(50, '\n');
	cout << "CSCI New Customer Information" << endl;
	cout << " " << endl;
	cout << "Customer Number: " << endl;
	cout << "First Name: " << endl;
	cout << "Last Name: " << endl;
	cout << "Middle Initial" << endl;
	cout << "Street: " << endl;
	cout << "City: " << endl;
	cout << "State: " << endl;
	cout << "Zip Code" << endl;
	cout << "Country: " << endl;
	cout << "Email Address: " << endl;
	cout << "Phone: " << endl;
	cout << "Comments: " << endl;
	if (flag == 1)
	{
		gotoxy(posx, posy);
	}
	return 0;
}


int Customer::cnaNewCust()
{
	int rc;
	//string inpt;
	//string key;
	//string *record;
	message = "";
	title = "CSCI New Customer Information";
	cnaScreen(title, 1, 16, 2);
	cnaIncCno();
	//Customer number
	gotoxy(16, 3);
	getline(cin, firstName);
	firstName.resize(40, ' ');

	gotoxy(16, 4);
	getline(cin, lastName);
	lastName.resize(40, ' ');

	gotoxy(16, 5);
	getline(cin, middleInitial);
	middleInitial.resize(40, ' ');

	gotoxy(16, 6);
	getline(cin, street);
	street.resize(40, ' ');

	gotoxy(16, 7);
	getline(cin, city);
	city.resize(40, ' ');

	gotoxy(16, 8);
	getline(cin, state);
	state.resize(40, ' ');

	gotoxy(16, 9);
	getline(cin, zipCode);
	zipCode.resize(40, ' ');

	gotoxy(16, 10);
	getline(cin, country);
	country.resize(40, ' ');

	gotoxy(16, 11);
	getline(cin, emailAddress);
	emailAddress.resize(40, ' ');

	gotoxy(16, 12);
	getline(cin, phoneNumber);
	phoneNumber.resize(40, ' ');

	gotoxy(16, 13);
	getline(cin, comments);
	comments.resize(40, ' ');

	Database::open("customer.txt");
	if (!open("customer.txt"))
	{
		return rc = -2;
	}

	Database::insert(key, record);
	
	if (rc = -2)
	{
		cout << "Error inserting New Customer – retry" << endl;
	}
	else
		cout << "Customer add complete – hit enter to return to the menu" << endl;
	Database::close();
	cout << string(50, '\n');
	gotoxy(0, 0);
	cin.get();
	return 0;
}

string Customer::cnaIncCno()
{
	int cno;
	ifstream ci;
	ofstream co;
	ci.open("custno.dat");
	ci >> cno;
	cno++;
	ci.close();
	co.open("custno.dat");
	co << cno;
	co.close();
	string s = to_string((unsigned long long) cno);
	s = "0000000000" + s;
	s = s.substr(s.length() - 10, 10);
	return s;

}

int Customer::cnaChangeCust()
{
	return 0;
}

int Customer::cnaDeleteCust()
{
		return 0;
}
int Customer::cnaDisplayCust(string type)
{
	return 0;
}
int Customer::cnaDisplayList(string type)
{
	return 0;
}
	