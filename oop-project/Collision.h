#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef COLLISION_H
#define COLLISION_H

class Collision {
private:
    //private helper methods
	bool isAbove(sf::Sprite actorSprite, sf::Sprite assetSprite);
	bool isBelow(sf::Sprite actorSprite, sf::Sprite assetSprite);
	bool isLeft(sf::Sprite actorSprite, sf::Sprite assetSprite);
	bool isRight(sf::Sprite actorSprite, sf::Sprite assetSprite);

public:
	virtual bool isColliding(sf::Sprite actorSprite, sf::Sprite assetSprite) = 0;
};

#endif COLLISION_H

