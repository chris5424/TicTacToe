#include <iostream>

#include "../inc/board.h"

using namespace std;

Board::Board(size_t size, int how_many)
{
	this->size = size;
	this->how_many_to_win = how_many;
	tab = new char*[size];
	for (size_t i = 0; i < size; i++)
	{
		tab[i] = new char[size];
	}

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			tab[i][j] = ' ';
		}
	}
}

Board::~Board()
{
	for (size_t i = 0; i < size; i++)
	{
		delete tab[i];
	}
	delete tab;
	tab = NULL;
}

void Board::display()
{
	cout << "  ";
	for (size_t i = 1; i < size + 1; i++)
	{
		cout << " " << i << "  ";
	}
	cout << "\n\n";
	for (size_t i = 0; i < size; i++)
	{
		cout << i + 1 << " ";
		for (size_t j = 0; j < size; j++)
		{
			cout << " " << tab[i][j] << " ";
			if (j < size - 1)
			{
				cout << "|";
			}
		}
		cout << endl;
		if (i < size - 1)
		{
			cout << "  ";
			for (size_t j = 0; j < size; j++)
			{
				cout << "--- ";
			}
		}
		cout << endl;
	}
}

void Board::changeField(int row, int col, char sign)
{
	tab[row][col] = sign;
}

void Board::clearBoard()
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			tab[i][j] = ' ';
		}
	}
}

void Board::header()
{
	cout << "Tic Tac Toe " << size << "X" << size << endl;
}

char Board::menu()
{
	{
		char choice;
		cout << "Opcje:\n";
		cout << "\tK - Graj przeciwko Komputerowi\n";
		cout << "\tG - Graj przeciwko innemu graczowi\n";
		cout << "\tW - Wyjdz\n";
		do {
			cout << "Twoj wybor: ";
			cin >> choice;
		} while (choice != 'K' && choice != 'G' && choice != 'W' && choice != 'k'&& choice != 'g'&& choice != 'w');
		return choice;
	}
}

void Board::clearScreen()
{
	system("cls");
}

bool Board::ifDraw()
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (tab[i][j] == ' ')
				return false;
		}
	}
	clearScreen();
	display();
	cout << "\nREMIS !!\n";
	return true;
}

bool Board::ifWin(char player)
{
	int count = 0;
	bool Win = false;
	//srawdŸ kolumny
	if (Win == false)
	{
		for (size_t i = 0; i < size; i++)
		{
			count = 0;
			for (size_t j = 0; j < size; j++)
			{
				if (tab[j][i] == player)
				{
					count++;
				}
				else
				{
					count = 0;
				}
				if (count == how_many_to_win)
				{
					Win = true;
				}
			}
		}
	}

	//sprawdŸ rzêdy
	if (Win == false)
	{
		for (size_t i = 0; i < size; i++)
		{

			count = 0;
			for (size_t j = 0; j < size; j++)
			{
				if (tab[i][j] == player)
				{
					count++;
				}
				else
				{
					count = 0;
				}
				if (count == how_many_to_win)
				{
					Win = true;
				}
			}
		}
	}


	//sprawdŸ przek¹tne
	//w przek¹tna od góry w prawo dó³
	if (Win == false)
	{
		for (size_t k = 0; k < size; k++)
		{
			count = 0;
			for (size_t i = k; i < size; i++)
			{
				int p = i - k;
				if (tab[i][p] == player)
				{
					count++;
				}
				else
				{
					count = 0;
				}
				if (count == how_many_to_win)
				{
					Win = true;
				}
			}
		}
		for (size_t k = 0; k < size; k++)
		{
			count = 0;
			for (size_t i = k; i < size; i++)
			{
				int p = i - k;
				if (tab[p][i] == player)
				{
					count++;
				}
				else
				{
					count = 0;
				}
				if (count == how_many_to_win)
				{
					Win = true;
				}
			}
		}
	}
	//przek¹tna od góry w lewo dó³
	if (Win == false)
	{
		for (size_t k = 0; k < size; k++)
		{
			count = 0;
			for (size_t i = k; i < size; i++)
			{
				if (tab[i][size - 1 + k - i] == player)
				{
					count++;
				}
				else
				{
					count = 0;
				}
				if (count == how_many_to_win)
				{
					Win = true;
				}
			}
		}
		for (size_t k = 0; k < size; k++)
		{
			count = 0;
			for (size_t i = 0; i < size-k; i++)
			{
				if (tab[i][size-1-i-k] == player)
				{
					count++;
				}
				else
				{
					count = 0;
				}
				if (count == how_many_to_win)
				{
					Win = true;
				}
			}
		}
	}
	return Win;
}

void Board::playHuman(Board &BRD)
{
	bool plr=0;
	char player1 = 'X';
	char player2 = 'O';
	int x, y;
	BRD.display();
	while (!BRD.ifWin('X') && !BRD.ifDraw() && !BRD.ifWin('O'))
	{
		if (plr)
		{
			cout << "Tura gracza: " << player1<<endl;
			cin >> x >> y;
			BRD.changeField(x-1, y-1, 'X');
			BRD.clearScreen();
			BRD.display();
			plr=!plr;
		}
		else
		{
			cout << "Tura gracza: " << player2<<endl;
			cin >> x >> y;
			BRD.changeField(x-1, y-1, 'O');
			BRD.clearScreen();
			BRD.display();
			plr=!plr;
		}
	}
	if (BRD.ifWin('X'))
	{
		cout << "\tGracz X wygral\n";
	}
	else if (BRD.ifWin('O'))
	{
		cout << "\tGracz O wygral\n";
	}
}

void Board::playComputer(Board &BRD)
{
	bool plr = 0;
	char player1 = 'X';
	char player2 = 'O';
	int x, y;
	BRD.display();
	while (!BRD.ifWin('X') && !BRD.ifDraw() && !BRD.ifWin('O'))
	{
		if (plr)
		{
			cout << "Tura gracza: " << player1 << endl;
			cin >> x >> y;
			BRD.changeField(x - 1, y - 1, 'X');
			BRD.clearScreen();
			BRD.display();
			plr = !plr;
		}
		else
		{
			cout << "Tura gracza: " << player2 << endl;
			cin >> x >> y;
			BRD.changeField(x - 1, y - 1, 'O');
			BRD.clearScreen();
			BRD.display();
			plr = !plr;
		}
	}
	if (BRD.ifWin('X'))
	{
		cout << "\tGracz X wygral\n";
	}
	else if (BRD.ifWin('O'))
	{
		cout << "\tGracz O wygral\n";
	}
}