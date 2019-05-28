#pragma once

class Move
{
public:
	size_t x;
	size_t y;
};

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
	void changeField(size_t col, size_t row, char sign);
	void clearBoard();
	void header();
	char menu();
	void clearScreen();
	bool ifWin(char player);
	bool ifDraw();
	void playHuman(Board &BRD);
	void playComputer(Board &BRD);
	Move computerMove(Board &BRD);
	int minMax(Board &BRD, int DepthOfRecursion, int alpha, int beta, bool computer);

};
