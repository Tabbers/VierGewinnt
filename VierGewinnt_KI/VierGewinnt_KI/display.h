#include <SFML\Graphics.hpp>
#include "AICore\globaldef.h"

class Board;

class Display
{
public:
	Display(sf::RenderWindow* window, Board *board);
	~Display();
	void Draw(sf::RenderWindow* window);

	void DrawMenu(sf::RenderWindow * window);
	void SetWinningOutline(bool Red);
	void ResetStones();
	

	//Getter
	inline int CellWidth() { return cellwidth; };
	inline int CellHeight() { return cellheight; };

private:
	int cellwidth;
	int cellheight;

	sf::CircleShape Cells[CellsX*CellsY];
	sf::CircleShape RedStone;
	sf::CircleShape BlackStone;
	sf::RectangleShape MenuBlock;
	sf::Text Text;
	sf::Font font;

	Board* board;
};
