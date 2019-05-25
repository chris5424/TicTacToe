#include <windows.h>
#include <iostream>

#include "../inc/board.h"

using namespace std;
int main()
{
	size_t size=5;
	int h_m_t_w =4;
	//cin >> size;
	Board brd(size, h_m_t_w);
	//brd.changeField(0, 0, 'X');
	brd.playHuman(brd);
	//brd.changeField(1, 0, 'X');
	//brd.changeField(1, 1, 'X');
	//brd.changeField(1, 2, 'X');
	//brd.changeField(2, 1, 'O');
	//brd.display();
	//brd.changeField(0, 1, 'O');
	//brd.changeField(0, 2, 'X');
	//brd.changeField(1, 1, 'X');
	//brd.changeField(2, 0, 'X');
	//brd.changeField(2, 2, 'X');
	//brd.changeField(3, 3, 'X');
	//brd.changeField(2, 0, ' ');
	//brd.display();
	//brd.clearBoard();
	/*while (!brd.ifWin('X'))
	{
		int x, y;
		cin >> x >> y;
		brd.changeField(x-1, y-1, 'X');
		brd.clearScreen();
		brd.display();
	}
	cout << "Wygrana\n";*/
	//cout << brd.ifWin('X');
















	//brd.header();
	//char choice = brd.menu();
	//brd.clearScreen();
	//switch (choice) {
	//case 'K':
	//	//brd.playComputer();
	//	cout << "grasz przeciwko komputerowi";
	//	break;
	//case 'k':
	//	//brd.playComputer();
	//	cout << "grasz przeciwko komputerowi";
	//	break;
	//case 'G':
	//	//brd.playHuman();
	//	cout << "grasz przeciwko innemu graczowi";
	//	break;
	//case 'g':
	//	//brd.playHuman();
	//	cout << "grasz przeciwko innemu graczowi";
	//	break;
	//case 'W':
	//	brd.header();
	//	cout << "Do Svidaniya!\n";
	//	break;
	//case 'w':
	//	brd.header();
	//	cout << "Do Svidaniya!\n";
	//}
	system("pause");
}

