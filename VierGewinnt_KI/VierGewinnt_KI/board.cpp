#include "board.h"

Board::Board()
{
	for (int i = 0; i < CellsX*CellsY;i++)
	{
		Cells[i] = 0;
	}
}
Board::~Board()
{
}

void Board::ResetBoard()
{
	for (int i = 0; i < CellsX*CellsY; i++)
	{
		Cells[i] = 0;
	}
}
