#include "searchAlgorithm.h"
#include "boardController.h"

#include "VierGewinnt_KI\board.h"

#include <algorithm>


SearchAlgorithm::SearchAlgorithm(BoardController* controller)
{
	this->m_controller = controller;
}


SearchAlgorithm::~SearchAlgorithm()
{
}
void SearchAlgorithm::Minimax(bool maximize, int color, int depth, int & move)
{
	SetCurrrentsearchDepth(depth);
	Minimax(maximize, color, depth, move, m_score);
}
void SearchAlgorithm::Megamax(int color, int depth, int & move)
{
	SetCurrrentsearchDepth(depth);
	Megamax(color, m_CurrentSearchDepth, move, m_score);
}
void SearchAlgorithm::MegamaxAB(int color, int depth, int & move)
{

}
void SearchAlgorithm::Minimax(bool maximize, int color, int depth, int& move, int& score)
{
	int bestScore = maximize ? BlackWin : RedWin;
	int bestMove = -1;
	int s = 0;
	for (int x = 0; x < CellsX; x++)
	{
		if (!m_controller->AddStonetoCollum(x, color))
			continue;
		s = m_controller->CheckBoard();
		if (s == (maximize ? RedWin : BlackWin))
		{
			bestMove = x;
			bestScore = s;
			m_controller->RemoveStoneFromColum(x);
			break;
		}

		int moveInner, scoreInner;
		if (depth > 1)
			Minimax(!maximize, color == Red ? Black : Red, depth - 1, moveInner, scoreInner);
		else
		{
			moveInner = -1;
			scoreInner = s;
		}

		m_controller->RemoveStoneFromColum(x);

		if (maximize) {
			bestScore = std::max(scoreInner, bestScore);
			if (scoreInner >= bestScore)
				bestMove = x;
		}
		else {
			bestScore = std::min(scoreInner, bestScore);
			if (scoreInner <= bestScore)
				bestMove = x;
		}
	}
	move = bestMove;
	score = bestScore;
}
void SearchAlgorithm::Megamax(int color, int depth, int& move, int& score)
{
	int bestScore = BlackWin;
	int bestMove = -1;
	int s = 0;
	for (int x = 0; x < CellsX; x++)
	{
		if (!m_controller->AddStonetoCollum(x, color))
			continue;
		s = m_controller->CheckBoard();
		if (color == Red && s == RedWin)
		{
			bestMove = x;
			bestScore = s;
			m_controller->RemoveStoneFromColum(x);
			break;
		}

		int moveInner, scoreInner;
		if (depth > 1)
			Megamax(color == Red ? Black : Red, depth - 1, moveInner, scoreInner);
		else
		{
			moveInner = -1;
			scoreInner = s;
		}

		m_controller->RemoveStoneFromColum(x);

		bestScore = std::max(scoreInner, bestScore);
		if (scoreInner >= bestScore && depth == m_CurrentSearchDepth)
			bestMove = x;
	}
	move = bestMove;
	score = bestScore * -1;
}
void SearchAlgorithm::MegamaxAB(int color, int depth, int& move, int& score, int alpha, int beta)
{
	int bestScore = BlackWin;
	int bestMove = -1;
	int s = 0;
	for (int x = 0; x < CellsX; x++)
	{
		if (!m_controller->AddStonetoCollum(x, color))
			continue;
		s = m_controller->CheckBoard();
		if (color == Red && s == RedWin)
		{
			bestMove = x;
			bestScore = s;
			m_controller->RemoveStoneFromColum(x);
			break;
		}

		int moveInner, scoreInner;
		if (depth > 1)
			MegamaxAB(color == Red ? Black : Red, depth - 1, moveInner, scoreInner, -beta, -bestScore);
		else
		{
			scoreInner = s;
		}

		m_controller->RemoveStoneFromColum(x);

		bestScore = std::max(scoreInner, bestScore);
		if (scoreInner >= bestScore)
		{
			//Pruning
			if (bestScore >= beta)
				break;
			//
			if (depth == m_CurrentSearchDepth)
				bestMove = x;
		}
	}
	move = bestMove;
	score = bestScore * -1;
}