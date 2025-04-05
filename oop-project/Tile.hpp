#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#ifndef MAP_HPP
#define MAP_HPP

class Tile {
public:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	bool isPassable;
	Tile(const std::string& textureName, float x, float y, bool isPassable);
	bool setSprite(const std::string);
};

#endif
