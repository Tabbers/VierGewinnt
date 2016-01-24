#include <SFML\Graphics.hpp>
#include "globaldef.h"
#include "board.h"

class Display
{
public:
	Display(sf::RenderWindow* window);
	~Display();
	void Draw(sf::RenderWindow* window);
private:
	int cellwidth;
	int cellheight;

	sf::RectangleShape Cells[CellsX*CellsY];
	sf::CircleShape RedStone;
	sf::CircleShape BlackStone;
	Board board;
};
