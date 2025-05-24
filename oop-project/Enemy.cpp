#include <iostream>
#include <string>

#include "Enemy.h"

Enemy::Enemy(const std::string& texturePath, int hitpoints, int damage) : Actor(texturePath) {
	this->sprite.setPosition(spawnEnemy());
	this->hitpoints = hitpoints;
	this->damage = damage;

	//seed the random number generator (available for both the movement and the spawn position)
	static bool seeded = false;
	if (!seeded) {
		std::srand(static_cast<unsigned>(std::time(nullptr)));
		seeded = true;
	}

	//initialize the enemy with a random direction (default is top-left)
	changeDirection();
}

//randomizer for spawn position
sf::Vector2f Enemy::spawnEnemy() {
	float x = float (std::rand() % 1920);
	float y = float (std::rand() % 1080);
	return sf::Vector2f(x, y);
}

//randomizer for direction changes
void Enemy::changeDirection() {
	this->verticalDirection = std::rand() % 3 - 1;
	this->horizontalDirection = std::rand() % 3 - 1;
}

//handle the movement of the enemy
void Enemy::handleMovement() {
	if (this->verticalDirection > 0) {
		this->sprite.move({ 0.f, 0.03f });
	}
	else if (this->verticalDirection < 0) {
		this->sprite.move({ 0.f, -0.03f });
	}

	if (this->horizontalDirection > 0) {
		this->sprite.move({ 0.03f, 0.f });
	}
	else if (this->horizontalDirection < 0) {
		this->sprite.move({ -0.03f, 0.f });
	}
}

//getters
EntityType Enemy::getEntityType() const {
	return EntityType::Enemy;
}

int Enemy::getHitpoints() {
	return hitpoints;
}
int Enemy::getDamage() {
	return damage;
}