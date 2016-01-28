#pragma once

#ifdef AICORE_EXPORTS
#define AICORE_API __declspec(dllexport) 
#else
#define AICORE_API __declspec(dllimport) 
#endif
#include "globaldef.h"

class BoardController;

class AICORE_API SearchAlgorithm
{
public:
	SearchAlgorithm(BoardController* controller);
	~SearchAlgorithm();

	void Minimax(bool maximize, int color, int depth, int & move);
	void Megamax(int color, int depth, int & move);
	void MegamaxAB(int color, int depth, int & move);

	//Setter
	inline void SetCurrrentsearchDepth(int sreachDepth)
	{
		this->m_CurrentSearchDepth = sreachDepth;
	}
private:

	void Minimax(bool maximize, int color, int depth, int & move, int & score);
	void Megamax(int color, int depth, int & move, int & score);
	void MegamaxAB(int color, int depth, int & move, int & score, int alpha, int beta);

	BoardController* m_controller;
	int m_CurrentSearchDepth = 0;
	int m_score = 0;
};

