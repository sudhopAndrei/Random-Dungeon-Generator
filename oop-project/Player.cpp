#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Player.hpp"

Player::Player(const std::string& textureName, sf::Vector2f spawnPosition, bool hasItem) :
    Actor(textureName, spawnPosition) {
	this->hasItem = hasItem;
}

void Player::handleMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && canMoveUp == true)
    {
        this->sprite.move({ 0.f, -0.2f });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && canMoveLeft == true)
    {
        this->sprite.move({ -0.2f, 0.f });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && canMoveDown == true)
    {
        this->sprite.move({ 0.f, 0.2f });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && canMoveRight == true)
    {
        this->sprite.move({ 0.2f, 0.f });
    }
}

//getters
bool Player::getHasItem() {
	return hasItem;
}

//setters
void Player::setHasItem(bool hasItem) {
	this->hasItem = hasItem;
}