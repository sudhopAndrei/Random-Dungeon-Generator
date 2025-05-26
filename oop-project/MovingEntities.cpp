#include <SFML/Graphics.hpp>
#include <vector>

#include "MovingEntities.h"

void MovingEntities::initializeActors() {
	//player
	GameEntity::entities.push_back(new Player("images/bear.png", sf::Vector2f(960, 540)));

	//enemies
	GameEntity::entities.push_back(new Enemy("images/bear.png", 100, 10));
	GameEntity::entities.push_back(new Enemy("images/bear.png", 100, 10));
	GameEntity::entities.push_back(new Enemy("images/bear.png", 100, 10));
	GameEntity::entities.push_back(new Enemy("images/bear.png", 100, 10));
	GameEntity::entities.push_back(new Enemy("images/bear.png", 100, 10));
	GameEntity::entities.push_back(new Enemy("images/bear.png", 100, 10));
	GameEntity::entities.push_back(new Enemy("images/bear.png", 100, 10));
	GameEntity::entities.push_back(new Enemy("images/bear.png", 100, 10));
}
