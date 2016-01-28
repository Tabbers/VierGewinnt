#include "aiplayer.h"
#include "boardcontroller.h"
#include "searchalgorithm.h"

AIPlayer::AIPlayer(BoardController* controller)
{
	this->m_controller = controller;
	this->m_search = new SearchAlgorithm(m_controller);
}
AIPlayer::~AIPlayer()
{
}
void AIPlayer::AIMove()
{
	switch (m_style)
	{
		case 'm':
			bool maximize;
			if (g_color == Red)
				maximize = true;
			else
				maximize = false;
			m_search->Minimax(maximize, g_color, m_MaxDepth, m_move);
			break;
		case 'n':
			m_search->Megamax(g_color, m_MaxDepth, m_move);
			break;
		case 'u':
			m_search->Megamax(g_color, 41, m_move);
			break;
		case 'a':
			m_search->MegamaxAB(g_color, m_MaxDepth, m_move);
			break;
		default:
			break;
	}
	 m_controller->AddStonetoCollum(m_move, g_color);
}
std::string AIPlayer::ReturnSettings()
{
	std::string out="";

	switch (m_MaxDepth)
	{
	case 3:
		out += "Difficulty: Easy ";
		break;
	case 5:
		out += "Difficulty: Medium ";
		break;
	case 7:
		out += "Difficulty: Hard ";
		break;
	case 9:
		out += "Difficulty: Prepare To Die ";
		break;
	default:
		break;
	}
	switch (m_style)
	{
	case 'm':
		out += "AI Setting: Minimax ";
		break;
	case 'u':
		out += "AI Setting: Unlimited ";
		break;
	case 'n':
		out += "AI Setting: Negamax ";
		break;
	case 'a':
		out += "AI Setting: Pruned Negamax";
		break;
	default:
		break;
	}

	return out;
}




