#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Player.hpp"

Player::Player(const std::string& textureName, sf::Vector2f spawnPosition, bool isHidden, bool hasItem) : Actor(textureName, spawnPosition) {
	this->isHidden = isHidden;
	this->hasItem = hasItem;
}

void Player::handleMovement(sf::Sprite sprite) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        this->sprite.move({ 0.f, -0.1f });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        this->sprite.move({ -0.1f, 0.f });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        this->sprite.move({ 0.f, 0.1f });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        this->sprite.move({ 0.1f, 0.f });
    }
}

//getters
bool Player::getIsHidden() {
	return isHidden;
}
bool Player::getHasItem() {
	return hasItem;
}

//setters
void Player::setIsHidden(bool isHidden) {
	this->isHidden = isHidden;
}
void Player::setHasItem(bool hasItem) {
	this->hasItem = hasItem;
}