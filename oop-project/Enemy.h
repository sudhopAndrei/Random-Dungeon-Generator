#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <time.h>

#include "Actor.h"

#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public Actor {
private:
	//vertical and horizontal movement indexes (-1 -> up+left, 0 -> idle, 1 -> down+right)
	int horizontalDirection;
	int verticalDirection;

public:
	Enemy(const std::string& texturePath);
	~Enemy() {};

	sf::Vector2f spawnEnemy();
	void changeDirection() override;
	void handleMovement(float deltaTime) override; //overrides the movement function

	//getters
	EntityType getEntityType() const override;  
};

#endif