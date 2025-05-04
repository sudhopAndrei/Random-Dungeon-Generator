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

	bool canMoveUp;
	bool canMoveLeft;
	bool canMoveRight;
	bool canMoveDown;
	
public:
	Actor(const std::string& texturePath, sf::Vector2f spawnPosition);
	virtual ~Actor() {};

	//block the movement
	void blockMovementUp();
	void blockMovementDown();
	void blockMovementLeft();
	void blockMovementRight();

	//reset all flags
	void resetMovementFlags();

	//getters
	sf::Texture getTexture();
	sf::Sprite getSprite();
	sf::Vector2f getSpawnPosition();

	bool getCanMoveUp();
	bool getCanMoveLeft();
	bool getCanMoveRight();
	bool getCanMoveDown();
};

#endif

