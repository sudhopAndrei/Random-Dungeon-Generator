#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

class CollisionDetection {
private:
    //private helper methods
	bool isAbove(sf::Sprite actorSprite, sf::Sprite assetSprite);
	bool isBelow(sf::Sprite actorSprite, sf::Sprite assetSprite);
	bool isLeft(sf::Sprite actorSprite, sf::Sprite assetSprite);
	bool isRight(sf::Sprite actorSprite, sf::Sprite assetSprite);

public:
	bool isColliding(sf::Sprite actorSprite, sf::Sprite assetSprite);

	bool isHorizontalCollision(sf::Sprite actorSprite, sf::Sprite assetSprite);
};

#endif 

