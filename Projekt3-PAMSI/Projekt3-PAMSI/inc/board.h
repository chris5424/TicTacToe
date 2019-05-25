#pragma once

class Board
{
private:
	size_t size;
	size_t how_many_to_win;
	char **tab;
public:
	Board(size_t size, int how_many);
	~Board();
	void display();
	void changeField(int col, int row, char sign);
	void clearBoard();
	void header();
	char menu();
	void clearScreen();
	bool ifWin(char player);
	bool ifDraw();
	void playHuman(Board &BRD);
	void playComputer(Board &BRD);
};