#include <iostream>
#include <vector>
#include <string>

#include "Map.hpp"
#include "Tile.hpp"
#include "Wall.hpp"

Map::Map() {
	setGrassTiles();
	setFloorTiles();
	setBear(bear);
	setWalls();
}

void Map::setGrassTiles() {
	std::vector<Tile*> grassRow;
	grassRow.clear();

	grassTiles.clear();
	for (int i = 0; i < gridWidth; i++) {
		for (int j = 0; j < gridHeight; j++) {
			grassRow.push_back(new Tile("images/grassTile.png", i * 120, j * 120, 120, 120, "grassTile", "sounds/grassTileWalk.wav"));
		}
		grassTiles.push_back(grassRow);
		grassRow.clear();
	}
}

void Map::setFloorTiles() {
	std::vector<Tile*> floorRow;
	floorRow.clear();

	floorTiles.clear();
	for (int i = 0; i < gridWidth - 4; i++) {
		for (int j = 0; j < gridHeight - 3; j++) {
			if (i >= (gridWidth - 4) - 3 && j < 2) {
				floorRow.push_back(new Tile("images/floorTile.png", (i + 2) * 120, (j + 1) * 120, 120, 120, "bathTile", "sounds/floorTileWalk.wav"));
			}
			else if (i >= (gridWidth - 4 ) - 3 && j >= 2) {
				floorRow.push_back(new Tile("images/floorTile.png", (i + 2) * 120, (j + 1) * 120, 120, 120, "concreteTile", "sounds/floorTileWalk.wav"));
			}
			else {
				floorRow.push_back(new Tile("images/floorTile.png", (i + 2) * 120, (j + 1) * 120, 120, 120, "floorTile", "sounds/floorTileWalk.wav"));
			}
		}
		floorTiles.push_back(floorRow);
		floorRow.clear();
	}
}

void Map::setBear(Tile* bear) {
	this->bear = new Tile("images/bear.png", 900, 420, 120, 120, "bear", "sounds/floorTileWalk.wav");
}

void Map::setWalls() {
	walls.clear();
	
	///vertical walls placement
	walls.push_back(new Wall("images/wall.png", 240, 120, 30, 720,"wall", false));

	walls.push_back(new Wall("images/wall.png", 585, 120, 30, 215,"wall", false));
	walls.push_back(new Wall("images/wall.png", 585, 455, 30, 50, "wall", false));
	walls.push_back(new Wall("images/wall.png", 585, 625, 30, 215, "wall", false));
	
	walls.push_back(new Wall("images/wall.png", 1305, 120, 30, 720,"wall", false));
	walls.push_back(new Wall("images/wall.png", 1650, 120, 30, 720,"wall", false));

	///horizontal walls placement
	walls.push_back(new Wall("images/wall.png", 240, 120, 1440, 30,"wall", false));
	walls.push_back(new Wall("images/wall.png", 1335, 345, 315, 30, "wall", false));
	walls.push_back(new Wall("images/wall.png", 240, 465, 345, 30,"wall", false));
	walls.push_back(new Wall("images/wall.png", 240, 810, 660, 30, "wall", false));
	walls.push_back(new Wall("images/wall.png", 1020, 810, 660, 30, "wall", false));
}

///getters
const int Map::getGridHeight() {
	return gridHeight;
}

const int Map::getGridWidth() {
	return gridWidth;
}

std::vector < std::vector <Tile*> > Map::getGrassTiles() {
	return grassTiles;
}
std::vector < std::vector <Tile*> > Map::getFloorTiles() {
	return floorTiles;
}
Tile* Map::getBear() {
	return bear;
}
std::vector < Wall* > Map::getWalls() {
	return walls;
}
