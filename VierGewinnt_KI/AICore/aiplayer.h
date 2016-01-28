#pragma once
#ifdef AICORE_EXPORTS
#define AICORE_API __declspec(dllexport) 
#else
#define AICORE_API __declspec(dllimport) 
#endif

#include <string>

class BoardController;
class SearchAlgorithm;

class AICORE_API AIPlayer
{
public:
	AIPlayer(BoardController* controller);
	~AIPlayer();

	void AIMove();
	
	//GETTER
	std::string ReturnSettings();

	//SETTER
	inline void SetMode(char mode)
	{
		this->m_style = mode;
	};
	inline void SetDifficulty(char difficulty)
	{
		switch (difficulty)
		{
		case 'e':
			m_MaxDepth = 3;
			break;
		case 'm':
			m_MaxDepth = 5;
			break;
		case 'h':
			m_MaxDepth = 7;
			break;
		case 'x':
			m_MaxDepth = 9;
			break;
		default:
			break;
		}
	};
	int g_color = 0;
private:
	int m_MaxDepth = 1;
	int m_move = -1;
	char m_style = 'n';

	BoardController* m_controller;
	SearchAlgorithm* m_search;
};