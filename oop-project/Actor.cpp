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

void Actor::handleCollision(GameEntity* managedEntity, GameEntity* collidedEntity) {
	//calculates if the player is above or below the wall
	if (CollisionDetection::isHorizontalCollision(managedEntity->getSprite(),collidedEntity->getSprite()) == false) {
		if (this->getSprite().getGlobalBounds().position.y > collidedEntity->getSprite().getGlobalBounds().position.y) {
			managedEntity->blockMovementUp();
		}
		else if (this->getSprite().getGlobalBounds().position.y < collidedEntity->getSprite().getGlobalBounds().position.y) {
			managedEntity->blockMovementDown();
		}
	}

	//calculates if the player is left or right of the wall
	if (CollisionDetection::isHorizontalCollision(managedEntity->getSprite(), collidedEntity->getSprite()) == true) {
		if (managedEntity->getSprite().getGlobalBounds().position.x < collidedEntity->getSprite().getGlobalBounds().position.x) {
			managedEntity->blockMovementRight();
		}
		else if (managedEntity->getSprite().getGlobalBounds().position.x > collidedEntity->getSprite().getGlobalBounds().position.x) {
			managedEntity->blockMovementLeft();
		}
	}
}