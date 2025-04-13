#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#ifndef ACTOR_HPP
#define ACTOR_HPP

class Actor {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f spawnPosition;
	
public:
	Actor(const std::string& texturePath, sf::Vector2f spawnPosition);
	~Actor() {};

	///gettrs
	sf::Texture getTexture();
	sf::Sprite getSprite();
	sf::Vector2f getSpawnPosition();
};

#endif 
