#include <iostream>
#include <vector>

#include "Tile.hpp"
#include "MapAsset.hpp"
#include "Actor.hpp"

#ifndef MAP_HPP
#define MAP_HPP

class Map {
	Tile* grassTile;
	std::vector <Tile*> floorTiles;
	Tile* bearTile;
	std::vector < MapAsset* > walls;
	std::vector < Actor* > actors;

public:
	Map();
	~Map() {};

	///setters
	void setGrassTiles(Tile* grassTile);
	void setFloorTiles();
	void setBearTile(Tile* bearTile);
	void setWalls();
	void setActors();
	
	///getters
	Tile* getGrassTiles();
	std::vector <Tile*> getFloorTiles();
	Tile* getBearTile();
	std::vector < MapAsset* > getWalls();
	std::vector < Actor* > getActors();
};

#endif