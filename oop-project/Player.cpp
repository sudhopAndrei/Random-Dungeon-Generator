#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Player.h"

Player::Player(const std::string& textureName, sf::Vector2f spawnPosition) :
    Actor(textureName) {
	this->sprite.setPosition(spawnPosition);
    this->setSpeed(350.f);
};

void Player::handleMovement(float deltaTime) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        this->sprite.move({ 0.f, -this->getSpeed() *deltaTime });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        this->sprite.move({ -this->getSpeed() * deltaTime, 0.f });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        this->sprite.move({ 0.f, this->getSpeed() * deltaTime });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        this->sprite.move({ this->getSpeed() * deltaTime, 0.f });
    }
}

EntityType Player::getEntityType() const {
    return EntityType::Player;
}


