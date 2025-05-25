#include <SFML/Graphics.hpp>
#include <iostream>

#include "CollisionDetection.h"

#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

class GameEntity; //forward declaration

class CollisionHandler {
public:
	virtual void handleCollision(GameEntity* managedEntity, GameEntity* collidedEntity = nullptr) = 0;
};

#endif