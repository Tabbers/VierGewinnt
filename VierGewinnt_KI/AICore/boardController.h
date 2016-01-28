#pragma once
#ifdef AICORE_EXPORTS
#define AICORE_API __declspec(dllexport) 
#else
#define AICORE_API __declspec(dllimport) 
#endif

#include "globaldef.h"

class Board;

class AICORE_API BoardController
{
public:
	BoardController(Board *board);
	~BoardController();
	bool AddStonetoCollum(const int column, const int color);
	void RemoveStoneFromColum(int column);

	int CheckBoard();
private:
	struct Score { int score[9] = { 0,0,0,0, 0 ,0,0,0,0 }; };
	void CheckVertical(Score &score);
	void CheckDiagonalL(Score &score);
	void CheckDiagonalR(Score &score);
	void CheckHorizontal(Score &score);
	bool Inside(int x, int y);
	Board* m_board;
};

