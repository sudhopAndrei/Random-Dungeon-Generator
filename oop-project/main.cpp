#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML", sf::Style::Close, sf::State::Fullscreen);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                
                shape.move({ 0.f, -5.f });
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
               
                shape.move({ -5.f, 0.f });
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
               
                shape.move({ 0.f, 5.f });
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                
                shape.move({ 5.f, 0.f });
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}