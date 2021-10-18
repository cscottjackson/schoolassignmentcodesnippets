//Carter Jackson
//CSCI 2010
#ifndef DATABASE_H    //Include Guard
#define DATABASE_H
#include <string>	  // Inlcudes
#include <iostream>
#include <fstream>
using namespace std;
//Class specification 
class Database
{
private:						//Private Member Variables
	string fileName;
	string tableName;
	string *arr;
	int keyLength;
	int maxRows;
	int maxRowSize;
	int cursor;
	int arrayCursor;
	int countInArray;
	ifstream iDFile, iMFile, iCFile;
	ofstream oDFile, oMFile;

public:
	
	//Default Constructor
	Database()
	{
		fileName = " ";
		tableName = " ";
		keyLength = 0;
		maxRows = 0;
		maxRowSize = 0;
		cursor = 0;
		arrayCursor = 0;
		countInArray = 0;
	}
	//Destructor
	~Database()
	{
		delete[]arr;
	}
	//Accessors for private member variables
	string getFileName()
	{
		return fileName;
	}
	string getTablename()
	{
		return tableName;
	}
	int getKeyLength()
	{
		return keyLength;
	}
	int getMaxRows()
	{
		return maxRows;
	}
	int getMaxRowSize()
	{
		return maxRowSize;
	}
	int getArrayCursor()
	{
		return arrayCursor;
	}
	int getCursor()
	{
		return cursor;
	}
	int getCountInArray()
	{
		return countInArray;
	}

	//Mutators

	void setArrayCursor(int c)
	{
		arrayCursor = c;
	}
	void setCursor(int c)
	{
		cursor = c;
	}
	void setCountInArray(int c)
	{
		countInArray = c;
	}

	//Member Functions
	int open(string);
	int close();
	int readKey(string, string*);
	int readGen(string, string*[], int*);
	int readSeq(string * record);
	int createTable(string, int, int, int);
	int deleteTable(string);
	int loadTableFromFile(string, string);
	int writeArray();
	int bubbleSort();
	int fetchAll(int *, string *[]);
	int readNext(string *);
	int insert(string, string *);
	int update(string, string *);
	int deleteKey(string, string *);
};
#endif
