#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef COLLISION_H
#define COLLISION_H

class Collision {
	bool isVerticalCollision;
	bool isHorizontalCollision;

    //private helper methods
	bool isAbove(sf::Sprite actorSprite, sf::Sprite assetSprite);
	bool isBelow(sf::Sprite actorSprite, sf::Sprite assetSprite);
	bool isLeft(sf::Sprite actorSprite, sf::Sprite assetSprite);
	bool isRight(sf::Sprite actorSprite, sf::Sprite assetSprite);

public:
	Collision() {};
	~Collision() {};
	bool isColliding(sf::Sprite actorSprite, sf::Sprite assetSprite);

	//getters
	bool getIsVerticalCollision();
	bool getIsHorizontalCollision();

	//setters
	void setIsVerticalCollision(bool isVerticalCollision);
	void setIsHorizontalCollision(bool isHorizontalCollision);
};

#endif COLLISION_H

