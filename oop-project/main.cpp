#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Map.hpp"
#include "Actor.hpp"

int main()
{
    //Window and cursor settings
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML", sf::State::Windowed);
    window.setMouseCursorVisible(true); 

    //Initialize the game map
    Map gameMap;

    //Main game loop in which every event and entity is rendered
    while (window.isOpen())
    {
        window.clear();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        //Drawing the grass tiles
		window.draw(gameMap.getGrassTiles()->getSprite());

		//Loop that loads the floor tiles
        for (int i = 0; i < gameMap.getFloorTiles().size(); i++)
        {
            window.draw(gameMap.getFloorTiles()[i]->getSprite());
        }

        //Drawing the bear carpet tile
		window.draw(gameMap.getBearTile()->getSprite());

		//Loop that loads the walls 
		for (int i = 0; i < gameMap.getWalls().size(); i++)
		{
            window.draw(gameMap.getWalls()[i]->getSprite());
		}
        
		//Drawing the player
        window.draw(gameMap.getPlayer()->getSprite());
		gameMap.getPlayer()->handleMovement(gameMap.getPlayer()->getSprite());
		gameMap.checkCollision();

        window.display();
    }

}

