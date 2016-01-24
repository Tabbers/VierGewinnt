#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include "globaldef.h"
#include "display.h"
int main(int argc, char *argv[])
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "Pathfinding");
	Display display;

	bool update = false;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					if (update)update = false;
					else update = true;
				}
				if (event.key.code == sf::Keyboard::Escape) window.close();
			}
			if (window.hasFocus() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i position = sf::Mouse::getPosition(window);
				if (position.y > displ cellwidth * 0 && position.y < cellwidth * 1)
				{
					std::cout << "Place stone on collumn 0";
				}
				else if (position.y > cellwidth * 1 && position.y < cellwidth * 2)
				{
					std::cout << "Place stone on collumn 1";
				}
				else if (position.y > cellwidth * 2 && position.y < cellwidth * 3)
				{
					std::cout << "Place stone on collumn 2";
				}
				else if (position.y > cellwidth * 3 && position.y < cellwidth * 4)
				{
					std::cout << "Place stone on collumn 3";
				}
				else if (position.y > cellwidth * 4 && position.y < cellwidth * 5)
				{
					std::cout << "Place stone on collumn 4";
				}
				else if (position.y > cellwidth * 5 && position.y < cellwidth * 6)
				{
					std::cout << "Place stone on collumn 5";
				}
				else if (position.y > cellwidth * 6 && position.y < cellwidth * 7)
				{
					std::cout << "Place stone on collumn 6";
				}
			}
		}
		if (update)
		{
			window.clear(sf::Color::White);
			//Show to window
			window.display();
		}
	}
	return 0;
}

