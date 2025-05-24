#include "GameEntity.h"

GameEntity::GameEntity(const std::string& textureName) : texture(textureName), sprite(texture) {
	texture.setSmooth(true);
	texture.setRepeated(true);
}

//static vector of game entities
std::vector <GameEntity*> GameEntity::entities;

//getters
sf::Sprite GameEntity::getSprite() {
	return sprite;
}
