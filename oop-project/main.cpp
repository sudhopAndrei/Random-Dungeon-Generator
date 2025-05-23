#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "GameManager.h"

int main()
{
    //Window and cursor settings
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML",sf::Style::Default, sf::State::Windowed);
    window.setMouseCursorVisible(true); 

    GameManager::startGame();

    //Main game loop in which every event and entity is rendered
    while (window.isOpen())
    {
        window.clear();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        //loop that draws every game entity
		for (int i = 0; i < GameEntity::entities.size(); i++)
		{
			window.draw(GameEntity::entities[i]->getSprite());
		}

        //game handler (collision, movement, etc.)
        GameManager::handleGame();

        window.display();
    }
}

