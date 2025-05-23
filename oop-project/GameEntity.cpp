#include "GameEntity.h"

GameEntity::GameEntity(const std::string& textureName) : texture(textureName), sprite(texture),
	isHorizontalCollision(false), isVerticalCollision(false) {
	texture.setSmooth(true);
	texture.setRepeated(true);
}

//static vector of game entities
std::vector <GameEntity*> GameEntity::entities;

//getters
sf::Sprite GameEntity::getSprite() {
	return sprite;
}
bool GameEntity::getIsVerticalCollision() {
	return isVerticalCollision;
}
bool GameEntity::getIsHorizontalCollision() {
	return isHorizontalCollision;
}

//setters
void GameEntity::setIsVerticalCollision(bool isVerticalCollision) {
	this->isVerticalCollision = isVerticalCollision;
}
void GameEntity::setIsHorizontalCollision(bool isHorizontalCollision) {
	this->isHorizontalCollision = isHorizontalCollision;
}