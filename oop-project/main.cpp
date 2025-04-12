#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Map.hpp"

int main()
{
    ///Window and cursor settings
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML", sf::State::Windowed);
    window.setMouseCursorVisible(true); 

    Map gameMap; ///Initialize the game map

    ///Main game loop in which every event and entity is rendered
    while (window.isOpen())
    {
        window.clear();

        ///Nested loop that loads the grass tiles
        for (int i = 0; i < gameMap.getGridWidth(); i++)
        {
            for (int j = 0; j < gameMap.getGridHeight(); j++)
            {
                window.draw(gameMap.getGrassTiles()[i][j]->getSprite());
            }
        }

		///Nested loop that loads the floor tiles 
        for (int i = 0; i < gameMap.getGridWidth()-4; i++)
        {
            for (int j = 0; j < gameMap.getGridHeight()-3; j++)
            {
                window.draw(gameMap.getFloorTiles()[i][j]->getSprite());
            }
        }

		window.draw(gameMap.getBear()->getSprite());

		///Loop that loads the walls 
		for (int i = 0; i < gameMap.getWalls().size(); i++)
		{
            window.draw(gameMap.getWalls()[i]->getSprite());
		}
        window.display();
    }
}

