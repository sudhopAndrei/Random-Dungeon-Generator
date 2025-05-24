#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Player.h"

Player::Player(const std::string& textureName, sf::Vector2f spawnPosition) :
    Actor(textureName) {
	this->sprite.setPosition(spawnPosition);
};

void Player::handleMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        this->sprite.move({ 0.f, -0.2f });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        this->sprite.move({ -0.2f, 0.f });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        this->sprite.move({ 0.f, 0.2f });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        this->sprite.move({ 0.2f, 0.f });
    }
}

EntityType Player::getEntityType() const {
    return EntityType::Player;
}


