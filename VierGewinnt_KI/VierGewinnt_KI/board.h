#pragma once
#include "AICore\globaldef.h"

class Board
{
public:
	Board();
	~Board();
	int Cells[CellsX*CellsY];
	void ResetBoard();
};

