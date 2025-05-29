#include <SFML/Graphics.hpp>
#include <vector>

#include "MovingEntities.h"

Enemy* MovingEntities::initializeEnemy() {
	//enemies
	return new Enemy("images/test.png");
}

Player* MovingEntities::initializePlayer() {
	//player
	return new Player("images/bear.png", sf::Vector2f(960, 540));
}