#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "GameManager.h"

int main()
{
    //Window and cursor settings
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML", sf::Style::Default, sf::State::Fullscreen);
    window.setMouseCursorVisible(false);

    //loading screen
    sf::Texture loadingTetxure;
	if (!loadingTetxure.loadFromFile("images/loadingScreen.png")) {
		std::cout << "error loading texture" << std::endl;
		return -1;
	}
	sf::Sprite loadingSprite(loadingTetxure);
    loadingSprite.setTextureRect({ {0, 0}, {1920, 1080} });

	window.clear();
	window.draw(loadingSprite);
	window.display();

    //start game
    GameManager::startGame();

    //Main game loop in which every event and entity is rendered
    while (window.isOpen())
    {
        window.clear();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (event->is<sf::Event::KeyPressed>()) {
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape) {
                    window.close();
                }
            }
        }

        //loop that draws every game entity
        for (int i = 0; i < GameManager::getActiveRoom()->getRoomEntities().size(); i++)
        {
            window.draw(GameManager::getActiveRoom()->getRoomEntities()[i]->getSprite());
        }

        //game handler (collision, movement, etc.)
        GameManager::handleGame();

        window.display();
    }
}