#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "MapAsset.hpp"

MapAsset::MapAsset(const std::string& textureName, float x, float y) : texture(textureName), sprite(texture) {
	texture.setSmooth(true);
	sprite.setTextureRect(sf::IntRect({ 0, 0 }, { 120, 120 })); ///customizing the texture
	sprite.setPosition(sf::Vector2f(x, y));

}

///getters
sf::Texture MapAsset::getTexture() {
	return texture;
}

sf::Sprite MapAsset::getSprite() {
	return sprite;
}
