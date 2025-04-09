#include <iostream>
#include <vector>

#include "Map.hpp"
#include "Tile.hpp"
#include "Wall.hpp"

Map::Map() {
	gridWidth = 16;
	gridHeight = 9;
	setTiles();
}

void Map::setTiles() {
	std::vector<Tile*> grassRow;
	grassRow.clear();

	grassTiles.clear();
	for (int i = 0; i < gridWidth; i++) {
		for (int j = 0; j < gridHeight; j++) {
			grassRow.push_back(new Tile("images/grassTile.png", i * 120, j * 120,"sounds/grassTileWalk.wav"));
		}
		grassTiles.push_back(grassRow);
		grassRow.clear();
	}

	std::vector<Tile*> floorRow;
	floorRow.clear();

	floorTiles.clear();
	for (int i = 0; i < gridWidth - 4; i++) {
		for (int j = 0; j < gridHeight - 3; j++) {
			floorRow.push_back(new Tile("images/floorTile.png", (i+2) * 120, (j+1) * 120, "sounds/floorTileWalk.wav"));
		}
		floorTiles.push_back(floorRow);
		floorRow.clear();
	}
}

///getters
int Map::getGridHeight() {
	return gridHeight;
}

int Map::getGridWidth() {
	return gridWidth;
}