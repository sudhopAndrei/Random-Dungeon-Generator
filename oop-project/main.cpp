#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "GameManager.h"

int main()
{
    //Window and cursor settings
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML",sf::Style::Default, sf::State::Fullscreen);
    window.setMouseCursorVisible(false); 

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

            if (event->is<sf::Event::KeyPressed>()) {
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape) {
                    window.close();
                }
            }
        }

        //loop that draws every game entity
		for (int i = 0; i < GameManager::getActiveRoom()->roomEntities.size(); i++)
		{
            window.draw(GameManager::getActiveRoom()->roomEntities[i]->getSprite());
		}

        //game handler (collision, movement, etc.)
        GameManager::handleGame();

        window.display();
    }
}

