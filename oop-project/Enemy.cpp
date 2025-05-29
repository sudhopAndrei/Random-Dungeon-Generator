#include <iostream>
#include <string>

#include "Enemy.h"

Enemy::Enemy(const std::string& texturePath) : Actor(texturePath) {
	this->sprite.setPosition(spawnEnemy());
	this->setSpeed(150.f);

	//seed the random number generator (available for both the movement and the spawn position)
	static bool seeded = false;
	if (!seeded) {
		srand(unsigned int (time(NULL)));
		seeded = true;
	}

	//initialize the enemy with a random direction (default is top-left)
	changeDirection();
}

//randomizer for spawn position (ensures that the enemy spawns within the game area)
sf::Vector2f Enemy::spawnEnemy() {
	float x = float (std::rand() % 1680 + 120);
	float y = float (std::rand() % 840 + 120);
	return sf::Vector2f(x, y);
}

//randomizer for direction changes
void Enemy::changeDirection() {
	this->verticalDirection = std::rand() % 3 - 1;
	this->horizontalDirection = std::rand() % 3 - 1;
}

//handle the movement of the enemy
void Enemy::handleMovement(float deltaTime) {

	if (this->verticalDirection > 0) {
		this->sprite.move({ 0.f, this->getSpeed() * deltaTime });
	}
	else if (this->verticalDirection < 0) {
		this->sprite.move({ 0.f, -this->getSpeed() * deltaTime });
	}

	if (this->horizontalDirection > 0) {
		this->sprite.move({ this->getSpeed() * deltaTime, 0.f });
	}
	else if (this->horizontalDirection < 0) {
		this->sprite.move({ -this->getSpeed() * deltaTime, 0.f });
	}
}

//getters
EntityType Enemy::getEntityType() const {
	return EntityType::Enemy;
}
