#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <chrono>

#include "Map.hpp"
#include "Actor.hpp"

int main()
{
    //Window and cursor settings
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML", sf::State::Fullscreen);
    window.setMouseCursorVisible(true); 

    //Initialize the game map
    Map gameMap;

    //timestamps for timed events
    auto lastTime = std::chrono::steady_clock::now();
    const std::chrono::seconds changeInterval(3);

    //Main game loop in which every event and entity is rendered
    while (window.isOpen())
    {
        window.clear();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()){
				
                for (int i = 0; i < gameMap.getEnemies().size(); i++)
				{
					delete gameMap.getEnemies()[i];
				}

                window.close();
            }
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

		//Loop that loads the vertical walls 
		for (int i = 0; i < gameMap.getWalls().size(); i++)
		{
            window.draw(gameMap.getWalls()[i]->getSprite());
		}
        
		//Drawing the player and handling movement and collision
        window.draw(gameMap.getPlayer()->getSprite());
        gameMap.handlePlayerCollision();
		gameMap.getPlayer()->handleMovement();

		//Drawing the enemy
		for (int i = 0; i < gameMap.getEnemies().size(); i++)
		{
			window.draw(gameMap.getEnemies()[i]->getSprite());		

            gameMap.getEnemies()[i]->handleMovement();
		}
		
		//Change the direction of the enemies every 3 seconds
        auto currentTime = std::chrono::steady_clock::now();

        if (currentTime - lastTime >= changeInterval) {
            for (int i = 0; i < gameMap.getEnemies().size(); i++) {
                gameMap.getEnemies()[i]->changeDirection();
            }
            lastTime = currentTime;
        }

        window.display();
    }
}

