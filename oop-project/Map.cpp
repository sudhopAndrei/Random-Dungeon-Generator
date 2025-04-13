#include <iostream>
#include <vector>
#include <string>

#include "Map.hpp"

Map::Map() {
	setGrassTiles(grassTile);
	setFloorTiles();
	setBearTile(bearTile);
	setWalls();

	setActors();
}

void Map::setGrassTiles(Tile* grassTile) {
	this->grassTile = new Tile("images/grassTile.png", 0, 0, 1920, 1080, "grassTile", "sounds/grassTileWalk.wav");
}

void Map::setFloorTiles() {
	floorTiles.clear();

	floorTiles.push_back(new Tile("images/floorTile.png", 240, 120, 1440, 720, "floorTile", "sounds/floorTileWalk.wav"));
	floorTiles.push_back(new Tile("images/bathTile.png", 1320, 120, 360, 240, "bathTile", "sounds/floorTileWalk.wav"));
}

void Map::setBearTile(Tile* bearTile) {
	this->bearTile = new Tile("images/bear.png", 880, 400, 160, 160, "bear", "sounds/floorTileWalk.wav");
}

void Map::setWalls() {
	walls.clear();
	
	///vertical walls placement
	walls.push_back(new MapAsset("images/wall.png", 240, 120, 30, 720,"wall"));

	walls.push_back(new MapAsset("images/wall.png", 585, 120, 30, 215,"wall"));
	walls.push_back(new MapAsset("images/wall.png", 585, 455, 30, 50, "wall"));
	walls.push_back(new MapAsset("images/wall.png", 585, 625, 30, 215, "wall"));
	
	walls.push_back(new MapAsset("images/wall.png", 1320, 120, 30, 720,"wall"));
	walls.push_back(new MapAsset("images/wall.png", 1650, 120, 30, 720,"wall"));

	///horizontal walls placement
	walls.push_back(new MapAsset("images/wall.png", 240, 120, 1440, 30,"wall"));
	walls.push_back(new MapAsset("images/wall.png", 1350, 360, 315, 30, "wall"));
	walls.push_back(new MapAsset("images/wall.png", 240, 465, 345, 30,"wall"));
	walls.push_back(new MapAsset("images/wall.png", 240, 810, 660, 30, "wall"));
	walls.push_back(new MapAsset("images/wall.png", 1020, 810, 660, 30, "wall"));
}

void Map::setActors() {
    actors.clear();

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
