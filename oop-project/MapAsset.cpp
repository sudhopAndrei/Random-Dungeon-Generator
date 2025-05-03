#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "MapAsset.hpp"

MapAsset::MapAsset(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& type) : texture(textureName), sprite(texture),
	isVerticalCollision(false), isHorizontalCollision(false), hasCollision(false) {
	texture.setSmooth(true);
	texture.setRepeated(true);
	sprite.setTextureRect(sf::IntRect({ 0, 0 }, { sizeX, sizeY }));
	sprite.setPosition(sf::Vector2f(x, y));
}

//getters
sf::Texture MapAsset::getTexture() {
	return texture;
}

sf::Sprite MapAsset::getSprite() {
	return sprite;
}

std::string MapAsset::getType() {
	return type;
}

bool MapAsset::getIsVerticalCollision() {
	return isVerticalCollision;
}
bool MapAsset::getIsHorizontalCollision() {
	return isHorizontalCollision;
}

bool MapAsset::getHasCollision() {
	return hasCollision;
}

//setters
void MapAsset::setIsVerticalCollision(bool isVerticalCollision) {
	this->isVerticalCollision = isVerticalCollision;
}
void MapAsset::setIsHorizontalCollision(bool isHorizontalCollision) {
	this->isHorizontalCollision = isHorizontalCollision;
}
void MapAsset::setHasCollision(bool hasCollision) {
	this->hasCollision = hasCollision;
}