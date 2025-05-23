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
	MovingEntities();
	~MovingEntities() {}

public:
	static void initializeActors();
};

#endif