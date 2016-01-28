#include "boardController.h"

#include "VierGewinnt_KI\board.h"

#include <algorithm>



BoardController::BoardController(Board *board)
{
	this->m_board = board;
}


BoardController::~BoardController()
{
}
bool BoardController::AddStonetoCollum(const int column, const int color)
{
	for (int y = CellsY - 1; y >= 0; y--)
	{
		if (m_board->Cells[column + CellsX * y] == 0)
		{
			m_board->Cells[column + CellsX * y] = color;
			return true;
		}
	}
	return false;
}
void BoardController::RemoveStoneFromColum(int column)
{
	for (int y = 0; y < CellsY; y++)
	{
		if (m_board->Cells[column + CellsX * y] != 0)
		{
			m_board->Cells[column + CellsX * y] = 0;
			return;
		}
	}
}
int BoardController::CheckBoard()
{
	Score score;

	CheckVertical(score);
	CheckDiagonalL(score);
	CheckDiagonalR(score);
	CheckHorizontal(score);

	if (score.score[0] != 0)
		return BlackWin;
	else if (score.score[8] != 0)
		return RedWin;
	else // heuristic function
		return
		score.score[5] + 10 * score.score[6] + 100 * score.score[7] -
		score.score[3] - 10 * score.score[2] - 100 * score.score[1];
}
void BoardController::CheckVertical(Score &score)
{
	int intermediate;
	for (int x = 0; x < CellsX; x++) {
		intermediate = m_board->Cells[x + CellsX * 0] + m_board->Cells[x + CellsX * 1] + m_board->Cells[x + CellsX * 2];
		for (int y = 3; y < CellsY; y++) {
			assert(Inside(y, x));
			intermediate += m_board->Cells[x + CellsX * y];
			score.score[intermediate + 4]++;
			assert(Inside(y - 3, x));
			intermediate -= m_board->Cells[x + CellsX * (y - 3)];
		}
	}
}

void BoardController::CheckDiagonalL(Score &score)
{
	int intermediate;
	for (int y = 3; y < CellsY; y++) {
		for (int x = 0; x < CellsX - 3; x++) {
			intermediate = 0;
			for (int idx = 0; idx < 4; idx++) {
				int yy = y - idx;
				int xx = x + idx;
				assert(Inside(yy, xx));
				intermediate += m_board->Cells[xx + CellsX * yy];
			}
			score.score[intermediate + 4]++;
		}
	}
}

void BoardController::CheckDiagonalR(Score &score)
{
	int intermediate;
	for (int y = 0; y < CellsY - 3; y++) {
		for (int x = 0; x < CellsX - 3; x++) {
			intermediate = 0;
			for (int idx = 0; idx < 4; idx++) {
				int yy = y + idx;
				int xx = x + idx;
				assert(Inside(yy, xx));
				intermediate += m_board->Cells[xx + CellsX * yy];
			}
			score.score[intermediate + 4]++;
		}
	}
}

void BoardController::CheckHorizontal(Score &score)
{
	int intermediate;
	for (int y = 0; y < CellsY; y++) {
		intermediate = m_board->Cells[0 + CellsX * y] + m_board->Cells[1 + CellsX * y] + m_board->Cells[2 + CellsX * y];
		for (int x = 3; x < CellsX; x++) {
			assert(Inside(y, x));
			intermediate += m_board->Cells[x + CellsX * y];
			score.score[intermediate + 4]++;
			assert(Inside(y, x - 3));
			intermediate -= m_board->Cells[(x - 3) + CellsX * y];
		}
	}
}
bool BoardController::Inside(int y, int x)
{
	return (y >= 0 && y < CellsY && x >= 0 && x < CellsX);
}
