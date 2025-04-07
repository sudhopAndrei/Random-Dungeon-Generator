#include <SFML/Graphics.hpp>
#include <vector>

#include "Tile.hpp"

#ifndef MAP_HPP
#define MAP_HPP

class Map {
	int gridHeight;
	int gridWidth;
public:
	std::vector < std::vector <Tile*> > tiles;
	Map();
	~Map() {};
	void setTiles();
	
	///getters
	int getGridHeight();
	int getGridWidth();
};

#endif