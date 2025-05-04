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
	setActors();
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

//initialize the actprs (player and enemies)
void Map::setActors() {
	actors.clear();

	actors.push_back(new Player("images/bear.png", sf::Vector2f(30, 30), false));

	actors.push_back(new Enemy("images/bear.png", 100, 10));
	actors.push_back(new Enemy("images/bear.png", 100, 10));
	actors.push_back(new Enemy("images/bear.png", 100, 10));
	actors.push_back(new Enemy("images/bear.png", 100, 10));
	actors.push_back(new Enemy("images/bear.png", 100, 10));
	actors.push_back(new Enemy("images/bear.png", 100, 10));
	actors.push_back(new Enemy("images/bear.png", 100, 10));
	actors.push_back(new Enemy("images/bear.png", 100, 10));
}

//get the collision type (vertical or horizontal) between an actor and a collidable object
void Map::setCollisionType(Actor* actor, MapAsset* wall) {
	float horizontalCollision;
	float verticalCollision;

	//calculates the lenght for vertical collisions (x-axis movement)
	verticalCollision = std::min(
		actor->getSprite().getGlobalBounds().position.x + actor->getSprite().getGlobalBounds().size.x,
		wall->getSprite().getGlobalBounds().position.x + wall ->getSprite().getGlobalBounds().size.x
	) - std::max(
		actor->getSprite().getGlobalBounds().position.x,
		wall->getSprite().getGlobalBounds().position.x
	);

	//calculates the lenght for horizontal collisions (y-axis movement)
	horizontalCollision = std::min(
		actor->getSprite().getGlobalBounds().position.y + actor->getSprite().getGlobalBounds().size.y,
		wall->getSprite().getGlobalBounds().position.y + wall->getSprite().getGlobalBounds().size.y
	) - std::max(
		actor->getSprite().getGlobalBounds().position.y,
		wall->getSprite().getGlobalBounds().position.y
	);

	//the longer collision is picked (one of them will always tend to 0)
	if (horizontalCollision > verticalCollision) {
		this->CollisionInstance.setIsHorizontalCollision(true);
	}

	if (horizontalCollision < verticalCollision) {
		this->CollisionInstance.setIsVerticalCollision(true);
	}
}

//handle the actor collision with the collidable instances
void Map::handleActorCollision() {

	for (int i = 0; i < actors.size(); i++) {
		bool collisionDetected = false;

		for (int j = 0; j < this->walls.size(); j++) {

			//if there is collision, set the collision type for the wall
			if (this->CollisionInstance.isColliding(this->actors[i]->getSprite(), this->walls[j]->getSprite())) {
				Map::setCollisionType(this->actors[i], this->walls[j]);

				//calculates if the player is above or below the wall
				if (this->CollisionInstance.getIsVerticalCollision() == true) {
					if (this->actors[i]->getSprite().getGlobalBounds().position.y > this->walls[j]->getSprite().getGlobalBounds().position.y) {
						this->actors[i]->blockMovementUp();
					}
					else if (this->actors[i]->getSprite().getGlobalBounds().position.y < this->walls[j]->getSprite().getGlobalBounds().position.y) {
						this->actors[i]->blockMovementDown();
					}
				}

				//calculates if the player is left or right of the wall
				if (this->CollisionInstance.getIsHorizontalCollision() == true) {
					if (this->actors[i]->getSprite().getGlobalBounds().position.x < this->walls[j]->getSprite().getGlobalBounds().position.x) {
						this->actors[i]->blockMovementRight();
					}
					else if (this->actors[i]->getSprite().getGlobalBounds().position.x > this->walls[j]->getSprite().getGlobalBounds().position.x) {
						this->actors[i]->blockMovementLeft();
					}
				}
				collisionDetected = true;
			}
		}

		//if no collision is detected, reset the movement flags
		if (collisionDetected == false) {
			this->CollisionInstance.setIsVerticalCollision(false);
			this->CollisionInstance.setIsHorizontalCollision(false);
			this->actors[i]->resetMovementFlags();
		}
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
Player* Map::getPlayer() {
	for (int i = 0; i < actors.size(); i++) {
		Player* player = dynamic_cast<Player*>(actors[i]);
		if (player != nullptr) {
			return player;
		}
	}
}
std::vector<Enemy*> Map::getEnemies() {
	enemies.clear();

	for (int i = 0; i < actors.size(); i++) {

		Enemy* enemy = dynamic_cast<Enemy*>(actors[i]);
		if (enemy != nullptr) {
			enemies.push_back(enemy);
		}
	}
	return enemies;
}