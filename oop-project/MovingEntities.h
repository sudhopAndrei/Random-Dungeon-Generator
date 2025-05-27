#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "GameEntity.h"
#include "Player.h"
#include "Enemy.h"

#ifndef MOVINGENTITIES_H
#define MOVINGENTITIES_H

class MovingEntities {
private:
	//factory class, private constructor
	MovingEntities();
	~MovingEntities() {}

public:
	static Player* initializePlayer();
	static Enemy* initializeEnemy();
};

#endif