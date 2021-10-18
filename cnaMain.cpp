//Carter Jackson
//CSCI 2010
//Driver function
#include <iostream>
#include <fstream>
#include "Customer.h"

#include <string>
using namespace std;
int cnaMain()
{
	string type;
	Customer c;
	do
	{
		c.cnaMenu();
		int rc = c.cnaMenu();
		switch (rc)
		{
		case 1: c.cnaNewCust();
			//break;
		case 2: c.cnaChangeCust();
			//break;
		case 3: c.cnaDeleteCust();
			//break;
		case 4: c.cnaDisplayCust(type);
			//break;
		case 5: c.cnaDisplayList(type);
			//break;
		case 6: return 0;
		}
	} while (true);
	return 0;
	
	system("pause");
	return 0;
}