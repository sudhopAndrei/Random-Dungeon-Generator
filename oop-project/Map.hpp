#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Tile.hpp"
#include "MapAsset.hpp"
#include "Actor.hpp"
#include "Player.hpp"
#include "Collision.h"

#ifndef MAP_HPP
#define MAP_HPP

class Map {
	Tile* grassTile;
	std::vector <Tile*> floorTiles;
	Tile* bearTile;
	std::vector < MapAsset* > walls;
	Player* player;

public:
	Map();
	~Map() {};
	void checkCollision();

	//setters
	void setGrassTiles(Tile* grassTile);
	void setFloorTiles();
	void setBearTile(Tile* bearTile);
	void setWalls();
	void setPlayer(Player* player);

	//getters
	Tile* getGrassTiles();
	std::vector <Tile*> getFloorTiles();
	Tile* getBearTile();
	std::vector < MapAsset* > getWalls();
	Player* getPlayer();
};

#endif
