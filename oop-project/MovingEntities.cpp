#include <SFML/Graphics.hpp>
#include <vector>

#include "MovingEntities.h"

Enemy* MovingEntities::initializeEnemy() {
	//enemies
	return new Enemy("images/bear.png", 100, 10);
}

Player* MovingEntities::initializePlayer() {
	//player
	return new Player("images/bear.png", sf::Vector2f(960, 540));
}