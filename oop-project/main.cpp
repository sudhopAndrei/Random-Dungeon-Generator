#include <SFML/Graphics.hpp>
#include <iostream>

#include "Map.hpp"
#include "Tile.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML", sf::State::Windowed);
	window.setMouseCursorVisible(false); ///window and cursor settings

	Map gameMap = Map(); ///initialize the game map

    while (window.isOpen())
    {
        window.clear();
        for (int i = 0; i < gameMap.getGridHeight(); i++) 
        {
			for (int j = 0; j < gameMap.getGridWidth(); j++)
			{
				window.draw(gameMap.tiles[i][j]->getSprite()); ///drawing the map tiles stored in the vector
			}
        }
        window.display();
    }
}