#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Actor.hpp"

Actor::Actor(const std::string& textureName, sf::Vector2f spawnPosition) : texture(textureName), sprite(texture) {
	texture.setSmooth(true);
	sprite.setPosition(spawnPosition);
	sprite.setTextureRect(sf::IntRect({ 30, 30 }, { 30, 30 }));
}

//getters
sf::Texture Actor::getTexture() {
	return texture;
}

sf::Sprite Actor::getSprite() {
	return sprite;
}

sf::Vector2f Actor::getSpawnPosition() {
	return spawnPosition;
}
