#include <SFML/Graphics.hpp>
#include <iostream>

#include "Map.hpp"
#include "Tile.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML", sf::Style::Close, sf::State::Fullscreen);
    window.setMouseCursorVisible(false);

    sf::Texture texture;
	if (texture.loadFromFile("images/test.png") == false)
	{
		std::cout << "Error loading texture" << std::endl;
        return 0;
	}

	sf::Sprite sprite(texture);
    texture.setSmooth(true);

	Map map = Map();


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                
                sprite.move({ 0.f, -5.f });
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
               
                sprite.move({ -5.f, 0.f });
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
               
                sprite.move({ 0.f, 5.f });
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                
                sprite.move({ 5.f, 0.f });
            }
        }

        window.clear();
        for (int i = 0; i < map.getGridHeight(); i++)
        {
			for (int j = 0; j < map.getGridWidth(); j++)
			{
				window.draw(map.tiles[i][j]->getSprite());
			}
        }
        window.draw(sprite);
        window.display();
    }
}