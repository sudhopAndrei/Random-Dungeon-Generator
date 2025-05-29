#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef COLLISION_H
#define COLLISION_H

#include "GameEntity.h"

class Collision {
private:
    //private helper methods
	static bool isAbove(sf::Sprite actorSprite, sf::Sprite assetSprite);
	static bool isBelow(sf::Sprite actorSprite, sf::Sprite assetSprite);
	static bool isLeft(sf::Sprite actorSprite, sf::Sprite assetSprite);
	static bool isRight(sf::Sprite actorSprite, sf::Sprite assetSprite);

protected:
	Collision() {};
	~Collision() {};

public:
	static bool isColliding(sf::Sprite actorSprite, sf::Sprite assetSprite);

	static bool isHorizontalCollision(sf::Sprite actorSprite, sf::Sprite assetSprite);
};

#endif 

