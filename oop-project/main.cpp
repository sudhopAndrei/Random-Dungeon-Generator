#include <SFML/Graphics.hpp>
#include <iostream>

#include "Map.hpp"
#include "Tile.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML", sf::State::Fullscreen);
    window.setMouseCursorVisible(false); ///window and cursor settings

    Map gameMap; ///initialize the game map

    while (window.isOpen())
    {
        window.clear();
        for (int i = 0; i < gameMap.getGridWidth(); i++)
        {
            for (int j = 0; j < gameMap.getGridHeight(); j++)
            {
                window.draw(gameMap.grassTiles[i][j]->getSprite()); ///drawing the map tiles stored in the vector
            }
        }

        for (int i = 0; i < gameMap.getGridWidth()-4; i++)
        {
            for (int j = 0; j < gameMap.getGridHeight()-3; j++)
            {
                window.draw(gameMap.floorTiles[i][j]->getSprite());///drawing the map tiles stored in the vector
            }
        }
        window.display();
    }
}