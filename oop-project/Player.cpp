#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Player.hpp"

Player::Player(const std::string& textureName, sf::Vector2f spawnPosition, bool isHidden, bool hasItem) : Actor(textureName, spawnPosition) {
	this->isHidden = isHidden;
	this->hasItem = hasItem;
}

void Player::handleMovement() {
	sf::Vector2f movement(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		movement.y -= 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		movement.y += 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		movement.x -= 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		movement.x += 1.f;
	}
	sprite.move(movement);
}

///getters
bool Player::getIsHidden() {
	return isHidden;
}
bool Player::getHasItem() {
	return hasItem;
}

///setters
void Player::setIsHidden(bool isHidden) {
	this->isHidden = isHidden;
}
void Player::setHasItem(bool hasItem) {
	this->hasItem = hasItem;
}