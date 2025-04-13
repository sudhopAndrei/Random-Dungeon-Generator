#include <iostream>
#include <vector>

#include "Tile.hpp"
#include "MapAsset.hpp"

#ifndef MAP_HPP
#define MAP_HPP

class Map {
	Tile* grassTile;
	std::vector <Tile*> floorTiles;
	Tile* bearTile;
	std::vector < MapAsset* > walls;

public:
	Map();
	~Map() {};

	///setters
	void setGrassTiles(Tile* grassTile);
	void setFloorTiles();
	void setBearTile(Tile* bearTile);
	void setWalls();
	
	///getters
	Tile* getGrassTiles();
	std::vector <Tile*> getFloorTiles();
	Tile* getBearTile();
	std::vector < MapAsset* > getWalls();
};

#endif