#include <SFML/Graphics.hpp>
#include <iostream>

#include "CollisionDetection.h"

bool CollisionDetection::isAbove(sf::Sprite actorSprite, sf::Sprite assetSprite) {
	return (actorSprite.getGlobalBounds().position.y + actorSprite.getGlobalBounds().size.y <
		assetSprite.getGlobalBounds().position.y);
}

bool CollisionDetection::isBelow(sf::Sprite actorSprite, sf::Sprite assetSprite) {
	return (actorSprite.getGlobalBounds().position.y >
		assetSprite.getGlobalBounds().position.y + assetSprite.getGlobalBounds().size.y);
}

bool CollisionDetection::isLeft(sf::Sprite actorSprite, sf::Sprite assetSprite) {
	return (actorSprite.getGlobalBounds().position.x + actorSprite.getGlobalBounds().size.x <
		assetSprite.getGlobalBounds().position.x);
}

bool CollisionDetection::isRight(sf::Sprite actorSprite, sf::Sprite assetSprite) {
	return (actorSprite.getGlobalBounds().position.x >
		assetSprite.getGlobalBounds().position.x + assetSprite.getGlobalBounds().size.x);
}

bool CollisionDetection::isColliding(sf::Sprite actorSprite, sf::Sprite assetSprite) {
	return (!CollisionDetection::isAbove(actorSprite, assetSprite) && 
		!CollisionDetection::isBelow(actorSprite, assetSprite) &&
		!CollisionDetection::isLeft(actorSprite, assetSprite) &&
		!CollisionDetection::isRight(actorSprite, assetSprite));
}

bool CollisionDetection::isHorizontalCollision(sf::Sprite actorSprite, sf::Sprite assetSprite) {
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

	if (horizontalCollision < verticalCollision) {
		return false;
	}
}
