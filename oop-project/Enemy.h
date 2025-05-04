#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Actor.hpp"

#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public Actor {
	int hitpoints;
	int damage;

public:
	Enemy(const std::string& texturePath, int hitpoints, int damage);
	~Enemy() {};

	sf::Vector2f spawnEnemy();
	void handleMovement();

	//getters
	int getHitpoints();
	int getDamage();
};

#endif