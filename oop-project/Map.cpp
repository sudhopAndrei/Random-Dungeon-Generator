#include <iostream>
#include <vector>

#include "Map.hpp"
#include "Tile.hpp"

Map::Map() {
	gridWidth = 4;
	gridHeight = 3;
	setTiles();
}

void Map::setTiles() {
	tiles.clear();
	std::vector < Tile* > firstRow;
	firstRow.push_back(new Tile("images/test.png", 0, 0, false));
	firstRow.push_back(new Tile("images/test.png", 0, 480, false));
	firstRow.push_back(new Tile("images/test.png", 0, 960, false));
	firstRow.push_back(new Tile("images/test.png", 0, 1440, false));
	tiles.push_back(firstRow);

	std::vector < Tile* > secondRow;
	secondRow.push_back(new Tile("images/test.png", 270, 0, false));
	secondRow.push_back(new Tile("images/test.png", 270, 480, false));
	secondRow.push_back(new Tile("images/test.png", 270, 960, false));
	secondRow.push_back(new Tile("images/test.png", 270, 1440, false));
	tiles.push_back(secondRow);

	std::vector < Tile* > thirdRow;
	thirdRow.push_back(new Tile("images/test.png", 540, 0, false));
	thirdRow.push_back(new Tile("images/test.png", 540, 480, false));
	thirdRow.push_back(new Tile("images/test.png", 540, 960, false));
	thirdRow.push_back(new Tile("images/test.png", 540, 1440, false));
	tiles.push_back(thirdRow);
}

///getters

int Map::getGridHeight() {
	return gridHeight;
}

int Map::getGridWidth() {
	return gridWidth;
}