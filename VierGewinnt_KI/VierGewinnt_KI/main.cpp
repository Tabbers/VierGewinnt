#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include "board.h"
#include "display.h"

#include "AICore\aiplayer.h"
#include "AICore\boardController.h"

#include <string>

int main(int argc, char *argv[])
{

	int CurrentPLayer = Black;
	int PlayerColor = CurrentPLayer;

	bool menu = true;



	Board board;
	BoardController controller(&board);
	AIPlayer ai(&controller);

	std::string input;

	ai.g_color = PlayerColor * -1;;
	sf::ContextSettings context;
	context.antialiasingLevel = 16;
	sf::RenderWindow window(sf::VideoMode(700, 600), "Connect 4",sf::Style::Default,context);
	Display display(&window, &board);

	int Win = 0;
	window.setFramerateLimit(30);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (window.hasFocus()  && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i position = sf::Mouse::getPosition(window);
				if (!menu)
				{
					if (Win != RedWin && Win != BlackWin && CurrentPLayer == PlayerColor)
					{
						int column = -1;
						bool NoOverflow = true;
						std::cout << "Mouse Position: " << position.x << " x " << position.y << " y \n";
						if (position.x > display.CellWidth() * 0 && position.x < display.CellWidth() * 1)
							column = 0;
						else if (position.x > display.CellWidth() * 1 && position.x < display.CellWidth() * 2)
							column = 1;
						else if (position.x > display.CellWidth() * 2 && position.x < display.CellWidth() * 3)
							column = 2;
						else if (position.x > display.CellWidth() * 3 && position.x < display.CellWidth() * 4)
							column = 3;
						else if (position.x > display.CellWidth() * 4 && position.x < display.CellWidth() * 5)
							column = 4;
						else if (position.x > display.CellWidth() * 5 && position.x < display.CellWidth() * 6)
							column = 5;
						else if (position.x > display.CellWidth() * 6 && position.x < display.CellWidth() * 7)
							column = 6;
						std::cout << "Column: " << column << "\n";
						if (column != -1)
							NoOverflow = controller.AddStonetoCollum(column, CurrentPLayer);
						if (NoOverflow)
							CurrentPLayer = -1 * CurrentPLayer;
					}
				}
				else
				{
					if (position.x > 0 && position.x <50) 
						CurrentPLayer = Red;
					if (position.x > 50 && position.x <100) 
						CurrentPLayer = Black;

					if (position.x > 100 && position.x <250 && position.y > 100 && position.y <350) 
						ai.SetMode('m');
					if (position.x > 250 && position.x <400 && position.y > 100 && position.y <350) 
						ai.SetMode('u');
					if (position.x > 100 && position.x <250 && position.y > 350 && position.y <600) 
						ai.SetMode('n');
					if (position.x > 250 && position.x <400 && position.y > 350 && position.y <600) 
						ai.SetMode('a');

					if (position.x > 400 && position.x <550 && position.y > 100 && position.y <350)
						ai.SetDifficulty('e');
					if (position.x > 550 && position.x <700 && position.y > 100 && position.y <350)	
						ai.SetDifficulty('m');
					if (position.x > 400 && position.x <550 && position.y > 350 && position.y <600)	
						ai.SetDifficulty('h');
					if (position.x > 550 && position.x <700 && position.y > 350 && position.y <600)	
						ai.SetDifficulty('x');

					std::string title = "Starting Player: ";
					if (CurrentPLayer == -1)
						title += "Green ";
					else
						title += "Red ";
					title += ai.ReturnSettings();;
					window.setTitle(title);
				}
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape) window.close();
				if (event.key.code == sf::Keyboard::Return)
				{
					menu = !menu;
					Win = 0;
					board.ResetBoard();
					display.ResetStones();
				}
			}
		}
		if (!menu)
		{
			if (Win != RedWin && Win != BlackWin)
			{
				if (CurrentPLayer != PlayerColor)
				{
					Win = controller.CheckBoard();
					if (Win == RedWin)
					{
						CurrentPLayer = 0;
						std::cout << "Red Won!!";
						display.SetWinningOutline(true);
					}
					else if (Win == BlackWin)
					{
						CurrentPLayer = 0;
						std::cout << "Green Won!!";
						display.SetWinningOutline(false);
					}

					if (CurrentPLayer != 0)
					{
						ai.AIMove();
						CurrentPLayer = -1 * CurrentPLayer;
					}
				}
				window.clear(sf::Color(120,30,230));
				display.Draw(&window);
				//Show to window
				window.display();
				if (CurrentPLayer != 0)
				{
					Win = controller.CheckBoard();
					if (Win == RedWin)
					{
						CurrentPLayer = 0;
						std::cout << "Red Won!!";
						display.SetWinningOutline(true);
					}
					else if (Win == BlackWin)
					{
						CurrentPLayer = 0;
						std::cout << "Green Won!!";
						display.SetWinningOutline(false);
					}
				}
			}
		}
		else
		{
			window.clear(sf::Color::White);
			display.DrawMenu(&window);
			//Show to window
			window.display();
		}
	}
	return 0;
}

