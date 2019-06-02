#include <windows.h>
#include <iostream>

#include "../inc/board.h"

using namespace std;
int main()
{
	size_t sizeOfGame = 4;
	int howManySignsToWin = 4;
	Board brd(sizeOfGame, howManySignsToWin);
	brd.header();
	char choice = brd.menu();
	switch (choice) {
	case 'K':
		brd.clearScreen();
		brd.header();
		cout << "Grasz przeciwko komputerowi\n";
		brd.playComputer(brd);
		break;
	case 'k':
		brd.clearScreen();
		brd.header();
		cout << "Grasz przeciwko komputerowi\n";
		brd.playComputer(brd);
		break;
	case 'G':
		brd.clearScreen();
		brd.header();
		cout << "Grasz przeciwko innemu graczowi\n";
		brd.playHuman(brd);
		break;
	case 'g':
		brd.clearScreen();
		brd.header();
		cout << "Grasz przeciwko innemu graczowi\n";
		brd.playHuman(brd);
		break;
	case 'W':
		brd.clearScreen();
		brd.header();
		cout << "Do Svidaniya!\n";
		break;
	case 'w':
		brd.clearScreen();
		brd.header();
		cout << "Do Svidaniya!\n";
	}
	system("pause");
}

