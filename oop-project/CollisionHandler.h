#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

class CollisionHandler {
public:
	virtual void handleCollision() = 0;
};

#endif