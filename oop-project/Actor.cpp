#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Actor.hpp"

Actor::Actor(const std::string& textureName, sf::Vector2f spawnPosition) : texture(textureName), sprite(texture),
	canMoveUp(true), canMoveLeft(true), canMoveRight(true), canMoveDown(true) {
	texture.setSmooth(true);
	sprite.setPosition(spawnPosition);
	sprite.setTextureRect(sf::IntRect({ 30, 30 }, { 30, 30 }));
}

void Actor::blockMovementUp() {
	this->canMoveUp = false;
	this->sprite.move({ 0.f, 0.2f });
}

void Actor::blockMovementDown() {
	this->canMoveDown = false;
	this->sprite.move({ 0.f, -0.2f });
}

void Actor::blockMovementLeft() {
	this->canMoveLeft = false;
	this->sprite.move({ 0.2f, 0.f });
}

void Actor::blockMovementRight() {
	this->canMoveRight = false;
	this->sprite.move({ -0.2f, 0.f });
}

void Actor::resetMovementFlags() {
	this->canMoveUp = true;
	this->canMoveLeft = true;
	this->canMoveRight = true;
	this->canMoveDown = true;
}

//getters
sf::Texture Actor::getTexture() {
	return texture;
}
sf::Sprite Actor::getSprite() {
	return sprite;
}
sf::Vector2f Actor::getSpawnPosition() {
	return spawnPosition;
}

bool Actor::getCanMoveUp() {
	return canMoveUp;
}
bool Actor::getCanMoveLeft() {
	return canMoveLeft;
}
bool Actor::getCanMoveRight() {
	return canMoveRight;
}
bool Actor::getCanMoveDown() {
	return canMoveDown;
}