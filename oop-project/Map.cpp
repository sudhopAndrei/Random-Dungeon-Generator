#include <iostream>
#include <vector>
#include <cstdlib>

#include "Map.hpp"
#include "Tile.hpp"

Map::Map() {
	gridWidth = 4;
	gridHeight = 3;
	playerPosition = sf::Vector2f(rand() % 1921, 0);
	setTiles();
}

void Map::setTiles() {
	tiles.clear();
	std::vector < Tile* > firstRow;
	firstRow.push_back(new Tile("images/test.png", 0, 0, false));
	firstRow.push_back(new Tile("images/test.png", 0, 480, false));
	firstRow.push_back(new Tile("images/test.png", 0, 960, false));
	firstRow.push_back(new Tile("images/test.png", 0, 1440, false));

	std::vector < Tile* > secondRow;
	secondRow.push_back(new Tile("images/test.png", 0, 0, false));
	secondRow.push_back(new Tile("images/test.png", 0, 480, false));
	secondRow.push_back(new Tile("images/test.png", 0, 960, false));
	secondRow.push_back(new Tile("images/test.png", 0, 1440, false));

	std::vector < Tile* > thirdRow;
	thirdRow.push_back(new Tile("images/test.png", 0, 0, false));
	thirdRow.push_back(new Tile("images/test.png", 0, 480, false));
	thirdRow.push_back(new Tile("images/test.png", 0, 960, false));
	thirdRow.push_back(new Tile("images/test.png", 0, 1440, false));
}