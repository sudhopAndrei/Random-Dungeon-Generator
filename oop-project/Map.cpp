#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Map.hpp"

Map::Map() {
	setGrassTiles(grassTile);
	setFloorTiles();
	setBearTile(bearTile);
	setWalls();
	setPlayer(player);
}

//initialize the grass tiles
void Map::setGrassTiles(Tile* grassTile) {
	this->grassTile = new Tile("images/grassTile.png", 0.f, 0.f, 1920, 1080, "grassTile", "sounds/grassTileWalk.wav");
}

//initialize the floor tiles
void Map::setFloorTiles() {
	floorTiles.clear();

	floorTiles.push_back(new Tile("images/floorTile.png", 240.f, 120.f, 1440, 720, "floorTile", "sounds/floorTileWalk.wav"));
	floorTiles.push_back(new Tile("images/bathTile.png", 1320.f, 120.f, 360, 240, "bathTile", "sounds/floorTileWalk.wav"));
}

//initialize the bear tile
void Map::setBearTile(Tile* bearTile) {
	this->bearTile = new Tile("images/bear.png", 880.f, 400.f, 160, 160, "bear", "sounds/floorTileWalk.wav");
}

//initialize the walls
void Map::setWalls() {
	walls.clear();
	
	///vertical walls placement
	walls.push_back(new MapAsset("images/wall.png", 240.f, 120.f, 30, 720,"wall"));

	walls.push_back(new MapAsset("images/wall.png", 585.f, 120.f, 30, 215,"wall"));
	walls.push_back(new MapAsset("images/wall.png", 585.f, 455.f, 30, 50, "wall"));
	walls.push_back(new MapAsset("images/wall.png", 585.f, 625.f, 30, 215, "wall"));
	
	walls.push_back(new MapAsset("images/wall.png", 1320.f, 120.f, 30, 720,"wall"));
	walls.push_back(new MapAsset("images/wall.png", 1650.f, 120.f, 30, 720,"wall"));

	///horizontal walls placement
	walls.push_back(new MapAsset("images/wall.png", 240.f, 120.f, 1440, 30,"wall"));
	walls.push_back(new MapAsset("images/wall.png", 1350.f, 360.f, 315, 30, "wall"));
	walls.push_back(new MapAsset("images/wall.png", 240.f, 465.f, 345, 30,"wall"));
	walls.push_back(new MapAsset("images/wall.png", 240.f, 810.f, 660, 30, "wall"));
	walls.push_back(new MapAsset("images/wall.png", 1020.f, 810.f, 660, 30, "wall"));
}

//initialize the player
void Map::setPlayer(Player* player) {
	this->player = new Player("images/bear.png", sf::Vector2f(30, 30), false);
}

//get the collision type (vertical or horizontal) between an actor and a collidable object
void Map::setCollisionType(Actor* actor, MapAsset* wall) {
	float horizontalCollision;
	float verticalCollision;

	verticalCollision = std::min(
		actor->getSprite().getGlobalBounds().position.x + actor->getSprite().getGlobalBounds().size.x,
		wall->getSprite().getGlobalBounds().position.x + wall ->getSprite().getGlobalBounds().size.x
	) - std::max(
		actor->getSprite().getGlobalBounds().position.x,
		wall->getSprite().getGlobalBounds().position.x
	);

	horizontalCollision = std::min(
		actor->getSprite().getGlobalBounds().position.y + actor->getSprite().getGlobalBounds().size.y,
		wall->getSprite().getGlobalBounds().position.y + wall->getSprite().getGlobalBounds().size.y
	) - std::max(
		actor->getSprite().getGlobalBounds().position.y,
		wall->getSprite().getGlobalBounds().position.y
	);


	if (horizontalCollision > verticalCollision) {
		wall->setIsHorizontalCollision(true);
	}
	else if (horizontalCollision < verticalCollision) {
		wall->setIsVerticalCollision(true);
	}
}

//handle the actor collision with the collidable instances
void Map::handlePlayerCollision() {
	bool collisionDetected = false;

	for (int i = 0; i < this->walls.size(); i++) {

		if (this->playerCollisionInstance.isColliding(this->player->getSprite(), this->walls[i]->getSprite())) {
			Map::setCollisionType(this->player, this->walls[i]);
			this->walls[i]->setHasCollision(true);
			collisionDetected = true;
		}

		if (this->walls[i]->getIsVerticalCollision() == true) {
			if (this->player->getSprite().getGlobalBounds().position.y > this->walls[i]->getSprite().getGlobalBounds().position.y) {
				this->player->resetUp();
			}
			else if (this->player->getSprite().getGlobalBounds().position.y < this->walls[i]->getSprite().getGlobalBounds().position.y) {
				this->player->resetDown();
			}
		}

		if (this->walls[i]->getIsHorizontalCollision() == true) {
			if (this->player->getSprite().getGlobalBounds().position.x < this->walls[i]->getSprite().getGlobalBounds().position.x) {
				this->player->resetRight();
			}
			else if (this->player->getSprite().getGlobalBounds().position.x > this->walls[i]->getSprite().getGlobalBounds().position.x) {
				this->player->resetLeft();
			}
		}
	}
		
	if (collisionDetected == false) {
		for (int i = 0; i < this->walls.size(); i++) {
			this->walls[i]->setIsVerticalCollision(false);
			this->walls[i]->setIsHorizontalCollision(false);
			this->walls[i]->setHasCollision(false);
		}
		this->player->resetMovementFlags();
	}
}

Tile* Map::getGrassTiles() {
	return grassTile;
}
std::vector <Tile*> Map::getFloorTiles() {
	return floorTiles;
}
Tile* Map::getBearTile() {
	return bearTile;
}
std::vector < MapAsset* > Map::getWalls() {
	return walls;
}
Player*  Map::getPlayer() {
	return player;
}