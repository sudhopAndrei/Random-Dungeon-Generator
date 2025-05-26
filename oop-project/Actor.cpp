#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Actor.h"

Actor::Actor(const std::string& textureName) : GameEntity(textureName) {
	sprite.setTextureRect(sf::IntRect({ 30, 30 }, { 30, 30 }));
}

void Actor::blockMovementUp() {
	this->sprite.move({ 0.f, 0.5f });
}

void Actor::blockMovementDown() {
	this->sprite.move({ 0.f, -0.5f });
}

void Actor::blockMovementLeft() {
	this->sprite.move({ 0.5f, 0.f });
}

void Actor::blockMovementRight() {
	this->sprite.move({ -0.5f, 0.f });
}
