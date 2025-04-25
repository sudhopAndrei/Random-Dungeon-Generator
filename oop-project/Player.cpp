#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Player.hpp"

Player::Player(const std::string& textureName, sf::Vector2f spawnPosition, bool isHidden, bool hasItem) :
    Actor(textureName, spawnPosition), canMoveUp(true), canMoveLeft(true), canMoveRight(true), canMoveDown(true) {
    this->isHidden = isHidden;
	this->hasItem = hasItem;
}

void Player::handleMovement(sf::Sprite sprite) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && canMoveUp == true)
    {
        this->sprite.move({ 0.f, -0.1f });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && canMoveLeft == true)
    {
        this->sprite.move({ -0.1f, 0.f });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && canMoveDown == true)
    {
        this->sprite.move({ 0.f, 0.1f });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && canMoveRight == true)
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
void Player::setCanMoveUp(bool canMoveUp) {
	this->canMoveUp = canMoveUp;
}
void Player::setCanMoveLeft(bool canMoveLeft) {
	this->canMoveLeft = canMoveLeft;
}
void Player::setCanMoveRight(bool canMoveRight) {
	this->canMoveRight = canMoveRight;
}
void Player::setCanMoveDown(bool canMoveDown) {
	this->canMoveDown = canMoveDown;
}
void Player::setIsHidden(bool isHidden) {
	this->isHidden = isHidden;
}
void Player::setHasItem(bool hasItem) {
	this->hasItem = hasItem;
}