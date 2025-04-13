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

		window.draw(gameMap.getGrassTiles()->getSprite());

        for (int i = 0; i < gameMap.getFloorTiles().size(); i++)
        {
            window.draw(gameMap.getFloorTiles()[i]->getSprite());
        }

		window.draw(gameMap.getBearTile()->getSprite());

		///Loop that loads the walls 
		for (int i = 0; i < gameMap.getWalls().size(); i++)
		{
            window.draw(gameMap.getWalls()[i]->getSprite());
		}

        window.display();
    }
}

