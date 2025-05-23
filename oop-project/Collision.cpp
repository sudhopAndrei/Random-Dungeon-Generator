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
