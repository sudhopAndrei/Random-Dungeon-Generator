#include <iostream>
#include <vector>
#include <string>

#include "Map.hpp"

Map::Map() {
	setGrassTiles(grassTile);
	setFloorTiles();
	setBearTile(bearTile);
	setWalls();
	setPlayer(player);
}

void Map::setGrassTiles(Tile* grassTile) {
	this->grassTile = new Tile("images/grassTile.png", 0.f, 0.f, 1920, 1080, "grassTile", "sounds/grassTileWalk.wav");
}

void Map::setFloorTiles() {
	floorTiles.clear();

	floorTiles.push_back(new Tile("images/floorTile.png", 240.f, 120.f, 1440, 720, "floorTile", "sounds/floorTileWalk.wav"));
	floorTiles.push_back(new Tile("images/bathTile.png", 1320.f, 120.f, 360, 240, "bathTile", "sounds/floorTileWalk.wav"));
}

void Map::setBearTile(Tile* bearTile) {
	this->bearTile = new Tile("images/bear.png", 880.f, 400.f, 160, 160, "bear", "sounds/floorTileWalk.wav");
}

void Map::setWalls() {
	verticalWalls.clear();
	horizontalWalls.clear();
	
	///vertical walls placement
	verticalWalls.push_back(new MapAsset("images/wall.png", 240.f, 120.f, 30, 720,"wall"));

	verticalWalls.push_back(new MapAsset("images/wall.png", 585.f, 120.f, 30, 215,"wall"));
	verticalWalls.push_back(new MapAsset("images/wall.png", 585.f, 455.f, 30, 50, "wall"));
	verticalWalls.push_back(new MapAsset("images/wall.png", 585.f, 625.f, 30, 215, "wall"));
	
	verticalWalls.push_back(new MapAsset("images/wall.png", 1320.f, 120.f, 30, 720,"wall"));
	verticalWalls.push_back(new MapAsset("images/wall.png", 1650.f, 120.f, 30, 720,"wall"));

	///horizontal walls placement
	horizontalWalls.push_back(new MapAsset("images/wall.png", 240.f, 120.f, 1440, 30,"wall"));
	horizontalWalls.push_back(new MapAsset("images/wall.png", 1350.f, 360.f, 315, 30, "wall"));
	horizontalWalls.push_back(new MapAsset("images/wall.png", 240.f, 465.f, 345, 30,"wall"));
	horizontalWalls.push_back(new MapAsset("images/wall.png", 240.f, 810.f, 660, 30, "wall"));
	horizontalWalls.push_back(new MapAsset("images/wall.png", 1020.f, 810.f, 660, 30, "wall"));
}

void Map::setPlayer(Player* player) {
	this->player = new Player("images/bear.png", sf::Vector2f(30, 30), false, false);
}

void Map::handlePlayerCollision() {
	Collision* collisionInstance = new Collision();

	//handle collision with horizontal walls
	for (int i = 0; i < this->horizontalWalls.size(); i++) {
		if (collisionInstance->isColliding(this->player->getSprite(), this->horizontalWalls[i]->getSprite())) {
			std::cout << "Collision detected" << std::endl;
			if (this->player->getSprite().getGlobalBounds().position.y > this->horizontalWalls[i]->getSprite().getPosition().y) 
				this->player->setCanMoveUp(false);
			else
				this->player->setCanMoveDown(false);
			break;
		}
		else {
			this->player->setCanMoveUp(true);
			this->player->setCanMoveDown(true);
		}
	}

	//handle collision with vertical walls
	for (int i = 0; i < this->verticalWalls.size(); i++) {
		if (collisionInstance->isColliding(this->player->getSprite(), this->verticalWalls[i]->getSprite())) {
			std::cout << "Collision detected" << std::endl;
			if (this->player->getSprite().getGlobalBounds().position.x < this->verticalWalls[i]->getSprite().getPosition().x)
				this->player->setCanMoveRight(false);
			else
				this->player->setCanMoveLeft(false);
			break;
		}
		else {
			this->player->setCanMoveLeft(true);
			this->player->setCanMoveRight(true);
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
std::vector < MapAsset* > Map::getVerticalWalls() {
	return verticalWalls;
}
std::vector < MapAsset* > Map::getHorizontalWalls() {
	return horizontalWalls;
}
Player*  Map::getPlayer() {
	return player;
}