#include <SFML/Graphics.hpp>
#include <vector>

#include "Tile.hpp"

#ifndef MAP_HPP
#define MAP_HPP

class Map {
	int gridHeight;
	int gridWidth;
public:
	std::vector < std::vector <Tile*> > grassTiles;
	std::vector < std::vector <Tile*> > floorTiles;
	Map();
	~Map() {};
	void setTiles();
	
	///getters
	int getGridHeight();
	int getGridWidth();
};

#endif