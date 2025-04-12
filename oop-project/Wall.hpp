#include <iostream>
#include <string>

#include "MapAsset.hpp"

#ifndef WALL_HPP
#define WALL_HPP


class Wall : public MapAsset {
	bool isPassable;

public:
	Wall(const std::string& textureName, float x, float y, int sizeX, int sizeY, const std::string& type, bool isPassable);
	~Wall() {};
	
	///getters
	bool getIsPassable();

	///setters
	void setIsPassable(bool isPassable);
};

#endif