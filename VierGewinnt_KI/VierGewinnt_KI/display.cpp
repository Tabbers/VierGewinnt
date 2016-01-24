#include "display.h"


Display::Display(sf::RenderWindow* window)
{
	cellwidth = window->getSize().x / CellsX;
	cellheight = window->getSize().y / CellsY;

	for (int y = 0; y < CellsY; y++)
	{
		for (int x = 0; x < CellsX; x++)
		{
			Cells[x + y*CellsX].setFillColor(sf::Color::Transparent);
			Cells[x + y*CellsX].setOutlineColor(sf::Color::Black);
			Cells[x + y*CellsX].setOutlineThickness(2);
			Cells[x + y*CellsX].setPosition(x*cellwidth, y*cellheight);
			Cells[x + y*CellsX].setSize(sf::Vector2f(cellwidth, cellheight));
		}
	}
	BlackStone.setFillColor(sf::Color::Black);
	BlackStone.setRadius(cellwidth);

	RedStone.setFillColor(sf::Color::Red);
	RedStone.setRadius(cellwidth);
}


Display::~Display()
{
}

void Display::Draw(sf::RenderWindow* window)
{

	for (int y = 0; y < CellsY; y++)
	{
		for (int x = 0; x < CellsX; x++)
		{
			switch (board.Cells[x + cellwidth*y])
			{
			case -1:
				RedStone.setPosition(x*cellwidth, y*cellheight);
				window->draw(RedStone);
				break;
			case 0:
				break;
			case 1:
				BlackStone.setPosition(x*cellwidth, y*cellheight);
				window->draw(RedStone);
				break;
			default:
				break;
			}
		}
	}
	for each (sf::RectangleShape rect in Cells)
	{
		window->draw(rect);
	}
}
