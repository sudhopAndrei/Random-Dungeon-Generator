#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Room.h"

//initialize the static vector of rooms
std::vector<Room*> Room::rooms;

//initialize the grass tiles
void Room::initializeTiles() {
	GameEntity::entities.push_back(new WalkableTile("images/grassTile.png", 0.f, 0.f, 1920, 1080, "sounds/grassTileWalk.wav"));

	GameEntity::entities.push_back(new WalkableTile("images/floorTile.png", 240.f, 120.f, 1440, 720, "sounds/floorTileWalk.wav"));
	GameEntity::entities.push_back(new WalkableTile("images/bathTile.png", 1320.f, 120.f, 360, 240, "sounds/floorTileWalk.wav"));

	GameEntity::entities.push_back(new WalkableTile("images/bear.png", 880.f, 400.f, 160, 160, "sounds/floorTileWalk.wav"));

	///vertical walls placement
	GameEntity::entities.push_back(new Wall("images/wall.png", 240.f, 120.f, 30, 720));

	GameEntity::entities.push_back(new Wall("images/wall.png", 585.f, 120.f, 30, 215));
	GameEntity::entities.push_back(new Wall("images/wall.png", 585.f, 455.f, 30, 50));
	GameEntity::entities.push_back(new Wall("images/wall.png", 585.f, 625.f, 30, 215));

	GameEntity::entities.push_back(new Wall("images/wall.png", 1320.f, 120.f, 30, 720));
	GameEntity::entities.push_back(new Wall("images/wall.png", 1650.f, 120.f, 30, 720));

	///horizontal walls placement
	GameEntity::entities.push_back(new Wall("images/wall.png", 240.f, 120.f, 1440, 30));
	GameEntity::entities.push_back(new Wall("images/wall.png", 1350.f, 360.f, 315, 30));
	GameEntity::entities.push_back(new Wall("images/wall.png", 240.f, 465.f, 345, 30));
	GameEntity::entities.push_back(new Wall("images/wall.png", 240.f, 810.f, 660, 30));
	GameEntity::entities.push_back(new Wall("images/wall.png", 1020.f, 810.f, 660, 30));
}
