#include <iostream>
#include <algorithm>

#include "../inc/board.h"

using namespace std;

#define INF 2147483647 

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

void Board::changeField(size_t row, size_t col, char sign)
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
				size_t p = i - k;
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
				size_t p = i - k;
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
			for (size_t i = 0; i < size - k; i++)
			{
				if (tab[i][size - 1 - i - k] == player)
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
	bool plr = 0;
	char player1 = 'X';
	char player2 = 'O';
	Move mov;
	BRD.display();
	while (!BRD.ifWin('X') && !BRD.ifDraw() && !BRD.ifWin('O'))
	{
		if (plr)
		{
			do
			{
				cout << "Twoj ruch: " << player1 << endl;
				cin >> mov.x >> mov.y;
			} while (mov.x > size || mov.y > size || (tab[mov.x - 1][mov.y - 1] == 'O') || (tab[mov.x - 1][mov.y - 1] == 'X'));
			BRD.changeField(mov.x - 1, mov.y - 1, 'X');
			BRD.clearScreen();
			BRD.display();
			plr = !plr;
		}
		else
		{
			do
			{
				cout << "Twoj ruch: " << player2 << endl;
				cin >> mov.x >> mov.y;
			} while (mov.x > size || mov.y > size || (tab[mov.x - 1][mov.y - 1] == 'O') || (tab[mov.x - 1][mov.y - 1] == 'X'));
			BRD.changeField(mov.x - 1, mov.y - 1, 'O');
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
	else if (BRD.ifDraw())
	{
		display();
		cout << "\nREMIS !!\n";
	}
}

void Board::playComputer(Board &BRD)
{
	bool plr = 1;
	char player1 = 'X';
	char player2 = 'O';
	Move mov;
	BRD.display();
	while (!BRD.ifWin('X') && !BRD.ifDraw() && !BRD.ifWin('O'))
	{
		if (plr)
		{
			do
			{
				cout << "Twoj ruch: " << player1 << endl;
				cin >> mov.x >> mov.y;
			} while (mov.x > size || mov.y > size||(tab[mov.x-1][mov.y-1]=='O')|| (tab[mov.x-1][mov.y-1] == 'X'));
			BRD.changeField(mov.x - 1, mov.y - 1, 'X');
			BRD.clearScreen();
			BRD.display();
			plr = !plr;
		}
		else
		{
			mov = BRD.computerMove(BRD);
			BRD.changeField(mov.x, mov.y, 'O');
			BRD.clearScreen();
			//cout <<"x: "<< mov.x <<" y: "<< mov.y;
			BRD.display();
			cout << "Ruch komputera to: " << mov.x + 1 << " " << mov.y+1<<endl;
			plr = !plr;
		}
	}
	if (BRD.ifWin('X'))
	{
		cout << "\tGracz wygral\n";
	}
	else if (BRD.ifWin('O'))
	{
		cout << "\tKomputer wygral\n";
	}
	else if (BRD.ifDraw()) 
	{
		//display();
		cout << "\nREMIS !!\n";
	}
	else
	{
		cout << "wyszedl z glownej petli, ale nikt nie wygral ani nie bylo remisu";
	}
}

Move Board::computerMove(Board &BRD)
{
	Move mov;
	int result, depth = 9;
	int max = -10;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (tab[i][j] == ' ')
			{
				BRD.changeField(i, j, 'O');
				result = minMax(BRD, depth, -INF, INF, 0);
				BRD.changeField(i, j, ' ');
				if (result > max)
				{
					max = result;
					mov.x = i;
					mov.y = j;
				}
			}
		}
	}
	return mov;
}

int Board::minMax(Board &BRD, int DepthOfRecursion, int alpha, int beta, bool computer)
{
	int eval=0, x=0;
	if (DepthOfRecursion == 0)
	{
		return 0;
	}
	if (BRD.ifWin('O'))return 1;
	else if (BRD.ifWin('X'))return -1;

	if (BRD.ifDraw()) return 0;

	if (computer)
	{
		eval = -INF;
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				if (tab[i][j] == ' ')
				{
					BRD.changeField(i, j, 'O');
					alpha = max(eval, alpha);
					x = minMax(BRD, DepthOfRecursion - 1, alpha, beta, false);
					BRD.changeField(i, j, ' ');
					eval = max(eval, x);
					if (x >= beta)
					{
						//return x;
						break;
					}
					
				}
			}
		}
	}
	else
	{
		eval = INF;
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				if (tab[i][j] == ' ')
				{
					BRD.changeField(i, j, 'X');
					beta = min(eval, beta);
					x = minMax(BRD, DepthOfRecursion - 1, alpha, beta, true);
					BRD.changeField(i, j, ' ');
					eval = min(eval, x);
					if (x <= alpha)
					{
						//return x;
						break;
					}
					
				}
			}
		}
	}
	return eval;
}