#include "display.h"
#include "board.h"

Display::Display(sf::RenderWindow* window, Board *board)
{
	this->board = board;
	cellwidth = window->getSize().x / CellsX;
	cellheight = window->getSize().y / CellsY;

	for (int y = 0; y < CellsY; y++)
	{
		for (int x = 0; x < CellsX; x++)
		{
			Cells[x + y*CellsX].setFillColor(sf::Color::Black);
			Cells[x + y*CellsX].setOutlineColor(sf::Color::Black);
			Cells[x + y*CellsX].setOutlineThickness(-1);
			Cells[x + y*CellsX].setPosition(x*cellwidth, y*cellheight);
			Cells[x + y*CellsX].setRadius(cellwidth / 2);
		}
	}
	BlackStone.setOutlineColor(sf::Color::Magenta);
	BlackStone.setFillColor(sf::Color::Green);
	BlackStone.setRadius(cellwidth/2);

	RedStone.setOutlineColor(sf::Color::Magenta);
	RedStone.setFillColor(sf::Color::Red);
	RedStone.setRadius(cellwidth/2);
	font.loadFromFile("Font/font.ttf");
	Text.setFont(font);
	Text.setCharacterSize(13);
	Text.setColor(sf::Color(50, 50, 50));
}


Display::~Display()
{
}

void Display::Draw(sf::RenderWindow* window)
{
	for each (sf::CircleShape rect in Cells)
	{
		window->draw(rect);
	}
	for (int y = 0; y < CellsY; y++)
	{
		for (int x = 0; x < CellsX; x++)
		{
			switch (board->Cells[x + CellsX*y])
			{
			case Red:
				RedStone.setPosition(x*cellwidth, y*cellheight);
				window->draw(RedStone);
				break;
			case 0:
				break;
			case Black:
				BlackStone.setPosition(x*cellwidth, y*cellheight);
				window->draw(BlackStone);
				break;
			default:
				break;
			}
		}
	}

}
void Display::DrawMenu(sf::RenderWindow* window)
{
	sf::Vector2f size(100, 100);
	MenuBlock.setOutlineColor(sf::Color::Black);
	MenuBlock.setOutlineThickness(2);

	//Menu Header Color
	MenuBlock.setSize(size);
	MenuBlock.setPosition(0, 0);
	MenuBlock.setFillColor(sf::Color(128, 128, 128));
	window->draw(MenuBlock);

	Text.setString("Starting Player\n--------------\nGreen Player\nRed CPU");
	Text.setPosition(5, 5);
	window->draw(Text);

	// Menu Header Algorithm
	size = sf::Vector2f(300, 100);
	MenuBlock.setSize(size);
	MenuBlock.setPosition(100, 0);
	window->draw(MenuBlock);

	Text.setString("Select AI Algorithm");
	Text.setPosition(105, 5);
	window->draw(Text);

	//Menu Header Difficulty
	MenuBlock.setPosition(400, 0);
	window->draw(MenuBlock);

	Text.setString("Select Difficulty Level");
	Text.setPosition(405, 5);
	window->draw(Text);

	//Menu Color Red
	size = sf::Vector2f(50, 500);
	MenuBlock.setSize(size);
	MenuBlock.setPosition(0, 100);
	MenuBlock.setFillColor(sf::Color::Red);
	window->draw(MenuBlock);

	//Menu Color Black
	MenuBlock.setPosition(50, 100);
	MenuBlock.setFillColor(sf::Color::Green);
	window->draw(MenuBlock);

	//Menu Mini 
	size = sf::Vector2f(150, 250);
	MenuBlock.setSize(size);
	MenuBlock.setFillColor(sf::Color(200, 200, 200));
	MenuBlock.setPosition(100, 100);
	window->draw(MenuBlock);

	Text.setString("MiniMax");
	Text.setPosition(105, 105);
	window->draw(Text);

	//Menu Unlimited
	MenuBlock.setPosition(250, 100);
	window->draw(MenuBlock);

	Text.setString("Unlimited");
	Text.setPosition(255, 105);
	window->draw(Text);

	//Menu Easy
	MenuBlock.setPosition(400, 100);
	window->draw(MenuBlock);

	Text.setString("Easy");
	Text.setPosition(405, 105);
	window->draw(Text);
	//Menu Medium
	MenuBlock.setPosition(550, 100);
	window->draw(MenuBlock);

	Text.setString("Medium");
	Text.setPosition(555, 105);
	window->draw(Text);

	//Menu Nega
	MenuBlock.setPosition(100, 350);
	window->draw(MenuBlock);

	Text.setString("Negamax");
	Text.setPosition(105, 355);
	window->draw(Text);

	//Menu Pruned
	MenuBlock.setPosition(250, 350);
	window->draw(MenuBlock);

	Text.setString("Pruned Negamax");
	Text.setPosition(255, 355);
	window->draw(Text);

	//Menu Hard
	MenuBlock.setPosition(400, 350);
	window->draw(MenuBlock);

	Text.setString("Hard");
	Text.setPosition(405, 355);
	window->draw(Text);

	//Menu Extra
	MenuBlock.setPosition(550, 350);
	window->draw(MenuBlock);

	Text.setString("Prepare To Die");
	Text.setPosition(555, 355);
	window->draw(Text);

}

void Display::SetWinningOutline(bool Red)
{
	if (Red)
	{
		RedStone.setOutlineColor(sf::Color::Yellow);
		RedStone.setOutlineThickness(-3);
	}
	else
	{
		BlackStone.setOutlineColor(sf::Color::Yellow);
		BlackStone.setOutlineThickness(-3);
	}

}

void Display::ResetStones()
{
	
	BlackStone.setOutlineColor(sf::Color::Black);
	RedStone.setOutlineColor(sf::Color::Black);
	BlackStone.setOutlineThickness(-1);
	RedStone.setOutlineThickness(-1);
}
