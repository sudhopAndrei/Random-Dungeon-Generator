#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#ifndef TILE_HPP
#define TILE_HPP

class Tile {
	sf::Texture texture;
	sf::Sprite sprite;
	bool isPassable; ///check if a tile is passable or not

public:
	Tile(const std::string& textureName, float x, float y, bool isPassable);
	~Tile() {};
	bool setSprite(const std::string& textureName);
	
	///getters
	sf::Texture getTexture();
	sf::Sprite getSprite();
	bool getIsPassable();
};

#endif
