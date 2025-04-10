#include <iostream>
#include <vector>
#include <string>

#include "Map.hpp"
#include "Tile.hpp"
#include "Wall.hpp"

Map::Map() {
	setGrassTiles();
	setFloorTiles();
	setWalls();
}

void Map::setGrassTiles() {
	std::vector<Tile*> grassRow;
	grassRow.clear();

	grassTiles.clear();
	for (int i = 0; i < gridWidth; i++) {
		for (int j = 0; j < gridHeight; j++) {
			grassRow.push_back(new Tile("images/grassTile.png", i * 120, j * 120, 120, 120,"sounds/grassTileWalk.wav"));
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
				floorRow.push_back(new Tile("images/bathTile.png", (i + 2) * 120, (j + 1) * 120, 120, 120, "sounds/floorTileWalk.wav"));
			}
			else if (i >= (gridWidth - 4 ) - 3 && j >= 2) {
				floorRow.push_back(new Tile("images/floorTile.png", (i + 2) * 120, (j + 1) * 120, 120, 120, "sounds/floorTileWalk.wav"));
			}
			else {
				floorRow.push_back(new Tile("images/floorTile.png", (i + 2) * 120, (j + 1) * 120, 120, 120, "sounds/floorTileWalk.wav"));
			}
		}
		floorTiles.push_back(floorRow);
		floorRow.clear();
	}
}

void Map::setWalls() {
	walls.clear();
	
	///vertical walls placement
	walls.push_back(new Wall("images/grass.png", 225, 120, 30, 720, false));
	walls.push_back(new Wall("images/grass.png", 585, 120, 30, 720, false));
	walls.push_back(new Wall("images/grass.png", 1305, 120, 30, 720, false));
	walls.push_back(new Wall("images/grass.png", 1665, 120, 30, 720, false));

	///horizontal walls placement
	walls.push_back(new Wall("images/grass.png", 225, 105, 1470, 30, false));
	walls.push_back(new Wall("images/grass.png", 225, 840, 1470, 30, false));
	walls.push_back(new Wall("images/grass.png", 225, 465, 360, 30, false));
	walls.push_back(new Wall("images/grass.png", 1305, 345, 360, 30, false));
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
std::vector < Wall* > Map::getWalls() {
	return walls;
}
