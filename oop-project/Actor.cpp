#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Actor.h"

Actor::Actor(const std::string& textureName) : GameEntity(textureName) {
	sprite.setTextureRect(sf::IntRect({ 30, 30 }, { 30, 30 }));
}

void Actor::blockMovementUp() {
	//this->setSpeed(0.f);
	this->sprite.move({ 0.f, 0.5f });
}

void Actor::blockMovementDown() {
	//this->setSpeed(0.f);
	this->sprite.move({ 0.f, -0.5f });
}

void Actor::blockMovementLeft() {
	//this->setSpeed(0.f);
	this->sprite.move({ 0.5f, 0.f });
}

void Actor::blockMovementRight() {
	//this->setSpeed(0.f);
	this->sprite.move({ -0.5f, 0.f });
}

float Actor::getSpeed() {
	return speed;
}

void Actor::setSpeed(float speed) {
	this->speed = speed;	
}
