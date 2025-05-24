#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Wall.h"
#include "WalkableTile.h"
#include "Door.h"

#ifndef ROOM_H
#define ROOM_H

class Room {
public:
	static std::vector <Room*> rooms; //holds all the rooms in the game

	Room() {};
	~Room() {};

	static void initializeTiles();
	void updateRooms();
};

#endif
