#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Actor.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player : public Actor {
	bool hasItem;

public:
	Player(const std::string& textureName, sf::Vector2f spawnPosition, bool hasItem);
	~Player() {};

	void handleMovement();

	//getters
	bool getHasItem();

	//setters
	void setHasItem(bool hasItem);
};

#endif 
