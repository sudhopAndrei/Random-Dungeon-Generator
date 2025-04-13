#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Actor.hpp"

#ifndef PLAYER.HPP
#define PLAYER.HPP

class Player : public Actor {
	bool isHidden;
	bool hasItem;

public:
	Player(const std::string& texturePath, sf::Vector2f spawnPosition, bool isHidden, bool hasItem);
	~Player() {};

	void handleMovement();

	///getters
	bool getIsHidden();
	bool getHasItem();

	///setters
	void setIsHidden(bool isHidden);
	void setHasItem(bool hasItem);
};

#endif 
