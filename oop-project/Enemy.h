#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Actor.hpp"

#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public Actor {
	//vertical and horizontal movement indexes (-1 -> up+left, 0 -> idle, 1 -> down+right)
	int horizontalDirection;
	int verticalDirection;

	int hitpoints;
	int damage;

public:
	Enemy(const std::string& texturePath, int hitpoints, int damage);
	~Enemy() {};

	sf::Vector2f spawnEnemy();
	void changeDirection();
	void handleMovement();

	//getters
	int getHitpoints();
	int getDamage();
};

#endif