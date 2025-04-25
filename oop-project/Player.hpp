#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Actor.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player : public Actor {
	bool canMoveUp;
	bool canMoveLeft;
	bool canMoveRight;
	bool canMoveDown;
	bool isHidden;
	bool hasItem;

public:
	Player(const std::string& textureName, sf::Vector2f spawnPosition, bool isHidden, bool hasItem);
	~Player() {};

	void handleMovement(sf::Sprite sprite);

	//getters
	bool getIsHidden();
	bool getHasItem();

	//setters
	void setCanMoveUp(bool canMoveUp);
	void setCanMoveLeft(bool canMoveLeft);
	void setCanMoveRight(bool canMoveRight);
	void setCanMoveDown(bool canMoveDown);
	void setIsHidden(bool isHidden);
	void setHasItem(bool hasItem);
};

#endif 
