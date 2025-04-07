#include <SFML/Graphics.hpp>
#include <vector>

#include "Tile.hpp"

#ifndef MAP_HPP
#define MAP_HPP

class Map {
	sf::Vector2f playerPosition;
	void setTiles();
public:
	std::vector < std::vector <Tile*> > tiles;
	int gridHeight;
	int gridWidth;
	Map();
};

#endif