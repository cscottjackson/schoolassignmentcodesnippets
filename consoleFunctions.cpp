#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;
//-----------------------------------------------------------
// Function: gotoxy(column, line)
// Purpose: Position cursor to location on console window 
//-----------------------------------------------------------

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);
}

//-----------------------------------------------------------
// Function: wherex()
// Purpose: Return cursor x position.
//-----------------------------------------------------------
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	//COORD  result;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
		))
		return -1;
	return csbi.dwCursorPosition.X;
}
//-----------------------------------------------------------
// Function: wherey()
// Purpose: Return cursor y position.
//-----------------------------------------------------------
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD  result;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
		))
		return -1;
	return csbi.dwCursorPosition.Y;
}