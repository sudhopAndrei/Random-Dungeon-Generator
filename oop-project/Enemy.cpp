#include <iostream>
#include <string>

#include "Enemy.h"

Enemy::Enemy(const std::string& texturePath, int hitpoints, int damage) : Actor(texturePath, spawnPosition) {
	this->sprite.setPosition(spawnEnemy());
	this->hitpoints = hitpoints;
	this->damage = damage;
}

sf::Vector2f Enemy::spawnEnemy() {
	float x = (rand() % 1920);
	float y = (rand() % 1080);
	return sf::Vector2f(x, y);
}

void Enemy::handleMovement() {
	sprite.move({ 0.1f, 0.1f });
}

//getters
int Enemy::getHitpoints() {
	return hitpoints;
}
int Enemy::getDamage() {
	return damage;
}