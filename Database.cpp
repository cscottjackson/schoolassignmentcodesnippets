//Carter Jackson
//CSCI 2010

#include <fstream>
#include <iostream>
#include "Database.h"
#include <string>
using namespace std;

int rc = 0;
int i = 0;
string r;
int Database::open(string tablenam)
{
	iDFile.open("customer.txt");
	if (iDFile.is_open())
	{
		rc = -5;
		return rc;
	}
	iMFile.open("tablenam.mta");
	if (!iMFile.is_open())
	{
		rc = -2;
		return rc;
	}
	iDFile >> keyLength >> maxRows >> maxRowSize;
	arr = new string[];
	iDFile.open(tablenam + ".dat");
	if (!iDFile.is_open())
	{
		return -2;
	}
	cursor = 0;
	tableName = "tablenam";
	fileName = tablenam + ".dat";
	arrayCursor = 0;
	return 0;
}
int Database::close()
{
	if (!(iDFile.is_open()))
	{
		return -2;
	}
	//Free dynamically allocated memory
	delete[] arr;
	//close file
	iDFile.close();
	//Set member variables to 0 or NULL
	fileName = " ";
	tableName = " ";
	keyLength = 0;
	maxRows = 0;
	maxRowSize = 0;
	cursor = 0;
	arrayCursor = 0;
	countInArray = 0;
	return 0;
}

int Database::readKey(string key, string* record)
{
	//Check if file is not open
	if (!(iDFile.is_open()))
	{
		return -2;
	}
	rc = -1;
	string rec = *record;
	string k = key.append(keyLength, ' ');   //Pad keylength
	k = k.substr(0, keyLength);

	//Seek to position 0 of the file
	iDFile.clear();
	iDFile.seekg(0, ios::beg);
	//Loop and read file
	while (!iDFile.eof())
	{
		getline(iDFile, rec);

		if (k == rec.substr(0, keyLength))
		{
			*record = rec;
			rc = 0;
			return 0;
		}
	}
	return -1;
}

int Database::readGen(string key, string* arr1[], int * count)
{
	if (!(iDFile.is_open()))
	{
		return -2;
	}
	//Seek to position 0 of the file
	iDFile.clear();
	iDFile.seekg(0, ios::beg);
	count = 0;
	rc = -1;
	//Loop and read file
	while (iDFile.good() && i < maxRows)
	{
		getline(iDFile, r);
		if (key == r.substr(0, key.length()))
		{
			for (int i = 0; i < *count; i++)
				arr1[i];
			rc = 0;
			count++;
		}
	}
	*arr1 = arr;
	arrayCursor = 0;
	countInArray = *count;
	return rc;
	//return *count;
}

int Database::readSeq(string * record)
{
	if (!(iDFile.is_open()))
	{
		return -2;
	}
	iDFile.seekg(cursor, ios::beg);

	if (iDFile.eof())
	{
		cursor = 0;
		iDFile.seekg(0, ios::beg);
		return -1;
	}
	getline(iDFile, *record);

	if (*record == "")
	{
		cursor = 0;
		iDFile.seekg(0, ios::beg);
		return -1;
	}
	cursor = iDFile.tellg();
	return 0;



}

int Database::fetchAll(int * count, string * arr1[])
{
	if (!(iDFile.is_open()))
	{
		return -2;
	}
	iDFile.seekg(0, ios::beg);
	*count = 0;
	rc = -1;

	while (!iDFile.eof())
	{
		getline(iDFile, r);

		if (r == "")
		{
			break;
		}
		for (int i = 0; i < *count; i++)
		{
			arr[i];
		}
		rc = 0;
		*count++;
	}
	*arr1 = arr;
	countInArray = *count;
	arrayCursor = 0;
	//count;
	return rc;
}

int Database::readNext(string * record)
{
	if (arrayCursor > countInArray)
	{
		return -1;
	}
	*record = arr[arrayCursor];
	arrayCursor++;
	return 0;
}

int Database::insert(string key, string * record)
{
	string *arr1;
	int count = 0;
	//Call fetchAll
	fetchAll(&count, &arr1);
	//Pad key
	string k = key.append(keyLength, ' ');
	k = k.substr(0, keyLength);
	//Loop through array
	for (int i = 0; i < countInArray; i++)
	{
		if (k == arr1[i].substr(0, keyLength))
			return -3;
	}
	arr[count] = *record;
	countInArray++;
	bubbleSort();
	iDFile.close();
	writeArray();
	iDFile.open(fileName.c_str());
	return 0;
}

int Database::update(string key, string * record)
{
	int count = 0;
	string *arr1 = nullptr;
	fetchAll(&count, &arr1);
	rc = -1;
	int i = 0;
	string k = key.append(keyLength, ' ');
	k = k.substr(0, keyLength);
	for (i = 0; i < count; i++)
	{
		if (k == arr1[i].substr(0, keyLength))
		{
			rc = 0;
			break;
		}
	}
	if (rc == -1)
	{
		return rc;
	}
	arr[count] = *record;
	bubbleSort();
	writeArray();
	iDFile.close();
	iDFile.open(fileName.c_str());
	return 0;
}


int Database::deleteKey(string key, string *record)
{
	rc = -1;
	string *arr1;
	int count = 0;
	string k = key.append(keyLength, ' ');
	k = k.substr(0, keyLength);
	fetchAll(&count, &arr1);
	for (int i = 0; i < count; i++)
	{
		if (k == arr1[i].substr(0, keyLength))
		{
			rc = 0;
			arr1[i++];
		}
	}
	if (rc == 0)
	{
		--countInArray;
		bubbleSort();
		iDFile.close();
		writeArray();
		iDFile.open(tableName);
		return rc;
	}
	return rc;
}
//Pass 5 functions
int Database::createTable(string tablename, int maxsize, int keylength, int maxrowsize)
{
	string s = tablename + ".mta";
	oMFile.open(s.c_str());
	oMFile << keylength << maxsize << maxrowsize;
	oMFile.close();
	iMFile.open("tablenam.dat");
	iMFile.close();
	return 0;

}

int Database::deleteTable(string tablename)
{
	string c1 = "del" + tablename + ".dat";
	string c2 = "del" + tablename + ".mta";
	system(c1.c_str());
	system(c2.c_str());
	return 0;
}

int Database::loadTableFromFile(string tablename, string filename)
{
	iCFile.open(filename);
	open(tablename);

	if (!iDFile.is_open())
	{
		return -2;
	}
	countInArray = 0;
	i = 0;
	int kl = keyLength;
	for (i; i < kl; i++)
	{
		iCFile >> arr[i];
		countInArray++;
	}
	bubbleSort();
	writeArray();
	return 0;
}

int Database::writeArray()
{
	(oDFile.open(fileName.c_str()));
	for (i = 0; i < countInArray; i++)
	{
		oDFile << arr[i] << endl;
	}
	oDFile.close();
	return 0;
}

int Database::bubbleSort()
{
	bool swap;
	string temp;

	do
	{
		swap = false;
		for (i = 0; i < (countInArray - 1); i++)
		{
			if (arr[countInArray] > arr[countInArray + 1])
			{
				temp = arr[countInArray];
				arr[countInArray] = arr[countInArray + 1];
				arr[countInArray + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
	return 0;
}