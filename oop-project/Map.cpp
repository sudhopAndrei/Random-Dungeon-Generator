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

void Map::setPlayer(Player* player) {
	this->player = new Player("images/bear.png", sf::Vector2f(0, 0), false, false);
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