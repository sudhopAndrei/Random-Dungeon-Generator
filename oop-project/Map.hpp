#include <iostream>
#include <vector>

#include "Tile.hpp"
#include "Wall.hpp"

#ifndef MAP_HPP
#define MAP_HPP

class Map {
	const int gridWidth = 16;
	const int gridHeight = 9;
	std::vector < std::vector <Tile*> > grassTiles;
	std::vector < std::vector <Tile*> > floorTiles;
	Tile* bear;
	std::vector < Wall* > walls;

public:
	Map();
	~Map() {};

	///setters
	void setGrassTiles();
	void setFloorTiles();
	void setBear(Tile* bear);
	void setWalls();
	
	///getters
	const int getGridHeight();
	const int getGridWidth();
	std::vector < std::vector <Tile*> > getGrassTiles();
	std::vector < std::vector <Tile*> > getFloorTiles();
	Tile* getBear();
	std::vector < Wall* > getWalls();
};

#endif