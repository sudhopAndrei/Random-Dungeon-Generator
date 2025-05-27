#include <SFML/Graphics.hpp>
#include <iostream>

#include "Collision.h"

bool Collision::isAbove(sf::Sprite actorSprite, sf::Sprite assetSprite) {
	return (actorSprite.getGlobalBounds().position.y + actorSprite.getGlobalBounds().size.y <
		assetSprite.getGlobalBounds().position.y);
}

bool Collision::isBelow(sf::Sprite actorSprite, sf::Sprite assetSprite) {
	return (actorSprite.getGlobalBounds().position.y >
		assetSprite.getGlobalBounds().position.y + assetSprite.getGlobalBounds().size.y);
}

bool Collision::isLeft(sf::Sprite actorSprite, sf::Sprite assetSprite) {
	return (actorSprite.getGlobalBounds().position.x + actorSprite.getGlobalBounds().size.x <
		assetSprite.getGlobalBounds().position.x);
}

bool Collision::isRight(sf::Sprite actorSprite, sf::Sprite assetSprite) {
	return (actorSprite.getGlobalBounds().position.x >
		assetSprite.getGlobalBounds().position.x + assetSprite.getGlobalBounds().size.x);
}

bool Collision::isColliding(sf::Sprite actorSprite, sf::Sprite assetSprite) {
	return (!Collision::isAbove(actorSprite, assetSprite) && 
		!Collision::isBelow(actorSprite, assetSprite) &&
		!Collision::isLeft(actorSprite, assetSprite) &&
		!Collision::isRight(actorSprite, assetSprite));
}

bool Collision::isHorizontalCollision(sf::Sprite actorSprite, sf::Sprite assetSprite) {
	float horizontalCollision;
	float verticalCollision;

	//calculates the lenght for vertical collisions (x-axis movement)
	verticalCollision = std::min(
		actorSprite.getGlobalBounds().position.x + actorSprite.getGlobalBounds().size.x,
		assetSprite.getGlobalBounds().position.x + assetSprite.getGlobalBounds().size.x
	) - std::max(
		actorSprite.getGlobalBounds().position.x,
		assetSprite.getGlobalBounds().position.x
	);

	//calculates the lenght for horizontal collisions (y-axis movement)
	horizontalCollision = std::min(
		actorSprite.getGlobalBounds().position.y + actorSprite.getGlobalBounds().size.y,
		assetSprite.getGlobalBounds().position.y + assetSprite.getGlobalBounds().size.y
	) - std::max(
		actorSprite.getGlobalBounds().position.y,
		assetSprite.getGlobalBounds().position.y
	);

	//the longer collision is picked (one of them will always tend to 0)
	if (horizontalCollision > verticalCollision) {
		return true;
	}

	return false;
}
